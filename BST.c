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
   	// Αν δεν υπάρχει δέντρο,τότε η ρίζα του δέντρου θα πάρει τη τιμή του δεδομένοy που ζητάμε να εισαχθεί, στο οποίο δείχνει ο δείκτης t.
  //Τα παιδιά right και left της νέας ρίζας θα δείχνουν στη τιμή NULL.    
   	        if((*rt)==NULL)
	        {
	         (*rt)=t;
	         (*rt)->left=NULL;
	         (*rt)->right=NULL;
	        }
// Όταν το μόνο στοιχείο του δέντρου είναι η ρίζα του root, τότε αν το δεδομένο data(κλειδί) που εισάγουμε είναι μεγαλύτερο 
//από το αντίστοιχο κλειδί της ρίζας τότε πηγαίνουμε στο αριστερό υπόδεντρο, αλλίως στο δεξιό υπόδεντρο. 
//Τα παιδιά right και left της νέας ρίζας θα δείχνουν στη τιμή NULL.
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
             
    // Στη περίπτωση που έχουμε ρίζα(root)με ένα δεξί(right)ή ένα αριστερό(left) παιδί(child),
//τότε χρησιμοποιούμε έναν βοηθητικό δείκτη a που δείχνει στη ρίζα και τότε πάλι αν το δεδομένο data(κλειδί) που εισάγουμε είναι μεγαλύτερο 
//από το αντίστοιχο κλειδί όπου δείχνει ο a τότε πηγαίνουμε στο αριστερό υπόδεντρο, αλλίως στο δεξιό υπόδεντρο.
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
void search(tp *rt)// Η υπορουτίνα void search(tp *rt) κάνει την αναζήτηση ενος στοιχείου στο δυαδικό δέντρο. Αν έχουμε ότι g=0,
//τότε το στοιχείο βρέθηκε, αλλίως δεν υπάρχει. Αυτή η υπορουτίνα χρησιμοποιείται και στην υπορουτίνα void DELETE(tp *rt) 
//για τη διαγραφή στοιχείου από το δυαδικό δέντρο.
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
    if(q==0)// Το στοιχείο που ψάχνουμε βρέθηκε.Χρησιμοποιούμε ένα δείκτη a για να δείχνει στο στοιχείο(κόμβο) που βρήκαμε.
    {
    //Εάν ο κόμβος που βρήκαμε έχει δύο παιδιά, χωρίς να μας ενδιαφέρει αν είναι η ρίζα ή όχι, τότε για αυτόν τον κόμβο βρίσκουμε τον αμέσως 
    //μεγαλύτερο διάδοχο(succesor), πηγαίνοντας στο δεξιό υπόδεντρο και διασχίζοντας το ύστερα αριστερά μέχρι να βρούμε το κόμβο 
	//χωρίς αριστερό παιδί(child).Μετά βάζουμε αυτόν τον κόμβο σε αυτόν που θέλουμε να διαγράψουμε.
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
     // Όταν ο κόμβος που θέλουμε να διαγράψουμε δεν είναι η ρίζα root και δεν έχει παιδιά τότε απλώς τον κάνουμε free. 
	 
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
    //Aν όμως έχει δεξί(right) ή αριστερό(left)παιδί(child),τότε σε κάθε περίπτωση πρέπει ο πατέρας(parent) του κόμβου 
	 //που θέλουμε να διαγράψουμενα δείχνει στο παιδί αυτού του κόμβου, και αντίστοιχα το παιδί αυτό να δείχνει 
	 //στο πατέρα(parent) αυτού του κόμβου.Έτσι αφού ο πατέρας(parent) του κόμβου προς διαγραφή έχει ως παιδί(child) του 
	 //το παιδί του κόμβου αυτού τότε κάνουμε free τον κόμβο οπού δείχνει ο δείκτης a.
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
	   
	 // Όταν ο κόμβος που θέλουμε να διαγράψουμε είναι η ρίζα root και δεν έχει παιδιά τότε απλώς τον κάνουμε free. 
	 if((a==(*rt))&&(a->left==NULL)&&(a->right==NULL))
         {
           free(a);
           (*rt)=NULL;
         }
      //Aν όμως έχει δεξί(right) ή αριστερό(left)παιδί(child),τότε αυτό το παιδί γίνεται η νέα ρίζα(root) του δέντρου και σε κάθε περίπτωση πρέπει ο πατέρας(parent)του παιδιού του κόμβου 
	 // προς διαγραφή, οπως και το παιδί αυτού του κόμβου, και αντίστοιχα το παιδί αυτό να δείχνει 
	 //στη τιμή NULL.Τέλος κάνουμε free τον κόμβο οπού δείχνει ο δείκτης a.   
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
   
    if((*rt)==NULL)// Στη περίπτωση αυτή δεν έχουμε δέντρο.
   { 
    printf("\n THE TREE IS EMPTY");
   }
        
 }       
  

void print_in_order(tp rt)// Μέσω αυτής της υπορουτίνας ,γίνεται διάσχιση του δέντρου(tree traversal)΄
// και εκτυπώνονται τα στοιχεία του δέντρου από το μικρότερο στο μεγαλύτερο.
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



