#ifndef JUST_OBSERVABLE_T_H
#define JUST_OBSERVABLE_T_H

#include "ceneric_closure.h"

typedef void (*just_disposable_t)(void);

void just_disposable() {
    
}

typedef struct {

} just_handler_closure_ctx_int_t;

CENERIC_CLOSURE(void, just_handler_closure_int_t, just_handler_closure_ctx_int_t, int)

typedef struct {
    int captured;
} just_subscribe_closure_ctx_int_t;

CENERIC_CLOSURE(just_disposable_t, just_subscribe_closure_int_t, just_subscribe_closure_ctx_int_t, just_handler_closure_int_t)

just_disposable_t just_subscribe_closure_lambda_int(just_subscribe_closure_ctx_int_t* ctx, just_handler_closure_int_t handler) {
    handler.lambda(&handler.ctx, ctx->captured);
    return just_disposable;
}

typedef struct {
    just_subscribe_closure_int_t subscribe;
} just_observable_int_t;

just_observable_int_t just_observable_int_init(int value) {
    just_observable_int_t observable;

    observable.subscribe.ctx.captured = value;
    observable.subscribe.lambda = just_subscribe_closure_lambda_int;

    return observable;
}

#endif