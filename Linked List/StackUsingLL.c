#include<stdio.h>
#include<stdlib.h>


struct node
{
  int data;
  struct node *next;
}*top=0;


/*int len()
{
  int c;
  struct node *temp=top;
  if(top=NULL)
  {
    return 0;
  }
  else
  {
    while(temp!=NULL)
    {
      c++;
      temp=temp->next;
    }
  }
  return c;
}*/
  


void push(int x)
{
  struct node *newnode;
  newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=x;
  newnode->next=0;
  if(top==NULL)
  {
    top=newnode;
  }
  else
  {
    newnode->next=top;
    top=newnode;
  }
}


void pop()
{
  struct node *temp;
  if(top==NULL)
  {
    printf("\nStack Is Empty.\n");
  }
  else
  {
    temp=top;
    printf("\nThe Popped element is:%d",top->data);
    top=top->next;
    free(temp);
  }
}


void peek()
{
  printf("\nThe topmost element is:%d",top->data);
}


/*void display()
{
  struct node *temp;
  temp=top;
  if(top==NULL)
  {
    printf("List Is Empty.\n");
  }
  else
  {  
    printf("\nThe elements are:");
    while(temp!=NULL)
    {
      printf("%d ",temp->data);
      temp=temp->next;
    }
  }
}*/


int display( struct node *top)
{
  if(top==NULL)
  {
   return 0;
  }
  else
  {
    printf("%d ",top->data);
    display(top->next);
  }
}


int rev_display(struct node *top)
{
  if (top==NULL)
  {
    return 0;
  }
  else
  {
    rev_display(top->next);
    printf("%d ",top->data);
  }
}


int main()
{
  int x,ch;
  do
  {
    printf("\n1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY\n5.REVERSE DISPLAY\n6.EXIT\n");
    printf("\nEnter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
      { 
        printf("\nEnter element to be Pushed:");
        scanf("%d",&x);
        push(x);
        break;
      }
      case 2:
      {
        pop();
        break;
      }
      case 3:
      {
        peek();
        break;
      }
      case 4:
      {
        display(top);
        break;
      }
      case 5:
      {
        rev_display(top);
        break;
      }
      case 6:
      {
        printf("\nEXITING...\n");
        exit(0);
      }
      default:
      {
        printf("\nInvalid Choice.");
      }
    }
  }while(ch);
}
  
    
  
  
