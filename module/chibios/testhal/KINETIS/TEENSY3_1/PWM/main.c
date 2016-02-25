/*
    ChibiOS/RT - Copyright (C) 2006-2013 Giovanni Di Sirio

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

static void pwmpcb(PWMDriver *pwmp) {

  (void)pwmp;
  palSetPad(TEENSY_PIN14_IOPORT, TEENSY_PIN14);
  palTogglePad(TEENSY_PIN15_IOPORT, TEENSY_PIN15);
}

static void pwmc1cb(PWMDriver *pwmp) {

  (void)pwmp;
  //~ palSetPad(TEENSY_PIN13_IOPORT, TEENSY_PIN13);
  palClearPad(TEENSY_PIN14_IOPORT, TEENSY_PIN14);
}

static PWMConfig pwmcfg = {
  36000000,                                   /* 36MHz PWM clock frequency.   */
  36000,                                        /* Initial PWM period 1ms     */
  pwmpcb,
  {
    {PWM_OUTPUT_ACTIVE_HIGH, NULL},
    {PWM_OUTPUT_DISABLED, pwmc1cb},
  },
};

/*
 * Application entry point.
 */
int main(void) {

  /*
   * System initializations.
   * - HAL initialization, this also initializes the configured device drivers
   *   and performs the board-specific initializations.
   * - Kernel initialization, the main() function becomes a thread and the
   *   RTOS is active.
   */
  halInit();
  chSysInit();
  /*
   * Initializes the PWM driver 1.
   * GPIOC1 is the PWM output.
   */

  palSetPadMode(IOPORT3, 1, PAL_MODE_ALTERNATIVE_4);
  pwmStart(&PWMD1, &pwmcfg);
  pwmEnablePeriodicNotification(&PWMD1);

  /*
   * Starts the PWM channel 0 using 25% duty cycle.
   */
  pwmEnableChannel(&PWMD1, 0, PWM_PERCENTAGE_TO_WIDTH(&PWMD1, 2500));
  pwmEnableChannel(&PWMD1, 1, PWM_PERCENTAGE_TO_WIDTH(&PWMD1, 2500));
  pwmEnableChannelNotification(&PWMD1, 1); // MUST be before EnableChannel...
  chThdSleepMilliseconds(2500);

  /*
   * Changes PWM period to 500µs the duty cycle becomes 50%
   * implicitly.
   */
  pwmChangePeriod(&PWMD1, 18000);
  chThdSleepMilliseconds(2500);
  //~ pwmEnablePeriodicNotification(&PWMD1);
  /*
   * Disables channel 0 and stops the drivers.
   */
  //~ pwmDisableChannel(&PWMD1, 0);
  //~ pwmStop(&PWMD1);

  /*
   * Normal main() thread activity, in this demo it does nothing.
   */
  while (TRUE) {
    palTogglePad(TEENSY_PIN13_IOPORT, TEENSY_PIN13);
    chThdSleepMilliseconds(5);
  }
  return 0;
}
