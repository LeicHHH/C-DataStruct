#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

typedef struct node{
  int data;
  struct node* right;
  struct node* mid;
  struct node* left;
}node;

int isLetter(int data);
int isVocal(int data);
void print(node* root);
void printGivenLevel(node* root, int level);
int height(node* node); 
void user_input(node* root);
node* search(node* root,int data);
void print2D(node* root);

node* getnewnode(int data){
  node* newnode = (node*)malloc(sizeof(node));
  newnode->data = data;
  newnode->left = newnode->right = newnode->mid = NULL;
  return newnode;
}

node*  insert(node* root, int data){
  if(isLetter(data)){
  if(root == NULL){
   root = getnewnode(data);
   return root;
  }
  else if(isVocal(data)){
    if(root->mid == NULL || data > root->mid->data){
      root->mid = insert(root->mid,data);
    }else{
      node* temp = root->mid;
      root->mid = getnewnode(data);
      root->mid->mid = temp;
      return root;
    }
  }
  else if(search(root, data) != NULL ){
    return root;
  }
  else{
  if(data < root->data){
    root->left = insert(root->left,data);
  }
  else if(data > root->data){
    root->right = insert(root->right,data);
  }
}
return root;
  }
else{
  return root;
}
}

int isLetter(int data){
    if(data == 65 || data == 66 || data == 67 || data == 68 || data == 69 || data == 70 || data == 71 || data == 72 || data == 73 || data == 74 || data == 75 || data == 76 || data == 77 || data == 78 || data == 79 || data == 80 || data == 81 || data == 82 || data == 83 || data == 84 || data == 85 || data == 86 || data == 87 || data == 88 || data == 89 || data == 90){
  return 1;
  }
  else{
  return 0;
  }
}

int isVocal(int data){
  if(data == 65 || data == 69 || data == 73 || data == 79 || data == 85){
  return 1;
  }
  else{
  return 0;
  }
}
void printLevelOrder(struct node* root) 
{ 
    int h = height(root); 
    printf("\nLevels:%d\n",h);
    int i; 
    for (i=1; i<=h; i++){
      printGivenLevel(root, i);
      printf("\n"); 
    }        
} 
  
/* Print nodes at a given level */
void printGivenLevel(node* root, int level) 
{ 
    if (root == NULL) 
        return; 
    if (level == 1) 
        printf(" %c ", root->data); 
    else if (level > 1) 
    { 
        printGivenLevel(root->left, level-1); 
        printGivenLevel(root->mid, level-1); 
        printGivenLevel(root->right, level-1); 
    } 
}

int height(node* node) 
{ 
    if (node==NULL) 
        return 0; 
    else
    { 
        /* compute the height of each subtree */
        int lheight = height(node->left); 
        int mheight = height(node->mid); 
        int rheight = height(node->right); 
  
        /* use the larger one */
        if (lheight > rheight && lheight > mheight) 
          return(lheight+1);
        else if(mheight > lheight && mheight > rheight)
          return(mheight+1);
        else 
          return(rheight+1); 
    } 
} 

void inorder(node*root){
if(root == NULL) {
  return;
}
  
	inorder(root->left);
  printf("%c ",root->data);
  inorder(root->mid);
	inorder(root->right);      // Visit right subtree
}

void print(node* root) 
{ 
print2D(root);
user_input(root);
}


node* search(node* root, int data) {
    if (root == NULL || root->data == data){
       return root; 
    }
    else if(root->data < data) {
       return search(root->right, data);
    }
    else if(isVocal(data)){
      return search(root->mid,data);
    }else{
      return search(root->left, data); 
    }
}

void user_input(node* root){
  char x,j;
  printf("\n(?)Para salir,(1)Print,(2)Buscar");
  printf("\nIngresa letra:");
  while(1){
  scanf("%c",&x);
  if(x == '?'){
    break;
  }
  /**else if(x == '2'){
    printf("Buscar:");
    scanf("%c",&j);
    if(search(root,j) != NULL){
      printf("[%c]Encontrado en el arbol",search(root,j)->data);
    }
    return;
  }
  **/
  else if(x == '1'){
    if(root == NULL){
      break;
    }
    else{
    print(root);
    }
  }else{
  x = toupper(x);
  root = insert(root, x);
  }
}
}

void print2DUtil(node *root, int space) 
{ 
  int i, COUNT = 6;
    // Base case 
    if (root == NULL) 
        return; 
  
    // Increase distance between levels 
    space += COUNT; 
  
    // Process right child first 
    print2DUtil(root->right, space); 

    // Print current node after space 
    // count 
    printf("\n");   printf("\n"); 
    print2DUtil(root->mid, space); 
    for (i = COUNT; i < space; i++) 
        printf(" "); 
    printf("%c\n", root->data); 
  
    // Process left child 
    print2DUtil(root->left, space); 
} 
  
// Wrapper over print2DUtil() 
void print2D(node *root) 
{ 
   // Pass initial space count as 0 
   print2DUtil(root, 0); 
}

int main(void) {
node* root = NULL;
user_input(root);
return 0;
}