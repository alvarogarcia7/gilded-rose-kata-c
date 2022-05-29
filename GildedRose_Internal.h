#ifndef GILDED_ROSE_KATA_GILDEDROSE_INTERNAL_H
#define GILDED_ROSE_KATA_GILDEDROSE_INTERNAL_H

#include <stdbool.h>
#include "GildedRose.h"

void decrease_sell_in(Item *item);
void increase_quality(Item *item);
void decrease_quality(Item *item);
bool is_expired(Item *item);

#endif //GILDED_ROSE_KATA_GILDEDROSE_INTERNAL_H
