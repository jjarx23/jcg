#ifndef VAR_R_H
#define VAR_R_H

#include <Obj.r.h>

#ifdef __cplusplus
extern 'C'{
#endif

typedef struct mlList {
    void *data;
    struct mlList *next;
} mlList_t;
typedef struct {
    mlList_t *list;
    int count;
} BuildData_t;

typedef struct VarClass* VarClass_t;
typedef struct VarClass VarClass_st;
typedef struct Var Var_st;
struct VarClass{
    ObjClass_st _;
    //other members go here
    void (*listdep)(void * head,void * v, struct mlList **list, int *count);
};
struct Var{
    const Obj_st _;
    //other members go here
    const void *builddata;
    const void **res;
    const int nres;
};

#define resI(x,i)(((Var_t)x)->nres>1?((Var_t)x)->res[i]:(void *)((Var_t)x)->res)
#define nRes(x)(((Var_t)x)->nres)
#define buildData(x)(((Var_t)x)->builddata)

#define setBuildData(o, y)mut(((Var_t)o)->builddata,void *,y)
#define setResI(x,i, y_)mut((i>=1?((Var_t)x)->res:&((Var_t)x)->res)[i], void *, (y_))
    //resI(x, i)=(y_))
#define setNRes(x,n)mut(((Var_t)x)->nres, int, n)

#define initRes(x, n)(((Var_t)x)->res=n>1?0:malloc((n)*sizeof(void *)))

#define listDeps(head, v, list, c)((*(VarClass_t *)v)->listdep(head, v, list, c))
#define mlAppend(l, v, c)mlList_t *_=malloc(sizeof(mlList_t));\
_->data=v;\
_->next=l[0];l[0]=_;c[0]++;
#define superListDep(class, head, v, list, c)(((VarClass_t)super(class))->listdep(head, v, list, c))

#ifdef __cplusplus
}
#endif
#endif