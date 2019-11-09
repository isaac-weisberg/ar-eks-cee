#ifndef CENERIC_CLOSURE_H
#define CENERIC_CLOSURE_H

#define CENERIC_CLOSURE(RETURN_TYPE, NAME, CONTEXT_TYPE, PARAMS_TYPE) \
\
typedef struct { \
    CONTEXT_TYPE ctx; \
    RETURN_TYPE (*lambda)(CONTEXT_TYPE*, PARAMS_TYPE); \
} NAME; \
\
NAME NAME##_init(CONTEXT_TYPE ctx, RETURN_TYPE (*lambda)(CONTEXT_TYPE*, PARAMS_TYPE)) { \
    NAME closure; \
    closure.ctx = ctx; \
    closure.lambda = lambda; \
    return closure; \
} \

#endif