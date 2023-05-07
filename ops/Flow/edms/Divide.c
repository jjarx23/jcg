#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include "Divide.h"
#include "Divide.r.h"

static void eval(void *v)
{
    Divide_t o = v;
    setRes(v, Flow.math.divide(res(depsI(v, 0)), res(depsI(v, 1))));
}

static void deval(void *v)
{
    setCoeftI(v, 0, Flow.deriv.divide(res(depsI(v, 0)), res(depsI(v, 1)), res(depsI(v, 0))));
    setCoeftI(v, 1, Flow.deriv.divide(res(depsI(v, 0)), res(depsI(v, 1)), res(depsI(v, 1))));
}

static DivideClass_st Class;
const void *Divide = 0;

// assigning inheritance and overrides
static void __attribute__((constructor)) divideClassf()
{
    if (Divide)
        return;
    twotooneLC();
    mut(Divide, void *, &Class);
    memcpy((void *)Divide, TwoToOne, sizeof(TwoToOneClass_st));
    (*(ObjClass_t)&Class).size = sizeof(Divide_st);
    static const char name[] = "Divide";
    (*(ObjClass_t)&Class).name = name;
    (*(ObjClass_t)&Class).super = TwoToOne;
    (*(VarClass_t)&Class).eval = eval;
    (*(VarClass_t)&Class).diff = deval;
}
