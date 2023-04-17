#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include "TwoToOne.h"
#include "TwoToOne.r.h"

static void cstr(void *obj, va_list *arg)
{
    setDeps(obj, internalOperands(obj), 2);
    setDepsI(obj, 0, va_arg(*arg, Op_t));
    setDepsI(obj, 1, va_arg(*arg, Op_t));
    return;
}

static void dstr(void *obj)
{
    setDeps(obj, 0, 2);
    superdstr(TwoToOne, obj);
}

static TwoToOneClass_st Class;
const void *TwoToOne = 0;

// assigning inheritance and overrides
static void __attribute__((constructor)) twotooneClassf()
{
    if (TwoToOne)
        return;
    opLC();
    mut(TwoToOne, void *, &Class);
    memcpy((void *)TwoToOne, Op, sizeof(TwoToOneClass_st));
    (*(ObjClass_t)&Class).size = sizeof(TwoToOne_st);
    static const char name[] = "TwoToOne";
    (*(ObjClass_t)&Class).name = name;
    (*(ObjClass_t)&Class).super = Op;
    (*(ObjClass_t)&Class).cstr = cstr;
    (*(ObjClass_t)&Class).dstr = dstr;
}

const fn_t twotooneLC = twotooneClassf;
