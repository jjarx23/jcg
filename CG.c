#include <stdlib.h>
#include "CG.h"
#include "CG.r.h"

//const void *Add;

static Var_t add(Var_t x, Var_t y){
    return neu(Add, x,y);
}

static void build(Op_t o){
    BuildData_t * _ = setBuildData(o, malloc(sizeof(BuildData_t)));
    //memset(_, 0, sizeof(buildData_t));
    struct mlList *list=malloc(sizeof(struct mlList));
    listDeps(o, o, &_->list, &_->count);
    /*
    list->next=list->data=0;
    if(istypeof(o, Op)){
        insertdep(o, list);
    }
    */
}

const CG_op_t CG={add, build};

static void __attribute__((constructor)) cg(){
    varClassf();
    opClassf();
    twotooneClassf();
    addClassf();
    printf("Loaded CG\n");
}