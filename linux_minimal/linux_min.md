# Resources and information about running Linux (or something similar) with the lowest system requirements or cheapest/simplest systems

Hardware:

https://jaycarlson.net/microcontrollers/
https://hackaday.com/2018/09/17/a-1-linux-capable-hand-solderable-processor/
https://sunxi.org/Main_Page - Wiki for Allwinner parts

Software:

- http://uzix.sourceforge.net/index.php?lang=us - UNIX for the z80
- https://en.wikipedia.org/wiki/Microkernel
- http://netbsd.org/ - Runs on many platforms, could be ported possibly
- http://retrobsd.org/ - Runs on STM32 with only 128k ram, could possibly be ported to other architectures
- https://github.com/vsolina/mipyshell - A Unix like shell for ESP32
- https://www.reddit.com/r/esp32/comments/dtlj7n/booting_linux_on_esp32_realtime_video/ - A video of Linux booting on an ESP32 using a port of uARM (the next link)
- https://dmitry.gr/?r=05.Projects&proj=07.%20Linux%20on%208bit - An ArmV5 emulator for 8 bit AVR with no MMU, includes porting instrutions 
- https://nuttx.apache.org/ - A Posix compliant RTOS that runs on many platforms, claims to runs on ATmega boards or even z80
  - https://cwiki.apache.org/confluence/display/NUTTX/Porting+Guide - Comes with porting guide
  - https://github.com/rohiniku/NuttX-nuttx-boards/tree/master/micropendous3 - Runs on Atmel AT90USB646, 647, 1286 or 1287 MCU
  - https://github.com/rohiniku/NuttX-nuttx-boards/tree/master/amber - Also runs on Atmel ATmega128
- https://freertos.org/RTOS.html - Will run on even Arduino, however is only a very basic RTOS that likely is nothing like UNIX
- https://www.yoctoproject.org/ - Embedded Linux, looks like system requirements are much higher than all of the other options
- http://www.beastielabs.net/minix/ - Talks about running Minix on a 8MHz M68000 with a Mbyte of RAM, seems easy enough to emulate
- https://www.minix3.org/ - Minix "mini-Unix" 
- https://en.wikipedia.org/wiki/ChibiOS/RT - Runs on many low-end MCUs
- https://www.minix3.org/ - Older versions apperently do not need MMU
- https://en.wikipedia.org/wiki/%CE%9CClinux
- https://en.wikipedia.org/wiki/AVR32
  - http://ww1.microchip.com/downloads/en/AppNotes/doc32092.pdf - AVR32 was natively supported in the Linux kernel in older versions
- https://www.esp32.com/viewtopic.php?t=6723&start=10
  - https://github.com/jcmvbkbc/linux-xtensa - These two pages seem to suggest Linux can run on ESP32
- http://www.dnx-rtos.org/ - 10KiB of RAM minimum

UZIX or FUZIX  on a z80 emulator could be promising
  - https://github.com/chettrick/uzics - Unix for z80
  - https://github.com/aldolo69/esp8266_zxspectrum_emulator - ZX Spectrum emulator
  - https://github.com/SmallRoomLabs/cpm8266 - z80 emulator running CPM, could be modified to run UNIX instead
  - http://www.fuzix.org/ - Another UNIX for z80

Maybe i386 NetBSD on x86 emulator?
  - https://hackaday.com/2018/02/26/pc-xt-emulator-on-esp8266/ -x86 emulator for ESP8266
  - http://wiki.netbsd.org/ports/ - Says it requires megabytes of RAM, so external RAM would have to be used
  
# Timeline of UNIX

![UNIX Timeline](https://upload.wikimedia.org/wikipedia/commons/c/cd/Unix_timeline.en.svg)
