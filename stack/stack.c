#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int n;
  struct node* next;
  struct node* top;
}node;

int k;
node* head = NULL;
void pulsus(int x);
int extractum();
int quaerere(int p);
void ostende();

void createTumulus(){
  printf("Inserte el numero de tumulus a crear:");
  scanf("%d",&k);
}


void userInput(){
  int i,j,w;
  printf("\nSeleccione una opción:");
  printf("\n(1)Pulsus(x) inserta en la última pila");
  printf("\n(2)extractum() extrae el último elemento");
  printf("\n(3)quarere(p) retorna el TOP de la pila p");
  printf("\n(4)ostende(head) muestra cantidad de elementos almacenados en cada pila\n");
  scanf("%d",&i);
  if(i == 1){
    printf("\nInserte un número entero");
    scanf("%d",&j);
    pulsus(j);
    }
  if(i == 2)
    {
      printf("\nSe extraera el elemento:%d", extractum());
    }
  if(i == 3)
   { printf("\nInserte el número de la pila:");
    scanf("%d",&w);
    printf("Top de la pila N° %d: %d",w,quaerere(w));
    }
  if(i == 4){
    printf("\nLos elementos de cada pila son:");
    ostende();}
  }


void pulsus(int x){ //inserta x en la primera pila, si no desborda en las siguientes si no hay espacio crea otra pila.
if(head == NULL){
  node* temp = (node*)malloc(sizeof(node));
  node* temp1 = (node*)malloc(sizeof(node));
  temp1->n = x;
  temp->n = 1;
  temp->top = temp1;
  head = temp;
  userInput();
}
if(head->n < k){
  node* temp1 = (node*)malloc(sizeof(node));
  temp1->n = x;
  temp1->next = head->top;
  head->top = temp1;
  head->n++;
  userInput();
}
else{
  node* temp = (node*)malloc(sizeof(node));
  node* temp1 = (node*)malloc(sizeof(node));
  temp1->n = x;
  temp->n = 1;
  temp->top = temp1;
  temp->next = head;
  head = temp;
  userInput();
}
}

int extractum(){ //extrae el último elemento insertado y lo retorna
   node* temp;
    if(head->top == NULL){
      return 0;
    }
    else{
      temp = head->top;
      head->top = head->top->next;
      return head->top->n;
      free(temp);
    }
    userInput();
}

int quaerere(int p){ //retorna el top de la pila N° (p)
int i;
if(p == 0){
  return head->top->n;
  userInput();
}
else{
while(p > i){
 head = head->next;
 i++;
}
return head->top->n;
userInput();
}
}

void ostende(){ //muestra la cantidad de elementos en cada pila
int i = 0;
  while(head != NULL){
    printf("\nPila N°%d:%d",i,head->n);
    head = head->next;
    i++;
  }
  userInput();
}


int main(void) {
 createTumulus();
 userInput();
  return 0;
}