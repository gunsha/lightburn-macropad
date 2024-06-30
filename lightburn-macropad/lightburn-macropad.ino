#include <Keyboard.h>
int delayTime = 300;
// button pins in order, from first button to last
int buttons[] = {18,4,6,5,2,3,10,8,9,16,7,14,15};

// Debug buttons - can use this to check which button goes to which pin
// int buttonAction[][13]{
//   {KEY_KP_1},
//   {KEY_KP_2},
//   {KEY_KP_3},
//   {KEY_KP_4},
//   {KEY_KP_5},
//   {KEY_KP_6},
//   {KEY_KP_7},
//   {KEY_KP_8},
//   {KEY_KP_9},
//   {KEY_KP_1,'a'},
//   {KEY_KP_1,'b'},
//   {KEY_KP_1,'c'},
//   {KEY_KP_1,'d'}};

int buttonAction[][13] = {
  {KEY_LEFT_CTRL, 'h'},{KEY_KP_8},{KEY_KP_2},
  {KEY_KP_4},{KEY_KP_4},{KEY_KP_6},
            {KEY_KP_2},
  {KEY_LEFT_CTRL, KEY_KP_7},{KEY_LEFT_CTRL, KEY_KP_3},{KEY_LEFT_CTRL, KEY_KP_4},
  {KEY_LEFT_ALT, 'r'},{KEY_LEFT_CTRL, KEY_KP_5},{KEY_LEFT_CTRL, KEY_KP_6},
  };

void delayRelease(){
  delay(100);
  Keyboard.releaseAll();
  delay(delayTime);
}

void setup()
{
  for(int i = 0; i < 13; i++){  
    pinMode(buttons[i], INPUT);
    digitalWrite(buttons[i], HIGH);
  }
}

void loop() {
  for(int i = 0; i < 13; i++){
    if (digitalRead(buttons[i]) == 0) {
      for(int key : buttonAction[i]) {
        Keyboard.press(key);
      }
      delayRelease();
    }
  }
}



