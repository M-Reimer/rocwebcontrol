RocWeb Control
==============

Introduction
------------

This Arduino Firmware should be used in combination with the "[RocWeb Extras](https://addons.mozilla.org/firefox/addon/rocwebextras/)" Firefox Addon to control the train speed with a hardware knob device on your Android phone.

It is meant to be used with chinese USB volume control devices which have to be reprogrammed with the HoodLoader2 bootloader, first.

Installation
------------

You need the following libraries from the Arduino library manager:

- EncoderStepCounter by Manuel Reimer
- IwitVolumeKnob by Manuel Reimer
- HID-Project by NicoHood

You'll also need some ISP programmer device to flash HoodLoader2. The IwitVolumeKnob GitHub page has [some instructions on how to do this](https://github.com/M-Reimer/IwitVolumeKnob#burning-the-bootloader).

After burning the bootloader, you can just upload RocWeb Control via the Arduino IDE.
