#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include "XCorrelation.h"
#include "XCorrelation.r.h"
#define UNIT_NAME "XCorrelation"

static XCorrelationClass_st Class;
const void *XCorrelation = 0;

// assigning inheritance and overrides
static void __attribute__((constructor)) xcorrelationClassf()
{
    if (XCorrelation)
        return;
    twotooneLC();
    mut(XCorrelation, void *, &Class);
    memcpy(XCorrelation, TwoToOne, sizeof(TwoToOneClass_st));
    (*(ObjClass_t)&Class).size = sizeof(XCorrelation_st);
    (*(ObjClass_t)&Class).super = TwoToOne;
    static const char name[] = "XCorrelation";
    (*(ObjClass_t)&Class).name = name;
    //(*(VarClass_t)&Class).eval = eval;
    //(*(VarClass_t)&Class).diff = deval;
}
const fn_t xcorrelationLC = xcorrelationClassf;
