#include <string.h>
#include "GildedRose.h"
#include <stdio.h>
#include <stdbool.h>

void decrease_sell_in(Item *item);
void decrease_quality(Item *item);
void increase_quality(Item *item);

void update_quality_aged_brie(Item *item){
    increase_quality(item);

    decrease_sell_in(item);

    if (item->sellIn < 0)
    {
        increase_quality(item);
    }
}

void update_quality_backstage_passes(Item *item){
    if (item->quality < 50) {
        increase_quality(item);

        if (item->sellIn < 11) {
            increase_quality(item);
        }
        if (item->sellIn < 6) {
            increase_quality(item);
        }
    }

    decrease_sell_in(item);

    if (item->sellIn < 0)
    {
        item->quality = 0;
    }
}

void update_quality_sulfuras(Item *item) {
}

void update_quality_default(Item *item) {
    decrease_quality(item);

    decrease_sell_in(item);

    bool is_expired = item->sellIn < 0;
    if (is_expired)
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
Item*
init_item(Item* item, const char *name, int sellIn, int quality)
{
    item->sellIn = sellIn;
    item->quality = quality;
    item->name = strdup(name);
    item->update_quality = obtain_update_quality(item);

    return item;
}

extern char*
sprint_item(char* buffer, Item* item)
{
    sprintf(buffer, "%s, %d, %d", item->name, item->sellIn, item->quality);
}

void update_quality_single(Item *item) {
    item->update_quality(item);
}

void
update_quality(Item items[], int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        Item *item = &items[i];
        update_quality_single(item);
    }
}


void decrease_sell_in(Item *item) { item->sellIn = item->sellIn - 1; }

void increase_quality(Item *item) {
    if (item->quality < 50) {
        item->quality = item->quality + 1;
    }
}

void decrease_quality(Item *item) {
    if (item->quality > 0) {
        item->quality = item->quality - 1;
    }
}
