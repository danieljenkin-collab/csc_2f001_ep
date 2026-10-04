#include <stdio.h>
#include <stdlib.h>

struct point { //type must be declared globally
        float x;
        float y;
    };

int sort_get_index(int* p, float tab[], int top, float val) {
    int i=0;
    while (val >= tab[i] && i < top) {
        i++;
    }
    *p = i;
    // printf("Insert %f at %d\n", val, i);
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

int nb_columns() {
    return 32;
}

int nb_lines() {
    return 16;
}

int grid_init(char grid[], char pixel) {
    for (int i=0; i<nb_columns()*nb_lines();i++) {
        grid[i]=pixel;
    }
    return 0;
}

int grid_display(char grid[]) {
    for (int j=0;j<nb_lines();j++){
        for (int i=0;i<nb_columns();i++) {
            printf("%c ", grid[i+j*nb_columns()]);
        }
        printf("\n");
    }
    return 0;
}

int plot_point(char grid[], int x, int y, char pixel) {
    if (x>nb_columns() || y>nb_lines()) {
        printf("(x,y) not in grid \n");
        exit(EXIT_FAILURE);
    } else {
        grid[(nb_lines() - y - 1)*nb_columns()+x]=pixel;
    }
    return 0;
} 

int plot_vline(char grid[], int x, float fy0, float fy1, char pixel) {
    int y0 = (fy0+0.5);
    if (fy0 == y0 - 0.5) {
        y0 = y0 - 1;
    }
    int y1 = (fy1+0.5);
    for (int y=y0; y<=y1; y++) {
        plot_point(grid, x, y, pixel);
    }
    return 0;
}

int plot_poly_sweep(char grid[], struct point p[], int Np, int x, char pixel) {
    float vlines[Np * 4];
    int top = 0;
    int j = Np - 1;
    for (int i=0; i<Np; i++) {
        if ((p[i].x <= x && x < p[j].x) || (p[j].x <= x && x < p[i].x)) {
            sort_insert(vlines, top, p[i].y + (x - p[i].x) * (p[j].y - p[i].y) / (p[j].x - p[i].x));
            top++;
        }
        j=i;
    }
    for (int n = 0; n < top; n++) {
        printf("%f ", vlines[n]);
    }
    printf("\n");
    for (int c=0; c < top; c+=2) {
        plot_vline(grid, x, vlines[c], vlines[c+1], '-');
    }
    return 0;
}

int plot_poly(char grid[], struct point p[], int Np, char pixel) {
    for (int x=0; x < nb_columns(); x++) {
        printf("Sweep %d: ", x);
        plot_poly_sweep(grid, p, Np, x, pixel);
        printf("\n");
    }
    return 0;
}

int main(int argc, char *argv[]) {
    char grid[nb_lines() * nb_columns()];
    struct point p[] = {{ 2, 13 }, { 10, 13 }, { 30, 7 }, { 10, 1 }, { 2, 1 }, { 18, 7 }};
    grid_init(grid, ' ');
    plot_poly(grid, p, 6, '*');
    grid_display(grid);
    return 0;
}