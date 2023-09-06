/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Administrator                                    */
/*    Created:      Fri Jun 30 2023                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Left_Give            motor         4               
// Right_Give           motor         3               
// Controller1          controller                    
// Get_Plate            motor         16              
// Motor8               motor         8               
// MOVE1                motor         10              
// MOVE2                motor         1               
// MOVE3_FO             motor         12              
// MOVE4                motor         19              
// Drivetrain           drivetrain    2, 11, 9, 20, 14
// BeginFire            motor         7               
// Air                  motor         5               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
int flag=0;
int flag2 = 0;
int collect = 0;
int Black_wheel = 0;
int tong = 0;
using namespace vex;

extern motor leftMotorA;
extern motor leftMotorB;
extern motor rightMotorA;
extern motor rightMotorB;

// motor& MOVE2_RE = leftMotorA;
// motor& MOVE3 = leftMotorB;
// motor& MOVE1_RE = rightMotorA;
// motor& MOVE4_FO = rightMotorB;

// void getPlate() ;
 void givePlate();
// void givePlate2();
// void givePlate3();
// void givePlate4();
void air_open();
 void spins();
 void spins2();
 void takePlate();
 void takePlate2();
 void AutoMode();
 void move(int, int);
// void rotationA();

// Debug
void move();
void testL();
void testR();
void tL();
void tR();
void fire();
void zhuantong();
// End Debug

int debug_flag = 1;

int main() 
{
  
  AutoMode();
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  // while (Inertial.isCalibrating()) wait(15, msec);
  int inf = 0;
  Controller1.ButtonR1.pressed(takePlate);
  Controller1.ButtonR2.pressed(takePlate2);
  Controller1.ButtonB.pressed(givePlate);
  Controller1.ButtonX.pressed(givePlate);
  Controller1.ButtonL1.pressed(spins);
  Controller1.ButtonL2.pressed(spins2);
  Controller1.ButtonA.pressed(fire);
  Controller1.Axis1.changed(move);
  Controller1.Axis3.changed(move);
  Controller1.Axis4.changed(move);
while(true){
  if(Controller1.ButtonDown.pressing())
  {
    Air.setVelocity(70,percent);
    Air.spin(reverse);
  }else if(Controller1.ButtonUp.pressing()){
    Air.setVelocity(70,percent);
    Air.spin(forward);
  }else{
    Air.stop();
  }
  wait(15,msec);
}
  // if (debug_flag) {
    // Controller1.ButtonUp.pressed(testL);
    // Controller1.ButtonDown.pressed(testR);
    // Controller1.ButtonLeft.pressed(tL);
    // Controller1.ButtonRight.pressed(tR);
  // }
  
  // wait(5, sec);
  // AutoMode();

}

void allStop() {
  Drivetrain.stop();
  MOVE1.stop();
  MOVE2.stop();
  MOVE3_FO.stop();
  MOVE4.stop();
}

void setVelocity(int x) {
  Drivetrain.setDriveVelocity(x, percent);
  Drivetrain.setTurnVelocity(x, percent);
  MOVE1.setVelocity(x, percent);
  MOVE2.setVelocity(x, percent);
  MOVE3_FO.setVelocity(x, percent);
  MOVE4.setVelocity(x, percent);
}

void AutoMode() {
// Drivetrain.stop();
  zhuantong();
  setVelocity(100);
  Drivetrain.drive(forward);
  MOVE1.spin(forward);
  MOVE2.spin(reverse);
  MOVE3_FO.spin(forward);
  MOVE4.spin(reverse);
  wait(400, msec);

  // test
  // wait(2, sec);
  // test end

  allStop();
  zhuantong();

  moveDist(30, reverse, 70);

  Drivetrain.setTurnVelocity(10, percent);
  Drivetrain.turnToHeading(135, degrees);
  
  inputPlate(100);
  moveDist(20, forward, 30);
  wait(500, msec);
  moveDist(20, reverse, 10);
  inputPlate(0);
  
  Drivetrain.setTurnVelocity(5, percent);
  Drivetrain.turnToHeading(45  + 180, degrees);

  for (int i = 0; i < 2; i++) {
    moveDist(10, forward, 95);
    Drivetrain.turnToHeading(45 + 181, degrees);
  }
  Drivetrain.turnToHeading(155 + 180, degrees);
  hit(11.4);
  wait(1, sec);
  fire();
  wait(500, msec);

  hit(11.2);
  wait(1, sec);
  fire();
  wait(500, msec);

  hit(11);
  wait(1, sec);
  fire();
  wait(100, msec);
  hit(0);

  Drivetrain.turnToHeading(44, degrees);
  for (int i = 0; i < 2; i++) {
    moveDist(10, forward, 95);
    Drivetrain.turnToHeading(44, degrees);
  }
  
  // setVelocity(100);
  // Drivetrain.setTimeout(2, sec);
  Controller1.Screen.print(10);

  // while (true) {
  // Drivetrain.drive(reverse);
  // MOVE1.spin(reverse);
  // MOVE2.spin(forward);
  // MOVE3_FO.spin(reverse);
  // MOVE4.spin(forward);
  // }

  // wait(2, sec);

  // Drivetrain.setDriveVelocity(10, percent);
  // Drivetrain.driveFor(reverse, 100, mm, false);
  // while (Drivetrain.isMoving()) {
  //   MOVE1.spin(reverse);
  //   MOVE2.spin(forward);
  //   MOVE3_FO.spin(reverse);
  //   MOVE4.spin(forward);
  // }
  // allStop();
}

/*
void tL() {
  leftGroup.stop();
}

void tR() {
  rightGroup.stop();
}

void testL() {
  leftGroup.setVelocity(50, percent);
  leftGroup.spin(reverse);
}

void testR() {
  rightGroup.setVelocity(50, percent);
  rightGroup.spin(forward);
}
*/

