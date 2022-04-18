#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node* next;
  struct node* prev;
};
struct node* head ,*newnode,*temp;

int main()
{
  int n,ch,count=0;
  head=0;
  printf("\nEnter number of elements\n");
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the element:");
    scanf("%d",&newnode->data);
    newnode->prev=0;
    newnode->next=0;
    if(head==0)
    { 
      head=temp=newnode;
    }
    else
    { 
      temp->next=newnode;
      newnode->prev=temp;
      temp=newnode;
    }
  }
  printf("\nThe elements are:");
  temp=head;
  while(temp!=0)
  {
    printf("%d ",temp->data);
    temp=temp->next;
    count++;
  }
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
      newnode=(struct node*)malloc(sizeof(struct node));
      printf("\nEnter the element you want to insert at the beginning:");
      scanf("%d",&newnode->data);
      newnode->prev=0;
      newnode->next=0;
      head->prev=newnode;
      newnode->next=head;
      head=newnode;
      break;
    }
    case 2:
    {
      newnode=(struct node*)malloc(sizeof(struct node));
      printf("\nEnter the element you want to insert at the end:");
      scanf("%d",&newnode->data);
      if(head==0)
      {
        newnode->prev=0;
        newnode->next=0;
        head=newnode;
        printf("\nThe list is empty");
      }
      else
      {
        temp=head;
        while(temp->next!=0)
        {
          temp=temp->next;
        }
          temp->next=newnode;
          newnode->prev=temp;
          newnode->next=0;
      }
        break;
    }
    case 3:
    {
      int pos,i=1;
      printf("\nEnter position:");
      scanf("%d",&pos);
      if(pos<1)
      {
        printf("\nInvalid position");
      }
      else if(pos==1)
      {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter data:");
        scanf("%d",&newnode->data);
        newnode->prev=0;
        newnode->next=0;
        head->prev=newnode;
        newnode->next=head;
        head=newnode;
        break;
      }
      else 
      {
        temp=head;
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter data:");
        scanf("%d",&newnode->data);
        while(i<pos-1)
        {
          temp=temp->next;
          i++;
        }
        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next=newnode;
        newnode->next->prev=newnode;
      }
      break;
    }
    case 4:
    {
      if(head==0)
      {
        printf("\nList is empty");
      }
      else
      {  
        temp=head;
        head=head->next;
        head->prev=0;
        free(temp);
      }
      break;
    }
    case 5:
    {
      struct node* prevnode;
      if(head==0)
      {
        printf("List is empty");
      }
      else
      temp=head;
      {
        while(temp->next!=0)
        {
          prevnode=temp;
          temp=temp->next;
        }
        if(temp==head)
        {
          head=0;
        }
        else
        {
          prevnode->next=0;
        }
      }
      free(temp);
      break;
    }
    case 6:
    {
      int pos,i=1;
      temp=head;
      printf("\nEnter position:");
      scanf("%d",&pos);
      while(i<pos)
      {
        temp=temp->next;
        i++;
      }
      temp->prev->next=temp->next;
      temp->next->prev=temp->prev;
      free(temp);
      break;
    }
    case 7:
    {
      temp=head;
      printf("The elements are:");
      while(temp->next!=0)
      {
        printf("%d ",temp->data);
        temp=temp->next;
      }
      printf("%d ",temp->data);
      break;
    }
    case 8:
    {
      printf("\nEXITING...\n\n");
      exit(0);
    }
  }
 }while(ch);
}   
      
