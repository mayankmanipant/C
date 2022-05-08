#include<stdio.h>
#include<stdlib.h>


struct node
{
  int data;
  struct node *left;
  struct node *right;
};


struct node *search(struct node *root,int key)
{
  if(root==NULL || root->data==key)
  {
    return root;
  }
  else if(root->data < key)
  {
    return search(root->right,key);
  }
  else if(root->data > key)
  {
    return search(root->left,key);
  }
}   


struct node *insert(struct node *root,int key)
{
  struct node *newnode;
  newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=key;
  newnode->left=NULL;
  newnode->right=NULL;
  if(root==NULL)
  {
    root=newnode;
    root->left=NULL;
    root->right=NULL;
  }
  if(key<root->data)
  {
    root->left=insert(root->left,key);
  }
  else if(key>root->data)
  {
    root->right=insert(root->right,key);
  }
  return root;
}


struct node* minvaluenode(struct node *root)
{
  struct node *temp=root;
  while(temp && temp->left!=NULL)
  {
    temp=temp->left;
  }
  return temp;                      
}


struct node *deletenode(struct node *root,int key)
{
  if(root==NULL)
  {
    return root;
  }
  if(key < root->data)
  {
    root->left = deletenode(root->left,key);
  }
  else if(key > root->data)
  {
    root->right = deletenode(root->right,key);
  }
  
  //node with only one child  
  
  else
  {
    if(root->left==NULL)
    {
      struct node *temp=root->right;
      free(root);
      return temp;
    }
    else if(root->right==NULL)
    {
      struct node *temp=root->left;
      free(root);
      return temp;
    }
    
  //node with two children 
  
  struct node *temp=minvaluenode(root->right); // finding the inorder successor
  
  root->data=temp->data;
  
  root->right=deletenode(root->right,temp->data);
  }
  return root;
}


int height(struct node *root)
{
  int leftheight,rightheight;
  if(root==NULL)
  {
    return 0;
  }
  else
  {
    leftheight = height(root->left);
    rightheight = height(root->right);
    if(leftheight > rightheight)
    {
      return (leftheight+1);
    }
    else
    {
      return (rightheight+1);
    }
  }
}


int totalnodes(struct node* root)
{
  if(root==NULL)
  {
    return 0;
  }
  else 
  {
    return(totalnodes(root->left)+totalnodes(root->right)+1);
  }
}


int internalnodes(struct node* root)
{
  if((root==NULL) || (root->left==NULL) || (root->right==NULL))
  {
    return 0;
  }
  else
  {
    return(internalnodes(root->left)+internalnodes(root->right)+1);
  }
}


int externalnodes(struct node* root)
{
  if(root==NULL)
  {
    return 0;
  }
  else if((root->left==NULL) && (root->right==NULL))
  {
    return 1;
  }
  else
  {
    return(externalnodes(root->left)+externalnodes(root->right));
  }
}


struct node* smallestelement(struct node* root)
{
  if((root==NULL) || (root->left==NULL))
  {
    return root;
  }
  else
  {
    return smallestelement(root->left);
  }
}


struct node* largestelement(struct node* root)
{
  if((root==NULL) || (root->right==NULL))
  {
    return root;
  }
  else
  {
    return largestelement(root->right);
  }
}


struct node* mirrorimage(struct node* root)
{
  struct node* temp;
  if(root!=NULL)
  {
    mirrorimage(root->left);
    mirrorimage(root->right);
    temp=root->left;
    root->left=root->right;
    root->right=temp;
  }
}


struct node* deletetree(struct node* root)
{
  if(root!=NULL)
  {
    deletetree(root->left);
    deletetree(root->right);
    free(root);
  }
}



void inorder(struct node *root)
{
  if(root==NULL)
  {
    return ;
  }
  inorder(root->left);
  printf("%d ",root->data);
  inorder(root->right);
}



int main()
{
  struct node *root=NULL;
  int ch,key;
  do
  {
    printf("\n1.INSERT   2.DELETE NODE   3.SEARCH   4.INORDER   5.HEIGHT  6.TOTAL NODES  7.INTERNAL NODES   8.EXTERNAL NODES  9.SMALLEST ELEMENT   10.LARGEST ELEMENT  11.MIRROR IMAGE  12.DELETE TREE   13.EXIT\n");
    printf("Enter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
      {
        printf("\nEnter data:");
        scanf("%d",&key);
        root=insert(root,key);
        break;
      }
      case 2:
      {
        printf("\nEnter data:");
        scanf("%d",&key);
        deletenode(root,key);
        break;
      }
      case 3:
      {
        printf("\nEnter data:");
        scanf("%d",&key);
        struct node *temp=search(root,key);
        if(temp->data == key)
        {
          printf("\nElement found succesfully.\n");
        }
        else
        {
          printf("\nElement not found");
        }
        break;          
      }
      case 4:
      {
        printf("\nThe inorder traversal is:");
        inorder(root);
        printf("\n");
        break;
      }
      case 5:
      {
        printf("\nHeight of the tree:%d \n",height(root));
        break;
      }
      case 6:
      {
        printf("\nTotal number of nodes:%d \n",totalnodes(root));
        break;
      }
      case 7:
      {
        printf("\nNumber of INTERNAL NODES:%d \n",internalnodes(root));
        break;
      }
      case 8:
      {
        printf("\nNumber of EXTERNAL NODES:%d \n",externalnodes(root));
        break;
      }
      case 9:
      {
        struct node* temp=smallestelement(root);
        printf("\nSmallest number:%d \n",temp->data);
        break;
      }
      case 10:
      {
        struct node* temp=largestelement(root);
        printf("\nLargest number:%d \n",temp->data);
        break;
      }
      case 11:
      {
        root=mirrorimage(root);
        break;
      }
      case 12:
      {
        root=deletetree(root);
        break;
      }
      case 13:
      {
        printf("\nEXITING...\n");
        exit(0);
      }
      default:
      {
        printf("\nEnter a valid choice.");
      }
    }
  }while(ch);
}
