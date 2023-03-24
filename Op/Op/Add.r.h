#ifndef ADD_R_H
#define ADD_R_H

#include "../TwoToOne.r.h"

#ifdef __cplusplus
extern 'C'{
#endif

typedef struct AddClass* AddClass_t;
typedef struct AddClass AddClass_st;
typedef struct Add Add_st;
struct AddClass{
    TwoToOneClass_st _;
    //other members go here
};
struct Add{
    const TwoToOne_st _;
    //other members go here
};

#ifdef __cplusplus
}
#endif
#endif