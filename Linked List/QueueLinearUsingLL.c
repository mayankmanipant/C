#include<stdio.h>
#include<stdlib.h>


struct node
{
  int data;
  struct node *next;
}*front=0,*rear=0;


void enqueue(int x)
{
  struct node *newnode;
  newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=x;
  newnode->next=0;
  if(front==NULL&&rear==NULL)
  {
    front=rear=newnode;
  }
  else
  {
    rear->next=newnode;
    rear=newnode;
  }
}


void dequeue()
{
  struct node *temp;
  if(front==NULL)
  {
    printf("\nQueue Is Empty.");
  }
  else
  {
    temp=front;
    printf("\nThe Dequeued Element is:%d",front->data);
    front=front->next;
    free(temp);
  }
}


void peek()
{
  if(front==NULL)
  {
    printf("\nEmpty.");
  }
  else
  {
    printf("\nThe Topmost Element is:%d",front->data);
  }
}
  
  
void display()
{
  struct node *temp;
  temp=front;
  if(front==NULL)
  {
    printf("\nEmpty");
  }
  else
  {
    printf("\nThe Elements are:");
    while(temp!=NULL)
    {
      printf("%d ",temp->data);
      temp=temp->next;
    }
  }
}


int main()
{
  int x,ch;
  do
  {
    printf("\n1.ENQUEUE\n2.DEQUEUE\n3.POP\n4.DISPLAY\n5.EXIT\n");
    printf("\nEnter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
      {
        printf("\nEnter element to be enqueued:");
        scanf("%d",&x);
        enqueue(x);
        break;
      }
      case 2:
      {
        dequeue();
        break;
      }
      case 3:
      {
        peek();
        break;
      }
      case 4:
      {
        display();
        break;
      }
      case 5:
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
   
