#include <stdio.h>
#include <stdlib.h>
#include "monster.h"

int main(int argc, char *argv[]) {
    char name[] = {'P','i','k','a','c','h','u','\0'}; //good to use a null character to detect end of string/array
    int health = 100;
    struct monster* p[10];
    char buf[10];
    for (int i=0; i<10; i++) {
        snprintf(buf, sizeof(buf), "%s-%d", name, i);
        p[i] = create_monster(buf, health);  
    }
    for (int i=0; i<10; i++) {
        display_monster(p[i]);  //they are all displayed as Pikachu-9 because each monster name points to the same buf which got overwritten during each iteration of the loop
    }
    for (int i=0; i<10; i++) {
        delete_monster(p[i]); 
    }
    return 0;
    
}