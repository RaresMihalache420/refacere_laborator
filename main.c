#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "structs.h"

int main(){

    FILE *f;
    char *token=(char*)malloc(25*sizeof(char));
    char line[100],aux;
    char s[2] = ",";
    node_stud* p;
    node_mat* q;
    int show;
    node_stud* head=(node_stud*)malloc(sizeof(node_stud));
    strcpy(head->nume,"head");
    strcpy(head->prenume,"head");

    if((f=fopen("studenti.txt","rt")) == NULL){
        printf("deschidere fisere esuata!");
        exit(1); 
    }



    while(fgets(line,100,f)){
        
        p=create_node();
        p->lista_materii=create_node_mat();
        
        line[strlen(line)-1]='\0';
       
   
        token = strtok(line, s);
        strcpy(p->prenume,token);

        token = strtok(NULL, s);
        strcpy(p->nume,token);

        token = strtok(NULL, s);
        strcpy(p->clasa,token);
        
    
        if(!is_in_list(head,p)){
            //printf("%s","am intrat in if\n");
            //printf("%d",is_in_list(head,p));
       
        token = strtok(NULL, s);
        strcpy(p->lista_materii->materie,token);
        
        token = strtok(NULL, s);  
        if(strcmp(token,"10")==0)
            p->lista_materii->nota=10;
        else{
            aux=token[0];
            p->lista_materii->nota=aux-'0';
        }
        
        append_node(head,p);
        
        }
        else{
            printf("intra in else");

            p=go_to_node(head,p);
            q=create_node_mat();

            token = strtok(NULL, s);
            strcpy(q->materie,token);
        
            token = strtok(NULL, s);  
            if(strcmp(token,"10")==0)
            q->nota=10;
            else{
            aux=token[0];
            q->nota=aux-'0';
            }
            append_node_mat(p->lista_materii,q);
            printf("%s %d",q->materie,q->nota);
            free(q);
        }
        
    }

    //print_list(head);
    fclose(f);

    //eliminarea elevilor care nu au promovat

    
    if((f=fopen("promovati.txt","rt")) == NULL){
        printf("deschidere fisere esuata!");
        exit(1); 
    }

    head=copy_list(head);

    print_list_to_file(head,f);
    

    //afisare student cu media cea mai mare
    print_max(head,max_med(head));
    return 0;
}