#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int rollno;
    char name[30];
    int mark;
    struct node *next;
};

struct node *head;
int n=0;

void display(){
    struct node *ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
        printf("Roll no:%d\n",ptr->rollno);
        printf("Name:%s\n",ptr->name);
        printf("Mark:%d\n",ptr->mark);
        printf("\n");
    }
}

int duplicheck(int num){
    struct node *ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
        if(ptr->rollno==num){
            return 1;
        }
    }
    if(ptr->next==NULL && ptr->rollno!=num){
        return 0;
    }
    else
    return 1;
}

void insertdata(){
    struct node *new=(struct node*)malloc(sizeof(struct node));
    printf("Input roll no:");
    int r;
    scanf("%d",&r);
    int res=duplicheck(r);

    if(res==1){
        printf("Duplicate entry\n");
    }
    else{
    new->rollno=r;
    char nam[8];
    printf("Input name:");
    gets(nam);
    gets(new->name);

    printf("Input mark:");
    scanf("%d",&new->mark);

    new->next=head->next;
    head->next=new;
    n++;
    printf("Data inserted successfully\n");

    }
}

void deletedata(){
    if(n==0){
        printf("Empty list");
    }
    else{
        printf("Input roll number of student to be deleted:-");
        int r;
        scanf("%d",&r);
        struct node *ptr=head;
        struct node *ptr1;

        while(ptr->next!=NULL){
            ptr1=ptr;
            ptr=ptr->next;
            if(ptr->rollno==r)
                break;
            
        }

        if((ptr->next==NULL) && (ptr->rollno!=r)){
            printf("Inputted roll no doesn't exist");
        }
        ptr1->next=ptr->next;
        n--;
    }
}

void searchdata_rollno(){
    struct node *ptr=head;
    int r;
    printf("Input roll no:");
    scanf("%d",&r);
    while(ptr->next!=NULL){
        ptr=ptr->next;
        if(ptr->rollno==r)
            break;
        
    }

    if((ptr->next==NULL) && (ptr->rollno!=r)){
      printf("Inputted roll no doesn't exist");
    }

    printf("Roll no:%d\n",r);
    printf("Name:%s\n",ptr->name);
    printf("Mark:%d\n",ptr->mark);
}

void searchdata_name(){
      struct node *ptr=head;
      char nam[8];
       printf("Input name:");
       gets(nam);

       while(ptr->next!=NULL){
        ptr=ptr->next;
        if(strcmp(nam,ptr->name)==0)
          break;
       }

       if((ptr->next==NULL) && strcmp(nam,ptr->name)!=0){
        printf("Inputted name doesn't exist\n");
       }

       printf("Roll no:%d\n",ptr->rollno);
       printf("Name:%s\n",ptr->name);
       printf("Mark:%d\n",ptr->mark);
}

void sortdata(){
    int swapped;
    do{
        struct node *ptr=head->next;
        swapped=0;
        while(ptr->next!=NULL){
            if((ptr->rollno)>(ptr->next->rollno)){
                int r1=ptr->next->rollno;
                ptr->next->rollno=ptr->rollno;
                ptr->rollno=r1;

                int r2=ptr->next->mark;
                ptr->next->mark=ptr->mark;
                ptr->mark=r2;

                char *r=(char*)malloc(sizeof(ptr->name));
                strcpy(r,ptr->name);
                strcpy(ptr->name,ptr->next->name);
                strcpy(ptr->next->name,r);
                swapped=1;
            }
            ptr=ptr->next;
        }
    }
    while(swapped);
}

void main(){
    head=(struct node*)malloc(sizeof(struct node));
    head->next=NULL;
    int choice;
    printf("STUDENT\n------------\n");
    printf("1.insertion\n2.deletion\n3.search by roll no\n4.search by name\n5.sort\n6.display\n7.exit\n");

    do{
        printf("Enter the choice:");
        scanf("%d",&choice);
        printf("\n");
        switch(choice){
            case 1:{
                insertdata();
                break;
            }
            case 2:{
                deletedata();
                break;
            }
            case 3:{
                searchdata_rollno();
                break;
            }
            case 4:{
                searchdata_name();
                break;
            }
            case 5:{
                sortdata();
                break;
            }
            case 6:{
                display();
                break;
            }
            case 7:{
                exit(0);
            }
            default:{
                printf("Enter a valid option\n");
            }
        }
    }while(choice!=7);
    
}