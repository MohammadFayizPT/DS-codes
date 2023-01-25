#include<stdio.h>
#include<stdlib.h>
int i = 0;
struct node
{
int DATA;
struct node* LC;
struct node* RC;
};
void sortBST(struct node* ptr, int* arr)
{
if(ptr->LC != NULL)
sortBST(ptr->LC, arr);
arr[i] = ptr->DATA;
i++;
if(ptr->RC != NULL)
sortBST(ptr->RC, arr);
}
void insertBST(struct node* ptr, int ITEM)
{
struct node* ptr1;
while(ptr != NULL)
{
if(ITEM <= ptr->DATA)
{
ptr1 = ptr;
ptr = ptr->LC;
}
else if(ITEM > ptr->DATA)
{
ptr1 = ptr;
ptr = ptr->RC;
}
}
if(ptr == NULL)
{
if(ptr1->DATA < ITEM)
{
ptr1->RC = (struct node*) malloc(sizeof(struct node));
ptr1->RC->LC = NULL;
ptr1->RC->RC = NULL;
ptr1->RC->DATA = ITEM;
}
else
{
ptr1->LC = (struct node*) malloc(sizeof(struct node));
ptr1->LC->LC = NULL;
ptr1->LC->RC = NULL;
ptr1->LC->DATA = ITEM;
}
}
}
void main(){
int* arr;
int n;
printf("Enter the array size\n");
scanf("%d", &n);
arr = malloc(n*sizeof(int));
printf("Enter the numbers\n");
for(int i=0; i<n; i++)
scanf("%d", &arr[i]);
struct node* ROOT = (struct node*) malloc(sizeof(struct node));
ROOT->LC = NULL;
ROOT->RC = NULL;
ROOT->DATA = arr[0];
for(int i=1; i<n; i++)
insertBST(ROOT, arr[i]);
sortBST(ROOT, arr);
printf("Sorted array: ");
for(int i=0; i<n; i++)
printf("%d ", arr[i]);
printf("\n");
}
