#include<stdio.h>
#include<stdlib.h>
void display(int hash[], int n)
{
printf("\n");
for(int i = 0; i < n; i++)
printf("%d\n", hash[i]);
}
void new_entry(int hash[], int n)
{
int key;
printf("\nEnter the element\n");
scanf("%d", &key);
int h = key % n;
if(hash[h] == 0)
{
hash[h] = key;
display(hash, n);
}
else
{
for(int i = h+1; i < n; i++)
if(hash[i] == 0)
{
hash[i] = key;
display(hash, n);
return;
}
for(int i = 0; i < h; i++)
if(hash[i] == 0)
{
hash[i] = key;
display(hash, n);
return;
}
printf("\nHash table is full!\n");
}
}
void main()
{
int size, flag;
printf("\nEnter size of hash table\n");
scanf("%d", &size);
int* hash = calloc(size, sizeof(int));
while(1)
{
printf("\nEnter\n1. New entry\n2. Display Hash table\n3. Exit\n");
scanf("%d", &flag);
switch(flag)
{
case 1:
new_entry(hash, size);
break;
case 2:
display(hash, size);
break;
case 3:
exit(0);
default:
printf("\nInvalid entry!\n");
break;
}
}
}