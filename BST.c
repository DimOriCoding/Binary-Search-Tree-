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
   	// �� ��� ������� ������,���� � ���� ��� ������� �� ����� �� ���� ��� ��������y ��� ������ �� ��������, ��� ����� ������� � ������� t.
  //�� ������ right ��� left ��� ���� ����� �� �������� ��� ���� NULL.    
   	        if((*rt)==NULL)
	        {
	         (*rt)=t;
	         (*rt)->left=NULL;
	         (*rt)->right=NULL;
	        }
// ���� �� ���� �������� ��� ������� ����� � ���� ��� root, ���� �� �� �������� data(������) ��� ��������� ����� ���������� 
//��� �� ���������� ������ ��� ����� ���� ���������� ��� �������� ���������, ������ ��� ����� ���������. 
//�� ������ right ��� left ��� ���� ����� �� �������� ��� ���� NULL.
   	       if((*rt!=NULL)&&((*rt)->left==NULL)&&((*rt)->right==NULL)&&((*rt)->am>t->am))
               {
    	       (*rt)->left=t;
    	       (*rt)->left->left=NULL;
               (*rt)->left->right=NULL;
                t->parent=(*rt);
               }
          if((*rt!=NULL)&&((*rt)->left==NULL)&&((*rt)->right==NULL)&&((*rt)->am<t->am))
               {
    	        (*rt)->right=t;
    	        (*rt)->right->left=NULL;
                (*rt)->right->right=NULL;
                 t->parent=(*rt);
               }  
             
    // ��� ��������� ��� ������ ����(root)�� ��� ����(right)� ��� ��������(left) �����(child),
//���� �������������� ���� ��������� ������ a ��� ������� ��� ���� ��� ���� ���� �� �� �������� data(������) ��� ��������� ����� ���������� 
//��� �� ���������� ������ ���� ������� � a ���� ���������� ��� �������� ���������, ������ ��� ����� ���������.
   	      if((((*rt)!=NULL)&&((*rt)->left!=NULL))||(((*rt)!=NULL)&&((*rt)->right!=NULL)))
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
  
}
void search(tp *rt)// � ���������� void search(tp *rt) ����� ��� ��������� ���� ��������� ��� ������� ������. �� ������ ��� g=0,
//���� �� �������� �������, ������ ��� �������. ���� � ���������� ��������������� ��� ���� ���������� void DELETE(tp *rt) 
//��� �� �������� ��������� ��� �� ������� ������.
{
	    tp a;
	    int data,g;
	    if((*rt)==NULL)
        {
          printf("\n THE TREE IS EMPTY");
        }
	    if((*rt)!=NULL)
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
    if(q==0)// �� �������� ��� �������� �������.�������������� ��� ������ a ��� �� ������� ��� ��������(�����) ��� �������.
    {
    //��� � ������ ��� ������� ���� ��� ������, ����� �� ��� ���������� �� ����� � ���� � ���, ���� ��� ����� ��� ����� ��������� ��� ������ 
    //���������� �������(succesor), ����������� ��� ����� ��������� ��� ������������ �� ������ �������� ����� �� ������ �� ����� 
	//����� �������� �����(child).���� ������� ����� ��� ����� �� ����� ��� ������� �� �����������.
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
     // ���� � ������ ��� ������� �� ����������� ��� ����� � ���� root ��� ��� ���� ������ ���� ����� ��� ������� free. 
	 
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
    //A� ���� ���� ����(right) � ��������(left)�����(child),���� �� ���� ��������� ������ � �������(parent) ��� ������ 
	 //��� ������� �� ������������� ������� ��� ����� ����� ��� ������, ��� ���������� �� ����� ���� �� ������� 
	 //��� ������(parent) ����� ��� ������.���� ���� � �������(parent) ��� ������ ���� �������� ���� �� �����(child) ��� 
	 //�� ����� ��� ������ ����� ���� ������� free ��� ����� ���� ������� � ������� a.
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
	   
	 // ���� � ������ ��� ������� �� ����������� ����� � ���� root ��� ��� ���� ������ ���� ����� ��� ������� free. 
	 if((a==(*rt))&&(a->left==NULL)&&(a->right==NULL))
         {
           free(a);
           (*rt)=NULL;
         }
      //A� ���� ���� ����(right) � ��������(left)�����(child),���� ���� �� ����� ������� � ��� ����(root) ��� ������� ��� �� ���� ��������� ������ � �������(parent)��� ������� ��� ������ 
	 // ���� ��������, ���� ��� �� ����� ����� ��� ������, ��� ���������� �� ����� ���� �� ������� 
	 //��� ���� NULL.����� ������� free ��� ����� ���� ������� � ������� a.   
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
   
    if((*rt)==NULL)// ��� ��������� ���� ��� ������ ������.
   { 
    printf("\n THE TREE IS EMPTY");
   }
        
 }       
  

void print_in_order(tp rt)// ���� ����� ��� ����������� ,������� �������� ��� �������(tree traversal)�
// ��� ������������ �� �������� ��� ������� ��� �� ��������� ��� ����������.
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



