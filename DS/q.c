#include<stdio.h>
#include<stdlib.h>
int queue[50],n,front=-1,rear=-1;

void enqueue(int x,int n){
 if(rear==n-1)
 printf("\nQueue is full\n");
 else if(front==-1 && rear==-1){
  front=0;
  rear=0;
  queue[rear]=x;
 
 }
 else{
   rear++;
   queue[rear]=x;
 }
}

int dequeue(int n){

  if(front==-1 && rear==-1)
  {
    printf("Queue is empty");
    return 0;
  }
  else if(front==rear){
   printf("Element removed:%d\n",queue[front]);
    front=-1;
    rear=-1;
  }
  else {
   front++;
   printf("Element removed:%d\n",queue[front-1]);
  
  }
}

void display(){
    if(front==-1 && rear==-1){
      printf("Queue is empty");
    
    }
    else{
      printf("Queue is:\n ");
     for(int i=front;i<=rear;i++){
       printf("%d,",queue[i]);
     }
    
}
}
void main(){
  int choice,x;
  printf("\nEnter the size of queue:\n");
  scanf("%d",&n);
  while(1){
    printf("\n1:Insertion\n2:Deletion\n3:Display\n4:Exit\nselect your choice(1-4)\n");
    scanf("%d",&choice);
    switch(choice){
       
       case 1:{
         printf("\nEnter the elements:\n");
         scanf("%d",&x);
         enqueue(x,n);
         display();
         break;
       }
       case 2:{
          dequeue(n);
          display();
          break;
         
       }
       case 3:{
         display();
         break;
         
       }
       case 4:{
         exit(0);
         break;
       }
       default :{
        printf("\nInvalid option\n");
        break;}
    
    }
    }
    }
      
      