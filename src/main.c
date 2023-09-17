#include <errno.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ann.h"

int
main (void)
{
  Ann ann = ann_create (2, 3);
  layer_add_tail (ann, 4);
  ann_destroy (ann);
}
