#include <stdio.h>
#include <stdlib.h>

int sort_get_index(float tab[], int top, float val) {
    int i=0;
    while (val >= tab[i] && i<top) {
        i++;
    }
    printf("Insert %f at %d\n", val, i);
    return 0;
}

int main(int argc, char *argv[]) {
    float tab[] = {1,3,5,7,0};
    sort_get_index(tab, 4, 7.5);
    int i=0;
    while (i<5) {
        printf("%f ", tab[i]);
        i++;
    }
    return 0;
}