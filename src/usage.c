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