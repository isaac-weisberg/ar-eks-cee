#include "just_observable_t.h"

void handleThemInts(int event) {

}

void usage() {
    just_observable_int_t observable = just_observable_int_init(4);

    observable.subscribe.lambda(&observable.subscribe.ctx, handleThemInts);
}