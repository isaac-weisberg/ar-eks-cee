#ifndef CENERIC_CLOSURE_H
#define CENERIC_CLOSURE_H

#define CENERIC_CLOSURE(RETURN_TYPE_NAME, NAME, CONTEXT_TYPE_NAME, PARAMS_TYPE_NAME) \
\
typedef struct { \
    CONTEXT_TYPE_NAME ctx; \
    RETURN_TYPE_NAME (*lambda)(CONTEXT_TYPE*, PARAMS_TYPE_NAME); \
} NAME; \
\
NAME NAME##_init(CONTEXT_TYPE_NAME ctx, RETURN_TYPE_NAME (*lambda)(CONTEXT_TYPE_NAME*, PARAMS_TYPE_NAME)) { \
    NAME closure; \
    closure.ctx = ctx; \
    closure.lambda = lambda; \
    return closure; \
} \

#endif