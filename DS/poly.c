#include<stdio.h>
void main(){
int p1[2][15],p2[2][15],p3[2][15],i,j,k,n,m;
printf("Enter the limit of first polynomial:\n");
scanf("%d",&n);
printf("Enter the limit of second polynomial:\n");
scanf("%d",&m);
printf("Input the first polynomial in such a way that 1st row is exponents and 2nd is coefficients:\n");
   for(i=0;i<2;i++){
     for(j=0;j<n;j++){
      scanf("%d",&p1[i][j]);

  }
  }
printf("Input the second polynomial in such a way that 1st row is exponents and 2nd is coefficients:\n");
   for(i=0;i<2;i++){
     for(j=0;j<m;j++){
      scanf("%d",&p2[i][j]);

  }
  }
   i=0;
   j=0;
   k=0;
 while(i<n && j<m){
     if(p1[0][i]==p2[0][j]){
         p3[0][k]=p1[0][i];
         p3[1][k]=p1[1][i]+p2[1][j];
          i++;j++;k++;
         }
     else if(p1[0][i]>p2[0][j]){
         p3[0][k]=p1[0][i];
         p3[1][k]=p1[1][i];
          i++;k++;
     }
     else{
         p3[0][k]=p2[0][j];
         p3[1][k]=p2[1][j];
          j++;k++;
     }
     
  }
 if(i<n){
   while(i<n){
     p3[0][k]=p1[0][i];
     p3[1][k]=p1[1][i];
     i++;k++;
   }
 }
 if(j<m){
    while(j<m){
     p3[0][k]=p2[0][j];
     p3[1][k]=p2[1][j];
     j++;k++;
   }
 }
 printf("Resultant polynomial is:\n");
   for(i=0;i<2;i++){
     for(j=0;j<n+m;j++){
       printf("%d\t",p3[i][j]);
     }
    printf("\n");
   }

}