//Keyboard : pause, move, next page, it does it all!

//---------------------------------------------

//Libraries
#include <Keyboard.h>

//Variables for rotary encoder
int lastStateoFCLK;
int CurrentStateOfCLK;


//-------------------------------------------------------------
void setup(){
 
  //VOLUME!
  //DP pin
  pinMode(0, INPUT_PULLUP);
  //CLK
  pinMode(1, INPUT_PULLUP);

  //SWITCHES!
  //LEFT
  pinMode(2, INPUT_PULLUP);
  //DOWN
  pinMode(3, INPUT_PULLUP);
  //UP
  pinMode(4, INPUT_PULLUP);
  //RIGHT
  pinMode(5, INPUT_PULLUP);
 //SPACE
  pinMode(10, INPUT_PULLUP);


  //START KEYBOARD!
  Keyboard.begin();

  //Set up variable
  lastStateoFCLK = digitalRead(1);
}

void loop(){
  //LEFT
  if (digitalRead(2) == LOW){
    keyboard.press(KEY_LEFT_ARROW);
  }

  //DOWN
  if (digitalRead(3) == LOW){
    keyboard.press(KEY_DOWN_ARROW);
  }

  //UP
  if (digitalRead(4) == LOW){
    keyboard.press(KEY_UP_ARROW);
  }

  //RIGHT
  if (digitalRead(5) == LOW){
    keyboard.press(KEY_RIGHT_ARROW);
  }

  //SPACE
  if (digitalRead(10) == LOW){
    keyboard.press(KEY_PAUSE);
  }

  //Rotary Encoder
  CurrentStateOfCLK = digitalRead(1);
      //Has position changed? Is CLK giving a high input?
  if (CurrentStateOfCLK != lastStateoFCLK && CurrentStateOfCLK = 1){
    //This means that it is being turned counter-clockwise, 
    //as if CLK is high and DP is low, it means that it being rotated CCW
    //Remember, CLK's state is being checked if it has or hasn't changed.
    //This means that the moment CLK changes value & is high, the exact moment where DP
    //Is tells us how it is being rotated 
    if (digitalRead(0) != CurrentStateOfCLK){
      keyboard.press(KEY_F8);
    }else{
      keyboard.press(KEY_F7);
    }
  }

  lastStateoFCLK = CurrentStateOfCLK;
}