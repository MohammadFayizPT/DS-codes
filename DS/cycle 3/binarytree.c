#include<stdio.h>
#include<stdlib.h>
struct NODE * loc;
int found=0;
struct NODE{
int DATA;
struct NODE *l;
struct NODE *r;
};
struct NODE * GetNode(){
struct NODE* new = (struct NODE*) malloc (sizeof(struct NODE));
return new;
}
void BuildTree(struct NODE* ptr){
if(ptr!=NULL){
int c;
printf("\nENTER ELEMENT TO INSERT : ");
scanf("%d",&(ptr->DATA));
printf("\n %d HAS LEFT CHILD (1/0)? ",ptr->DATA);
scanf("%d",&c);
if(c==1){
struct NODE * left = GetNode();
ptr->l = left;
BuildTree(left);
}
else{
ptr->l=NULL;
}
printf("\n%d HAS RIGHT CHILD (1/0)?",ptr->DATA);
scanf("%d",&c);
if(c==1){
struct NODE * right = GetNode();
ptr->r = right;
BuildTree(right);
}
else{
ptr->r=NULL;
}
}
}
void Inorder(struct NODE* ptr){
if (ptr!=NULL){
Inorder(ptr->l);
printf("%d\t",ptr->DATA);
Inorder(ptr->r);
}
}
void Preorder(struct NODE* ptr){
if (ptr!=NULL){
printf("%d\t",ptr->DATA);
Preorder(ptr->l);
Preorder(ptr->r);
}
}
void Postorder(struct NODE* ptr){
if (ptr!=NULL){
Postorder(ptr->l);
Postorder(ptr->r);
printf("%d\t",ptr->DATA);
}
}
struct NODE* Search(struct NODE * ptr,int item){
if(ptr->DATA != item){
if ((ptr->l!= NULL)&&(found==0)){
loc = Search(ptr->l,item);
if (loc!=NULL){
found=1;
return loc;
}
}
if ((ptr->r != NULL)&&(found==0)){
 loc = Search(ptr->r,item);
if (loc!=NULL){
found=1;
return loc;
}
}
else {
return NULL;
}
}
else
return ptr;
}
void Insert(struct NODE * root,int key, int item){
found=0;
loc=NULL;
char ch;
struct NODE * ptr = Search(root,key);
if (ptr == NULL){
printf("KEY NOT FOUND\n");
}
else{
printf("INSERT AS LEFT NODE OR RIGHT NODE (L/R) ?");
ch=getchar();
scanf("%c",&ch);
if (ch=='L'){
if (ptr->l==NULL){
struct NODE * new = GetNode();
new->DATA = item;
new->l=NULL;
new->r = NULL;
ptr->l=new;
printf("ELEMENT ADDED");
}
else{
printf("CANNOT BE INSERTED AS IT IS LEAF NODE\n");
}
}
else{
if (ptr->r==NULL){
struct NODE * new = GetNode();
new->DATA = item;
new->l=NULL;
new->r = NULL;
ptr->r=new;
printf("ELEMENT ADDED");
}
else{
printf("CANNOT INSERT AS LEAF NODE\n");
}
}
}
}
struct NODE * SearchParent(struct NODE * ptr, int key)
{
if (ptr->DATA!=key){
if((ptr->l!=NULL)&&(found==0)){
if(ptr->l->DATA == key){
found=1;
return ptr;
}
else{
loc=SearchParent(ptr->l,key);
if (loc!=NULL){
found=1;
return loc;
}
}
}
if((ptr->r!=NULL)&&(found==0))
{
if(ptr->r->DATA == key){
found=1;
return ptr;
}
else{
loc=SearchParent(ptr->r,key);
if (loc!=NULL){
found=1;
return loc;
}
}
}
else
return NULL;
}
else{
return ptr;
}
}
void Delete(struct NODE * ptr,int key){
loc=NULL;
found=0;
struct NODE * locp = SearchParent(ptr,key);
if (locp==NULL)
{
printf("ELEMENT NOT FOUND\n");
}
else{
if(locp->l!=NULL){
if(locp->l->DATA == key){
if((locp->l->l==NULL)&&(locp->l->r == NULL)){
locp->l=NULL;
printf("ELEMENT DELETED");
}
else{
printf("CANNOT DELETE ELEMENT\n");
}
}
}
if(locp->r!=NULL){
if (locp->r->DATA == key){
if((locp->r->l==NULL)&&(locp->r->r == NULL)){
locp->r=NULL;
printf("ELEMENT DELETED");
}
else{
printf("CANNOT DELETE ELEMENT\n");
}
}
}
}
}
void main(){
struct NODE * ROOT = GetNode();
BuildTree(ROOT);
int ch ;
do{
printf("\n\nMENU\n****\n1.INSERT\n2.INORDER TRAVERSAL\n3.PREORDER TRAVERSAL\n4.POSTORDER TRAVERSAL\n5.DELETE\n6.EXIT\n\nENTER YOUR CHOICE : ");
scanf("%d",&ch);
if(ch==1){
int key,item;
printf("ENTER PARENT NODE TO SEARCH AND INSERT : ");
scanf("%d",&key);
printf("ENTER DATA IN NODE TO INSERT : ");
scanf("%d",&item);
Insert(ROOT,key,item);
}
else if(ch==2){
Inorder(ROOT);
}
else if(ch==3){
Preorder(ROOT);
}
else if(ch==4){
Postorder(ROOT);
}
else if(ch==5){
int key;
printf("ENTER ELEMENT TO DELETE : ");
scanf("%d",&key);
Delete(ROOT,key);
}
else if (ch==6){
printf("EXIT\n");
break;
}
else{
printf("ENTER VALID OPTION\n");
}
}while(ch!=6);
}
