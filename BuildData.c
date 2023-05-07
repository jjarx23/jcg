#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "BuildData.h"
#include "BuildData.r.h"

static void cstr(void *obj, va_list *arg)
{
    BuildData_t bd = obj;
    mut(bd->count, int, va_arg(*arg, int));
    mut(bd->list, void **, va_arg(*arg, void **));
}
static void dstr(void *obj)
{
    BuildData_t bd = obj;
    free(bd->list);
    mut(bd->list, int, 0);
    mut(bd->count, void *, 0);
}

static BuildDataClass_st Class;
const void *BuildData = &Class;

// assigning inheritance and overrides
static void __attribute__((constructor)) builddataClassf()
{
    memcpy((void *)BuildData, Obj, sizeof(ObjClass_st));
    (*(ObjClass_t)&Class).size = sizeof(BuildData_st);
    (*(ObjClass_t)&Class).super = Obj;
    static const char name[] = "BuildData";
    (*(ObjClass_t)&Class).name = name;
    (*(ObjClass_t)&Class).cstr = cstr;
    (*(ObjClass_t)&Class).dstr = dstr;
}

static int isBuildData(const void *bd)
{
    return (*(ObjClass_t *)bd) == BuildData;
}
static int buildList(const void *bd, const void ***liat)
{
    *liat = ((BuildData_t)bd)->list;
    return ((BuildData_t)bd)->count;
}

BuildDataFn_t BuildDataFn = {isBuildData, buildList};
