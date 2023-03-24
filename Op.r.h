#ifndef OP_R_H
#define OP_R_H

#include "Var.r.h"

#ifdef __cplusplus
extern 'C'{
#endif

typedef struct OpClass* OpClass_t;
typedef struct OpClass OpClass_st;
typedef struct Op Op_st;
struct OpClass{
    VarClass_st _;
    //other members go here
};
struct Op{
    const Var_st _;
    //other members go here
    const int ndeps;
    const Op_t *deps;
};

#define nDeps(x)(((Op_t)x)->ndeps)
#define depList(x)(((Op_t)x)->deps)

#define setNDeps(o, y)mut(((Op_t)o)->ndeps,int,y)
#define setDeps(o, y)mut(((Op_t)o)->deps,Op_t *,y)

#define initDeps(x, n)mut(((Op_t)x)->deps, Op_t *, n>1?malloc(n*sizeof(Op_t)):0)

#ifdef __cplusplus
}
#endif
#endif