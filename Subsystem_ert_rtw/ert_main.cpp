//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ert_main.cpp
//
// Code generated for Simulink model 'Subsystem'.
//
// Model version                  : 9.2
// Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
// C/C++ source code generated on : Wed Apr 16 17:41:16 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: Atmel->AVR
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#include "Subsystem.h"
#include "rtwtypes.h"
#include "MW_target_hardware_resources.h"

static Subsystem rtObj;                // Instance of model class
volatile int IsrOverrun = 0;
static boolean_T OverrunFlag = 0;
void rt_OneStep(void)
{
  // Check for overrun. Protect OverrunFlag against preemption
  if (OverrunFlag++) {
    IsrOverrun = 1;
    OverrunFlag--;
    return;
  }

#ifndef _MW_ARDUINO_LOOP_

  sei();

#endif;

  rtObj.step();

  // Get model outputs here
#ifndef _MW_ARDUINO_LOOP_

  cli();

#endif;

  OverrunFlag--;
}

volatile boolean_T stopRequested;
volatile boolean_T runModel;
int main(void)
{
  float modelBaseRate = 0.05;
  float systemClock = 0;

  // Initialize variables
  stopRequested = false;
  runModel = false;
  init();
  MW_Arduino_Init();
  rtObj.getRTM()->setErrorStatus(0);
  initialize();
  cli();
  configureArduinoAVRTimer();
  runModel =
    rtObj.getRTM()->getErrorStatus() == (nullptr);

#ifndef _MW_ARDUINO_LOOP_

  sei();

#endif;

  sei ();
  while (runModel) {
    stopRequested = !(
                      rtObj.getRTM()->getErrorStatus() == (nullptr));
    runModel = !(stopRequested);
    MW_Arduino_Loop();
  }

  cli();
  return 0;
}

//
// File trailer for generated code.
//
// [EOF]
//
