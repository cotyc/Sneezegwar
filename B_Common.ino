

void initLEDs() {
  // Commented out for LED tests to secondary Teensy
  // pinMode(LED_RED_PIN, OUTPUT);
  // pinMode(LED_GREEN_PIN, OUTPUT);
  // pinMode(LED_BLUE_PIN, OUTPUT);
  // analogWrite(LED_RED_PIN, 200);
  // delay(300);
  // analogWrite(LED_RED_PIN, 0);
  // analogWrite(LED_GREEN_PIN, 255);
  analogWrite(LED_BLUE_PIN, 0);
  delay(300);
  // analogWrite(LED_RED_PIN, 0);
  // analogWrite(LED_GREEN_PIN, 0);
  analogWrite(LED_BLUE_PIN, 255);
  delay(300);
  // analogWrite(LED_RED_PIN, 0);
  // analogWrite(LED_GREEN_PIN, 0);
  analogWrite(LED_BLUE_PIN, 0);
  redLevel = 182;
  greenLevel = 246;
  blueLevel = 41;
}


void initMultiplexor() {
  pinMode(MUXDATA0_PIN, OUTPUT);
  pinMode(MUXDATA1_PIN, OUTPUT);
  pinMode(MUXDATA2_PIN, OUTPUT);
  pinMode(MUXDATA3_PIN, OUTPUT);
  pinMode(MUXSIGNAL_PIN, INPUT);

  digitalWrite(MUXDATA0_PIN, LOW);
  digitalWrite(MUXDATA1_PIN, LOW);
  digitalWrite(MUXDATA2_PIN, LOW);
  digitalWrite(MUXDATA3_PIN, LOW);
}

void initButtons() {
  noteOne.onPress = onPressNoteOne;
  noteOne.onHold = onHoldNoteOne;
  noteOne.onRelease = onReleaseNoteOne;

  noteTwo.onPress = onPressNoteTwo;
  noteTwo.onHold = onHoldNoteTwo;
  noteTwo.onRelease = onReleaseNoteTwo;

  noteThree.onPress = onPressNoteThree;
  noteThree.onHold = onHoldNoteThree;
  noteThree.onRelease = onReleaseNoteThree;

  noteFour.onPress = onPressNoteFour;
  noteFour.onHold = onHoldNoteFour;
  noteFour.onRelease = onReleaseNoteFour;

  noteFive.onPress = onPressNoteFive;
  noteFive.onHold = onHoldNoteFive;
  noteFive.onRelease = onReleaseNoteFive;

  noteSix.onPress = onPressNoteSix;
  noteSix.onHold = onHoldNoteSix;
  noteSix.onRelease = onReleaseNoteSix;

  noteSeven.onPress = onPressNoteSeven;
  noteSeven.onHold = onHoldNoteSeven;
  noteSeven.onRelease = onReleaseNoteSeven;

  noteEight.onPress = onPressNoteEight;
  noteEight.onHold = onHoldNoteEight;
  noteEight.onRelease = onReleaseNoteEight;

  //  modeToggle.onPress = onPressModeToggle;       // fires when pressed
  //  modeToggle.onRelease = onReleaseModeToggle;   // fires everytime it's released
  //  modeToggle.onClick = onClickModeToggle;       // fires only when released without being held
  //  modeToggle.onHold = onHoldModeToggle;         // fires when held
}

int readMuxer(int channel) {
  int controlPin[] = {MUXDATA0_PIN, MUXDATA1_PIN, MUXDATA2_PIN, MUXDATA3_PIN};

  int muxChannel[16][4] = {
    {0, 0, 0, 0}, //channel 0
    {1, 0, 0, 0}, //channel 1
    {0, 1, 0, 0}, //channel 2
    {1, 1, 0, 0}, //channel 3
    {0, 0, 1, 0}, //channel 4
    {1, 0, 1, 0}, //channel 5
    {0, 1, 1, 0}, //channel 6
    {1, 1, 1, 0}, //channel 7
    {0, 0, 0, 1}, //channel 8
    {1, 0, 0, 1}, //channel 9
    {0, 1, 0, 1}, //channel 10
    {1, 1, 0, 1}, //channel 11
    {0, 0, 1, 1}, //channel 12
    {1, 0, 1, 1}, //channel 13
    {0, 1, 1, 1}, //channel 14
    {1, 1, 1, 1} //channel 15
  };

  // Set the control pins for the channel to read from
  for (int i = 0; i < 4; i ++) {
    digitalWrite(controlPin[i], muxChannel[channel][i]);
  }

  // Read the value from the set channel
  int val = getSmooth(MUXSIGNAL_PIN);

  //return the value
  return val;
}

