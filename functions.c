#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "structs.h"


//functii pentru lista de elevi
void file_open(FILE*f,char * nume_fis,char* mod){
    f=fopen(nume_fis,mod);
    if(f == NULL){
        printf("deschidere fisere esuata!");
        exit(1); 
    }
}

node_stud* create_node(){
    node_stud* p=(node_stud*)malloc(sizeof(node_stud));
    p->next=NULL;
    p->prev=NULL;
    return p;
}

void append_node(node_stud* head,node_stud* x){
    node_stud* p=head;
    
    if(strcmp(head->nume,"head")==0){
    strcpy(head->nume,x->nume);
    strcpy(head->prenume,x->prenume);
    strcpy(head->clasa,x->clasa);
    //printf("%s,%s,%s\n",head->prenume,head->nume,head->clasa);
    return;
    }
    //else
    while(p->next!=NULL){
         p=p->next;
    }
    x->next=NULL;
    x->prev=p;
    p->next=x;
    return;
}

void print_list(node_stud* head){
    node_stud* p;
    node_mat* q;
    for(p=head->next;p!=NULL;p=p->next)
    {
        printf("%s,%s,%s ",p->prenume,p->nume,p->clasa);
        for(q=p->lista_materii;q!=NULL;q=q->next)
            printf("%s %d\n",q->materie,q->nota);
    }
}

void print_node(node_stud* p){
    node_mat* q;
    printf("%s,%s,%s:",p->prenume,p->nume,p->clasa);
    for(q=p->lista_materii;q!=NULL;q=q->next)
            printf("%s %d,",q->materie,q->nota);
    printf("\n");
}

int is_in_list(node_stud* head,node_stud* x){
    int k=0;
    node_stud* z=create_node();
    z=head;
    //printf("%s\n","am intrat in is_in_list");
    //printf("%s %s %s \n",x->prenume,x->nume,x->clasa);
    while(z->next!=NULL)
    {   
        z=z->next;
       
        
        //printf("%s","am intrat in is_in_list\n");
       // printf("%s %s %s ",x->prenume,x->nume,x->clasa);

        if(strcmp(x->nume,z->nume)==0 && strcmp(x->prenume,z->prenume)==0){
            k=1;
        }  
    }
    
    return k;
}

node_stud* go_to_node(node_stud* head,node_stud* x){
    node_stud* p;
    for(p=head;p!=NULL;p=p->next)
    {
        if((strcmp(x->nume,p->nume)==0) && (strcmp(x->prenume,p->prenume)==0))
        return p;
    }
    return NULL;
}

//functii pentru listele de materii

node_mat* create_node_mat(){
    node_mat *p=(node_mat*)malloc(sizeof(node_mat));
    p->next=NULL;
    return p;
}

void append_node_mat(node_mat* head,node_mat* x){
    node_mat* p;
    if(head==NULL){
    head=x;
    return;
    }
    else
        while(p->next!=NULL){
            p=p->next;
        }
    x->next=NULL;
    p->next=x;
    return;

}

//functii subpct. 3
node_stud* copy_list(node_stud* head){
    node_stud* p=head;
    node_stud* aux=NULL;
    node_mat* q=NULL;

    for(p=head->next;p!=NULL;p=p->next)
        for(q=p->lista_materii;q!=NULL;q=q->next)
            if(q->nota < 5)
            {
                aux=p;
                p->prev=p->next;
                free(aux);
            }
    
    return head;
}

void print_list_to_file(node_stud* head,FILE* f){
    node_stud* p;
    node_mat* q;
    for(p=head->next;p!=NULL;p=p->next)
    {
        fprintf(f,"%s,%s,%s ",p->prenume,p->nume,p->clasa);
        for(q=p->lista_materii;q!=NULL;q=q->next)
            fprintf(f,"%s %d\n",q->materie,q->nota);
    }
}

//functii subpct. 4

int max_med(node_stud* head){
    node_stud* p;
    node_mat* q;
    int max=0;
    for(p=head->next;p!=NULL;p=p->next){
        int nota=0;
        int nr_mat=0;
        for(q=p->lista_materii;q!=NULL;q=q->next){
            nr_mat++;
            nota+= q->nota;
        }
        if((nota/nr_mat)>max)
            max=(nota/nr_mat);
    }
    return max;
}

void print_max(node_stud* head,int max_med){
    node_stud* p;
    node_mat* q;
    for(p=head->next;p!=NULL;p=p->next){
        int nota=0;
        int nr_mat=0;
        for(q=p->lista_materii;q!=NULL;q=q->next){
            nr_mat++;
            nota+= q->nota;
        }
        if((nota/nr_mat)==max_med)
            print_node(p);
            
    }
}