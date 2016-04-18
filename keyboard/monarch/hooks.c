#include "action_layer.h"
#include "layer.h"
#include "print.h"

#ifdef BACKLIGHT_ENABLE
#include "backlight.h"
#endif

void hook_keyboard_init(void)
{
    #ifdef BACKLIGHT_ENABLE
    init_backlight_pin();
    #endif

    layer_on(L_FN_SPACEFN);
    layer_on(L_OVERLAY_CTRL_REMAP);
    layer_on(L_FN_PRIMARY);
}
