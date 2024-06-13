
/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: regulator.h
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

#ifndef regulator_h_
#define regulator_h_
#ifndef regulator_COMMON_INCLUDES_
#define regulator_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#endif                                 /* regulator_COMMON_INCLUDES_ */

#include "regulator_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T LIjevisenzor;                 /* '<Root>/LIjevi senzor' */
  real_T Desnisenzor;                  /* '<Root>/Desni senzor' */
} ExtU_regulator_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Lijevimotor;                  /* '<Root>/Lijevi motor' */
  real_T Desnimotor;                   /* '<Root>/Desni motor' */
} ExtY_regulator_T;

/* Real-time Model Data Structure */
struct tag_RTM_regulator_T {
  const char_T * volatile errorStatus;
};

/* External inputs (root inport signals with default storage) */
extern ExtU_regulator_T regulator_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_regulator_T regulator_Y;

/* Model entry point functions */
extern void regulator_initialize(void);
extern void regulator_step();
extern void regulator_terminate(void);

/* Real-time Model object */
extern RT_MODEL_regulator_T *const regulator_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'regulator'
 */
#endif                                 /* regulator_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */