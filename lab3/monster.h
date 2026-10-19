struct monster {
    char name[256];
    int health;
};

extern struct monster* create_monster(char name[], int health);

extern int display_monster(struct monster* p);

extern int delete_monster(struct monster* p);

