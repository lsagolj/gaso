
/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled.c
 *
 * Code generated for Simulink model 'untitled'.
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

#include "untitled.h"
#include "rtwtypes.h"

/* External inputs (root inport signals with default storage) */
ExtU_untitled_T untitled_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_untitled_T untitled_Y;

/* Real-time model */
static RT_MODEL_untitled_T untitled_M_;
RT_MODEL_untitled_T *const untitled_M = &untitled_M_;

/* Model step function */
void untitled_step(void)
{
  real_T rtb_Sum1;

  /* Gain: '<Root>/Gain' incorporates:
   *  Inport: '<Root>/Desni senzor'
   *  Inport: '<Root>/LIjevi senzor'
   *  Sum: '<Root>/Sum'
   */
  rtb_Sum1 = (untitled_U.LIjevisenzor - untitled_U.Desnisenzor) * 0.1;

  /* Saturate: '<Root>/Saturation' incorporates:
   *  Constant: '<Root>/Constant'
   *  Sum: '<Root>/Sum2'
   */
  if (0.2 - rtb_Sum1 > 1.0) {
    /* Outport: '<Root>/Lijevi motor' */
    untitled_Y.Lijevimotor = 1.0;
  } else if (0.2 - rtb_Sum1 < 0.0) {
    /* Outport: '<Root>/Lijevi motor' */
    untitled_Y.Lijevimotor = 0.0;
  } else {
    /* Outport: '<Root>/Lijevi motor' */
    untitled_Y.Lijevimotor = 0.2 - rtb_Sum1;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Saturate: '<Root>/Saturation1' incorporates:
   *  Constant: '<Root>/Constant'
   *  Sum: '<Root>/Sum1'
   */
  if (rtb_Sum1 + 0.2 > 1.0) {
    /* Outport: '<Root>/Desni motor' */
    untitled_Y.Desnimotor = 1.0;
  } else if (rtb_Sum1 + 0.2 < 0.0) {
    /* Outport: '<Root>/Desni motor' */
    untitled_Y.Desnimotor = 0.0;
  } else {
    /* Outport: '<Root>/Desni motor' */
    untitled_Y.Desnimotor = rtb_Sum1 + 0.2;
  }

  /* End of Saturate: '<Root>/Saturation1' */
}

/* Model initialize function */
void untitled_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void untitled_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
has popup