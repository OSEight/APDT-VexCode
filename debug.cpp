#pragma region VEXcode Generated Robot Configuration
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include "vex.h"

using namespace vex;
brain Brain;
inertial BrainInertial = inertial();
motor Motor6 = motor(PORT6, false);
motor Motor5 = motor(PORT5, false);
controller Controller = controller();
bool RemoteControlCodeEnabled = true;
bool ControllerRightShoulderControlMotorsStopped = true;
int rc_auto_loop_function_Controller() {
  while (true) {
    if (RemoteControlCodeEnabled) {
      if (Controller.ButtonRUp.pressing()) {
        Motor6.spin(forward);
        ControllerRightShoulderControlMotorsStopped = false;
      } else if (Controller.ButtonRDown.pressing()) {
        Motor6.spin(reverse);
        ControllerRightShoulderControlMotorsStopped = false;
      } else if (!ControllerRightShoulderControlMotorsStopped) {
        Motor6.stop();
        ControllerRightShoulderControlMotorsStopped = true;
      }
    }
    wait(20, msec);
  }
  return 0;
}

task rc_auto_loop_task_Controller(rc_auto_loop_function_Controller);
#pragma endregion VEXcode Generated Robot Configuration

#include "iq_cpp.h"
int errornum = 0;
using namespace vex;
void DirectionTest() {
  int dirtestnum = 0;
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
  printf("BAP.action.DirTest.finished | Press Left Button to Continue\n or press Right Button to log INCOMPLETE");
  while (true) {
    if (Brain.buttonLeft.pressed()) {
      main(0);
    }
    if (Brain.buttonRight.pressed()) {
      error();
    }
  }
}

void error() {
  errornum++;
  printf("Error Number: %d", &errornum);
  main();
}

int main() {
  int foreverTrue = 1;
  Brain.Screen.print("BAP Console | DEVICE IDLE");
  printf("Brendon's All-Purpose Console\n ");
  printf("Events:\n");
  while (foreverTrue == 1) {
    if (Brain.buttonLeft.pressed == true) {
      printf("brain.burronleft.press\n");
      DirectionTest();
    }
    if (Controller.ButtonLUp.pressing == true) {
      printf("Controller.Insider.Disabled");
    }
    if (Controller.ButtonRUp.pressing == true) {
      printf("Controller.Insider.Disabled");
    }
    if (Controller.ButtonL3.pressing == true) {
      printf("Controller.Insider.Disabled");
    }
    if (Controller.ButtonL3.pressing == true) {
      printf("Controller.Insider.Disabled");
    }
    if (Controller.ButtonL3.pressing == true) {
      printf("Controller.Insider.Disabled");
    }
    if (Controller.ButtonR3.pressing == true) {
      printf("Controller.Insider.Disabled");
    }
  }
}
