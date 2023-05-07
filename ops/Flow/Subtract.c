#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include "Subtract.h"
#include "Subtract.r.h"

static void eval(void *v)
{
    Subtract_t o = v;
    setRes(v, Flow.math.subtract(res(depsI(v, 0)), res(depsI(v, 1))));
}
static void deval(void *v)
{
    setCoeftI(v, 0, Flow.deriv.subtract(res(depsI(v, 0)), res(depsI(v, 1)), res(depsI(v, 0))));
    setCoeftI(v, 1, Flow.deriv.subtract(res(depsI(v, 0)), res(depsI(v, 1)), res(depsI(v, 1))));
}

static SubtractClass_st Class;
const void *Subtract = 0;

// assigning inheritance and overrides
static void __attribute__((constructor)) subtractClassf()
{
    if (Subtract)
        return;
    twotooneLC();
    mut(Subtract, void *, &Class);
    memcpy((void *)Subtract, TwoToOne, sizeof(TwoToOneClass_st));
    (*(ObjClass_t)&Class).size = sizeof(Subtract_st);
    static const char name[] = "Subtract";
    (*(ObjClass_t)&Class).name = name;
    (*(ObjClass_t)&Class).super = TwoToOne;
    (*(VarClass_t)&Class).eval = eval;
    (*(VarClass_t)&Class).diff = deval;
}
