#include <stdio.h>
#include <stdlib.h>
#include "monster.h"
#include "macro.h"

struct monster* create_monster(char name[], int health) {
    struct monster* p = malloc(sizeof(*p));
    int i=0;
    while (name[i] != '\0' && i<NAME_SIZE -1) {
        (*p).name[i]=name[i];
        i++;
    }
    p->name[i]='\0';
    p->health=health;
    return p;
}

int display_monster(struct monster* p) {
    
    for (int i=0; p->name[i] != '\0'; i++) { //name[i]==*(name+i), works same way for type pointer and type array --> next character of array: if name is pointer to nth character, name+1 is pointer to n+1th character
        printf("%c", p->name[i]);
    }
    printf(", %d \n", p->health);
    return 0;
}

int delete_monster(struct monster* p) {
    free(p);
    return 0;
}