// void getPlate() 
// {
//   if (flag == 0 || flag == 2) {
//     flag = 1;
//  //   Motor19.spinToPosition(100,degrees);
//    Motor19.spinToPosition(100,degrees);
//   } else if (flag == 1) {
//     flag = 0;
    
//   }
// }
  void takePlate() 
  {
  if(Black_wheel == 0){
    Black_wheel = 1;
    Left_Give.stop();
    Right_Give.stop();
  }
    if (flag2 == 0 || flag2 == 1) 
    {
     flag2 = 2;
      Get_Plate.setVelocity(100,percent);
      Get_Plate.spin(reverse);
    }  
   
    else if (flag2 == 2)
    {
     flag2 = 0;
     Get_Plate.stop();
    }
  }

  void takePlate2() 
  {
   if(Black_wheel == 1){
    Black_wheel = 0;
    Left_Give.stop();
    Right_Give.stop();
  }
    if (flag2 == 0 || flag2 == 1) 
    {
     flag2 = 2;
      Get_Plate.setVelocity(100,percent);
      Get_Plate.spin(forward);
    }  
   
    else if (flag2 == 2)
    {
     flag2 = 0;
     Get_Plate.stop();
    }
  }


  void givePlate() 
{
  float velocity = 0.0;
  float fastspeed = 100;
  float lowspeed = 100;
 if (flag == 2||flag2 == 2) {
    flag = 0;
    flag2 = 0;
    Get_Plate.stop();
  }
  if (Black_wheel) {
    if(Controller1.ButtonB.pressing()){
    Left_Give.spin(forward,12.5,volt);
    Right_Give.spin(reverse,12.5,volt);
    }else{
    Left_Give.spin(forward,10.8,volt);
    Right_Give.spin(reverse,10.8,volt);
    }
    Black_wheel = false;
  }
  else {
    velocity = 0.0;
    Black_wheel = true;
    Left_Give.stop();
    Right_Give.stop();
  }
}

void zhuantong()
{
    if (tong == 0) 
    {
     tong = 2;
      Motor8.setVelocity(35,percent);
      Motor8.spin(reverse);
    }  
   
    else if (tong == 2)
    {
     tong = 0;
     Motor8.stop();
    }
}

void spins()
{
   Motor8.setVelocity(100,percent);
    Motor8.setPosition(0,degrees);
    Motor8.spin(reverse);
    wait(0.16,seconds);
    Motor8.stop();
   tong = 0;
}

