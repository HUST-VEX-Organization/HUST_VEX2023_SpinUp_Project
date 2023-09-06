#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor Left_Give = motor(PORT4, ratio18_1, false);
motor Right_Give = motor(PORT3, ratio18_1, false);
controller Controller1 = controller(primary);
motor Get_Plate = motor(PORT16, ratio18_1, true);
motor Motor8 = motor(PORT8, ratio18_1, true);
motor MOVE1 = motor(PORT10, ratio18_1, true);
motor MOVE2 = motor(PORT1, ratio18_1, true);
motor MOVE3_FO = motor(PORT12, ratio18_1, true);
motor MOVE4 = motor(PORT19, ratio18_1, true);
motor leftMotorA = motor(PORT2, ratio18_1, true);
motor leftMotorB = motor(PORT11, ratio18_1, true);
motor_group LeftDriveSmart = motor_group(leftMotorA, leftMotorB);
motor rightMotorA = motor(PORT9, ratio18_1, false);
motor rightMotorB = motor(PORT20, ratio18_1, false);
motor_group RightDriveSmart = motor_group(rightMotorA, rightMotorB);
inertial DrivetrainInertial = inertial(PORT14);
smartdrive Drivetrain = smartdrive(LeftDriveSmart, RightDriveSmart, DrivetrainInertial, 319.19, 320, 40, mm, 1);
motor BeginFire = motor(PORT7, ratio18_1, false);
motor Air = motor(PORT5, ratio18_1, false);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  Brain.Screen.print("Device initialization...");
  Brain.Screen.setCursor(2, 1);
  // calibrate the drivetrain Inertial
  wait(200, msec);
  DrivetrainInertial.calibrate();
  Brain.Screen.print("Calibrating Inertial for Drivetrain");
  // wait for the Inertial calibration process to finish
  while (DrivetrainInertial.isCalibrating()) {
    wait(25, msec);
  }
  // reset the screen now that the calibration is complete
  Brain.Screen.clearScreen();
  Brain.Screen.setCursor(1,1);
  wait(50, msec);
  Brain.Screen.clearScreen();
}