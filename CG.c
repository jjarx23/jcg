#include <stdlib.h>
#include <stdio.h>

#include "CG.h"
#include "CG.r.h"
#include "Op/Flow/edms/Divide.h"
#include "Op/Flow/edms/Multiply.h"
#include "Op/Flow/Subtract.h"
#include "Op/Flow/XCorrelation.h"

static void print(void *o_)
{
    char buf[1024];
    stringOf(o_, buf, 1024);
    printf((const char *)buf);
}
static void listDeps(const void *head, Op_t o, struct mlList **list, int *count)
{
    if (buildData(o) == head)
        return;
    if (classOf(o) != Var)
    {
        for (int i = 0; i < nDeps(o); i++)
        {
            listDeps(head, depsI(o, i), list, count);
        }
    }
    if (o != head)
    {
        setBuildData(o, head);
    }
    mlList_t *node = malloc(sizeof(mlList_t));
    node->data = o;
    node->next = list[0];
    list[0] = node;
    count[0]++;
}
static void build(void *o_)
{
    Op_t o = o_;
    struct mlList *list = 0, *__;
    int count = 0;
    if (classOf(o_) != Var)
        listDeps(o_, o_, &list, &count);
    printf("%p has %i dependencies\n", o, count);
    void **List = malloc(sizeof(void *) * count);
    int i = count;
    while (list)
    {
        __ = list;
        i--;
        List[i] = list->data;
        printf("%p %s\n", List[i], className(List[i]));
        list = list->next;
        free(__);
    }
    setBuildData(o, neu(BuildData, count, List));
    /*
    list->next=list->data=0;
    if(istypeof(o, Op)){
        insertdep(o, list);
    }
    */
}

static void setNodeData(Var_t node, void *data)
{
    setRes(node, data);
}
static void nodeData(Var_t node, void *data)
{
    return res(node);
}

static void eval(void *v)
{
    if (!(buildData(v) ? BuildDataFn.isBuildData(buildData(v)) : 0))
    {
        jCG.build(v);
    }
    // array of Var_t(struct Var *)
    const void **list;
    int count = BuildDataFn.buildList(buildData(v), &list);
    for (int i = 0; i < count; i++)
    {
        (*(VarClass_t *)list[i])->eval((void *)list[i]);
    }
}

static void calcGrad(void *x, void *grad_)
{
    void *_0 = grad_;
    void *oldxgrad = grad(x);
    void *xgrad = Flow.math.add(oldxgrad ? oldxgrad : Flow.constants.zero,
                                grad_ = (grad_ ? grad_ : Flow.constants.one));
    if (oldxgrad != xgrad)
    {
        setGrad(x, xgrad);
        if (oldxgrad && oldxgrad != grad_)
            del(oldxgrad);
    }
    printf("%s\n", className(x));
    if (classOf(x) != Var)
        for (int i = 0; i < nDeps(x); i++)
        {
            xgrad = Flow.math.multiply(grad_, oldxgrad = coeftI(x, i));
            calcGrad(depsI(x, i), xgrad);
            if (xgrad != oldxgrad && xgrad != grad_)
                del(xgrad);
        }
}

static void diff(void *x)
{
    const void **list;
    int count = BuildDataFn.buildList(buildData(x), &list);
    for (int i = 0; i < count; i++)
    {
        if (classOf(list[i]) != Var)
        {
            coeftMk(list[i]);
            (*(VarClass_t *)list[i])->diff((void *)list[i]);
        }
    }
    calcGrad(x, NULL);
    for (int i = 0; i < count; i++)
    {
        if (classOf(list[i]) != Var)
        {
            printf("%s\n", className(list[i]));
            coeftRm(list[i]);
        }
    }
}
static void *gradx(void *x)
{
    return ((Var_t)x)->grads;
}
static void *var(void *x)
{
    return neu(Var, x);
}
static void *add(void *x, void *y)
{
    return neu(Add, x, y);
}
static void *subtract(void *x, void *y)
{
    return neu(Subtract, x, y);
}
static void *multiply(void *x, void *y)
{
    return neu(Multiply, x, y);
}
static void *divide(void *x, void *y)
{
    return neu(Divide, x, y);
}
static void *xcorrel(void *x, void *y)
{
    return neu(XCorrelation, x, y);
}
const CG_op_t jCG = {print, build, setNodeData, eval, diff, nodeData, gradx, var, add, subtract, multiply, divide, xcorrel};
