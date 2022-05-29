#ifndef ROSE_INCLUDED
#define ROSE_INCLUDED

typedef struct Item
{
    char *name;
    int sellIn;
    int quality;
    void (*update_quality)(struct Item *);
} Item;

extern Item* init_item(Item* item, const char *name, int sellIn, int quality);
extern void update_quality(Item items[], int size);
extern char* sprint_item(char* buffer, Item* item);
extern int print_item(Item* item);

#endif