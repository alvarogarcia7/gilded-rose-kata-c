#include <string.h>
#include "GildedRose.h"
#include "GildedRose_Quality.h"
#include <stdio.h>

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

void
update_quality(Item items[], int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        items[i].update_quality(&items[i]);
    }
}

