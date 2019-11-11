#ifndef JUST_OBSERVABLE_T_H
#define JUST_OBSERVABLE_T_H

#include "ceneric_closure.h"

typedef void (*just_disposable_t)(void);

void just_disposable() {
    
}

#define CENERIC_JUST_OBSERVABLE(EVENT_TYPE_NAME) \
\
\
typedef struct { } just_handler_closure_ctx_##EVENT_TYPE_NAME##_t; \
\
\
CENERIC_CLOSURE( \
    void, \
    just_handler_closure_##EVENT_TYPE_NAME##_t, \
    just_handler_closure_ctx_##EVENT_TYPE_NAME##_t, \
    EVENT_TYPE_NAME \
) \
\
\
typedef struct { \
    EVENT_TYPE_NAME captured; \
} just_subscribe_closure_ctx_##EVENT_TYPE_NAME##_t; \
\
\
CENERIC_CLOSURE( \
    just_disposable_t, \
    just_subscribe_closure_##EVENT_TYPE_NAME##_t, \
    just_subscribe_closure_ctx_##EVENT_TYPE_NAME##_t, \
    just_handler_closure_##EVENT_TYPE_NAME##_t \
) \
\
\
just_disposable_t \
just_subscribe_closure_lambda_##EVENT_TYPE_NAME( \
    just_subscribe_closure_ctx_##EVENT_TYPE_NAME##_t* ctx, \
    just_handler_closure_##EVENT_TYPE_NAME##_t handler \
) { \
    call_just_handler_closure_##EVENT_TYPE_NAME##_t(handler, ctx->captured); \
    return just_disposable; \
} \
\
\
typedef struct { \
    just_subscribe_closure_##EVENT_TYPE_NAME##_t subscribe; \
} just_observable_##EVENT_TYPE_NAME##_t; \
\
\
just_observable_##EVENT_TYPE_NAME##_t \
just_observable_##EVENT_TYPE_NAME##_init( \
    EVENT_TYPE_NAME value \
) { \
    just_observable_##EVENT_TYPE_NAME##_t observable; \
\
    observable.subscribe = just_subscribe_closure_##EVENT_TYPE_NAME##_t_init( \
        (just_subscribe_closure_ctx_##EVENT_TYPE_NAME##_t){ value }, \
        just_subscribe_closure_lambda_##EVENT_TYPE_NAME); \
\
    return observable; \
} \

#endif