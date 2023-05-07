#ifndef MULTIPLY_R_H
#define MULTIPLY_R_H

#include "../../TwoToOne.r.h"

#ifdef __cplusplus
extern 'C'
{
#endif

    extern const fn_t multiplyLC;

    typedef struct MultiplyClass *MultiplyClass_t;
    typedef struct MultiplyClass MultiplyClass_st;
    typedef struct Multiply Multiply_st;
    struct MultiplyClass
    {
        TwoToOneClass_st _;
        // other members go here
    };
    struct Multiply
    {
        const TwoToOne_st _;
        // other members go here
    };

#ifdef __cplusplus
}
#endif
#endif