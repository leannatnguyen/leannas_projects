/* double pointers*/

//pointers are just variables that hold an address
int *p;
char *p;
// these two are both pointers but they point to different types of data types

//double pointer = pointer to a pointer

int *p1;
int **p2;
p2 = &p1;   //p2 points to the address of p1
**p2 = 5;   //dereference the pointer twice and set the value to 5

/* common usages */
/*
-pass by reference
    -c passes arguments by value
-can use as an array
*/