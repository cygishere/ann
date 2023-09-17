#include "fact.h"
#include <math.h>

/* activation functions declarations */
static float relu (float x);
/* derivative of activation functions declarations */
static float d_relu (float x);

float
activate (Fact fact, float x)
{
  switch (fact)
    {
    case FACT_RELU:
      return (relu (x));
    default:
      return NAN;
    }
}

float
d_activate (Fact fact, float x)
{
  switch (fact)
    {
    case FACT_RELU:
      return (d_relu (x));
    default:
      return NAN;
    }
}

/* activation functions */
static float
relu (float x)
{
  return (x > 0 ? x : 0);
}

/* derivative of activation functions */
static float
d_relu (float x)
{
  return (x > 0 ? 1 : 0);
}
