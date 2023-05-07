#ifndef OP_R_H
#define OP_R_H

#include "Var.r.h"
#include <Flow.h>

#ifdef __cplusplus
extern 'C'
{
#endif

    extern const fn_t opLC;

    typedef struct OpClass *OpClass_t;
    typedef struct OpClass OpClass_st;
    typedef struct Op Op_st;
    struct OpClass
    {
        VarClass_st _;
        // other members go here
    };
    struct Op
    {
        const Var_st _;
        // other members go here
        const int ndeps;
        const Var_t *deps;
    };
    /*--------------------------------*/
    static inline void setDeps(Op_t v, Var_t * list, int n)
    {
        v->deps = list;
        *(int *)&v->ndeps = n;
    }
    static inline void initDeps(Op_t v, int n)
    {
        if (n > 1)
            return setDeps(v, malloc(n * sizeof(Var_t)), n);
        return setDeps(v, 0, n);
    }
    static inline void brkDeps(Op_t v)
    {
        if (v->ndeps == 1)
        {
            detach(v->deps);
            v->deps = 0;
        }
        else if (v->deps)
            free(v->deps);
        *(int *)&v->ndeps = 0;
        *(void **)&v->deps = NULL;
    }
    static inline void setDepsI(Op_t vv, int i, Var_t v)
    {
        if (vv->ndeps == 1)
        {
            detach(vv->deps);
            vv->deps = v;
        }
        else
        {
            detach(vv->deps[i]);
            *(Var_t *)&vv->deps[i] = v;
        }
        attach(v);
    }
    static inline Var_t depsI(Op_t vv, int i)
    {
        if (vv->ndeps == 1)
            return vv->deps;
        else
            return *(Var_t *)&vv->deps[i];
    }
    static inline int nDeps(Op_t o)
    {
        return o->ndeps;
    }

    static inline void coeftMk(Op_t v)
    {
        void **_ = malloc((nDeps(v) + 1) * sizeof(void *));
        _[0] = buildData(v);
        ((Var_t)v)->builddata = _;
    }
    static inline void coeftRm(Op_t v)
    {
        void **_ = buildData(v);
        ((Var_t)v)->builddata = _[0];
        for (int i = 0; i < nDeps(v);)
        {
            i++;
            detach(_[i]);
            del(_[i]);
        }
        free(_);
    }
    static inline void *coeftI(Op_t v, int i)
    {
        return ((void **)buildData(v))[i + 1];
    }
    static inline void setCoeftI(Op_t v, int i, void *y)
    {
        // we are not calling detach since we  do not expect
        // Op_t.diff to be called more than once
        attach(y);
        ((void **)buildData(v))[i + 1] = y;
    }
    /*static inline void unsetCoeftI(Op_t v, int i)
    {
        // we are not calling detach since we  do not expect
        // Op_t.diff to be called more than once
        detach(((void **)buildData(v))[i + 1]);
        ((void **)buildData(v))[i + 1] = 0;
    }
*/
#ifdef __cplusplus
}
#endif
#endif
