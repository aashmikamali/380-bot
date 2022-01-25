/*
 * motors.c
 *
 *  Created on: Jul 26, 2021
 *      Author: amali
 */

/* Define to prevent recursive inclusion */
#ifndef __motors_H
#define __motors_H
#ifdef __cplusplus
 extern "C" {
#endif

 /* Includes */
#include "main.h"

 void RightInit(void);
 void LeftInit(void);
 void RightCW(uint32_t duty);
 void RightCCW(uint32_t duty);
 void RightOFF(void);
 void LeftCW(uint32_t duty);
 void LeftCCW(uint32_t duty);
 void LeftOFF(void);

#ifdef __cplusplus
}
#endif
#endif /* __motors_H */
