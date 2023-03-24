#include <stdlib.h>
#include <stdarg.h>
#include "Add.h"
#include "Add.r.h"

/*
//implement if necessary
static void cstr(void *obj, va_list *arg){
    printf("Add constructor \n");
}
static void dstr(void *obj){
    printf("Add destructor \n");
}
//other implentation go here
static int rpr(const void *b, char *str, int length){
    return printf("Add %p \n", b);
}
*/
static AddClass_st Class;
const void *Add=&Class;

//assigning inheritance and overrides
/*static*/ void /*__attribute__((constructor))*/ addClassf(){
    memcpy(Add, TwoToOne, sizeof(AddClass_st));
    (*(ObjClass_t)&Class).size=sizeof(Add_st);
    (*(ObjClass_t)&Class).super=TwoToOne;
}
//other implentation go here
