#ifndef BUILDDATA_H
#define BUILDDATA_H

#include <Obj.h>

#ifdef __cplusplus
extern 'C'
{
#endif

    extern const void *BuildData;
    typedef struct BuildData *BuildData_t;
    // other declarations go here
    typedef struct BuildDataFn
    {
        int (*isBuildData)(const void *bd);
        int (*buildList)(const void *bd, const void ***liat);
    } BuildDataFn_t;
    extern BuildDataFn_t BuildDataFn;

#ifdef __cplusplus
}
#endif
#endif