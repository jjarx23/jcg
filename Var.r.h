#ifndef VAR_R_H
#define VAR_R_H

#include <Obj.r.h>
#include "BuildData.h"
#ifdef __cplusplus
extern 'C'
{
#endif

    extern const fn_t varLC;

    typedef struct mlList
    {
        void *data;
        struct mlList *next;
    } mlList_t;

    typedef struct VarClass *VarClass_t;
    typedef struct VarClass VarClass_st;
    typedef struct Var Var_st;
    struct VarClass
    {
        ObjClass_st _;
        // other members go here
        void (*eval)(void *v);
        void (*diff)(void *v);
    };
    struct Var
    {
        const Obj_st _;
        // other members go here
        const void *builddata;
        const void *res;
        const void *grads;
    };
    /*_____________________________________________*/
    static inline BuildData_t buildData(Var_t v)
    {
        return v->builddata;
    }
    static inline void setBuildData(Var_t v, BuildData_t bd)
    {
        if (v->builddata)
            detach(v->builddata);
        v->builddata = bd;
        attach(bd);
    }
    static inline void *res(Var_t v)
    {
        return v->res;
    }
    static inline void *grad(Var_t v)
    {
        return v->grads;
    }
    static inline void *setGrad(Var_t v, void *y)
    {
        return *(void **)&v->grads = y;
    }
    static inline void setRes(Var_t v, void *y)
    {
        detach(v->res);
        v->res = y;
        attach(y);
    }
    static inline void supereval(ObjClass_t cls, Var_t o)
    {
        return ((VarClass_t)cls->super)->eval(o);
    }
#ifdef __cplusplus
}
#endif
#endif