void spins2()
{
   Motor8.setVelocity(100,percent);
    Motor8.setPosition(0,degrees);
    Motor8.spin(forward);
    wait(0.16,seconds);
    Motor8.stop();
  tong = 0;
}

void fire(){
  BeginFire.setVelocity(70.0, percent);
  // while (true) {
  //   if ((fabs(static_cast<float>(LeftFlyCircle.velocity(rpm))) > velocity - 2.0 && LeftFlyCircle.velocity(rpm) < velocity + 2.0) && (fabs(static_cast<float>(RightFlyCircle.velocity(rpm))) > velocity - 2.0 && RightFlyCircle.velocity(rpm) < velocity + 2.0)) {
      BeginFire.spin(reverse);
      wait(200,msec);
      BeginFire.spin(forward);
      wait(200,msec);
  BeginFire.stop();
    // }
  wait(5, msec);
  // }

}

void air_open()
{



}

void move()
{
  Controller1.Screen.print(Controller1.Axis3.position(percent));
  Controller1.Screen.clearLine();
  // Drivetrain.turn(left);
  float run_straight=0.0;
  float run_rotate=0.0;
  float  run_vertical = 0.0;
   run_straight=-Controller1.Axis3.position(percent)/2.0;
   run_rotate=-Controller1.Axis1.position(percent)/5.0;

   run_vertical = Controller1.Axis4.position(percent)/3.0;
  

  MOVE1.setVelocity(-run_straight+run_rotate-run_vertical,percent);
  rightMotorA.setVelocity(+run_straight-run_rotate+run_vertical,percent);

  MOVE2.setVelocity(+run_straight+run_rotate-run_vertical,percent);
  leftMotorA.setVelocity(-run_straight-run_rotate+run_vertical,percent);
  
  leftMotorB.setVelocity(-run_straight-run_rotate-run_vertical,percent);
  MOVE3_FO.setVelocity(-run_straight-run_rotate-run_vertical,percent);

  MOVE4.setVelocity(+run_straight-run_rotate-run_vertical,percent);
  rightMotorB.setVelocity(+run_straight-run_rotate-run_vertical,percent);

 
  MOVE1.spin(forward);
  rightMotorA.spin(reverse);
  MOVE2.spin(forward);
  leftMotorA.spin(forward);
  leftMotorB.spin(forward);
  MOVE3_FO.spin(forward);
  MOVE4.spin(forward);
  rightMotorB.spin(reverse);
}

void setMaxTorque(int x) {
  MOVE1.setMaxTorque(x, percent);
  MOVE2.setMaxTorque(x, percent);
  MOVE3_FO.setMaxTorque(x, percent);
  MOVE4.setMaxTorque(x, percent);
  leftMotorA.setMaxTorque(x, percent);
  leftMotorB.setMaxTorque(x, percent);
  rightMotorA.setMaxTorque(x, percent);
  rightMotorB.setMaxTorque(x, percent);
}

void move(int x, int y)
{
  setMaxTorque(70);
  // Drivetrain.turn(left);
  int run_straight=0;
  int run_rotate=0;
   run_straight=x * 2;
   run_rotate=y * 2;


  

  MOVE1.setVelocity(-run_straight+run_rotate,rpm);
  rightMotorA.setVelocity(+run_straight-run_rotate,rpm);

  MOVE2.setVelocity(+run_straight+run_rotate,rpm);
  leftMotorA.setVelocity(-run_straight-run_rotate,rpm);
  
  leftMotorB.setVelocity(-run_straight-run_rotate,rpm);
  MOVE3_FO.setVelocity(-run_straight-run_rotate,rpm);

  MOVE4.setVelocity(+run_straight-run_rotate,rpm);
  rightMotorB.setVelocity(+run_straight-run_rotate,rpm);

 
  MOVE1.spin(forward);
  rightMotorA.spin(reverse);
  MOVE2.spin(forward);
  leftMotorA.spin(forward);
  leftMotorB.spin(forward);
  MOVE3_FO.spin(forward);
  MOVE4.spin(forward);
  rightMotorB.spin(reverse);
}