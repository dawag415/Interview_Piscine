#include "header.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int minValue(struct s_node* node) 
{
	struct s_node* current = node;
 
     if (root == NULL)
      return INT_MIN;
 
    // Return maximum of 3 values:
    // 1) Root's data 2) Max in Left Subtree
    // 3) Max in right subtree
    int res = root->data;
    int lres = findMax(root->left);
    int rres = findMax(root->right);
    if (lres > res)
      res = lres;
    if (rres > res)
      res = rres;
    return res;
}
}

int maxValue(struct s_node* node)
{
	struct s_node* current = node;

  while (current->right != NULL) 
  {
    current = current->right;
  }
  return(current->value);
}

int isBST(struct s_node* node, int min, int max) 
{ 

  if (node==NULL) 
     return 1;
  if (node->value < min || node->value > max) 
     return 0; 

 
  return
    isBST(node->left, min, node->value-1) &&  
    isBST(node->right, node->value+1, max);  
} 
 int height(struct s_node* node) 
{
   if (node==NULL) 
       return 0;
   else
   {
       int lDepth = height(node->left);
       int rDepth = height(node->right);
 
       if (lDepth > rDepth) 
           return(lDepth+1);
       else return(rDepth+1);
   }
} 

unsigned int getNodeCount(struct s_node* node)
{
  if(node == NULL)       
    return 0;
  if(node->left == NULL && node->right==NULL)      
    return 1;            
  else
    return getNodeCount(node->left)+ getNodeCount(node->right) +1;      
}

bool isBalanced(struct s_node *root)
{
   int lh; 
   int rh; 
 
   if(root == NULL)
    return 1; 
   lh = height(root->left);
   rh = height(root->right);
   if( abs(lh-rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
     return 1;
   return 0;
}
 
struct s_info getInfo(struct s_node *root)
{	//printf("testfucked\n");
	//write(1,"fucked",6);
	struct s_info info;
	info =*(struct s_info*)malloc(sizeof(struct s_info));
	//printf("fucked\n");
	if (root != NULL)
	{
		info.min=minValue(root);
		info.max=maxValue(root);
		info.elements=getNodeCount(root);
		info.height=height(root)-1;
	}	
	info.isBST=isBST(root,info.min,info.max);
	info.isBalanced=isBalanced(root);
	//printf("min:%d\nmax:%d\nelements:%d\nheight:%d\nisBST:%d\nisBalanced:%d\n",info.min,info.max,info.elements,info.height,info.isBST,info.isBalanced );
return (info);
}