#include <stdlib.h>
#include <stdarg.h>
#include "TwoToOne.h"
#include "TwoToOne.r.h"


//implement if necessary
static void cstr(void *obj, va_list *arg){
    TwoToOne_t o=obj;
    setNRes(o, 1);
    setNDeps(o, 2);
    setA(o, va_arg(*arg, Op_t));
    setB(o, va_arg(*arg, Op_t));
    //printf("TwoToOne constructor \n");
    setDeps(o, &o->a);
    return;
}

static void dstr(void *obj){
    TwoToOne_t o=obj;
    setNDeps(o, 0);
    superdstr(TwoToOne, o);
    //printf("TwoToOne destructor \n");
}/*
//other implentation go here
static int rpr(const void *b, char *str, int length){
    return printf("TwoToOne %p \n", b);
}
*/
static TwoToOneClass_st Class;
const void *TwoToOne=&Class;

//assigning inheritance and overrides
/*static*/ void /*__attribute__((constructor))*/ twotooneClassf(){
    memcpy(TwoToOne, Op, sizeof(TwoToOneClass_st));
    (*(ObjClass_t)&Class).size=sizeof(TwoToOne_st);
    (*(ObjClass_t)&Class).super=Op;
    (*(ObjClass_t)&Class).cstr=cstr;
}
//other implentation go here
