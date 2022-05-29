#include <stdbool.h>
#include <stdio.h>
#include "GildedRose_Quality.h"
#include "GildedRose.h"
#include <string.h>
#include "GildedRose_Internal.h"


void decrease_sell_in(Item *item) { item->sellIn = item->sellIn - 1; }

void increase_quality(Item *item) {
    const int MAXIMUM_QUALITY = 50;
    if (item->quality < MAXIMUM_QUALITY) {
        item->quality = item->quality + 1;
    }
}

void decrease_quality(Item *item) {
    if (item->quality > 0) {
        item->quality = item->quality - 1;
    }
}

bool is_expired(Item *item) {
    return item->sellIn < 0;
}