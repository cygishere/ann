#include "ann.h"
#include <stdlib.h>

Ann
ann_create (u32 nin, u32 nout)
{
  Ann ann = malloc (sizeof *ann);
  ann->head = malloc (sizeof *ann->head);
  ann->head->na = nin;
  ann->head->next = NULL;
  ann->head->prev = NULL;
  ann->head->zs = NULL;
  ann->head->as = NULL;
  ann->head->ws = NULL;
  ann->head->bs = NULL;
  ann->head->fas = NULL;

  ann->tail = malloc (sizeof *ann->tail);
  ann->tail->na = nout;
  ann->tail->next = NULL;
  ann->tail->prev = ann->head;
  ann->tail->zs = malloc (sizeof *ann->tail->zs * ann->tail->na);
  ann->tail->as = malloc (sizeof *ann->tail->as * ann->tail->na);
  ann->tail->bs = malloc (sizeof *ann->tail->bs * ann->tail->na);
  ann->tail->fas = malloc (sizeof *ann->tail->fas * ann->tail->na);
  ann->tail->ws
      = malloc (sizeof *ann->tail->ws * (ann->tail->na * ann->tail->prev->na));
  ann->head->next = ann->tail;
  return ann;
}

void
ann_destroy (Ann ann)
{
  Layer layer = ann->tail;
  while (layer->prev != NULL)
    {
      free (layer->zs);
      free (layer->as);
      free (layer->bs);
      free (layer->fas);
      free (layer->ws);
      layer = layer->prev;
      free (layer->next);
    }
  free (layer);
  free (ann);
}

Layer
layer_add_tail (Ann ann, u32 na)
{
  Layer layer = malloc (sizeof *layer);
  layer->na = na;
  layer->prev = ann->tail;
  layer->next = NULL;
  layer->zs = malloc (sizeof *layer->zs * layer->na);
  layer->as = malloc (sizeof *layer->as * layer->na);
  layer->bs = malloc (sizeof *layer->bs * layer->na);
  layer->fas = malloc (sizeof *layer->fas * layer->na);
  layer->ws = malloc (sizeof *layer->ws * (layer->na * layer->prev->na));

  layer->prev->next = layer;
  ann->tail = layer;

  return layer;
}
