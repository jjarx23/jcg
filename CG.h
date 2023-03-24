#ifndef CG_H
#define CG_H

#include "Var.h"
#include "Op.h"
#include "Op/Op/Add.h"

#ifdef __cplusplus
extern 'C'{
#endif

typedef struct {
    Var_t (*add)(Var_t x, Var_t y);
    void (*build)(Var_t x);
} CG_op_t;
extern const CG_op_t CG;
//other declarations go here
#ifdef __cplusplus
}
#endif
#endif