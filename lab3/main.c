#include <stdio.h>
#include <stdlib.h>
#include "monster.h"
#include "macro.h"
#include "army.h"

int main(int argc, char *argv[]) {
    char name[] = {'P','i','k','a','c','h','u', '\0'}; //a null-terminator allows you to treat the character array as a string %s and stops loops before entering empty space
    int health = 100;
    struct monster* p[10];
    char buf[NAME_SIZE];
    struct army* a = create_army();
    for (int i=0; i<10; i++) {
        snprintf(buf, sizeof(buf), "%s-%d", name, i);
        p[i] = create_monster(buf, health);  
        add_monster_to_army(p[i], a);
    }

    // for (int i=0; i<10; i++) {
    //     display_monster(p[i]); 
    // }
    // for (int i=0; i<10; i++) {
    //     delete_monster(p[i]); 
    // }
    display_army(a);
    delete_army(a);
    return 0;
    
}