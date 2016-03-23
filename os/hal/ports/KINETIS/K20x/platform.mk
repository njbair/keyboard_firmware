# List of all platform files.
PLATFORMSRC = ${CHIBIOS}/os/hal/ports/common/ARMCMx/nvic.c \
              ${CHIBIOS}/os/hal/ports/KINETIS/K20x/hal_lld.c \
              ${CHIBIOS}/os/hal/ports/KINETIS/LLD/pal_lld.c \
              ${CHIBIOS}/os/hal/ports/KINETIS/LLD/serial_lld.c \
              ${CHIBIOS}/os/hal/ports/KINETIS/K20x/spi_lld.c \
              ${CHIBIOS}/os/hal/ports/KINETIS/LLD/i2c_lld.c \
              ${CHIBIOS}/os/hal/ports/KINETIS/LLD/ext_lld.c \
              ${CHIBIOS}/os/hal/ports/KINETIS/LLD/adc_lld.c \
              ${CHIBIOS}/os/hal/ports/KINETIS/LLD/gpt_lld.c \
              ${CHIBIOS}/os/hal/ports/KINETIS/K20x/pwm_lld.c \
              ${CHIBIOS}/os/hal/ports/KINETIS/LLD/st_lld.c \
              ${CHIBIOS}/os/hal/ports/KINETIS/LLD/usb_lld.c

# Required include directories
PLATFORMINC = ${CHIBIOS}/os/hal/ports/common/ARMCMx \
              ${CHIBIOS}/os/hal/ports/KINETIS/K20x \
              ${CHIBIOS}/os/hal/ports/KINETIS/LLD
