#pragma region VEXcode Generated Robot Configuration
// Make sure all required headers are included.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>


#include "vex.h"

using namespace vex;

// Brain should be defined by default
brain Brain;


// START IQ MACROS
#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)
// END IQ MACROS


// Robot configuration code.
inertial BrainInertial = inertial();
motor Right = motor(PORT6, false);
motor Left = motor(PORT5, false);
controller Controller = controller();
motor Claw = motor(PORT4, false);
motor ClawUpandDown = motor(PORT10, false);



// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;
// define variables used for controlling motors based on controller inputs
bool ControllerRightShoulderControlMotorsStopped = true;

// define a task that will handle monitoring inputs from Controller
int rc_auto_loop_function_Controller() {
  // process the controller input every 20 milliseconds
  // update the motors based on the input values
  while(true) {
    if(RemoteControlCodeEnabled) {
      // check the ButtonRUp/ButtonRDown status to control Right
      if (Controller.ButtonRUp.pressing()) {
        Right.spin(forward);
        ControllerRightShoulderControlMotorsStopped = false;
      } else if (Controller.ButtonRDown.pressing()) {
        Right.spin(reverse);
        ControllerRightShoulderControlMotorsStopped = false;
      } else if (!ControllerRightShoulderControlMotorsStopped) {
        Right.stop();
        // set the toggle so that we don't constantly tell the motor to stop when the buttons are released
        ControllerRightShoulderControlMotorsStopped = true;
      }
    }
    // wait before repeating the process
    wait(20, msec);
  }
  return 0;
}

task rc_auto_loop_task_Controller(rc_auto_loop_function_Controller);

#pragma endregion VEXcode Generated Robot Configuration


#include "iq_cpp.h"
int errornum = 0;
using namespace vex;
void stopAllMotors(){
  Right.stop();
  Left.stop();
  ClawUpandDown.stop();
  Claw.stop();
}
void ClawTest(){
  Claw.spin(forward);
  ClawUpandDown.spin(forward); // Should open the claw and move it up.
  wait(10, seconds);
  stopAllMotors(); // Now added for accsessiblity - V1.2 Salmon
}
void DirectionTest(){
  int dirtestnum;
  dirtestnum = dirtestnum++;
  Brain.Screen.print("BAP Console | DirectionTest()");
  printf("BAP.action.DirTest.Start | UIDN: %d", &dirtestnum);
  Right.spin(forward);
  wait(10, seconds);
  Right.stop();
  Right.spin(reverse);
  wait(10, seconds);
  Right.stop();
  Left.spin(forward);
  wait(10, seconds);
  Left.stop();
  Left.spin(reverse);
  wait(10, seconds);
  Left.stop();
  Right.spin(forward);
  Left.spin(forward);
  wait(10, seconds);
  Right.stop();
  Left.stop();
  Right.spin(reverse);
  Left.spin(reverse);
  wait(10, seconds);
  Right.stop();
  Left.stop();
  Right.spin(reverse);
  Left.spin(forward);
  wait(10, seconds);
  Right.stop();
  Left.stop();
  Right.spin(forward);
  Left.spin(reverse);
  wait(10, seconds);
  Right.stop();
  Left.stop();
  Brain.Screen.print("\nTEST FINISHED");
  std::printf("BAP.action.DirTest.finished | Press Left Button to Continue\n or press Right Button to log INCOMPLETE");
  while (true){
    if (Brain.buttonLeft.pressed() = True){
      main(0);
    }
    if (Brain.buttonRight.pressed() = True){
      error();
    }
  }
}
void error(){
  errornum = errornum++;
  std::printf("Error Number: %d", &errornum);
  main();
}
int main() {
  int foreverTrue = 1;
  int modulenum;
  Brain.Screen.print("BAP Console | DEVICE IDLE");
  std::printf("Brendon's All-Purpose Console\n ");
  std::printf("ENTER MODULE NUMBER: ");
  std::scanf("%d", &modulenum);
  if(modulenum == 1){
    std::printf("SPEED BOT");
  } else if (modulenum == 2){
    std::printf("CLAW BOT");
  } else {
    std::printf("NOT IMPLEMENTED OR INCORRECT");
  }
  std::printf("Events:\n");
  while(foreverTrue == 1){
    if(Brain.buttonLeft.pressed == true){
      if(modulenum == 1){
        std::printf("brain.buttonleft.press\n");
        DirectionTest();
      } else if (modulenume == 2){
        std::printf("brain.buttonleft.press\n");
      }
    }
    if(Controller.ButtonLUp.pressing == True){
      std::printf("Controller.Insider.Disabled")
    }
    if(Controller.ButtonRUp.pressing == True){
      std::printf("Controller.Insider.Disabled")
    }
    if(Controller.ButtonL3.pressing == True){
      std::printf("Controller.Insider.Disabled")
    }
    if(Controller.ButtonL3.pressing == True){
      std::printf("Controller.Insider.Disabled")
    }
    if(Controller.ButtonL3.pressing == True){
      std::printf("Controller.Insider.Disabled")
    }
    if(Controller.ButtonR3.pressing == True){
      std::printf("Controller.Insider.Disabled")
    }
  }
}
