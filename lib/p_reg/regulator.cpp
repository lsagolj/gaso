
/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: regulator.c
 *
 * Code generated for Simulink model 'regulator'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Fri May 31 22:28:02 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "regulator.h"
#include "rtwtypes.h"
#include <stdio.h>
/* External inputs (root inport signals with default storage) */
ExtU_regulator_T regulator_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_regulator_T regulator_Y;

/* Real-time model */
static RT_MODEL_regulator_T regulator_M_;
RT_MODEL_regulator_T *const regulator_M = &regulator_M_;

/* Model step function */
void regulator_step()
{
  real_T rtb_Sum1;

  /* Gain: '<Root>/Gain' incorporates:
   *  Inport: '<Root>/Desni senzor'
   *  Inport: '<Root>/LIjevi senzor'
   *  Sum: '<Root>/Sum'
   */
  rtb_Sum1 = (regulator_U.LIjevisenzor - regulator_U.Desnisenzor) * 0.1;
  /* Saturate: '<Root>/Saturation' incorporates:
   *  Constant: '<Root>/Constant'
   *  Sum: '<Root>/Sum2'
   */
  if (0.2 - rtb_Sum1 > 1.0) {
    /* Outport: '<Root>/Lijevi motor' */
    regulator_Y.Lijevimotor = 1.0;
  } else if (0.2 - rtb_Sum1 < 0.0) {
    /* Outport: '<Root>/Lijevi motor' */
    regulator_Y.Lijevimotor = 0.0;
  } else {
    /* Outport: '<Root>/Lijevi motor' */
    regulator_Y.Lijevimotor = 0.2 - rtb_Sum1;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Saturate: '<Root>/Saturation1' incorporates:
   *  Constant: '<Root>/Constant'
   *  Sum: '<Root>/Sum1'
   */
  if (rtb_Sum1 + 0.2 > 1.0) {
    /* Outport: '<Root>/Desni motor' */
    regulator_Y.Desnimotor = 1.0;
  } else if (rtb_Sum1 + 0.2 < 0.0) {
    /* Outport: '<Root>/Desni motor' */
    regulator_Y.Desnimotor = 0.0;
  } else {
    /* Outport: '<Root>/Desni motor' */
    regulator_Y.Desnimotor = rtb_Sum1 + 0.2;
  }

  /* End of Saturate: '<Root>/Saturation1' */
}

/* Model initialize function */
void regulator_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void regulator_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */