#include "just_observable_t.h"
#include "ceneric_closure.h"

CENERIC_JUST_OBSERVABLE(int)

void handleThemInts(just_handler_closure_ctx_int_t* ctx, int event) {

}

void usage() {
    just_observable_int_t observable = just_observable_int_init(4);

    just_handler_closure_int_t handler = just_handler_closure_int_t_init(
        (just_handler_closure_ctx_int_t){}, 
        handleThemInts
    );

    call_just_subscribe_closure_int_t(observable.subscribe, handler);
}

// closure usage
typedef struct {
    float captured;
} add_some_context;

CENERIC_CLOSURE(float, add_some, add_some_context, float)

static float add_some_impl(add_some_context* ctx, float param) {
    return ctx->captured + param;
}

void closureUsage() {
    add_some_context add_35_ctx = { .captured = 35 };
    add_some add_35_closure = add_some_init(add_35_ctx, add_some_impl);

    float value1 = call_add_some(add_35_closure, 3); // 38
    float value2 = call_add_some(add_35_closure, -30); // 5
}