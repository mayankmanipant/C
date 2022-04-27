#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
};


void display1(struct node *head1)
{
  struct node *temp=head1;
  while(temp!=NULL)
  {
    printf("%d ",temp->data);
    temp=temp->next;
  }
}


void display2(struct node *head2)
{
  struct node *temp=head2;
  while(temp!=NULL)
  {
    printf("%d ",temp->data);
    temp=temp->next;
  }
}



struct node* create(struct node *head)
{
  struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    temp = head;
    if(head==NULL)
    {
      head=temp=newnode;
    }
    else
    {
      while(temp->next != NULL){
          temp = temp->next;
      }
      temp->next = newnode;
    }
    return head;
}


void merge(struct node *head1,struct node *head2)
{
   struct node *temp1=head1;
   struct node *temp2=temp1;
   while(temp1->next!=NULL)
   {
     temp1=temp1->next;
   }
   temp1->next=head2;
   
   printf("The merged ll is:");
   while(temp2!=NULL)
   {
     printf("%d ",temp2->data);
     temp2=temp2->next;
   }
}




int main()
{
  struct node *head1 = NULL;
  struct node *head2=NULL;
  int ch;
  while(1)
  {
     printf("\n1.CREATE LL1    2.CREATE LL2    3.DISPLAY LL1    4.DISPLAY LL2   5.MERGE    6.EXIT\n");
     printf("\nEnter your choice:");
     scanf("%d",&ch);
     switch(ch)
     {
       case 1:
         head1=create(head1);
         break;
       case 2:
         head2=create(head2);
         break;
       case 3:
         display1(head1);
         break;
       case 4:
         display2(head2);
         break;
       case 5:
         merge(head1,head2);
         break;
       case 6:
         printf("EXITING...");
         exit(0);
       default:
       printf("\nInvalid choice");
         
     }
   }
}
