#include "action_layer.h"
#include "action_util.h"
#include "action.h"
#include "layer.h"
#include "print.h"
#include "debug.h"

void hook_early_init(void) {
    dprint("Testing early init hook\n");
}

void hook_late_init(void) {
    dprint("Late Init hook is running...\n");
#ifdef CONFIG_H_DEFAULT_LAYER
    /**
     * Set a default layer. Useful for when Boot Magic is not available.
     */
    uint8_t default_layer = 0;
    int config_h_default_layer[1] = { CONFIG_H_DEFAULT_LAYER };
    default_layer |= (1<<config_h_default_layer[0]);
    default_layer_set((uint32_t)default_layer);
#endif

#ifdef CONFIG_H_ENABLE_LAYERS
    /**
     * Enable layers by default
     *
     * The default layer is defined in EEPROM and configurable via boot magic
     * commands. But sometimes you want to enable other layers by default as
     * well. You can do that by defining the CONFIG_H_ENABLE_LAYERS macro in your
     * config.h file.
     */
    int enable_layers[32] = { CONFIG_H_ENABLE_LAYERS };
    int i;

    for (i=0; i<32; i++) {
        if (enable_layers[i] == 1) {
            layer_on(i);
        }
    }
#endif
    dprint("Late Init hook finished.\n");
}