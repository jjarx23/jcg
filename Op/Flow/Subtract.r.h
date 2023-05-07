#ifndef SUBTRACT_R_H
#define SUBTRACT_R_H

#include "../TwoToOne.r.h"

#ifdef __cplusplus
extern 'C'
{
#endif

    typedef struct SubtractClass *SubtractClass_t;
    typedef struct SubtractClass SubtractClass_st;
    typedef struct Subtract Subtract_st;
    struct SubtractClass
    {
        TwoToOneClass_st _;
        // other members go here
    };
    struct Subtract
    {
        const TwoToOne_st _;
        // other members go here
    };

#ifdef __cplusplus
}
#endif
#endif