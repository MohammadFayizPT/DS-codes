#include<stdio.h>
#include<stdlib.h>
void createheap(int* arr, int n)
{
int i = 0, temp, j;
while(i < n)
{
j = i;
while(j > 0)
{
if(arr[j] > arr[(j-1)/2])
{
temp = arr[j];
arr[j] = arr[(j-1)/2];
arr[(j-1)/2] = temp;
j = (j-1)/2;
}
else
break;
}
i++;
}
}
void removemax(int* arr, int i)
{
int temp = arr[i];
arr[i] = arr[0];
arr[0] = temp;
}
void rebuildheap(int* arr, int i)
{
if(i == 0)
return;
int j = 0, temp, lc, rc;
while(1)
{
lc = 2 * j + 1;
rc = 2 * (j + 1);
if(rc <= i)
{
if(arr[j] <= arr[lc] && arr[lc] >= arr[rc])
{
temp = arr[j];
arr[j] = arr[lc];
arr[lc] = temp;
j = lc;
}
else if(arr[j] <= arr[rc] && arr[rc] >= arr[lc])
{
temp = arr[j];
arr[j] = arr[rc];
arr[rc] = temp;
j = rc;
}
else
break;
}
else if(lc <= i)
{
if(arr[j] <= arr[lc])
{
temp = arr[j];
arr[j] = arr[lc];
arr[lc] = temp;
break;
}
else
break;
}
else
break;
}
}
void heapsort(int* arr, int n)
{
createheap(arr, n);
for(int i = n-1; i > 0; i--)
{
removemax(arr, i);
rebuildheap(arr, i-1);
}
}
int binarysearch(int* arr, int num, int l, int r)
{
while(l <= r)
{
int m = l + (r - l) / 2; //For small size, (l + r) / 2
if(arr[m] == num)
return m;
else if(arr[m] < num)
l = m + 1;
else
r = m - 1;
}
return -1;
}
void main()
{
int n, num;
printf("Enter the array size\n");
scanf("%d", &n);
int* arr = malloc(n * sizeof(int));
printf("Enter the elements\n");
for(int i = 0; i < n; i++)
scanf("%d", &arr[i]);
heapsort(arr, n);
printf("\nThe sorted array: ");
for(int i = 0; i < n; i++)
printf("%d ", arr[i]);
printf("\n");
while(1)
{
printf("\nEnter the number to search (Enter -1 to exit)\n");
scanf("%d", &num);
if(num == -1)
break;
int index = binarysearch(arr, num, 0, n);
if(index != -1)
printf("%d found at index %d\n", num, index);
else
printf("Search unsuccessful!\n");
}
}