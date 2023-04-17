#include <stdlib.h>
#include <stdio.h>
#include "CG.h"

#ifndef AS_LIB
int main()
{
    Var_t x = neu(Var);
    Var_t y = neu(Var);
    Var_t w = neu(Var);
    Var_t u = neu(Var);
    Var_t v = jCG.add(x, y);
    Var_t t = jCG.add(u, y);
    Var_t z = jCG.add(t, v);
    printf("xObj %i\n", istypeof(x, Obj));
    printf("xVar %i\n", istypeof(x, Var));
    printf("xOp %i\n", istypeof(x, Op));
    printf("yObj %i\n", istypeof(y, Obj));
    printf("yVar %i\n", istypeof(y, Var));
    printf("yOp %i\n", istypeof(y, Op));
    printf("zObj %i\n", istypeof(z, Obj));
    printf("zVar %i\n", istypeof(z, Var));
    printf("zOp %i %p\n", istypeof(z, Op), z);

    jCG.build(t);
    jCG.build(v);
    jCG.build(z);
    return 0;
}
#endif