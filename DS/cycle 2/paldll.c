#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    char letter;
    struct node *prev;
    struct node *next;
}node;

int length;
char str[20];
node *head;

void readdata(node *head1){
    printf("Input string:");
    gets(str);
    strupr(str);
    length=strlen(str);
    node *ptr=head1;

    int i=0;
    while(str[i]!='\0'){
     node *new=(node*)malloc(sizeof(node));
     ptr->next=new;
     new->prev=ptr;
     new->letter=str[i];
     new->next=NULL;
     ptr=ptr->next;
     i++;
    }
}

void displayinput(node *head1){
    node *ptr=head1;
    while(ptr->next!=NULL){
        ptr=ptr->next;
        printf("%c---->",ptr->letter);
    }
    if(ptr->next==NULL){
        printf("NULL");
    }
    printf("\n");

}

void palindromecheck(node *head1){
    node *ptrback=head1;
    node *ptrfront=head1->next;
    int flag=0;
    while(ptrback->next!=NULL){
        ptrback=ptrback->next;
    }

    for(int i=0;i<(length/2);i++){
      if((ptrfront->letter)!=(ptrback->letter)){
        flag=1;
        break;
      }
      else{
        ptrfront=ptrfront->next;
        ptrback=ptrback->prev;
      }
    }

    if(flag==0){
        printf("\nString is palindrome");
    }
    else printf("\nString is not palindrome");
}

void main(){
    head=(node*)malloc(sizeof(node));
    head->next=NULL;
    head->prev=NULL;

    readdata(head);
    displayinput(head);
    palindromecheck(head);
}