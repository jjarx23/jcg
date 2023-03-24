#include <stdlib.h>
#include "CG.h"

#ifndef AS_LIB
int main(){
    Var_t x=neu(Var);
    Var_t y=neu(Var);
    Var_t z=CG.add(x,y);
    printf("xObj%i\n",istypeof(x, Obj));
    printf("xVar%i\n",istypeof(x, Var));
    printf("xOp%i\n", istypeof(x, Op));
    printf("yObj%i\n",istypeof(y, Obj));
    printf("yVar%i\n",istypeof(y, Var));
    printf("yOp%i\n", istypeof(y, Op));
    printf("zObj%i\n",istypeof(z, Obj));
    printf("zVar%i\n",istypeof(z, Var));
    printf("zOp%i %p\n", istypeof(z, Op), z);

    CG.build(z);
    return 0;
}
#endif