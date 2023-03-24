#include <stdlib.h>
#include <stdarg.h>
#include "Var.h"
#include "Var.r.h"

/*
//implement if necessary
static void cstr(void *obj, va_list *arg){
    printf("Var constructor \n");
}
static void dstr(void *obj){
    printf("Var destructor \n");
}
//other implentation go here
static int rpr(const void *b, char *str, int length){
    return printf("Var %p \n", b);
}
*/

static void listdep(Var_t head, Var_t v, struct mlList ** l, int *c){
    if(v==head)return;
    if(v->builddata==head)return;
    setBuildData(v, head);
    mlAppend(l, v, c);
}

static VarClass_st Class;
const void *Var=&Class;

//assigning inheritance and overrides
void //__attribute__((constructor)) 
varClassf(){
    memcpy(Var, Obj, sizeof(VarClass_st));
    (*(ObjClass_t)&Class).size=sizeof(Var_st);
    (*(ObjClass_t)&Class).super=Obj;
    Class.listdep=listdep;
}

//other implentation go here
