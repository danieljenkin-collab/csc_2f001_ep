#include <stdio.h>
#include <stdlib.h>
#include "monster.h"
#include "army.h"

struct army {
  struct monster** monsters; // a pointer to an array, where each element of the array is a pointer to a monster
  int top;                   // where you have the last monster in the array
  int capacity;              // the capacity of the array
};


struct army* create_army() {
    struct army* a = malloc(sizeof(*a));
    a->capacity=0;
    a->monsters=NULL;
    a->top=0;
    return a;
}

int add_monster_to_army(struct monster* m, struct army* a) {
    if (a -> capacity == a -> top) {
        if (a -> capacity == 0){
            struct monster** monsters = malloc(sizeof(*monsters));
            a->capacity++;
            monsters[a->top]=m;
            free(a->monsters);
            a -> monsters = monsters;
        } else {
            struct monster** monsters = malloc(2*a->capacity*sizeof(*monsters)); //p points to the first element of the array, *p is the value of the first element. To determine the size of the entire array you have to multiply by the number of elements (capacity)
            a -> capacity *=2;
            int i=0;
            while (i < a -> top){
                monsters[i] = a -> monsters[i];
                i++;
            }
            monsters[a->top]=m;
            free(a->monsters);
            a -> monsters = monsters;
        }
    }else{    
        a->monsters[a->top]=m;
    }
    a->top++;
    return 0;
}

int display_army(struct army* a) {
    for (int i=0; i<(a -> top); i++) {
        display_monster(a -> monsters[i]);
    }
    return 0;
}

int delete_army(struct army* a){
    free(a -> monsters);
    free(a);
    return 0;
}