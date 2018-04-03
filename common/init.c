#include "action_layer.h"
#include "action_util.h"
#include "action.h"
#include "layer.h"

void hook_late_init(void)
{
    layer_on(L_OVERLAY_CTRL_REMAP);
    layer_on(L_FN_SPACEFN);
    layer_on(L_FN_PRIMARY);
}