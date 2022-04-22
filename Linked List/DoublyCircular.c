#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
  struct node *prev;
}*head,*tail,*newnode,*temp;


int getlength()
{
  int count;
  temp=head;
  while(temp->next==head)
  {
    count++;
    temp=temp->next;
  }
  return count;
}



void insertatbeg()
{
  newnode=(struct node*)malloc(sizeof(struct node));
  printf("\nEnter data you want to enter at the beginning:");
  scanf("%d",&newnode->data);
  if(head==0)
  {
    head=tail=newnode;
    head->prev=tail;
    head->next=head;
  }
  else
  {
    head->prev=newnode;
    newnode->next=head;
    newnode->prev=tail;
    tail->next=newnode;
    head=newnode;
  }
}


void insertatend()
{
  newnode=(struct node*)malloc(sizeof(struct node));
  printf("\nEnter data you want to enter at the end:");
  scanf("%d",&newnode->data);
  if(head==0)
  {
    head=tail=newnode;
    head->prev=tail;
    head->next=head;
  }
  else
  {
    tail->next=newnode;
    newnode->prev=tail;
    newnode->next=head;
    head->prev=newnode;
    tail=newnode;
  }
}


void insertatpos()
{
  int pos,i=1,l;
  temp=head;
  printf("\nEnter the position:");
  scanf("%d",&pos);
  l=getlength();
  if(pos<1||pos>l)
  {
    printf("\nInvalid postion.");
  }
  else if(pos==1)
  {
    insertatbeg();
  }
  else
  {
    while(i<pos-1)
    {
      temp=temp->next;
      i++;
    }
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter data:");
    scanf("%d",&newnode->data);
    newnode->prev=temp;
    newnode->next=temp->next;
    temp->next->prev=newnode;
    temp->next=newnode;
  }
}


void delatbeg()
{
  temp=head;
  if(head==0)
  {
    printf("\nList is Empty");
  }
  else if(head->next==head)
  {
    head=0;
  }
  else
  {
    head=head->next;
    head->prev=tail;
    tail->next=head;
  }
  free(temp);
}


void delatend()
{
  temp=tail;
  if(head==0)
  {
    printf("\nList is Empty.");
  }
  else if(tail->next==tail)
  {
    tail=0;
  }
  else
  {
    tail=tail->prev;
    tail->next=head;
    head->prev=tail;
  }
  free(temp);
}


void delatpos()
{
  int pos,i=1,l;
  temp=head;
  printf("\nEnter position:");
  scanf("%d",&pos);
  l=getlength();
  if(pos<1||pos>l)
  {
    printf("\nList is Empty.");
  }
  else if(pos==1)
  {
    delatbeg();
  }
  else
  {
    while(i<pos)
    {
      temp=temp->next;
      i++;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    if(temp->next==head)
    {
      tail=temp->prev;
      free(temp);
    }
    else
    {
      free(temp);
    }
  }
}
  

void display()
{
  printf("\nThe elememts are:");
  temp=head;
  while(temp->next!=head)
  {
    printf("%d ",temp->data);
    temp=temp->next;
  }
  printf("%d",temp->data);
}
    
  
void create()
{
  int n,ch;
  head=0;
  printf("Enter the number of element:");
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter data:");
    scanf("%d",&newnode->data);
    if(head==0)
    { 
      head=tail=newnode;
      head->next=head;
      head->prev=head;
    }
    else
    {
      tail->next=newnode;
      newnode->prev=tail;
      newnode->next=head;
      head->prev=newnode;
      tail=newnode;
    }
  }
  printf("%d\n",tail->next->data);       //to check whether the doubly cll is created or not
}
   
int main()
{
  int ch;
  create();
  display();
  do
  {
   printf("\n\nINSERTION\n1.At the Beginning\n2.At the End\n3.At a given location\n");
   printf("DELETION\n4.At the Beginning\n5.At the End\n6.At a given location\n");
   printf("7.DISPLAY\n8.EXIT\n\n");
   printf("Enter your choice:");
   scanf("%d",&ch);
   switch(ch)
   {
    case 1:
    {
      insertatbeg();
      break;
    }
    case 2:
    {
      insertatend();
      break;
    }
    case 3:
    {
      insertatpos();
      break;
    }
    case 4:
    {
      delatbeg();
      break;
    }
    case 5:
    {
      delatend();
      break;
    }
    case 6:
    {
      delatpos();
      break;
    }
    case 7:
    {
       display();
       break;
    }
    case 8:
    {
      printf("\n\nEXITING...\n\n");
      exit(0);
    }
    default:
    {
      printf("\nInvalid choice.\n");
    }
   }
  }while(ch);
}    
  
                                                                     
