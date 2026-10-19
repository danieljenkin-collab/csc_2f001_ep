#include <stdio.h>
#include <stdlib.h>
#include "monster.h"

int main(int argc, char *argv[]) {
    char name[] = {'P','i','k','a','c','h','u','\0'}; //good to use a null character to detect end of string/array
    
    int health = 100;
    struct monster* p = create_monster(name, health); 
    display_monster(p);
    delete_monster(p);
    return 0;
}