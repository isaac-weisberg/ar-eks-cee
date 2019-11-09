#include "just_observable_t.h"

void handleThemInts(just_handler_closure_ctx_int_t* ctx, int event) {

}

void usage() {
    just_observable_int_t observable = just_observable_int_init(4);

    just_handler_closure_int_t handler;
    handler.lambda = handleThemInts;

    observable.subscribe.lambda(&observable.subscribe.ctx, handler);
}