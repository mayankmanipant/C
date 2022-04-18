#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node* next;
 };
 struct node* head,*newnode,*temp;
 
 int main()
 {
 int ch,n,pos,count=0,i=0;
 head=0;
 printf("\nEnter number of element:");
 scanf("%d",&n);
 for(int i=0;i<n;i++)
 {
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&newnode->data);
    newnode->next=0;
    if(head==0)
    {
      head=temp=newnode;
    }
    else
    {
      temp->next=newnode;
      temp=newnode;
    }
  }
  temp=head;                                         //to display
  printf("The elements are:");
  while(temp!=0)
  {
    printf("%d ",temp->data);
    temp=temp->next;
    count++;
  }
  while(ch!=8)
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
     printf("\nEnter data you want to enter at the beginning:");
     scanf("%d",&newnode->data);
     newnode->next=head;
     head=newnode; 
     break;
   }
   case 2:
   {  
     newnode=(struct node*)malloc(sizeof(struct node));
     printf("\nEnter data you want to enter at the end:");
     scanf("%d",&newnode->data);
     newnode->next=0;
     temp=head;
     while(temp->next!=0)
     {
       temp=temp->next;
     }
     temp->next=newnode;
     break;
   }
   case 3:
   {
     newnode=(struct node*)malloc(sizeof(struct node));
     printf("\nEnter the position:");
     scanf("%d",&pos);
     if(pos>count)
     {
       printf("\nInvlaid position\n");
     }
     else
     {
       temp=head;
       while(i<pos)
       {
         temp=temp->next;
         i++;
       }
     printf("\nEnter data:");
     scanf("%d",&newnode->data);
     newnode->next=temp->next;
     temp->next=newnode;
     break;
     }
   }
   case 4:
   {
     if(head==0)
     {
       printf("EMPTY");
     }
     else
     {
       temp=head;
       head=head->next;
       free(temp);
     }
     break;
   }
   case 5:
   {
     struct node* prevnode;
     temp=head;
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
       free(temp);
     break;
   }
   case 6:
   {
     struct node* nextnode;
     temp=head;
     printf("\nEnter position");
     scanf("%d",&pos);
     while(i<pos-1)
     {
       temp=temp->next;
       i++;
     }
     nextnode=temp->next;
     temp->next=nextnode->next;
     free(nextnode);
     break;
   }
   case 7:
   {
     printf("\nThe elements are:");
     temp=head;
     while(temp!=0)
     {
       printf("%d ",temp->data);
       temp=temp->next;
     }
     break;
   }
   case 8:
   {
     printf("\nEXITING...\n\n");
     exit(0);
   }
  }
 }
}
