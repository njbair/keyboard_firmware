#include "action_layer.h"
#include "layer.h"
#include "print.h"

void hook_init_late(void)
{
    layer_on(L_FN_SPACEFN);
    layer_on(L_OVERLAY_CTRL_REMAP);
    layer_on(L_FN_PRIMARY);
}
