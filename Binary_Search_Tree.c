#include<stdio.h>
#include<stdlib.h>

typedef struct treenode *tp;
struct treenode
{
        int am;
        tp left;
        tp right;
        tp parent;

};
   tp rt,t,a,d,b,c;
   
   void  insert(tp *rt);
   void  search(tp *rt);
   void  DELETE(tp *rt);
   void  print_in_order(tp rt);
  
   
   
   int main (void)
   {
   
     char f;
     f='a';
     rt=NULL;
     
     
     while(f!='q')
     {
     	printf("\n Previous Fry %c \n", f);
     	
		 if (f!='q')
     	{
     		
     		printf("\n Give new choice \n");
     		f='a';
     		fflush(stdin);
     		f=getchar();
     		getchar();
     	   	if(f=='i')
			{
			    printf("\n INSERT \n");
			    insert(&rt);
			}
				if(f=='s')
			{
			    printf("\n SEARCH \n");
			    search(&rt);
			}
			
			if(f=='d')
			{
			    printf("\n DELETE \n");
			    DELETE(&rt);
			}
			
            if(f=='p')
			{
			   printf("\n PRINT_IN_ORDER \n");
			   print_in_order(rt);
			}
			
		}
     	
     }
     
   }



void insert(tp *rt)
{
	      tp t,a;
   	      int data;
   	      t=(tp)malloc(sizeof(struct treenode));
   	      printf("\n Give me an AM integer \n");
   	      scanf("%d",&data);
   	      getchar();
   	      t->am=data;
	      t->left=NULL;
	      t->right=NULL;
   	      printf("\n The AM of temp is %d \n", t->am);
// When the only element of the tree is the root, then if the data (key) we enter is greater 
//than the corresponding key of the root, we go to the left subtree, otherwise to the right subtree. 
//The right and left children of the new root will point to the NULL value.
   	       if((*rt!=NULL)&&((*rt)->left==NULL)&&((*rt)->right==NULL))
   	         {
   	          if((*rt)->am>t->am)
               {
    	       (*rt)->left=t;
    	       (*rt)->left->left=NULL;
               (*rt)->left->right=NULL;
                t->parent=(*rt);
               }
              else
               {
    	        (*rt)->right=t;
    	        (*rt)->right->left=NULL;
                (*rt)->right->right=NULL;
                 t->parent=(*rt);
               }  
             }
    // In the case where we have a root with a right or left child,
//then we use an auxiliary pointer a that points to the root, and then again, if the data (key) we enter is greater 
//than the corresponding key where a points, then we go to the left subtree, otherwise to the right subtree.
   	      if(((*rt)!=NULL)&&(((*rt)->left!=NULL)||((*rt)->right!=NULL)))
            {
              a=(*rt);
          
              while((a->left!=t)&&(a->right!=t))
               {
             
                if((a->am>=t->am)&&(a->left!=NULL))
                 {
                    a=a->left;
                 }
                if((a->am>=t->am)&&(a->left==NULL))
                 {
				  a->left=t;
                  t->parent=a;
                 } 
                 if((a->am<t->am)&&(a->right!=NULL)) 
                {
                   a=a->right; 
                } 
                if((a->am<t->am)&&(a->right==NULL))
                {
                    a->right=t;
                    t->parent=a;
                }
               }
            }
  // If there is no tree, then the root of the tree will take the value of the data we want to insert, which is pointed to by the pointer t.
  //The right and left children of the new root will point to the value NULL.    
   	        if((*rt)==NULL)
	        {
	         (*rt)=t;
	         (*rt)->left=NULL;
	         (*rt)->right=NULL;
	        }
}
void search(tp *rt)// The void search(tp *rt) subroutine searches for an element in the binary tree. If we have g=0,
//then the element was found, otherwise it does not exist. This subroutine is also used in the void DELETE(tp *rt) subroutine 
//to delete an element from the binary tree.
{
	    tp a;
	    int data,g;
	    if(*rt!=NULL)
	    {
	     a=*rt;
	     printf("\n Give me an AM integer \n");
   	     scanf("%d",&data);
         g=0;
         while((a->am!=data)&&(g==0))
          {
            if((a->am>data)&&(a->left!=NULL))
             {
                a=a->left;
             }
             if((a->am<data)&&(a->right!=NULL))
             {
                a=a->right;
		 	 }
            if(((a->am>data)&&(a->left==NULL))||((a->am<data)&&(a->right==NULL)))
             {
               g=1;
               printf("\n NOT FOUND");
             }
          }
          if(g==0)
          {
          	printf("\n ELEMENT IS FOUND");
          }
            
        }
        else
        {
          printf("\n THE TREE IS EMPTY");
        }
        
   
}
void DELETE(tp *rt)
{
    tp a,b,d,c;
    int data,q,s;
    if((*rt)!=NULL)
   {
   	    a=*rt;
   	    printf("\n Give me an AM integer \n");
   	    scanf("%d",&data);
   	    q=0;
      while((a->am!=data)&&(q==0))
          {
            if((a->am>data)&&(a->left!=NULL))
             {
                a=a->left;
             }
             if((a->am<data)&&(a->right!=NULL))
             {
                a=a->right;
		 	 }
            if(((a->am>data)&&(a->left==NULL))||((a->am<data)&&(a->right==NULL)))
             {
               q=1;
               printf("\n NOT FOUND");
             }
          }
    if(q==0)// The element we are looking for has been found. We use an index a to point to the element (node) we found.
    {
    //If the node we found has two children, regardless of whether it is the root or not, then for this node we find the immediate 
    //successor for this node by going to the right subtree and traversing it to the left until we find the node 
    //without a left child. Then we put this node in the one we want to delete.
		if((a->left!=NULL)&&(a->right!=NULL))
        {
          b=a->right;
          while(b->left!=NULL)
          {
            b=b->left;
          }
           s=b->am;
           b->am=a->am;
           a->am=s;
           a=b;
           
        }
     // When the node we want to delete is not the root node and has no children, we simply make it free. 
	 
		 if(a!=(*rt))
   	    {
   	        
		  if((a->left==NULL)&&(a->right==NULL))
           {
             d=a->parent;
             if((d->left!=NULL)&&(d->left->am==data))
             {   
              d->left->parent=NULL;
              d->left=NULL;
              free(d->left);
             }
             else if((d->right!=NULL)&&(d->right->am==data))
             {
		      d->right->parent=NULL;
		      d->right=NULL;
              free(d->right);
             }
           }
    //However, if it has a right or left child, then in any case the parent of the node 
     //we want to delete must point to the child of that node, and correspondingly that child must point 
	 //to the parent of this node. So, since the parent of the node to be deleted has as its child 
     //the child of this node, we then free the node pointed to by the pointer a.
          else if(a->left!=NULL)  
         {
            c=a->parent;
            if(a==c->left)
            {
              a->left->parent=c;
              c->left=a->left;
              a->left=NULL;
              c=NULL;
              free(a);
            }
            else if(a==c->right)
            {
              a->left->parent=c;
              c->right=a->left;
              a->left=NULL;
              c=NULL;
              free(a);
            }
		 }
           else if(a->right!=NULL)
           {
               c=a->parent;
               if(a==c->right)
               {
                a->right->parent=c;
                c->right=a->right;
                a->right=NULL;
                c=NULL;
                free(a);
               }
               else if(a==c->left)
               {
               a->right->parent=c;
               c->left=a->right;
               a->right=NULL;
               c=NULL;
               free(a);
               }
         
		    }
	     }
	   
	 // When the node we want to delete is the root node and has no children, we simply make it free. 
	 if((a==(*rt))&&(a->left==NULL)&&(a->right==NULL))
         {
           free(a);
           (*rt)=NULL;
         }
      //However, if it has a right or left child, then that child becomes the new root of the tree, and in any case, the parent of the child node 
	 // to be deleted, as well as the child of that node, and correspondingly that child must point 
     //to the NULL value. Finally, we free the node pointed to by the pointer a.  
     if((a==(*rt))&&(a->right!=NULL))
         {
            (*rt)=a->right;
            a->right->parent=NULL;
            a->right=NULL;
            free(a);
         }
     if((a==(*rt))&&(a->left!=NULL))
         { 
           (*rt)=a->left;
           a->left->parent=NULL;
           a->left=NULL;
           free(a);
         }
         
    }
    
         
   }
   
    if((*rt)==NULL)//In this case, we do not have a tree.
   { 
    printf("\n THE TREE IS EMPTY");
   }
        
 }       
  

void print_in_order(tp rt)// Μέσω αυτής της υπορουτίνας ,γίνεται διάσχιση του δέντρου(tree traversal)΄
// και εκτυπώνονται τα στοιχεία του δέντρου με σειρά από το μικρότερο στο μεγαλύτερο.
{
	tp a;
	a=rt;
    if(a!=NULL)
    { 
		  if(a->left!=NULL)
          {
           print_in_order(a->left);
          }
		   
		   printf("\n %d", a->am);
           
		   if(a->right!=NULL)
          {
           print_in_order(a->right);
          }
    }
}




