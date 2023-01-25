#include<stdio.h>
#include<stdlib.h>

struct node{
    int exp_x;
    int exp_y;
    int coeff;
    struct node *next;
};

struct node *head1,*head2,*head3;
int n1,n2;

void getpol(struct node *head,int n){
    struct node *new=(struct node*)malloc(sizeof(struct node));
     for(int i=0;i<n;i++){
        int value;
        printf("Input coefficient:-");
        scanf("%d",&value);
        int expx;
        int expy;
        printf("Input exponent of x and y respectively:-");
        scanf("%d%d",&expx,&expy);

        new->coeff=value;
        new->exp_x=expx;
        new->exp_y=expy;

        if(i==0){
            head->next=new;
        }

        if(i==n-1){
            new->next=NULL;
        }
        else{
            struct node *ptr=new;
            new=(struct node*)malloc(sizeof(struct node));
            ptr->next=new;
        }
     }
}

void displaypol(struct node *head){
    struct node *ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
        printf("%d",ptr->coeff);

        if((ptr->exp_x)!=0){
            printf("x^(%d)",ptr->exp_x);
        }
        if((ptr->exp_y)!=0){
            printf("y^(%d)",ptr->exp_y);
        }

        if(ptr->next!=NULL){
            printf("+");
        }
    }
    printf("\n");
}

void addpol(struct node *head,int t1,int t2){
    struct node *new=(struct node*)malloc(sizeof(struct node));
     head->next=new;
     struct node *ptr1=head1->next;
     struct node *ptr2=head2->next;
     struct node *ptr;
     int i=0,j=0;

     while(i<t1 && j<t2){
         if((ptr1->exp_x)>(ptr2->exp_x)){
            ptr=new;
            ptr->coeff=ptr1->coeff;
            ptr->exp_x=ptr1->exp_x;
            ptr->exp_y=ptr1->exp_y;
            new=(struct node*)malloc(sizeof(struct node));
            ptr->next=new;
            i++;
            ptr1=ptr1->next;
         }
         else if((ptr1->exp_x)<(ptr2->exp_x)){
            ptr=new;
            ptr->coeff=ptr2->coeff;
            ptr->exp_x=ptr2->exp_x;
            ptr->exp_y=ptr2->exp_y;
            new=(struct node*)malloc(sizeof(struct node));
            ptr->next=new;
            j++;
            ptr2=ptr2->next;

         }
         else{
         if((ptr1->exp_y)>(ptr2->exp_y)){
            ptr=new;
            ptr->coeff=ptr1->coeff;
            ptr->exp_x=ptr1->exp_x;
            ptr->exp_y=ptr1->exp_y;
            new=(struct node*)malloc(sizeof(struct node));
            ptr->next=new;
            i++;
            ptr1=ptr1->next;
         }
         else if((ptr1->exp_y)<(ptr2->exp_y)){
            ptr=new;
            ptr->coeff=ptr2->coeff;
            ptr->exp_x=ptr2->exp_x;
            ptr->exp_y=ptr2->exp_y;
            new=(struct node*)malloc(sizeof(struct node));
            ptr->next=new;
            j++;
            ptr2=ptr2->next;

         }
         else{
            ptr=new;
            ptr->coeff=ptr2->coeff+ptr1->coeff;
            ptr->exp_x=ptr2->exp_x;
            ptr->exp_y=ptr2->exp_y;
            new=(struct node*)malloc(sizeof(struct node));
            ptr->next=new;
            j++;i++;
            ptr1=ptr1->next;
            ptr2=ptr2->next;

         }
           
         }
     } 

     if(i<t1){
        while(i<t1){
            ptr=new;
            ptr->coeff=ptr1->coeff;
            ptr->exp_x=ptr1->exp_x;
            ptr->exp_y=ptr1->exp_y;
            new=(struct node*)malloc(sizeof(struct node));
            ptr->next=new;
            i++;
            ptr1=ptr1->next;
        }
     }

       if(j<t2){
        while(j<t2){
            ptr=new;
            ptr->coeff=ptr2->coeff;
            ptr->exp_x=ptr2->exp_x;
            ptr->exp_y=ptr2->exp_y;
            new=(struct node*)malloc(sizeof(struct node));
            ptr->next=new;
            j++;
            ptr2=ptr2->next;
        }
     }

   ptr->next=NULL;

}

void main(){
    printf("Enter the number of terms in polynomial 1:");
    scanf("%d",&n1);
    head1=(struct node*)malloc(sizeof(struct node));
    getpol(head1,n1);

    printf("Enter the number of terms in polynomial 2:");
    scanf("%d",&n2);
    head2=(struct node*)malloc(sizeof(struct node));
    getpol(head2,n2);

    printf("polynomial 1:-");
    displaypol(head1);
    printf("polynomial 2:-");
    displaypol(head2);

    printf("Sum is:");

    head3=(struct node*)malloc(sizeof(struct node));
    head3->next=NULL;
    addpol(head3,n1,n2);
    displaypol(head3);
    
}
