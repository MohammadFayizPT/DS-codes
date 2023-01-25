#include<stdio.h>
#include<stdlib.h>
struct stack
{
int size;
int TOP;
int *arr;
};
struct queue
{
int FRONT;
int REAR;
int *arr;
int SIZE;
};
int isFull(struct stack *st)
{
if(st->TOP >= st->size-1)
return 1;
return 0;
}
int isEmpty(struct stack *st)
{
if(st->TOP == -1)
return 1;
return 0;
}
void push(struct stack *st, char x)
{
if(!isFull(st))
{
st->arr[++st->TOP] = x;
}
}
char pop(struct stack *st)
{
if(!isEmpty(st))
{
char x = st->arr[st->TOP];
st->TOP--;
return x;
}
}
void createStack(struct stack *st, int n)
{
st->size = n;
st->arr = (int*) malloc (st->size * sizeof(int));
st->TOP = -1;
}
void enqueue(struct queue *q, char X)
{
if(q->REAR != q->SIZE-1)
{
if(q->FRONT == -1)
q->FRONT = 0;
q->REAR += 1;
q->arr[q->REAR] = X;
}
}
char dequeue(struct queue *q)
{
if(q->FRONT != -1)
{
char X = q->arr[q->FRONT];
if(q->FRONT == q->REAR)
{
q->FRONT = -1;
q->REAR = -1;
}
else
q->FRONT += 1;
return X;
}
}
void createQueue(struct queue *q, int n)
{
q->SIZE = n;
q->arr = malloc(q->SIZE * sizeof(int));
q->FRONT = -1;
q->REAR = -1;
}
void dfs(int n, char arr[][n+1])
{
 struct stack *st = malloc(sizeof(struct stack));
int count = 0;
int i = 0;
char v;
char visit[n];
createStack(st, n*n);
push(st, arr[0][1]);
while(!isEmpty(st))
{
v = pop(st);
for(int j=0; j<n; j++)
if(visit[j] == v)
count++;
if(count == 0)
{
printf("%c ", v);
visit[i] = v;
i++;
for(int j=1; i<=n; j++)
if(arr[0][j] == v)
{
for(int k=1; k<=n; k++)
if(arr[k][j] == '1')
push(st, arr[k][0]);
break;
}
}
count = 0;
}
}
void bfs(int n, char arr[][n+1])
{
struct queue *q = malloc(sizeof(struct queue));
int i = 1;
int count = 0;
char visit[n];
char v;
createQueue(q, n*n);
enqueue(q, arr[0][1]);
printf("%c ", arr[0][1]);
visit[0] = arr[0][1];
while(q->FRONT != -1)
{
v = dequeue(q);
for(int j=1; i<=n; j++)
if(arr[0][j] == v)
{
for(int k=1; k<=n; k++)
if(arr[k][j] == '1')
{
for(int l=0; l<n; l++)
if(visit[l] == arr[k][0])
count++;
if(count == 0)
{
enqueue(q, arr[k][0]);
printf("%c ", arr[k][0]);
visit[i] = arr[k][0];
i++;
}
count = 0;
}
break;
}
}
}
void main()
{
int n;
char c;
int m;
printf("Enter the no. of vertices\n");
scanf("%d", &n);
char arr[n+1][n+1];
arr[0][0] = ' ';
printf("Enter the vertices\n");
for(int i=1; i<=n; i++)
{
scanf("\n%c", &arr[i][0]);
arr[0][i] = arr[i][0];
}
for(int i=1;i<=n;i++)
for(int j=i;j<=n;j++)
{
 if(arr[i][0] == arr[0][j])
{
printf("Is %c a self loop ? (Y/N)\n", arr[i][0]);
L1:
scanf("\n%c", &c);
if(c == 'y' || c == 'Y')
arr[i][j] = '1';
else if(c == 'n' || c == 'N')
arr[i][j] = '0';
else
{
printf("Enter Y/N!\n");
goto L1;
}
continue;
}
printf("Are %c and %c adjacent ? (Y/N)\n", arr[i][0], arr[0][j]);
L2:
scanf("\n%c", &c);
if(c == 'y' || c == 'Y')
{
arr[i][j] = '1';
arr[j][i] = '1';
}
else if(c == 'n' || c == 'N')
{
arr[i][j] = '0';
arr[j][i] = '0';
}
else
{
printf("Enter Y/N!\n");
goto L2;
}
}
printf("\nAdjacency matrix of the graph:\n");
for(int i=0;i<=n;i++)
{
for(int j=0;j<=n;j++)
printf("%c ", arr[i][j]);
printf("\n");
}
L3:
printf("\nChoose the operation\n");
printf("1. DFS Traversal\n2. BFS Traversal\n3. Quit\n");
printf("Enter your choice\n");
scanf("%d", &m);
if(m == 1)
{
printf("\nDFS Traversal : ");
dfs(n, arr);
printf("\n");
goto L3;
}
else if(m == 2)
{
printf("\nBFS Traversal : ");
bfs(n, arr);
printf("\n");
goto L3;
}
else if(m == 3)
exit(0);
else
{
printf("Invalid entry\n");
goto L3;
}
}