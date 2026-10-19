#include "macro.h"

struct monster {
    char name[NAME_SIZE];
    int health;
};

extern struct monster* create_monster(char name[], int health);

extern int display_monster(struct monster* p);

extern int delete_monster(struct monster* p);

