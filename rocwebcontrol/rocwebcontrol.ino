/*
    RocWeb Control - Control train speed with iWit volume knob device
    Copyright (C) 2019 Manuel Reimer <manuel.reimer@gmx.de>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "IwitVolumeKnob.h"
#include "HID-Project.h"

void setup() {
  // Initialize hardware
  IwitKnob.begin();
  Keyboard.begin();
}

bool lastbtn = false;
bool lastsuspended = true;
void loop() {
  delay(100);
  // Read values on every loop run
  signed char pos = IwitKnob.getPosition();
  bool btn = IwitKnob.getButton();
  bool suspended = USBDevice.isSuspended();

  // Disable the LED if the PC is shut down
  if (suspended != lastsuspended) {
    lastsuspended = suspended;
    if (suspended)
      IwitKnob.setLed(false);
    else
      IwitKnob.setLed(127); // Enable with 50% brightness
  }

  // Send volume keys based on position
  if (pos > 0) {
    Keyboard.write(KEYPAD_ADD);
    IwitKnob.reset();
  }
  else if (pos < 0) {
    Keyboard.write(KEYPAD_SUBTRACT);
    IwitKnob.reset();
  }

  // Send mute key based on encoder button
  if (btn != lastbtn) {
    lastbtn = btn;
    if (btn)
      Keyboard.press(KEYPAD_MULTIPLY);
    else
      Keyboard.release(KEYPAD_MULTIPLY);
  }
}
