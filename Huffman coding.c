#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>


/** Implémentation **\: ARBRE BINAIRE DE ENTIERS**/

  /** Arbres de recherche binaire **/


  typedef struct Noeud_Ai * pointeur ;

  struct Noeud_Ai
    {
      int  Val ;
      pointeur fg ;
      pointeur fd ;
      pointeur pere ;
     } ;

  int info( pointeur P )
    { return P->Val;   }

  pointeur fg ( pointeur P)
    { return P->fg ; }

  pointeur fd( pointeur P)
    { return P->fd ; }

  pointeur pere( pointeur p)
  { return p->pere ; }

  void aff_info ( pointeur P, int Val)
    {
       P->Val = Val ;
    }

  void Aff_fg( pointeur P, pointeur Q)
    { P->fg =  Q;  }

  void Aff_fd( pointeur P, pointeur Q)
    { P->fd =  Q ; }

  void aff_pere( pointeur p, pointeur Q)
    { p->pere = Q ; }

  void creernoeud( pointeur *P ,int val)
    {
      *P = (struct Noeud_Ai *) malloc( sizeof( struct Noeud_Ai))   ;
      (*P)->fg = NULL;
      (*P)->fd = NULL;
      //aff_info(*P,val);
       (*P)->Val = val;

      (*P)->pere = NULL;
    }
    pointeur CreerNoeud (int val)
{
    pointeur p;
    p = (struct Noeud_Ai *) malloc( sizeof( struct Noeud_Ai))   ;
    p->Val = val;
    p->fg = NULL;
    p->fd = NULL;
    return (p);
}

  void liberernoeud ( pointeur P)
    { free( P ) ; }
    
    

pointeur creer ( pointeur root , int val)
      {
          if(!root){ // root = null
          creernoeud(&root,val);
          return root ;}

          else if(val<info(root)) {Aff_fg(root,creer(fg(root),val)) ;aff_pere(creer(fg(root),val),root) ;}
          else if(val>info(root)) {Aff_fd(root,creer(fd(root),val)) ; aff_pere(creer(fd(root),val),root) ;}
          return root ;
      }
      
      
void creer_arb(pointeur *root)
   {
       int nb ;
       int i ;
       int val;
       printf("donner le nombre des elements de votre arbre \n");
       scanf("%d",&nb);
       for(i=0;i<nb;i++)
       {
           printf("donner une valeur : ");
           scanf("%d",&val);

           (*root) = creer((*root),val);
       }
   }
void print_tree(pointeur root)
{
    if(root == NULL)
        return ;
    if(pere(root)!= NULL)
    {
        printf("(%d) -> (%d)\n",info(pere(root)),info(root));

    }
    else




        printf("(%d)\n",info(root));

    if(fg(root)!=NULL)
        print_tree(fg(root));
     if(fd(root)!=NULL)
        print_tree(fd(root));

}




int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    pointeur root = NULL;
     int nd ;
     creer_arb(&root);
      print_tree(root);
    
    return 0;
}
