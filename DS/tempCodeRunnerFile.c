#include<stdio.h>
void tuple(int m[10][10],int ,int);
void transpose(int tp[10][3],int n);
int t[10][3];

int main(void){
int a[10][10],b[10][10],t1[10][3],t2[10][3],t3[10][3],r1,c1,r2,c2,i,j,count1,count2;
int k;
printf("Enter the order of 1st matrix:\n");
scanf("%d%d",&r1,&c1);

printf("Enter the order of 2nd matrix:\n");
scanf("%d%d",&r2,&c2);

  printf("Input first matrix:\n");
   for(i=0;i<r1;i++){
      for(j=0;j<c1;j++){
        scanf("%d",&a[i][j]);
      }
    }
    
  printf("Input second matrix:\n");
    for(i=0;i<r2;i++){
      for(j=0;j<c2;j++){
        scanf("%d",&b[i][j]);
      }
    }
    
    tuple(a,r1,c1);
    count1=t[0][2]+1;
    
    for(i=0;i<count1;i++){
      for(j=0;j<3;j++){
        t1[i][j]=t[i][j];
      }
      printf("\n");
    }
     printf("Tuple form of 1st matrix is:\n");
    for(i=0;i<count1;i++){
     for(j=0;j<3;j++){
     
      printf("%d\t",t1[i][j]);
     }
     printf("\n");
  }
  
 
    tuple(b,r2,c2);
    count2=t[0][2]+1;
    
      for(i=0;i<count2;i++){
       for(j=0;j<3;j++){
        t2[i][j]=t[i][j];
      }
      printf("\n");
    }
    printf("Tuple form of 2nd matrix is:\n");
    for(i=0;i<count2;i++){
     for(j=0;j<3;j++){
     
      printf("%d\t",t2[i][j]);
     }
     printf("\n");
  }
  i=1;
  j=1;
  k=1;
  if(t1[0][0]!=t2[0][0] && t1[0][1]!=t2[0][1]){
     printf("Addition is not possible");
  }
  else{
  t3[0][0]=t1[0][0];
  t3[0][1]=t1[0][1];

    while(i<=t1[0][2] && j<=t2[0][2]){
       if(t1[i][0]==t2[j][0] && t1[i][1]==t2[j][1]){
         t3[k][0]=t1[i][0];
         t3[k][1]=t1[i][1];
         t3[k][2]=t1[i][2]+t2[j][2];
         i++;j++;k++;
       }
       else if(t1[i][0]<t2[j][0]){
         t3[k][0]=t1[i][0];
         t3[k][1]=t1[i][1];
         t3[k][2]=t1[i][2];
         i++;k++;
       }
       else if(t1[i][0]>t2[j][0]){
          t3[k][0]=t2[j][0];
          t3[k][1]=t2[j][1];
          t3[k][2]=t2[j][2];
         j++;k++;
       }    
       else if(t1[i][0]==t2[j][0] && t1[i][1]>t2[j][1]){
          t3[k][0]=t2[j][0];
          t3[k][1]=t2[j][1];
          t3[k][2]=t2[j][2];
         j++;k++;
       
       }
       else{
         t3[k][0]=t1[i][0];
         t3[k][1]=t1[i][1];
         t3[k][2]=t1[i][2];
         i++;k++;
       
       }
    }
  }
  if(i<t1[0][2]){
    while(i<t1[0][2]){
         t3[k][0]=t1[i][0];
         t3[k][1]=t1[i][1];
         t3[k][2]=t1[i][2];
         i++;k++;
    }
  
  }
  if(j<t2[0][2]){
     while(i<t1[0][2]){
         t3[k][0]=t2[j][0];
         t3[k][1]=t2[j][1];
         t3[k][2]=t2[j][2];
         j++;k++;
    }
  }
  t3[0][2]=k-1;
  printf("Sum:\n");
  for(i=0;i<k;i++){
    for(j=0;j<3;j++){
       printf("%d\t",t3[i][j]);
    }
    printf("\n");
  }
   printf("Transpose of first matrix is:\n");
   transpose(t1,t1[0][2]);
   
   printf("Transpose of second matrix is:\n");
   transpose(t2,t2[0][2]);
  
  return 0;
   }
   
   
  void tuple(int m[10][10],int r,int c){
    int i,j,k=1;
    t[0][0]=r;
    t[0][1]=c;
    for(i=0;i<r;i++){
      for(j=0;j<c;j++){
        if(m[i][j]!=0){
          t[k][0]=i;
          t[k][1]=j;
          t[k][2]=m[i][j];
          k++;
        } 
      }
    }
    t[0][2]=k-1;
  
}


void transpose(int tp[10][3],int n){
  int i,j,k=1;
  int trp[10][3];
  
  trp[0][0]=tp[0][1];
  trp[0][1]=tp[0][0];
  trp[0][2]=tp[0][2];
  for(i=0;i<tp[0][1];i++){
   for(j=1;j<=n;j++){
    if(tp[j][1]==i){
    
      trp[k][0]=tp[j][1];
      trp[k][1]=tp[j][0];
      trp[k][2]=tp[j][2];
       k++;
    }
  }
  }
  for(i=0;i<=trp[0][2];i++){
   for(j=0;j<3;j++){
     printf("%d\t",trp[i][j]);
   
   }
   printf("\n");
  }
   
}