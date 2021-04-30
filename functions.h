#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "structs.h"

void file_open(FILE*f,char * nume_fis,char* mod);
node_stud* create_node();
void append_node(node_stud* head,node_stud* x);
void print_list(node_stud* head);
void print_node(node_stud* p);
int is_in_list(node_stud* head,node_stud* x);
node_stud* go_to_node(node_stud* head,node_stud* x);
node_mat* create_node_mat();
void append_node_mat(node_mat* head,node_mat* x);
node_stud* copy_list(node_stud* head);
void print_list_to_file(node_stud* head,FILE* f);
void print_max(node_stud* head,int max_med);
int max_med(node_stud* head);
#endif