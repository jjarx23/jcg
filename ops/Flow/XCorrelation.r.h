#ifndef XCORRELATION_R_H
#define XCORRELATION_R_H

#include "../TwoToOne.r.h"

#ifdef __cplusplus
extern 'C'
{
#endif

    extern const fn_t xcorrelationLC;

    typedef struct XCorrelationClass *XCorrelationClass_t;
    typedef struct XCorrelationClass XCorrelationClass_st;
    typedef struct XCorrelation XCorrelation_st;
    struct XCorrelationClass
    {
        TwoToOneClass_st _;
        // other members go here
    };
    struct XCorrelation
    {
        const TwoToOne_st _;
        // other members go here
    };

#ifdef __cplusplus
}
#endif
#endif