#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node* next;
};
struct node* tail;

int main()
{
  struct node* newnode,*temp,*current,*prev;
  int n,ch,count=0;
  tail=0;
  printf("Enter the number of elements:");
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&newnode->data);
    newnode->next=0;
    if(tail==0)
    {
      tail=newnode;
      tail->next=newnode;
    }
    else
    {
      newnode->next=tail->next;
      tail->next=newnode;
      tail=newnode;
    }
  }
  printf("%d\n",tail->next->data);                         //to check that the circular linked is create or not 
  printf("The elements are:");                            //to display
  if(tail==0)
  {
    printf("Empty");
  }
  else
  {
    temp=tail->next;
    while(temp->next!=tail->next)
    {
      printf("%d ",temp->data);
      temp=temp->next;
    }
    printf("%d",temp->data);
    printf("\n\n");
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
        printf("\nEnter the element you want to enter at the beginning:");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(tail==0)
        {
          tail=newnode;
          tail->next=newnode;
        }
        else
        {
          newnode->next=tail->next;
          tail->next=newnode;
        }
        break;
      }
      case 2:
      { 
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter the element you want to enter at the end:");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(tail==0)
        {
          tail=newnode;
          tail->next=newnode;
        } 
        else
        {
          newnode->next=tail->next;
          tail->next=newnode;
          tail=newnode;
        }
        break;
      }
      case 3:
      {
        int pos,i=1;
        printf("\nEnter the position:");
        scanf("%d",&pos);
        temp=tail->next;
        while(temp->next!=tail->next)
        {
          count++;
          temp=temp->next;
        }
        if(pos<1||pos>count)
        {
          printf("\nInvalid Position");
        }
        else if(pos==1)
        {
          newnode=(struct node*)malloc(sizeof(struct node));
          printf("\nEnter the element you want to enter:");
          scanf("%d",&newnode->data);
          newnode->next=0;
          if(tail==0)
          {
            tail=newnode;
            tail->next=newnode;
          }
          else
          {
            tail->next=newnode->next;
            tail->next=newnode;
          }
        }
        else
        {
          newnode=(struct node*)malloc(sizeof(struct node));
          printf("\nEnter the element you want to enter:");
          scanf("%d",&newnode->data);
          newnode->next=0;
          temp=tail->next;
          while(i<pos-1)
          {
            temp=temp->next;
            i++;
          }
          newnode->next=temp->next;
          temp->next=newnode;
        }
        break;
      }
      case 4:
      {
        temp=tail->next;
        if(tail==0)
        {
          printf("\nList is Empty");
        }
        else if(temp->next==temp)
        {
          tail=0;
        }
        else
        {
          tail->next=temp->next;
        }
        free(temp);
        break;
      }
      case 5:
      {
        current=tail->next;
        if(tail==0)
        {
          printf("\nList is Empty");
        }
        else if(current->next==current)
        {
          tail=0;
        }
        else
        {
          while(current->next!=tail->next)
          {
            prev=current;
            current=current->next;
          }
          prev->next=tail->next;
          tail=prev;
        }
        free(current);
        break;
      }
      case 6:
      {
        int pos,i=1;
        printf("\nEnter position:");
        scanf("%d",&pos);
        current=tail->next;
        while(current->next!=tail->next)
        {
          count++;
          current=current->next;
        }
        if(pos<1||pos>count)
        {
          printf("\nList is empty");
        }
        else if(pos==1)
        {
          if(tail==0)
          {  
            printf("\nList is Empty");
          }
          else if(temp->next=temp)
          {
            tail=0;
          }
          else
          {
            tail->next=temp->next;
          }
          free(temp);
          break;
        }
      else
      {
        while(i<pos)
        {
          current=current->next;
          i++;
        }
        temp=current->next;
        current->next=temp->next;
        free(temp);
      }
      break;
    }
    case 7:
    {
      if(tail==0)
      {
        printf("\nList IS Empty");
      }
      else
      {
        temp=tail->next;
        while(temp->next!=tail->next)
        {
          printf("%d ",temp->data);
          temp=temp->next;
        }
        printf("%d ",temp->data);
        printf("\n\n");
        break;
      }
    }
    case 8:
    {
      printf("\nEXITING...\n\n");
      exit(0);
    }
   }
  }while(ch);
}    
