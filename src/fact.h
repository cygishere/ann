/**
 * This header contains all functions related to activation.
 */
#ifndef _FACT_H_
#define _FACT_H_

typedef enum
{
  FACT_RELU,
} Fact;

float activate (Fact fact, float x);
float d_activate (Fact fact, float x);

#endif /* _FACT_H_ */
