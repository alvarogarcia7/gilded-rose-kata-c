#include "GildedRose.h"
#include <string.h>
#include "GildedRose_Quality.h"
#include "GildedRose_Internal.h"

void update_quality_aged_brie(Item *item){
    increase_quality(item);

    decrease_sell_in(item);

    if (is_expired(item))
    {
        increase_quality(item);
    }
}

void update_quality_backstage_passes(Item *item){
    increase_quality(item);

    if (item->sellIn < 11) {
        increase_quality(item);
    }
    if (item->sellIn < 6) {
        increase_quality(item);
    }

    decrease_sell_in(item);

    if (is_expired(item))
    {
        item->quality = 0;
    }
}

void update_quality_sulfuras(Item *item) {
}

void update_quality_default(Item *item) {
    decrease_quality(item);

    decrease_sell_in(item);

    if (is_expired(item))
    {
        decrease_quality(item);
    }
}

void *obtain_update_quality(Item *item) {
    if (strcmp(item->name, "Aged Brie") == 0) {
        return &update_quality_aged_brie;
    } else if (strcmp(item->name, "Backstage passes to a TAFKAL80ETC concert") == 0) {
        return &update_quality_backstage_passes;
    } else if (!strcmp(item->name, "Sulfuras, Hand of Ragnaros")) {
        return &update_quality_sulfuras;
    }
    return &update_quality_default;
}
