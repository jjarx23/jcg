#ifndef TWOTOONE_R_H
#define TWOTOONE_R_H

#include "../Op.r.h"

#ifdef __cplusplus
extern 'C'{
#endif

typedef struct TwoToOneClass* TwoToOneClass_t;
typedef struct TwoToOneClass TwoToOneClass_st;
typedef struct TwoToOne TwoToOne_st;
struct TwoToOneClass{
    OpClass_st _;
    //other members go here
};
struct TwoToOne{
    const Op_st _;
    //other members go here
    const Op_t a, b;
};

#define setA(x,y)mut(((TwoToOne_t)x)->a, Op_t, y)
#define setB(x,y)mut(((TwoToOne_t)x)->b, Op_t, y)

#ifdef __cplusplus
}
#endif
#endif