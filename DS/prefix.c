
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
int priority(char ch)
{
switch(ch)
{
case '+':return 1;break;
case '-':return 1;break;
case '*':return 2;break;
case '/':return 2;break;
case '^':return 3;break;
case '(':return 0;break;
}return 0;
}

void main()
{int p1,p2,item1,item2,o=0,i=0,j=0,k=1,top=-1,a[20],len ;
 char ch[100],str[100];
 printf("Enter the infix expression\n");
 scanf("%s",str);
 len=strlen(str);
 
 for(i=len-1;i>=0;i--)
 {if(str[i]==')')
  ch[j]='(';
  else if(str[i]=='(')
  ch[j]=')';
  else
  ch[j]=str[i];
  j++;
  }
  
  ch[j]='\0';
  i=0;
  char stack[100],output[100];
  
  while(ch[i]!='\0')
  {if(isalpha(ch[i])||isdigit(ch[i]))
  {output[o]=ch[i];
  i++;o++;
  }
  
   else if(ch[i]=='(')
    {top++;
    stack[top]=ch[i];
    i++;
    }
   
   else if(ch[i]==')')
    {while(top!=-1)
    {if(stack[top]=='(')
    break;
    output[o]=stack[top];
    o++;top--;
    }
    if(stack[top]=='(')
    top--;
    i++;
    } 
   else
    {if(top==-1||stack[top]=='(')
    {top++;
    stack[top]=ch[i];
    i++;
    } 
    else
    {p1=priority(stack[top]);
         p2=priority(ch[i]);
         
         if(p1<p2)
         {top++;
         stack[top]=ch[i];
         i++;
         }
         else if(p1==p2)

         {  if(ch[i]=='^')
            {top++;
            stack[top]=ch[i];
            i++;
            }
            else
            {output[o]=stack[top];
             stack[top]=ch[i];
             i++;o++;
            }
         }    
       else

         {  while(p1>=p2)
            {output[o]=stack[top];
             top--;o++;
             if(top==-1)
                break;
             p1=priority(stack[top]);
            }
         top++;
        stack[top]=ch[i];
         i++;
         }
        }
       
        }
          }
   while(top!=-1)
{  if(stack[top]=='('||stack[top]==')')
            continue;
    else
    {output[o]=stack[top];
     top--;
     o++;
    }
}
for(j=o;j>=0;j--)
    {printf("%c",output[j]);
    }
    top=-1;
for(i=0;i<strlen(output);i++)
{  if(isalpha(output[i])||isdigit(output[i]))
  {
  if(isalpha(output[i]))
  {top++;

     printf("\nEnter the value of %c",output[i]);
     scanf("\n%d",&a[top]);
    }
   
   else if(isdigit(output[i]))
   {top++;
    a[top]=output[i]-'0';
    }
   }
   
    else if(output[i]=='+'||output[i]=='-'||output[i]=='*'||output[i]=='/'||output[i]=='^')
    {item2=a[top];
     top--;
     item1=a[top];

         switch(output[i])

     {  case '+':a[top]=item2+item1;break;
        case '-':a[top]=item2-item1;break;
        case '*':a[top]=item2*item1;break;
        case '/':a[top]=item2/item1;break;
        case '^':  for(j=0;j<item1;j++)
        {k*=item2;}
        a[top]=k;
        break;
     }
    }
   
   }
   
   printf("\nOutput is %d",a[0]);
}

