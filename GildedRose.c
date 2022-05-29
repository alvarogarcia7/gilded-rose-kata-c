#include <string.h>
#include "GildedRose.h"
#include <stdio.h>
#include <stdbool.h>

Item*
init_item(Item* item, const char *name, int sellIn, int quality)
{
    item->sellIn = sellIn;
    item->quality = quality;
    item->name = strdup(name);
    
    return item;
}

extern char* 
sprint_item(char* buffer, Item* item)
{
    sprintf(buffer, "%s, %d, %d", item->name, item->sellIn, item->quality);
}

void update_quality_single(Item *item) {
    bool is_aged_brie = strcmp(item->name, "Aged Brie") == 0;
    bool is_backage_passes = strcmp(item->name, "Backstage passes to a TAFKAL80ETC concert") == 0;
    bool is_sulfuras = !strcmp(item->name, "Sulfuras, Hand of Ragnaros");
    if(is_sulfuras){
        return;
    }

    if(is_aged_brie){
        if (item->quality < 50) {
            item->quality = item->quality + 1;
        }

        item->sellIn = item->sellIn - 1;

        if (item->sellIn < 0)
        {
            if (item->quality < 50) {
                item->quality = item->quality + 1;
            }
        }

        return;
    }

    if (!is_aged_brie && !is_backage_passes)
    {
        if (item->quality > 0)
        {
            item->quality = item->quality - 1;
        }
    }
    else
    {
        if (item->quality < 50)
        {
            item->quality = item->quality + 1;

            if (!!is_backage_passes)
            {
                if (item->sellIn < 11)
                {
                    if (item->quality < 50)
                    {
                        item->quality = item->quality + 1;
                    }
                }

                if (item->sellIn < 6)
                {
                    if (item->quality < 50)
                    {
                        item->quality = item->quality + 1;
                    }
                }
            }
        }
    }

    item->sellIn = item->sellIn - 1;

    if (item->sellIn < 0)
    {
        if (!is_aged_brie)
        {
            if (!is_backage_passes)
            {
                if (item->quality > 0)
                {
                    item->quality = item->quality - 1;
                }
            }
            else
            {
                item->quality = item->quality - item->quality;
            }
        }
        else
        {
            if (item->quality < 50)
            {
                item->quality = item->quality + 1;
            }
        }
    }
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
