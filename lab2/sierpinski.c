#include <stdio.h>
#include <stdlib.h>

int sort_get_index(int* p, float tab[], int top, float val) {
    int i=0;
    while (val >= tab[i] && i < top) {
        i++;
    }
    *p = i;
    printf("Insert %f at %d\n", val, i);
    return 0;
}

int sort_insert_at(int i, float tab[], int top, float val) {
    
    for (int j=top; j>i; j--) {
        tab[j] = tab[j-1];
    }
    tab[i] = val; // altering an array in the function alters the original array
    return 0;
}
int sort_insert(float tab[], int top, float val) {
    int i;
    sort_get_index(&i, tab, top, val);
    sort_insert_at(i, tab, top, val);
    return 0;
}

int main(int argc, char *argv[]) {
    float tab[]={1,3,5,7,0};
    int top = 4;
    float val = 10;
    int i=0;
    sort_insert(tab, top, val);
    while (i<5) {
        printf("%f ", tab[i]);
        i++;
    }
    printf("\n");
    return 0;
}