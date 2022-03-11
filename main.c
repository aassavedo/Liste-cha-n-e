#include <stdio.h>
#include <stdlib.h>
//L'enregistrement du cellule ou composant du cellule
struct node{
  int val;
  struct node *next;
};

//Creation d'une liste chain�e
struct node*creatlist(int n){
  struct node *p,*head,*Q; //D�claration des variables de la liste
  int x,i;

  p=malloc(sizeof(struct node)); //Allocation d'une espace
  scanf("%d",&x); //Ajout du premi�re �lements
  p->val=x; //Information que contient la cellule
  p->next=NULL; //Le pointeur de la cellule
  head=p; //Relier l'en t�te a la cellule

  for(i=1;i<n;i++){
    Q=p; //Attribution p � Q
    p=malloc(sizeof(struct node)); //Allocation d'une espace
    scanf("%d",&x); //Ajout du premi�re �lements
    p->val=x; //Information que contient la cellule
    p->next=NULL; //Le pointeur de la cellule
    Q->next=p; //Relier le precedent au nouveau
  }
  return head;
  }

//Lecture ou affichage de la liste chain�e
void display_list(struct node *head){
    while(head!=NULL){ //Verification que nous ne somme pas encore a la fin
      printf("%d ", head->val); //Affifichage de chaque �lement de la liste
      head=head->next; //Passage a l'address de l'�lement suivant
    }
  }

//Ajouter a la fin de la liste chain�e
void addTail(struct node *head, int addT){
  struct node *p; //Nouveau P
  p=malloc(sizeof(struct node)); //Allocation d'une espace pour p
  p->val=addT; //Information que contient la cellule
  p->next=NULL; //Le pointeur de la cellule
  while(head->next!=NULL){ //Parcourir jusqu'a la fin
    head=head->next;
  }
  head->next=p; //Relier le p a la fin
  }

//Ajouter au debut de la fonction
struct node *addHead(struct node *head, int addH){
  struct node *p;
  p=(struct note*)malloc(sizeof(struct node));
  p->val=addH;
  p->next=head;
  head=p;
  return head;
  }

struct node *init_node(void){
  struct node *n=(struct note*)malloc(sizeof(struct node));
  n->val=-1;
  return n;
  }

int main(){

  struct node *head;
  //head=init_node();
  head=creatlist(5);
  display_list(head);
  printf("\n");
  head=addHead(head,23);
  display_list(head);
  printf("\n");
  addTail(head,54);
  display_list(head);


  return 0;
 }
