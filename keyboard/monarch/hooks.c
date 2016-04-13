#include "action_layer.h"
#include "layer.h"
#include "print.h"

void hook_keyboard_init(void)
{
    layer_on(L_FN_SPACEFN);
    layer_on(L_OVERLAY_CTRL_REMAP);
    layer_on(L_FN_PRIMARY);
}
