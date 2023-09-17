#ifndef _ANN_H_
#define _ANN_H_

#include "fact.h"
#include "types.h"

typedef struct Layer_t *Layer;
typedef struct Ann_t *Ann;

struct Layer_t
{
  u32 na;
  Layer prev;
  Layer next;

  float *zs;
  float *as;

  float *ws;
  float *bs;
  Fact *fas; /* activation functions */
};

struct Ann_t
{
  Layer head;
  Layer tail;
};

Ann ann_create (u32 nin, u32 nout);
void ann_destroy (Ann ann);
Layer layer_add_tail (Ann ann, u32 na);

#endif /* _ANN_H_ */
