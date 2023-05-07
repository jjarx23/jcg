#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include "Add.h"
#include "Add.r.h"
// static inline void *derivs(Op_t o, int count, ...);
static void eval(void *v)
{
    setRes(v, Flow.math.add(res(depsI(v, 0)), res(depsI(v, 1))));
}
static void deval(void *v)
{
    setCoeftI(v, 0, Flow.deriv.add(res(depsI(v, 0)), res(depsI(v, 1)), res(depsI(v, 0))));
    setCoeftI(v, 1, Flow.deriv.add(res(depsI(v, 0)), res(depsI(v, 1)), res(depsI(v, 1))));
}

static AddClass_st Class;
const void *Add = 0;

// assigning inheritance and overrides
static void __attribute__((constructor)) addClassf()
{
    if (Add)
        return;
    twotooneLC();
    mut(Add, const void *, &Class);
    memcpy((void *)Add, TwoToOne, sizeof(TwoToOneClass_st));
    (*(ObjClass_t)&Class).size = sizeof(Add_st);
    static const char name[] = "Add";
    (*(ObjClass_t)&Class).name = name;
    (*(ObjClass_t)&Class).super = TwoToOne;
    (*(VarClass_t)&Class).eval = eval;
    (*(VarClass_t)&Class).diff = deval;
}
