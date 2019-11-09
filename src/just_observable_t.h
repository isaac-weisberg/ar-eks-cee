#ifndef JUST_OBSERVABLE_T_H
#define JUST_OBSERVABLE_T_H

typedef void (*handler_int_t)(int);

typedef void (*just_disposable_int_t)(void);

void just_disposable_int() {
    
}

typedef struct {
    int captured;
} just_subscribe_closure_ctx_t;

typedef just_disposable_int_t (*just_subscribe_closure_lambda_t)(just_subscribe_closure_ctx_t*, handler_int_t);

just_disposable_int_t just_subscribe_closure_lambda(just_subscribe_closure_ctx_t* ctx, handler_int_t handler) {
    handler(ctx->captured);
    return just_disposable_int;
}

typedef struct {
    just_subscribe_closure_ctx_t ctx;
    just_subscribe_closure_lambda_t lambda;
} just_subscribe_closure_t;

typedef struct {
    just_subscribe_closure_t subscribe;
} just_observable_int_t;

just_observable_int_t just_observable_int_init(int value) {
    just_observable_int_t observable;

    observable.subscribe.ctx.captured = value;
    observable.subscribe.lambda = just_subscribe_closure_lambda;

    return observable;
}

#endif