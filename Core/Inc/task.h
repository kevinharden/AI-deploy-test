#ifndef __TASK_H__
#define __TASK_H__
#include "stdint.h"


void My_delay_us(uint32_t n);
void My_delay_ms(uint32_t t);

void HMISendstart(void);
void HMISends(uint8_t *buf1);
void HMISendb(uint8_t k);
void Camera_Init(void);
void copy_rgb_to_in_data();
int ai_Init(void);
int aiRun(const void *in_data, void *out_data);
#endif /*__ TASK_H__ */
