#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include "Multiply.h"
#include "Multiply.r.h"

static void eval(void *v)
{
    Multiply_t o = v;
    setRes(v, Flow.math.multiply(res(depsI(v, 0)), res(depsI(v, 1))));
}
static void deval(void *v)
{
    setCoeftI(v, 0, Flow.deriv.multiply(res(depsI(v, 0)), res(depsI(v, 1)), res(depsI(v, 0))));
    setCoeftI(v, 1, Flow.deriv.multiply(res(depsI(v, 0)), res(depsI(v, 1)), res(depsI(v, 1))));
}

static MultiplyClass_st Class;
const void *Multiply = 0;

// assigning inheritance and overrides
static void __attribute__((constructor)) multiplyClassf()
{
    if (Multiply)
        return;
    twotooneLC();
    mut(Multiply, void *, &Class);
    memcpy((void *)Multiply, TwoToOne, sizeof(TwoToOneClass_st));
    (*(ObjClass_t)&Class).size = sizeof(Multiply_st);
    static const char name[] = "Multiply";
    (*(ObjClass_t)&Class).name = name;
    (*(ObjClass_t)&Class).super = TwoToOne;
    (*(VarClass_t)&Class).eval = eval;
    (*(VarClass_t)&Class).diff = deval;
}
