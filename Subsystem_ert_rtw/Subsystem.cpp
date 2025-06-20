//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Subsystem.cpp
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
#include <cmath>
#include "Subsystem_capi.h"
#include "cmath"
#include "limits"

// Named constants for Chart: '<S1>/AEBLogic'
const uint8_T IN_Default{ 1U };

const uint8_T IN_FCW{ 2U };

const uint8_T IN_Full_Braking{ 3U };

const uint8_T IN_Partial_Braking1{ 4U };

const uint8_T IN_Partial_Braking2{ 5U };

extern "C"
{
  real_T rtNaN { -std::numeric_limits<real_T>::quiet_NaN() };

  real_T rtInf { std::numeric_limits<real_T>::infinity() };

  real_T rtMinusInf { -std::numeric_limits<real_T>::infinity() };

  real32_T rtNaNF { -std::numeric_limits<real32_T>::quiet_NaN() };

  real32_T rtInfF { std::numeric_limits<real32_T>::infinity() };

  real32_T rtMinusInfF { -std::numeric_limits<real32_T>::infinity() };
}

extern "C"
{
  // Return rtNaN needed by the generated code.
  static real_T rtGetNaN(void)
  {
    return rtNaN;
  }

  // Return rtNaNF needed by the generated code.
  static real32_T rtGetNaNF(void)
  {
    return rtNaNF;
  }
}

extern "C"
{
  // Test if value is infinite
  static boolean_T rtIsInf(real_T value)
  {
    return std::isinf(value);
  }

  // Test if single-precision value is infinite
  static boolean_T rtIsInfF(real32_T value)
  {
    return std::isinf(value);
  }

  // Test if value is not a number
  static boolean_T rtIsNaN(real_T value)
  {
    return std::isnan(value);
  }

  // Test if single-precision value is not a number
  static boolean_T rtIsNaNF(real32_T value)
  {
    return std::isnan(value);
  }
}

