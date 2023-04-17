#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "Op.h"
#include "Op.r.h"
#include "BuildData.h"

static void dstr(void *obj)
{
    brkDeps(obj);
    superdstr(Op, obj);
    // printf("Op destructor \n");
}

static void eval(void *v)
{
    // TODO: check availablity of v->Res
    int i = nDeps(v);
    while (i)
    {
        i--;
        supereval(Op, depsI(v, i));
    }
    VarClass_t c = classOf(v);
    printf("%p==%p\n", c->eval, eval);
    if ((c = classOf(v))->eval == eval)
    {
        printf("extend class Op and override its eval() fn\n");
        exit(-1);
    }
}
static void diff(void *v)
{
    // TODO: check availablity of v->Res
    int i = nDeps(v);
    while (i)
    {
        i--;
        supereval(Op, depsI(v, i));
    }
    VarClass_t c = classOf(v);
    // printf("%p==%p\n", c->diff, diff);
    if ((c = classOf(v))->diff == diff)
    {
        if (c == Op)
            printf("Op requires inheritance \n");
        else
            printf("override class %s diff()\n", className(v));
        exit(-1);
    }
}

static OpClass_st Class;
const void *Op = 0;

// assigning inheritance and overrides
static void __attribute__((constructor)) opClassf()
{
    if (Op)
        return;
    varLC();
    mut(Op, void *, &Class);
    memcpy((void *)Op, Var, sizeof(VarClass_st));
    (*(ObjClass_t)&Class).size = sizeof(Op_st);
    static const char name[] = "Op";
    (*(ObjClass_t)&Class).name = name;
    (*(ObjClass_t)&Class).super = Var;
    (*(ObjClass_t)&Class).dstr = dstr;
    (*(VarClass_t)&Class).diff = diff;
    (*(VarClass_t)&Class).eval = eval;
}
const fn_t opLC = opClassf;
