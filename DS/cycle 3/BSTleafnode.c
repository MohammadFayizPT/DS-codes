#include<stdio.h>
#include<stdlib.h>
int count=0;
struct NODE{
int DATA;
struct NODE *l;
struct NODE *r;
};
struct NODE * GetNode(){
struct NODE* new = (struct NODE*) malloc (sizeof(struct NODE));
return new;
}
void Insert(struct NODE * root, int item){
struct NODE * ptr=root;
struct NODE * ptr1;
int flag = 0;
while((ptr!=NULL)&&(flag==0)){
if(ptr->DATA > item){
ptr1=ptr;
ptr=ptr->l;
}
else if(ptr->DATA ==item){
flag=1;
printf("ELEMENT ALREADY EXISTS");
break;
}
else{
ptr1=ptr;
ptr=ptr->r;
}
}
if(ptr==NULL){
struct NODE * new = GetNode();
new->DATA = item;
new->l=NULL;
new->r = NULL;
if(ptr1->DATA<item){
ptr1->r = new;
}
else{
ptr1->l = new;
}
printf("ELEMENT ADDED");
}
}
void Count(struct NODE * ptr){
if(ptr!=NULL){
if((ptr->l==NULL)&&(ptr->r==NULL)){
count++;
}
else{
if (ptr->l!=NULL){
Count(ptr->l);
}
if(ptr->r!=NULL){
Count(ptr->r);
}
}
}
}
void main(){
struct NODE * ROOT = GetNode();
printf("ENTER ROOT NODE OF BST : ");
scanf("%d",&(ROOT->DATA));
ROOT->l=NULL;
ROOT->r=NULL;
int ch;
do{
printf("\n\nMENU\n1.INSERT\n2.COUNT LEAF NODE\n3.EXIT\n\nENTER YOUR CHOICE : ");
scanf("%d",&ch);
if(ch==1){
int key,item;
printf("ENTER DATA IN NODE TO INSERT : ");
scanf("%d",&item);
Insert(ROOT,item);
}
else if(ch==2){
count=0;
Count(ROOT);
printf("NUMBER OF LEAF NODES : %d\n",count);
}
else if (ch==3){
printf("EXIT.\n");
break;
}
else{
printf("ENTER VALID OPTION\n");
}
}while(ch!=3);
}