void setVolumes() {
  mainVolume = analogRead(VOLUME_PIN);
  mainVolume = mainVolume / 1023;
  sgtl5000_1.volume(mainVolume);
  tempLineOutLevel = analogRead(VOLUME_PIN);
  tempLineOutLevel = map(tempLineOutLevel, 0, 1023, 31, 13);
  sgtl5000_1.lineOutLevel(tempLineOutLevel);
}

void playChime(int chime) {
  switch (chime) {
    case 0: // Good sound - !! doesn't exist yet
      for (int i = 0; i < 2; i++) {
        voice1env.amplitude(.5, 1);
        voice1a.frequency(noteFreq[0][i]);
        voice1b.frequency(noteFreq[0][i] + 3);
        delay(100);
        voice1env.amplitude(0, 0);
      }
      break;
    case 1: // Bad Sound
      for (int i = 0; i < 2; i++) {
        voice1env.amplitude(.5, 1);
        voice1a.frequency(noteFreq[0][i]);
        voice1b.frequency(noteFreq[0][i] + 3);
        delay(200);
        voice1env.amplitude(0, 0);
      }
      break;
    case 2: // Bootup Sound
      for (int i = 0; i < 4; i++) {
        voice1env.amplitude(.5, 1);
        voice1a.frequency(noteFreq[0][i]);
        voice1b.frequency(noteFreq[0][i] + 3);
        delay(200);
        voice1env.amplitude(0, 0);
      }
      break;
    case 3: // Extended Bootup Sound
      for (int i = 0; i < 6; i++) {
        voice1env.amplitude(.5, 1);
        voice1a.frequency(noteFreq[0][i] + 2);
        voice1b.frequency(noteFreq[0][i] + 5);
        delay(200);
        voice1env.amplitude(0, 0);
      }
      break;
    default:
      for (int i = 0; i < 2; i++) {
        voice1env.amplitude(.5, 1);
        voice1a.frequency(noteFreq[0][i] + 3);
        voice1b.frequency(noteFreq[0][i]);
        delay(100);
        voice1env.amplitude(0, 0);
      }
  }
}

