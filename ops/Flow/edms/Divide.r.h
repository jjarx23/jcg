#ifndef DIVIDE_R_H
#define DIVIDE_R_H

#include "../../TwoToOne.r.h"

#ifdef __cplusplus
extern 'C'
{
#endif

    extern const fn_t divideLC;

    typedef struct DivideClass *DivideClass_t;
    typedef struct DivideClass DivideClass_st;
    typedef struct Divide Divide_st;
    struct DivideClass
    {
        TwoToOneClass_st _;
        // other members go here
    };
    struct Divide
    {
        const TwoToOne_st _;
        // other members go here
    };

#ifdef __cplusplus
}
#endif
#endif