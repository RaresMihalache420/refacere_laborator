#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct node_mat{
    char materie[20];
    int nota;
    struct node_mat* next;
}node_mat;

typedef struct node_stud{
    char prenume[20];
    char nume[20];
    char clasa[3];
    struct node_mat* lista_materii;
    struct node_stud*prev;
    struct node_stud* next;
}node_stud;

#endif