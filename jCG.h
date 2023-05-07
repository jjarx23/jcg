#ifndef JCG_H
#define JCG_H

#define JCG_V_MAJ 0
#define JCG_V_MIN 2

#ifdef __cplusplus
extern 'C'
{
#endif

    typedef struct
    {
        void (*print)(void *x);
        void (*build)(void *x);
        void (*setVarData)(void *var, void *data);
        void (*eval)(void *x);
        void (*diff)(void *x);
        void *(*varData)(void *var);
        void *(*grad)(void *);
        void *(*var)(void *);
        void *(*add)(void *x, void *y);
        void *(*subtract)(void *x, void *y);
        void *(*multiply)(void *x, void *y);
        void *(*divide)(void *x, void *y);
        void *(*Xcorrelation)(void *x, void *y);
        void *(*dot)(void *x, void *y);
    } CG_op_t;
    extern const CG_op_t jCG;

#ifdef __cplusplus
}
#endif
#endif