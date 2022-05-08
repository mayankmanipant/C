#include<stdio.h>
#include<stdlib.h>
typedef enum{FALSE ,TRUE}bool;


struct node
{
  int data;
  int balance;
  struct node* left;
  struct node* right;
};


struct node* search(struct node* root,int val)
{
  if(root!=NULL)
  {
    if(val < root->data)  
    {
      root=search(root->left,val);
    }
    else if(val > root->data)
    {
      root=search(root->right,val);
    }
    return root;
  }
}


struct node* insert(struct node* root,int val,int *ht_inc)
{
  struct node* aptr;
  struct node* bptr;
  if(root==NULL)
  {
    root=(struct node*)malloc(sizeof(struct node));
    root->data=val;
    root->left=NULL;
    root->right=NULL;
    root->balance=0;
    *ht_inc=TRUE;
    return root;
  }
  if(val<root->data)
  {
    root->left=insert(root->left,val,ht_inc);
    if(*ht_inc==TRUE)
    {
      switch(root->balance)
      {
        case -1:   //right heavy
          root->balance=0;
          *ht_inc=FALSE;
          break;
        case 0:   //balanced
          root->balance=1;
          break;
        case 1:   //left heavy
          aptr=root->left;
          if(aptr->balance==1)
          {
            printf("\nLeft to left rotation\n");
            root->left=aptr->right;
            aptr->right=root;
            root->balance=0;
            aptr->balance=0;
            root=aptr;
          }
          else
          {
            printf("\nLeft to right rotation:\n");
            bptr=aptr->right;
            aptr->right=bptr->left;
            bptr->left=aptr;
            root->left=bptr->right;
            bptr->right=root;
            if(bptr->balance==1)
              root->balance=-1;
            else
              root->balance=0;
            if(bptr->balance==-1)
              aptr->balance=1;
            else
              aptr->balance=0;
            bptr->balance=0;
            root=bptr;
          }
          *ht_inc=FALSE;
      }
    }
  }
  if(val > root->data)
  {
    root->right=insert(root->right,val,ht_inc);
    if(*ht_inc==TRUE)
    {
      switch(root->balance)
      {
        case 1:   //left heavy
          root->balance=0;
          *ht_inc=FALSE;
          break;
        case 0:    //balanced
          root->balance=-1;
          break;
        case -1:   //right heavy
          aptr=root->right;
          if(aptr->balance==-1)
          {
            printf("\nRR Rotation\n");
            root->right=aptr->left;
            aptr->left=root;
            root->balance=0;
            aptr->balance=0;
            root=aptr;
          }
          else
          {
            printf("\nRL Rotation\n");
            bptr=aptr->left;
            aptr->left=bptr->right;
            bptr->right=aptr;
            root->right=bptr->left;
            bptr->left=root;
            if(bptr->balance==-1)
              root->balance=1;
            else
              root->balance=0;
            if(bptr->balance==1)
              aptr->balance=-1;
            else 
              aptr->balance=0;
            bptr->balance=0;
            root=bptr;
          }
          *ht_inc=FALSE;
      }
    }
  }
  return root;
}


void display(struct node* root,int level)
{
  int i;
  if(root!=NULL)
  {
    display(root->right,level+1);
    printf("\n");
    for(i=0;i<level;i++)
      printf(" ");
    printf("%d",root->data);
    display(root->left,level+1);
  }
}
  
  
void inorder(struct node* root)
{
  if(root!=NULL)
  {
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
  }
}


int main()
{
  bool ht_inc;
  int val;
  int ch;
  struct node *root=(struct node*)malloc(sizeof(struct node));
  root=NULL;
  do
  {
    printf("\n1.INSERT\n");
    printf("\n2.DISPLAY\n");
    printf("\n3.QUIT\n");
    printf("Enter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
        printf("Enter the value to be inserted:");
        scanf("%d",&val);
          if(search(root,val)==NULL)
            root=insert(root,val,&ht_inc);
          else
            printf("Duplicate valuye ignored\n");
          break;
       case 2:
         if(root==NULL)
         {
           printf("Tree is empty\n");
           return 0;
         }
         printf("Tree is:\n");
         display(root,1);
         printf("\n\n");
         printf("Inorder Traversal:");
         inorder(root);
         printf("\n");
         break;
       case 3:
         exit(0);
       default:
         printf("Wrong Choice");
     }
   }while(ch);
}
