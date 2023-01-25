#include<stdio.h>
#include<stdlib.h>

int n,front=-1,rear=-1,queue[50];

void insert(int x){
  if(front==(rear+1)%n){
    printf("\nThe queue is full\n");
  
  }
  else if(front==-1 && rear==-1){
    front=0;
    rear=0;
    queue[rear]=x;
    
  }
  else{
   queue[++rear]=x;
   
  }
}

int delete()
{

   if(front==-1 && rear==-1)
     printf("\nQueue is empty\n");
   
   else if(front==rear)
   {
     front=-1;
     rear=-1;
     return queue[front+1];
   }
   else
   {  
     front++;
     return queue[front-1];
   }
  
}

void display(){
   if(front==-1 && rear==-1){
     printf("\nQueue is empty\n");
   
   }
   else{
    printf("The Queue is:\n");
    int i;
     for(i=front;i<=rear;i++){
       printf("%d\t",queue[i]);
   }
     }
}

void main(){
   int choice,x;
   printf("Enter the size of circular queue:\n");
    scanf("%d",&n);
   
   while(1){
   
    printf("\n1:Insert\n2:Delete\n3:Display\n4:Exit\nselect your choice(1-4)\n");
      scanf("%d",&choice);
      switch(choice){
        case 1:{
         printf("Enter the element:\n");
         scanf("%d",&x);
         insert(x);
         display();
         break;
        }
        case 2:{
         printf("The element removed:%d\n",delete());
         display();
         break;
        }
        case 3:{
         display();
         break;}
        
        case 4:
         exit(0);
        
        default :
        printf("\nInvalid choice\n");
      }
   
   }
  }








