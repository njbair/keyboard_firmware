/*
    ChibiOS/RT - Copyright (C) 2006-2014 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/
#include "hal.h"

static bool spiOk = false;

static THD_WORKING_AREA(waThread1, 64);
static THD_FUNCTION(Thread1, arg) {

  (void)arg;
  chRegSetThreadName("Blinker");
  while (TRUE) {
    if (spiOk) {
      palTogglePad(TEENSY_PIN13_IOPORT, TEENSY_PIN13);
      spiOk=0;
    }
    chThdSleepMilliseconds(500);
  }
}

static void spicb(SPIDriver *spip) {

  (void)spip;
  //~ palSetPad(TEENSY_PIN13_IOPORT, TEENSY_PIN13);
  palTogglePad(TEENSY_PIN14_IOPORT, TEENSY_PIN14);
}

static SPIConfig spicfg = {
  spicb,
  TEENSY_PIN10_IOPORT,
  TEENSY_PIN10,
  KINETIS_SPI_TAR_8BIT_SLOW
};

/*
 * Application entry point.
 */
int main(void) {

  uint8_t tx[8], rx[8];

  /*
   * System initializations.
   * - HAL initialization, this also initializes the configured device drivers
   *   and performs the board-specific initializations.
   * - Kernel initialization, the main() function becomes a thread and the
   *   RTOS is active.
   */
  halInit();
  chSysInit();

  //~ palSetPadMode(IOPORT3, 0, PAL_MODE_OUTPUT_PUSHPULL);  /* CS */
  palSetPadMode(IOPORT4, 1, PAL_MODE_ALTERNATIVE_2);  /* SCLK */
  palSetPadMode(IOPORT3, 4, PAL_MODE_OUTPUT_PUSHPULL);  /* CS */
    palSetPad(IOPORT3, 4);
    //~ palSetPad(IOPORT3, 0);
  palSetPadMode(IOPORT3, 6, PAL_MODE_ALTERNATIVE_2);  /* MOSI */
  palSetPadMode(IOPORT3, 7, PAL_MODE_ALTERNATIVE_2);  /* MISO */

  chThdCreateStatic(waThread1, sizeof(waThread1), NORMALPRIO, Thread1, NULL);

  while (1) {
    tx[0] = 0x1;
    tx[1] = 0x79;
    spiAcquireBus(&SPID1);                /* Acquire ownership of the bus.    */
    spiStart(&SPID1, &spicfg);            /* Setup transfer parameters.       */
    spiSelect(&SPID1);                    /* Slave Select assertion.          */
    spiExchange(&SPID1, 2,tx, rx);        /* Atomic transfer operations.      */
    spiUnselect(&SPID1);                  /* Slave Select de-assertion.       */
    spiReleaseBus(&SPID1);                /* Ownership release.               */
    chThdSleepMilliseconds(2000);
    palTogglePad(TEENSY_PIN13_IOPORT, TEENSY_PIN13);
  }
}