// Model step function
void Subsystem::step()
{
  real_T rtb_Divide11;
  real_T u0;
  uint8_T rtb_AEBstatus;
  boolean_T rtb_AND;

  // Outputs for Atomic SubSystem: '<Root>/Subsystem'
  // Sum: '<S4>/Sum' incorporates:
  //   Constant: '<S4>/const1'
  //   Inport: '<Root>/MIO Distance'

  rtDW.headway = rtU.MIODistance - 3.7;

  // Abs: '<S4>/Abs' incorporates:
  //   Inport: '<Root>/MIO Velocity'

  u0 = std::abs(rtU.MIOVelocity);

  // Saturate: '<S4>/Saturation'
  if (u0 > 100.0) {
    u0 = 100.0;
  } else if (u0 < 0.01) {
    u0 = 0.01;
  }

  // Product: '<S4>/Divide3' incorporates:
  //   Saturate: '<S4>/Saturation'

  rtDW.TTC = rtDW.headway / u0;

  // Signum: '<S4>/Sign' incorporates:
  //   Inport: '<Root>/MIO Velocity'

  if (std::isnan(rtU.MIOVelocity)) {
    u0 = (rtNaN);
  } else if (rtU.MIOVelocity < 0.0) {
    u0 = -1.0;
  } else {
    u0 = (rtU.MIOVelocity > 0.0);
  }

  // Product: '<S4>/Divide11' incorporates:
  //   Signum: '<S4>/Sign'

  rtb_Divide11 = rtDW.TTC * u0;

  // Sum: '<S3>/Sum1' incorporates:
  //   Constant: '<S3>/const3'
  //   Constant: '<S3>/const6'
  //   Inport: '<Root>/ego_velocity'
  //   Product: '<S3>/Divide12'

  rtDW.FCWstoppingTime = rtU.ego_velocity / 4.0 + 1.2;

  // Sum: '<S3>/Sum2' incorporates:
  //   Constant: '<S1>/const6'
  //   Constant: '<S3>/const7'
  //   Inport: '<Root>/ego_velocity'
  //   Product: '<S3>/Divide5'

  rtDW.PB1stoppingTime = rtU.ego_velocity / 3.8 + 0.08;

  // Sum: '<S3>/Sum3' incorporates:
  //   Constant: '<S1>/const4'
  //   Constant: '<S3>/const7'
  //   Inport: '<Root>/ego_velocity'
  //   Product: '<S3>/Divide3'

  rtDW.PB2stoppingTime = rtU.ego_velocity / 5.3 + 0.08;

  // Sum: '<S3>/Sum4' incorporates:
  //   Constant: '<S1>/const5'
  //   Constant: '<S3>/const7'
  //   Inport: '<Root>/ego_velocity'
  //   Product: '<S3>/Divide1'

  rtDW.FBstoppingTime = rtU.ego_velocity / 9.8 + 0.08;

  // Logic: '<S1>/AND' incorporates:
  //   Constant: '<S1>/const3'
  //   Delay: '<S1>/Delay'
  //   Inport: '<Root>/ego_velocity'
  //   RelationalOperator: '<S1>/Relational Operator1'

  rtb_AND = ((rtU.ego_velocity <= 0.27777777777777779) && (rtDW.Delay_DSTATE !=
              0));

  // Chart: '<S1>/AEBLogic'
  if (rtDW.is_active_c5_Subsystem == 0) {
    rtDW.is_active_c5_Subsystem = 1U;
    rtDW.is_c5_Subsystem = IN_Default;
    rtb_AEBstatus = 0U;

    // Outport: '<Root>/FCW Activate'
    rtY.FCWActivate = 0U;

    // Outport: '<Root>/Deceleration'
    rtY.Deceleration = 0.0;
  } else {
    switch (rtDW.is_c5_Subsystem) {
     case IN_Default:
      rtb_AEBstatus = 0U;

      // Outport: '<Root>/FCW Activate'
      rtY.FCWActivate = 0U;
      if ((std::abs(rtb_Divide11) < rtDW.FCWstoppingTime) && (rtb_Divide11 < 0.0))
      {
        rtDW.is_c5_Subsystem = IN_FCW;

        // Outport: '<Root>/FCW Activate'
        rtY.FCWActivate = 1U;

        // Outport: '<Root>/Deceleration'
        rtY.Deceleration = 0.0;
      }
      break;

     case IN_FCW:
      rtb_AEBstatus = 0U;

      // Outport: '<Root>/FCW Activate'
      rtY.FCWActivate = 1U;
      u0 = std::abs(rtb_Divide11);
      if ((u0 < rtDW.PB1stoppingTime) && (rtb_Divide11 < 0.0)) {
        rtDW.is_c5_Subsystem = IN_Partial_Braking1;
        rtb_AEBstatus = 1U;

        // Outport: '<Root>/Deceleration' incorporates:
        //   Constant: '<S1>/const6'

        rtY.Deceleration = 3.8;
      } else if (u0 >= 1.2 * rtDW.FCWstoppingTime) {
        rtDW.is_c5_Subsystem = IN_Default;

        // Outport: '<Root>/FCW Activate'
        rtY.FCWActivate = 0U;

        // Outport: '<Root>/Deceleration'
        rtY.Deceleration = 0.0;
      }
      break;

     case IN_Full_Braking:
      rtb_AEBstatus = 3U;

      // Outport: '<Root>/FCW Activate'
      rtY.FCWActivate = 1U;
      if (rtb_AND) {
        rtDW.is_c5_Subsystem = IN_Default;
        rtb_AEBstatus = 0U;

        // Outport: '<Root>/FCW Activate'
        rtY.FCWActivate = 0U;

        // Outport: '<Root>/Deceleration'
        rtY.Deceleration = 0.0;
      }
      break;

     case IN_Partial_Braking1:
      rtb_AEBstatus = 1U;

      // Outport: '<Root>/FCW Activate'
      rtY.FCWActivate = 1U;
      if ((std::abs(rtb_Divide11) < rtDW.PB2stoppingTime) && (rtb_Divide11 < 0.0))
      {
        rtDW.is_c5_Subsystem = IN_Partial_Braking2;
        rtb_AEBstatus = 2U;

        // Outport: '<Root>/Deceleration' incorporates:
        //   Constant: '<S1>/const4'

        rtY.Deceleration = 5.3;
      } else if (rtb_AND) {
        rtDW.is_c5_Subsystem = IN_Default;
        rtb_AEBstatus = 0U;

        // Outport: '<Root>/FCW Activate'
        rtY.FCWActivate = 0U;

        // Outport: '<Root>/Deceleration'
        rtY.Deceleration = 0.0;
      }
      break;

     default:
      // case IN_Partial_Braking2:
      rtb_AEBstatus = 2U;

      // Outport: '<Root>/FCW Activate'
      rtY.FCWActivate = 1U;
      if ((std::abs(rtb_Divide11) < rtDW.FBstoppingTime) && (rtb_Divide11 < 0.0))
      {
        rtDW.is_c5_Subsystem = IN_Full_Braking;
        rtb_AEBstatus = 3U;

        // Outport: '<Root>/Deceleration' incorporates:
        //   Constant: '<S1>/const5'

        rtY.Deceleration = 9.8;
      } else if (rtb_AND) {
        rtDW.is_c5_Subsystem = IN_Default;
        rtb_AEBstatus = 0U;

        // Outport: '<Root>/FCW Activate'
        rtY.FCWActivate = 0U;

        // Outport: '<Root>/Deceleration'
        rtY.Deceleration = 0.0;
      }
      break;
    }
  }

  // End of Chart: '<S1>/AEBLogic'

  // Update for Delay: '<S1>/Delay'
  rtDW.Delay_DSTATE = rtb_AEBstatus;

  // End of Outputs for SubSystem: '<Root>/Subsystem'

  // Outport: '<Root>/egoCarStop'
  rtY.egoCarStop = rtb_AND;

  // Outport: '<Root>/AEB Status'
  rtY.AEBStatus = rtb_AEBstatus;
}

// Model initialize function
void Subsystem::initialize()
{
  // Registration code

  // Initialize DataMapInfo substructure containing ModelMap for C API
  Subsystem_InitializeDataMapInfo((&rtM), &rtDW);
}

Subsystem::RT_MODEL::DataMapInfo_T Subsystem::RT_MODEL::getDataMapInfo() const
{
  return DataMapInfo;
}

void Subsystem::RT_MODEL::setDataMapInfo(Subsystem::RT_MODEL::DataMapInfo_T
  aDataMapInfo)
{
  DataMapInfo = aDataMapInfo;
}

const char_T* Subsystem::RT_MODEL::getErrorStatus() const
{
  return (errorStatus);
}

void Subsystem::RT_MODEL::setErrorStatus(const char_T* const volatile
  aErrorStatus)
{
  (errorStatus = aErrorStatus);
}

// Constructor
Subsystem::Subsystem() :
  rtU(),
  rtY(),
  rtDW(),
  rtM()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
Subsystem::~Subsystem() = default;

// Real-Time Model get method
Subsystem::RT_MODEL * Subsystem::getRTM()
{
  return (&rtM);
}

//
// File trailer for generated code.
//
// [EOF]
//
