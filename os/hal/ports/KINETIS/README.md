# Kinetis port unfinished business

The aim is to have a decent support for Teensy 3.* and LC, Freedom KL2{5,6,7}Z and K20D50M boards, and MCHCK. This means Freescale Kinetis MK20DX* and MKL2{5,6,7}Z* chips.

## Functional issues

 - port _SPI_ driver from `K20x` to `KL2x` or `LLD` (note that there are differences even between KL25Z and KL26Z).
 - add more drivers to `os/hal/ports/KINETIS/`. The immediate candidates: DMA.

 - figure out USB0->USBTRC0 USBRESMEN and USB_RESUME_INT; also USB0->CTL RESUME bit (sending wakeup packet)
 - only enable SOF if callback defined

## For code clarity

## For completeness

 - CMSIS / register definitions and structures in `os/ext/CMSIS/KINETIS/*` (google MKL25Z4.h for official KL25 Freescale headers)
