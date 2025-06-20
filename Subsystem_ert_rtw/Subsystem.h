//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Subsystem.h
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
#ifndef Subsystem_h_
#define Subsystem_h_
#include <cmath>
#include "rtwtypes.h"
#include "rtw_modelmap.h"
#define Subsystem_M                    (rtM)
#ifndef SS_UINT64
#define SS_UINT64                      17
#endif

#ifndef SS_INT64
#define SS_INT64                       18
#endif

// Function to get C API Model Mapping Static Info
extern const rtwCAPI_ModelMappingStaticInfo*
  Subsystem_GetCAPIStaticMap(void);
extern "C"
{
  static real_T rtGetNaN(void);
  static real32_T rtGetNaNF(void);
}                                      // extern "C"

extern "C"
{
  extern real_T rtInf;
  extern real_T rtMinusInf;
  extern real_T rtNaN;
  extern real32_T rtInfF;
  extern real32_T rtMinusInfF;
  extern real32_T rtNaNF;
  static boolean_T rtIsInf(real_T value);
  static boolean_T rtIsInfF(real32_T value);
  static boolean_T rtIsNaN(real_T value);
  static boolean_T rtIsNaNF(real32_T value);
}                                      // extern "C"

// Class declaration for model Subsystem
class Subsystem final
{
  // public data and function members
 public:
  // Block signals and states (default storage) for system '<Root>'
  struct DW {
    real_T headway;                    // '<S4>/Sum'
    real_T TTC;                        // '<S4>/Divide3'
    real_T FCWstoppingTime;            // '<S3>/Sum1'
    real_T PB1stoppingTime;            // '<S3>/Sum2'
    real_T PB2stoppingTime;            // '<S3>/Sum3'
    real_T FBstoppingTime;             // '<S3>/Sum4'
    uint8_T Delay_DSTATE;              // '<S1>/Delay'
    uint8_T is_active_c5_Subsystem;    // '<S1>/AEBLogic'
    uint8_T is_c5_Subsystem;           // '<S1>/AEBLogic'
  };

  // External inputs (root inport signals with default storage)
  struct ExtU {
    real_T MIODistance;                // '<Root>/MIO Distance'
    real_T MIOVelocity;                // '<Root>/MIO Velocity'
    real_T ego_velocity;               // '<Root>/ego_velocity'
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY {
    boolean_T egoCarStop;              // '<Root>/egoCarStop'
    uint8_T FCWActivate;               // '<Root>/FCW Activate'
    real_T Deceleration;               // '<Root>/Deceleration'
    uint8_T AEBStatus;                 // '<Root>/AEB Status'
  };

  // Real-time Model Data Structure
  struct RT_MODEL {
    const char_T * volatile errorStatus;

    //
    //  DataMapInfo:
    //  The following substructure contains information regarding
    //  structures generated in the model's C API.

    struct DataMapInfo_T {
      rtwCAPI_ModelMappingInfo mmi;
      void* dataAddress[10];
      int32_T* vardimsAddress[10];
      RTWLoggingFcnPtr loggingPtrs[10];
    };

    DataMapInfo_T DataMapInfo;
    Subsystem::RT_MODEL::DataMapInfo_T getDataMapInfo() const;
    void setDataMapInfo(Subsystem::RT_MODEL::DataMapInfo_T aDataMapInfo);
    const char_T* getErrorStatus() const;
    void setErrorStatus(const char_T* const volatile aErrorStatus);
  };

  // Copy Constructor
  Subsystem(Subsystem const&) = delete;

  // Assignment Operator
  Subsystem& operator= (Subsystem const&) & = delete;

  // Move Constructor
  Subsystem(Subsystem &&) = delete;

  // Move Assignment Operator
  Subsystem& operator= (Subsystem &&) = delete;

  // Real-Time Model get method
  Subsystem::RT_MODEL * getRTM();

  // External inputs
  ExtU rtU;

  // External outputs
  ExtY rtY;

  // Block states
  DW rtDW;

  // model initialize function
  void initialize();

  // model step function
  void step();

  // Constructor
  Subsystem();

  // Destructor
  ~Subsystem();

  // private data and function members
 private:
  // Real-Time Model
  RT_MODEL rtM;
};

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Note that this particular code originates from a subsystem build,
//  and has its own system numbers different from the parent model.
//  Refer to the system hierarchy for this subsystem below, and use the
//  MATLAB hilite_system command to trace the generated code back
//  to the parent model.  For example,
//
//  hilite_system('AEBController/Subsystem')    - opens subsystem AEBController/Subsystem
//  hilite_system('AEBController/Subsystem/Kp') - opens and selects block Kp
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'AEBController'
//  '<S1>'   : 'AEBController/Subsystem'
//  '<S2>'   : 'AEBController/Subsystem/AEBLogic'
//  '<S3>'   : 'AEBController/Subsystem/StoppingTimeCalculation'
//  '<S4>'   : 'AEBController/Subsystem/TTCCalculation'

#endif                                 // Subsystem_h_

//
// File trailer for generated code.
//
// [EOF]
//
