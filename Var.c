#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <Flow.h>
#include "Var.h"
#include "Var.r.h"

static void cstr(void *obj, va_list *arg)
{
    setRes(obj, va_arg(*arg, void *));
}
static int rpr(const void *b, char *str, int length)
{
    return Flow->stringOf(res(b), str, length);
}

static void eval(void *v)
{
    if (!res(v))
    {
        printf("%p(%s) missing operand\n", v, className(v));
        exit(-1);
    }
}

static VarClass_st Class;
const void *Var = 0;
static const char name[] = "Var";

static void __attribute__((constructor)) varClassf()
{
    if (Var)
        return;
    // assigning inheritance and overrides
    mut(Var, void *, &Class);
    memcpy((void *)Var, Obj, sizeof(ObjClass_st));
    (*(ObjClass_t)&Class).size = sizeof(Var_st);
    (*(ObjClass_t)&Class).name = name;
    (*(ObjClass_t)&Class).super = Obj;
    (*(ObjClass_t)&Class).cstr = cstr;
    (*(ObjClass_t)&Class).rpr = rpr;
    Class.diff = Class.eval = eval;
}

const fn_t varLC = varClassf;
