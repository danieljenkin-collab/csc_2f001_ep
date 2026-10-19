#include <stdio.h>
#include <stdlib.h>
#include "monster.h"

int main(int argc, char *argv[]) {
    char name[] = {'P','i','k','a','c','h','u','\0'}; //good to use a null character to detect end of string/array
    int health = 100;
    struct monster* p[10];
    for (int i=0; i<10; i++) {
        p[i] = create_monster(name, health);  
    }
    for (int i=0; i<10; i++) {
        display_monster(p[i]);  
    }
    for (int i=0; i<10; i++) {
        delete_monster(p[i]); 
    }
    return 0;
}