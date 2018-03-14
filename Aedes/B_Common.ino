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
  note0.onPress = onPressNote0;
  note0.onHold = onHoldNote0;
  note0.onRelease = onReleaseNote0;

  note1.onPress = onPressNote1;
  note1.onHold = onHoldNote1;
  note1.onRelease = onReleaseNote1;

  note2.onPress = onPressNote2;
  note2.onHold = onHoldNote2;
  note2.onRelease = onReleaseNote2;

  note3.onPress = onPressNote3;
  note3.onHold = onHoldNote3;
  note3.onRelease = onReleaseNote3;

  note4.onPress = onPressNote4;
  note4.onHold = onHoldNote4;
  note4.onRelease = onReleaseNote4;

  note5.onPress = onPressNote5;
  note5.onHold = onHoldNote5;
  note5.onRelease = onReleaseNote5;

  note6.onPress = onPressNote6;
  note6.onHold = onHoldNote6;
  note6.onRelease = onReleaseNote6;

  note7.onPress = onPressNote7;
  note7.onHold = onHoldNote7;
  note7.onRelease = onReleaseNote7;

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


void readPots() {
  // Read potentiometers via muxer
  for (int i = 0; i < 16; i ++) {

    // Reverse the readings (pots installed inverted)
    potValues[i] = (1023 - readMuxer(i));

    switch (currentMode) {
      case 0:
        processPotsSynth(i);
        break;
      case 1:
        processPotsDrums(i);
        break;
    }
  }

  // Read potentiometers via direct pins
  for (int i = 16; i < 21; i++) {

    // Reverse the readings (pots installed inverted)
    potValues[i] = (1023 - getSmooth(potDirectPins[i]));

    switch (currentMode) {
      case 0:
        processPotsSynth(i);
        break;
      case 1:
        processPotsDrums(i);
        break;
    }
  }
}

boolean checkValueChange(int pot, int changeThresh) {
  if (abs(potValues[pot] - potValuesPrevious[pot]) > changeThresh || firstRunRead) return true;
  else return false;
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

void onPressNote0(DebounceButton * btn) {
  switch (currentMode) {
    case 0:
      onPressSynth(0);
      break;
    case 1:
      onPressDrum(0);
      break;
  }
}

void onHoldNote0(DebounceButton * btn) {
  switch (currentMode) {
    case 0:
      onHoldSynth(0);
      break;
    case 1:
      onHoldDrum(0);
      break;
  }
}
void onReleaseNote0(DebounceButton * btn) {
  switch (currentMode) {
    case 0:
      onReleaseSynth(0);
      break;
    case 1:
      onReleaseDrum(0);
      break;
  }
}
void onPressNote1(DebounceButton * btn) {
  switch (currentMode) {
    case 0:
      onPressSynth(1);
      break;
    case 1:
      onPressDrum(1);
      break;
  }
}
void onHoldNote1(DebounceButton * btn) {
  switch (currentMode) {
    case 0:
      onHoldSynth(1);
      break;
    case 1:
      onHoldDrum(1);
      break;
  }
}
void onReleaseNote1(DebounceButton * btn) {
  switch (currentMode) {
    case 0:
      onReleaseSynth(1);
      break;
    case 1:
      onReleaseDrum(1);
      break;
  }
}
void onPressNote2(DebounceButton * btn) {
  switch (currentMode) {
    case 0:
      onPressSynth(2);
      break;
    case 1:
      onPressDrum(2);
      break;
  }
}
void onHoldNote2(DebounceButton * btn) {
  switch (currentMode) {
    case 0:
      onHoldSynth(2);
      break;
    case 1:
      onHoldDrum(2);
      break;
  }
}
void onReleaseNote2(DebounceButton * btn) {
  switch (currentMode) {
    case 0:
      onReleaseSynth(2);
      break;
    case 1:
      onReleaseDrum(2);
      break;
  }
}
void onPressNote3(DebounceButton * btn) {
  switch (currentMode) {
    case 0:
      onPressSynth(3);
      break;
    case 1:
      onPressDrum(3);
      break;
  }
}
void onHoldNote3(DebounceButton * btn) {
  switch (currentMode) {
    case 0:
      onHoldSynth(3);
      break;
    case 1:
      onHoldDrum(3);
      break;
  }
}
void onReleaseNote3(DebounceButton * btn) {
  switch (currentMode) {
    case 0:
      onReleaseSynth(3);
      break;
    case 1:
      onReleaseDrum(3);
      break;
  }
}
void onPressNote4(DebounceButton * btn) {
  switch (currentMode) {
    case 0:
      onPressSynth(4);
      break;
    case 1:
      onPressDrum(4);
      break;
  }
}
void onHoldNote4(DebounceButton * btn) {
  switch (currentMode) {
    case 0:
      onHoldSynth(4);
      break;
    case 1:
      onHoldDrum(4);
      break;
  }
}
void onReleaseNote4(DebounceButton * btn) {
  switch (currentMode) {
    case 0:
      onReleaseSynth(4);
      break;
    case 1:
      onReleaseDrum(4);
      break;
  }
}
void onPressNote5(DebounceButton * btn) {
  switch (currentMode) {
    case 0:
      onPressSynth(5);
      break;
    case 1:
      onPressDrum(5);
      break;
  }
}
void onHoldNote5(DebounceButton * btn) {
  switch (currentMode) {
    case 0:
      onHoldSynth(5);
      break;
    case 1:
      onHoldDrum(5);
      break;
  }
}
void onReleaseNote5(DebounceButton * btn) {
  switch (currentMode) {
    case 0:
      onReleaseSynth(5);
      break;
    case 1:
      onReleaseDrum(5);
      break;
  }
}
void onPressNote6(DebounceButton * btn) {
  switch (currentMode) {
    case 0:
      onPressSynth(6);
      break;
    case 1:
      onPressDrum(6);
      break;
  }
}
void onHoldNote6(DebounceButton * btn) {
  switch (currentMode) {
    case 0:
      onHoldSynth(6);
      break;
    case 1:
      onHoldDrum(6);
      break;
  }
}
void onReleaseNote6(DebounceButton * btn) {
  switch (currentMode) {
    case 0:
      onReleaseSynth(6);
      break;
    case 1:
      onReleaseDrum(6);
      break;
  }
}
void onPressNote7(DebounceButton * btn) {
  switch (currentMode) {
    case 0:
      onPressSynth(7);
      break;
    case 1:
      onPressDrum(7);
      break;
  }
}
void onHoldNote7(DebounceButton * btn) {
  switch (currentMode) {
    case 0:
      onHoldSynth(7);
      break;
    case 1:
      onHoldDrum(7);
      break;
  }
}
void onReleaseNote7(DebounceButton * btn) {
  switch (currentMode) {
    case 0:
      onReleaseSynth(7);
      break;
    case 1:
      onReleaseDrum(7);
      break;
  }
}



