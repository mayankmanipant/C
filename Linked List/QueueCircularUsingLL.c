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
    rear->next=front;
  }
  else
  {
    rear->next=newnode;
    newnode->next=front;
    rear=newnode;
  }
}


void dequeue()
{
  struct node *temp;
  temp=front;
  if(front==NULL&&rear==NULL)
  {
    printf("\nEmpty");
  }
  else if(front==rear)
  {
    front=rear=0;
    free(temp);
  }
  else
  {
    printf("\nThe Dequeued Element is:%d",front->data);
    front=front->next;
    rear->next=front;
    free(temp);
  }
}


void peek()
{
  if(front==NULL)
  {
    printf("\nEmpty");
  }
  else
  {
    printf("The topmost element is:%d",front->data);
  }
}


void display()
{
  struct node *temp;
  temp=front;
  if(front==NULL)
  {
    printf("\nEMPTY");
  }
  else
  {
    printf("\nThe elements are:");
    while(temp->next!=front)
    { 
      printf("%d ",temp->data);
      temp=temp->next;
    }
    printf("%d",temp->data);
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
   
