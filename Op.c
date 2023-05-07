#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include "Op.h"
#include "Op.r.h"
#include "BuildData.h"

static void dstr(void *obj)
{
    brkDeps(obj);
    superdstr(Op, obj);
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
    if ((c = classOf(v))->eval == eval)
    {
        fatalErr("Op: %s extend class Op and override its eval() fn\n", className(v));
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
    if ((c = classOf(v))->diff == diff)
    {
        if (c == Op)
            fatalErr("Op: Op requires inheritance \n");
        else
            fatalErr("Op: override class %s diff()\n", className(v));
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