float mapfloat(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int getSmooth(int pin) {
  int vals[5]; // Array to hold 5 readings
  for (int i = 0; i < 5; i++) {
    vals[i] = analogRead(pin); // Take 5 readings
  }
  float smooth = (vals[0] + vals[1] + vals[2] + vals[3] + vals[4]) / 5;
  return smooth;
}

void onPressNoteOne(DebounceButton* btn) {
  DEBUG_PRINTS("\nButton 1 Pressed.");
  if (currentMode == 0) {
    // synth
    voice1env.amplitude(1, attackTime);
    voice1filterenv.amplitude(1, attackTimeFilter);
    noteTrigFlag[0] = true;
    attackWait[0] = millis();
  }
  else if (currentMode == 1) {
  // drum
  playFlashRaw1.play(sampleNames[4]);

}
}
void onHoldNoteOne(DebounceButton* btn) {
  DEBUG_PRINTS("\nButton 1 Held.");
  if (currentMode == 0) {
    // synth
    if (millis() - attackWait[0] > attackTime && noteTrigFlag[0]) {
      voice1env.amplitude(sustainLevel, decayTime);
    }
    if (millis() - attackWait[0] > attackTimeFilter && noteTrigFlag[0]) {
      voice1filterenv.amplitude(sustainLevelFilter, decayTimeFilter);
    }
  }
  else if (currentMode == 1) {
  // drum
}
}
void onReleaseNoteOne(DebounceButton* btn) {
  if (currentMode == 0) {
    // synth
    noteTrigFlag[0] = false;
    voice1env.amplitude(0, releaseTime);
    voice1filterenv.amplitude(-1, releaseTimeFilter);
  }
  else if (currentMode == 1) {
  // drum
}
}

void onPressNoteTwo(DebounceButton* btn) {
  DEBUG_PRINTS("\nButton 2 Pressed.");
  if (currentMode == 0) {
    // synth
    voice2env.amplitude(1, attackTime);
    voice2filterenv.amplitude(1, attackTimeFilter);
    noteTrigFlag[1] = true;
    attackWait[1] = millis();
  }
  else if (currentMode == 1) {
  // drum
  playFlashRaw2.play(sampleNames[3]);
}
}
void onHoldNoteTwo(DebounceButton* btn) {
  DEBUG_PRINTS("\nButton 2 Held.");
  if (currentMode == 0) {
    // synth
    if (millis() - attackWait[1] > attackTime && noteTrigFlag[1]) {
      voice2env.amplitude(sustainLevel, decayTime);
    }
    if (millis() - attackWait[1] > attackTimeFilter && noteTrigFlag[1]) {
      voice2filterenv.amplitude(sustainLevelFilter, decayTimeFilter);
    }
  }
  else if (currentMode == 1) {
  // drum
}
}
void onReleaseNoteTwo(DebounceButton* btn) {
  if (currentMode == 0) {
    // synth
    noteTrigFlag[1] = false;
    voice2env.amplitude(0, releaseTime);
    voice2filterenv.amplitude(-1, releaseTimeFilter);
  }
  else if (currentMode == 1) {
  // drum
}
}

void onPressNoteThree(DebounceButton* btn) {
  DEBUG_PRINTS("\nButton 3 Pressed.");
  if (currentMode == 0) {
    // synth
    voice3env.amplitude(1, attackTime);
    voice3filterenv.amplitude(1, attackTimeFilter);
    noteTrigFlag[2] = true;
    attackWait[2] = millis();
  }
  else if (currentMode == 1) {
  // drum
  playFlashRaw3.play(sampleNames[2]);
}
}
void onHoldNoteThree(DebounceButton* btn) {
  DEBUG_PRINTS("\nButton 3 Held.");
  if (currentMode == 0) {
    // synth
    if (millis() - attackWait[2] > attackTime && noteTrigFlag[2]) {
      voice3env.amplitude(sustainLevel, decayTime);
    }
    if (millis() - attackWait[2] > attackTimeFilter && noteTrigFlag[2]) {
      voice3filterenv.amplitude(sustainLevelFilter, decayTimeFilter);
    }
  }
  else if (currentMode == 1) {
  // drum
}
}
void onReleaseNoteThree(DebounceButton* btn) {
  if (currentMode == 0) {
    // synth
    noteTrigFlag[2] = false;
    voice3env.amplitude(0, releaseTime);
    voice3filterenv.amplitude(-1, releaseTimeFilter);
  }
  else if (currentMode == 1) {
  // drum
}
}

void onPressNoteFour(DebounceButton* btn) {
  DEBUG_PRINTS("\nButton 4 Pressed.");
  if (currentMode == 0) {
    // synth
    voice4env.amplitude(1, attackTime);
    voice4filterenv.amplitude(1, attackTimeFilter);
    noteTrigFlag[3] = true;
    attackWait[3] = millis();
  }
  else if (currentMode == 1) {
  // drum
  playFlashRaw4.play(sampleNames[5]);
}
}
void onHoldNoteFour(DebounceButton* btn) {
  DEBUG_PRINTS("\nButton 4 Held.");
  if (currentMode == 0) {
    // synth
    if (millis() - attackWait[3] > attackTime && noteTrigFlag[3]) {
      voice4env.amplitude(sustainLevel, decayTime);
    }
    if (millis() - attackWait[3] > attackTimeFilter && noteTrigFlag[3]) {
      voice4filterenv.amplitude(sustainLevelFilter, decayTimeFilter);
    }
  }
  else if (currentMode == 1) {
  // drum
}
}
void onReleaseNoteFour(DebounceButton* btn) {
  if (currentMode == 0) {
    // synth
    noteTrigFlag[3] = false;
    voice4env.amplitude(0, releaseTime);
    voice4filterenv.amplitude(-1, releaseTimeFilter);
  }
  else if (currentMode == 1) {
  // drum
}
}

void onPressNoteFive(DebounceButton* btn) {
  DEBUG_PRINTS("\nButton 5 Pressed.");
  if (currentMode == 0) {
    // synth
    voice5env.amplitude(1, attackTime);
    voice5filterenv.amplitude(1, attackTimeFilter);
    noteTrigFlag[4] = true;
    attackWait[4] = millis();
  }
  else if (currentMode == 1) {
  // drum
  playFlashRaw5.play(sampleNames[0]);
}
}
void onHoldNoteFive(DebounceButton* btn) {
  DEBUG_PRINTS("\nButton 5 Held.");
  if (currentMode == 0) {
    // synth
    if (millis() - attackWait[4] > attackTime && noteTrigFlag[4]) {
      voice5env.amplitude(sustainLevel, decayTime);
    }
    if (millis() - attackWait[4] > attackTimeFilter && noteTrigFlag[4]) {
      voice5filterenv.amplitude(sustainLevelFilter, decayTimeFilter);
    }
  }
  else if (currentMode == 1) {
  // drum
}
}
void onReleaseNoteFive(DebounceButton* btn) {
  if (currentMode == 0) {
    // synth
    noteTrigFlag[4] = false;
    voice5env.amplitude(0, releaseTime);
    voice5filterenv.amplitude(-1, releaseTimeFilter);
  }
  else if (currentMode == 1) {
  // drum
}
}

void onPressNoteSix(DebounceButton* btn) {
  DEBUG_PRINTS("\nButton 6 Pressed.");
  if (currentMode == 0) {
    // synth
    voice6env.amplitude(1, attackTime);
    voice6filterenv.amplitude(1, attackTimeFilter);
    noteTrigFlag[5] = true;
    attackWait[5] = millis();
  }
  else if (currentMode == 1) {
  // drum
  playFlashRaw6.play(sampleNames[1]);
}
}
void onHoldNoteSix(DebounceButton* btn) {
  DEBUG_PRINTS("\nButton 6 Held.");
  if (currentMode == 0) {
    // synth
    if (millis() - attackWait[5] > attackTime && noteTrigFlag[5]) {
      voice6env.amplitude(sustainLevel, decayTime);
    }
    if (millis() - attackWait[5] > attackTimeFilter && noteTrigFlag[5]) {
      voice6filterenv.amplitude(sustainLevelFilter, decayTimeFilter);
    }
  }
  else if (currentMode == 1) {
  // drum
}
}
void onReleaseNoteSix(DebounceButton* btn) {
  if (currentMode == 0) {
    // synth
    noteTrigFlag[5] = false;
    voice6env.amplitude(0, releaseTime);
    voice6filterenv.amplitude(-1, releaseTimeFilter);
  }
  else if (currentMode == 1) {
  // drum
}
}

void onPressNoteSeven(DebounceButton* btn) {
  DEBUG_PRINTS("\nButton 7 Pressed.");
  if (currentMode == 0) {
    // synth
    voice7env.amplitude(1, attackTime);
    voice7filterenv.amplitude(1, attackTimeFilter);
    noteTrigFlag[6] = true;
    attackWait[6] = millis();
  }
  else if (currentMode == 1) {
  // drum
  playFlashRaw7.play(sampleNames[6]);
}
}
void onHoldNoteSeven(DebounceButton* btn) {
  DEBUG_PRINTS("\nButton 7 Held.");
  if (currentMode == 0) {
    // synth
    if (millis() - attackWait[6] > attackTime && noteTrigFlag[6]) {
      voice7env.amplitude(sustainLevel, decayTime);
    }
    if (millis() - attackWait[6] > attackTimeFilter && noteTrigFlag[6]) {
      voice7filterenv.amplitude(sustainLevelFilter, decayTimeFilter);
    }
  }
  else if (currentMode == 1) {
  // drum
}
}
void onReleaseNoteSeven(DebounceButton* btn) {
  if (currentMode == 0) {
    // synth
    noteTrigFlag[6] = false;
    voice7env.amplitude(0, releaseTime);
    voice7filterenv.amplitude(-1, releaseTimeFilter);
  }
  else if (currentMode == 1) {
  // drum
}
}

void onPressNoteEight(DebounceButton* btn) {
  DEBUG_PRINTS("\nButton 8 Pressed.");
  if (currentMode == 0) {
    // synth
    voice8env.amplitude(1, attackTime);
    voice8filterenv.amplitude(1, attackTimeFilter);
    noteTrigFlag[7] = true;
    attackWait[7] = millis();
  }
  else if (currentMode == 1) {
  // drum
  playFlashRaw8.play(sampleNames[7]);
}
}
void onHoldNoteEight(DebounceButton* btn) {
  DEBUG_PRINTS("\nButton 8 Held.");
  if (currentMode == 0) {
    // synth
    if (millis() - attackWait[7] > attackTime && noteTrigFlag[7]) {
      voice8env.amplitude(sustainLevel, decayTime);
    }
    if (millis() - attackWait[7] > attackTimeFilter && noteTrigFlag[7]) {
      voice8filterenv.amplitude(sustainLevelFilter, decayTimeFilter);
    }
  }
  else if (currentMode == 1) {
  // drum
}
}
void onReleaseNoteEight(DebounceButton* btn) {
  if (currentMode == 0) {
    // synth
    noteTrigFlag[7] = false;
    voice8env.amplitude(0, releaseTime);
    voice8filterenv.amplitude(-1, releaseTimeFilter);
  }
  else if (currentMode == 1) {
  // drum
}
}



