#ifndef BUILDDATA_R_H
#define BUILDDATA_R_H

#include "Obj.r.h"

#ifdef __cplusplus
extern 'C'
{
#endif

    typedef struct BuildDataClass *BuildDataClass_t;
    typedef struct BuildDataClass BuildDataClass_st;
    typedef struct BuildData BuildData_st;
    struct BuildDataClass
    {
        ObjClass_st _;
        // other members go here
    };
    struct BuildData
    {
        const Obj_st _;
        // other members go here
        const void **list;
        const int count;
    };

#ifdef __cplusplus
}
#endif
#endif