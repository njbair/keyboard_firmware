#include "action_layer.h"
#include "init.h"
#include "layer.h"
#include "debug.h"

/**
 * Init actions
 *
 * This function is run at the end of matrix_init(), as defined in matrix.c. So
 * whatever you put here will be triggered on keyboard boot.
 */
void user_init_actions(void)
{
    debug_enable = true;
    debug("debug test");
    xprintf("Running user init...\n");

    xprintf("Enable layer %d\n", L_FN_SPACEFN);
    layer_on(L_FN_SPACEFN);
    xprintf("Enable layer %d\n", L_OVERLAY_CTRL_REMAP);
    layer_on(L_OVERLAY_CTRL_REMAP);
    xprintf("Enable layer %d\n", L_FN_PRIMARY);
    layer_on(L_FN_PRIMARY);

    xprintf("User init finished.");
}
