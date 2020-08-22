# Resources and information about running Linux (or something similar) with the lowest system requirements or cheapest/simplest systems
# Useful
  - http://retrobsd.org/
    - UNIX with only 128K ram? This seems like one of the most promising options
    - It runs on PIC32MX, which is MIPS32 M4K architecture. 
    - The dev boards for this are pretty pricey, but none of the DIP versions of this chip have enough ram (64K only). 
      They have the same architecture though, so it could be possible to use one of those with an external ram chip
  - https://dmitry.gr/?r=05.Projects&proj=07.%20Linux%20on%208bit 
    - This is an ARM emulator for 8 bit 24MHz AVR, but boots in 6 hours. 
    - It includes porting instructions and seems straighforward enough to port to a different platform, so
      if it has enough processing power it should be able to boot in a few minutes rather than hours. An esp8266 can run at 
      378MHz using CNLOHRs toolchain. That's 16x faster, so boot time should be reduced to 22 minutes. That's reasonable enough to work.
      If it was ported to an ESP32 Wrover module with SPIRAM (Like in this video https://www.reddit.com/r/esp32/comments/dtlj7n/booting_linux_on_esp32_realtime_video/)
      external ram wouldn't have to be used at all. This video shows it booting in 6 minutes, which is pretty good.
  - http://www.jcwolfram.de/projekte/mxe11_en/main.php
    - A PDP11 emulator for STM32 boards. Possibly port-able, but also those boards are very cheap
  - https://www.thirtythreeforty.net/posts/2019/12/my-business-card-runs-linux/
    https://www.digikey.ca/en/products/detail/seeed-technology-co-ltd/102110199/9975970
      - A $10 Canadian, full Linux capable board the size of an SD card. I don't think there's a simpler, cheaper, and lower power board.
        Unless you want to have Linux (Or UNIX or BSD) running on something really cheap/crappy just for the fun of it, this is probably the best option
  
# The big list (not all of these are useful)
  - https://larrylisky.com/2012/07/14/how-to-create-a-small-rtos/
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
