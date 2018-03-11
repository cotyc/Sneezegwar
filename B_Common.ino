void initLEDs() {
  pinMode(LED_RED_PIN, OUTPUT);
  pinMode(LED_GREEN_PIN, OUTPUT);
  pinMode(LED_BLUE_PIN, OUTPUT);
  analogWrite(LED_RED_PIN, 200);
  delay(300);
  analogWrite(LED_RED_PIN, 0);
  analogWrite(LED_GREEN_PIN, 255);
  analogWrite(LED_BLUE_PIN, 0);
  delay(300);
  analogWrite(LED_RED_PIN, 0);
  analogWrite(LED_GREEN_PIN, 0);
  analogWrite(LED_BLUE_PIN, 255);  
  delay(300);
  analogWrite(LED_RED_PIN, 0);
  analogWrite(LED_GREEN_PIN, 0);
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

int readMuxer(int channel){
    int controlPin[] = {MUXDATA0_PIN, MUXDATA1_PIN, MUXDATA2_PIN, MUXDATA3_PIN};
  
    int muxChannel[16][4]={
      {0,0,0,0}, //channel 0
      {1,0,0,0}, //channel 1
      {0,1,0,0}, //channel 2
      {1,1,0,0}, //channel 3
      {0,0,1,0}, //channel 4
      {1,0,1,0}, //channel 5
      {0,1,1,0}, //channel 6
      {1,1,1,0}, //channel 7
      {0,0,0,1}, //channel 8
      {1,0,0,1}, //channel 9
      {0,1,0,1}, //channel 10
      {1,1,0,1}, //channel 11
      {0,0,1,1}, //channel 12
      {1,0,1,1}, //channel 13
      {0,1,1,1}, //channel 14
      {1,1,1,1}  //channel 15
    };
  
    // Set the control pins for the channel to read from
    for(int i = 0; i < 4; i ++){
      digitalWrite(controlPin[i], muxChannel[channel][i]);
    }
    
    // Read the value from the set channel
    int val = getSmooth(MUXSIGNAL_PIN);
  
    //return the value
    return val;
}

void setVolumes() {
  mainVolume = analogRead(VOLUME_PIN);
  mainVolume = mainVolume/1023;
  sgtl5000_1.volume(mainVolume);
  tempLineOutLevel = analogRead(VOLUME_PIN);
  tempLineOutLevel = map(tempLineOutLevel, 0, 1023, 31, 13);
  sgtl5000_1.lineOutLevel(tempLineOutLevel);
}
  
void playChime(int chime) {
  switch (chime) {
    case 0: // Good sound - !! doesn't exist yet
      for(int i=0; i<2; i++){
        voice1env.amplitude(.5,1);
        voice1a.frequency(noteFreq[0][i]);
        voice1b.frequency(noteFreq[0][i]+3);
        delay(100);
        voice1env.amplitude(0,0);
      }
      break;
    case 1: // Bad Sound
      for(int i=0; i<2; i++){
        voice1env.amplitude(.5,1);
        voice1a.frequency(noteFreq[0][i]);
        voice1b.frequency(noteFreq[0][i]+3);
        delay(200);
        voice1env.amplitude(0,0);
      }
      break;
    case 2: // Bootup Sound
      for(int i=0; i<4; i++){
        voice1env.amplitude(.5,1);
        voice1a.frequency(noteFreq[0][i]);
        voice1b.frequency(noteFreq[0][i]+3);
        delay(200);
        voice1env.amplitude(0,0);
      }
      break;
    case 3: // Extended Bootup Sound
      for(int i=0; i<6; i++){
        voice1env.amplitude(.5,1);
        voice1a.frequency(noteFreq[0][i]+2);
        voice1b.frequency(noteFreq[0][i]+5);
        delay(200);
        voice1env.amplitude(0,0);
      }
      break;
    default:  
      for(int i=0; i<2; i++){
        voice1env.amplitude(.5,1);
        voice1a.frequency(noteFreq[0][i]+3);
        voice1b.frequency(noteFreq[0][i]);
        delay(100);
        voice1env.amplitude(0,0);
      }
  }
}

float mapfloat(float x, float in_min, float in_max, float out_min, float out_max){
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int getSmooth(int pin){
  int vals[5]; // Array to hold 5 readings
  for(int i = 0; i < 5; i++){
    vals[i] = analogRead(pin); // Take 5 readings
  }
  float smooth = (vals[0] + vals[1] + vals[2] + vals[3] + vals[4]) / 5;
  return smooth;
}
