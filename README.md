# TeensyGamepad
An arcade-style gamepad system based on Teensy 2.0.

## Purpose
This project lets a Teensy microcontroller send keyboard events to a PC, based on input from arcade controller components.

## Hardware
* Teensy 2.0 ([PJRC](http://pjrc.com/store/teensy.html), [AliExpress](http://www.aliexpress.com/item/Teensy-2-0-USB-Keyboard-Mouse-AVR-for-arduino-ISP-Board-Mega32u4-U-Disk-Experiment-usb/32363184858.html)) or Teensy++ 2.0 ([PJRC](http://pjrc.com/store/teensypp.html), [AliExpress](http://www.aliexpress.com/item/Genuine-PJRC-Teensy-2-0-USB-AVR-develope-board-for-ps3-Teensy-free-1pcs-usb-cable/32224600966.html))
* A set of arcade buttons (e.g. [these](http://www.aliexpress.com/item/New-Arcade-Push-Button-Durable-Multicade-MAME-Jamma-Game-Long-Switch-Mult-color/32329694375.html))
* Joystick (e.g. [this](http://www.aliexpress.com/item/New-Hotsale-Promotion-Bot-Bola-roja-8-modos-Joystick-para-consola-muina-recreativa-arcade/32333965577.html))

You can probably find even cheaper sources for the hardware if you search at sites like [AliExpress](http://www.aliexpress.com/) or [DealExtreme](http://www.dx.com/).

## Build instructions
The code can be compiled and uploaded to the Teensy 2.0 board through [Teensyduino](http://pjrc.com/teensy/td_download.html), which is available for Linux, Mac and Windows.

* Select the correct board model (Teensy 2.0 or Teensy++ 2.0) in the Arduino IDE under Tools -> Board.
* Set the correct USB type (Serial + Keyboard + Mouse + Joystick) under Tools -> USB Type.

## Pin setup
TODO - refer to source code for documentation