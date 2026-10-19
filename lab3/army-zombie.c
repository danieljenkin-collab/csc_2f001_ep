#include <stdio.h>
#include <stdlib.h>
#include "monster.h"
#include "army.h"

struct army {
  struct node* root; 
  int top;                  
  int stars;
};

struct node {
    struct monster* monster;
    struct node* next_node;
};


struct army* create_army() {
    struct army* a = malloc(sizeof(*a));
    a->root=NULL;
    a->stars=0;
    return a;
}

int add_monster_to_army(struct monster* m, struct army* a) {
    if (a->root==NULL) {
        a->root=malloc(sizeof(*(a->root)));
        a->root->monster=m;
        a->root->next_node=NULL;
    }
    else{
        struct node* p=a->root;
        struct node* s;
        while (p!=NULL) {
            s=p;
            p=p->next_node;
        }
        p=malloc(sizeof(*p));
        p->monster=m;
        p->next_node=NULL;
        s->next_node=p;
    }
    return 0;
}

int display_army(struct army* a) {
    printf("This is a %d stars army \n", a->stars);
    for (struct node* p=a->root; p!=NULL; p=p->next_node) {
        display_monster(p->monster);
    }
    return 0;
}

int delete_army(struct army* a){
    struct node* p=a->root;
    struct node* s;
    while (p!=NULL){
        s=p->next_node;
        free(p);
        p=s;
    }
    free(a);
    return 0;
}