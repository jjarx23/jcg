#include <stdlib.h>
#include <stdarg.h>
#include "Op.h"
#include "Op.r.h"

/*
//implement if necessary
static void cstr(void *obj, va_list *arg){
    printf("Op constructor \n");
}
*/
static void dstr(void *obj){
    Op_t o=obj;
    if(nDeps(o)>1 && depList(o))free(o->deps);
    superdstr(Op, obj);
    //printf("Op destructor \n");
}
/*
//other implentation go here
static int rpr(const void *b, char *str, int length){
    return printf("Op %p \n", b);
}
*/
static void listdep(Op_t head, Op_t v, struct mlList ** l, int *c){
    for(int i =0; i<nDeps(v);i++)
    {
        listDeps(head, depList(v)[i], l, c);
        //l->next=malloc(sizeof(struct mlList));
    }
    superListDep(Op, head, v, l, c);
}

static OpClass_st Class;
const void *Op=&Class;

//assigning inheritance and overrides
void// __attribute__((constructor)) 
opClassf(){
    memcpy(Op, Var, sizeof(OpClass_st));
    (*(ObjClass_t)&Class).size=sizeof(Op_st);
    (*(ObjClass_t)&Class).super=Var;
    (*(VarClass_t)&Class).listdep=listdep;
}
//other implentation go here
