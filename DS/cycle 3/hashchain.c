#include<stdio.h>
#include<stdlib.h>
struct node
{
int DATA;
struct node* LINK;
};
void display(struct node** hash)
{
struct node* ptr;
for(int i = 0; i < 10; i++)
{
ptr = hash[i]->LINK;
printf("\n%d - ", i);
while(ptr != NULL)
{
printf("%d ", ptr->DATA);
ptr = ptr->LINK;
}
}
printf("\n");
}
void new_entry(struct node** hash)
{
int key;
printf("Enter the element\n");
scanf("%d", &key);
int h = key % 10;
struct node *ptr = hash[h];
while(ptr->LINK != NULL)
ptr = ptr->LINK;
ptr->LINK = malloc(sizeof(struct node));
ptr->LINK->DATA = key;
ptr->LINK->LINK = NULL;
display(hash);
}
void main()
{
int flag;
struct node** hash = malloc(10 * sizeof(struct node*));
for(int i = 0; i < 10; i++)
{
hash[i] = malloc(sizeof(struct node));
hash[i]->LINK = NULL;
}
while(1)
{
printf("\nEnter\n1. New entry\n2. Display Hash table\n3. Exit\n");
scanf("%d", &flag);
switch(flag)
{
case 1:
new_entry(hash);
break;
case 2:
display(hash);
break;
case 3:
exit(0);
default:
printf("\nInvalid entry!\n");
}
}
}