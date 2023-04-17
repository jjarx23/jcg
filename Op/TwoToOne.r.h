#ifndef TWOTOONE_R_H
#define TWOTOONE_R_H

#include "../Op.r.h"

#ifdef __cplusplus
extern 'C'
{
#endif

    extern const fn_t twotooneLC;

    typedef struct TwoToOneClass *TwoToOneClass_t;
    typedef struct TwoToOneClass TwoToOneClass_st;
    typedef struct TwoToOne TwoToOne_st;
    struct TwoToOneClass
    {
        OpClass_st _;
        // other members go here
    };
    struct TwoToOne
    {
        const Op_st _;
        // other members go here
        const Var_t operand1, operand2;
    };
    static inline Var_t *internalOperands(TwoToOne_t t)
    {
        return &t->operand1;
    }
#ifdef __cplusplus
}
#endif
#endif
