struct army {
  struct monster** monsters; // a pointer to an array, where each element of the array is a pointer to a monster
  int top;                   // where you have the last monster in the array
  int capacity;              // the capacity of the array
};

extern struct army* create_army();

extern int add_monster_to_army(struct monster* m, struct army* a); //Use pointers if you need to modify the structures, read without copying. Use value if you want to copy

extern int display_army(struct army* a);

extern int delete_army(struct army* a);