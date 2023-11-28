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
motor Motor6 = motor(PORT6, false);
motor Motor5 = motor(PORT5, false);
controller Controller = controller();



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
      // check the ButtonRUp/ButtonRDown status to control Motor6
      if (Controller.ButtonRUp.pressing()) {
        Motor6.spin(forward);
        ControllerRightShoulderControlMotorsStopped = false;
      } else if (Controller.ButtonRDown.pressing()) {
        Motor6.spin(reverse);
        ControllerRightShoulderControlMotorsStopped = false;
      } else if (!ControllerRightShoulderControlMotorsStopped) {
        Motor6.stop();
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
void DirectionTest(){
  int dirtestnum;
  dirtestnum = dirtestnum++;
  Brain.Screen.print("BAP Console | DirectionTest()");
  printf("BAP.action.DirTest.Start | UIDN: %d", &dirtestnum);
  Motor6.spin(forward);
  wait(10, seconds);
  Motor6.stop();
  Motor6.spin(reverse);
  wait(10, seconds);
  Motor6.stop();
  Motor5.spin(forward);
  wait(10, seconds);
  Motor5.stop();
  Motor5.spin(reverse);
  wait(10, seconds);
  Motor5.stop();
  Motor6.spin(forward);
  Motor5.spin(forward);
  wait(10, seconds);
  Motor6.stop();
  Motor5.stop();
  Motor6.spin(reverse);
  Motor5.spin(reverse);
  wait(10, seconds);
  Motor6.stop();
  Motor5.stop();
  Motor6.spin(reverse);
  Motor5.spin(forward);
  wait(10, seconds);
  Motor6.stop();
  Motor5.stop();
  Motor6.spin(forward);
  Motor5.spin(reverse);
  wait(10, seconds);
  Motor6.stop();
  Motor5.stop();
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
  Brain.Screen.print("BAP Console | DEVICE IDLE");
  std::printf("Brendon's All-Purpose Console\n ");
  std::printf("Events:\n");
  while(foreverTrue == 1){
    if(Brain.buttonLeft.pressed == true){
      std::printf("brain.burronleft.press\n");
      DirectionTest();
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
