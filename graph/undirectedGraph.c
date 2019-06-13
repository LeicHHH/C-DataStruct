#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

struct AdjListNode 
{ 
    int dest; 
    struct AdjListNode* next; 
}; 
  
// A structure to represent an adjacency list 
struct AdjList 
{ 
    struct AdjListNode *head;  
}; 
  
// A structure to represent a graph. A graph 
// is an array of adjacency lists. 
// Size of array will be V (number of vertices  
// in graph) 
typedef struct Graph 
{ 
    int V; 
    struct AdjList* array; 
}Graph; 
  
// A utility function to create a new adjacency list node 
struct AdjListNode* newAdjListNode(int dest) 
{ 
    struct AdjListNode* newNode = 
     (struct AdjListNode*) malloc(sizeof(struct AdjListNode)); 
    newNode->dest = dest; 
    newNode->next = NULL; 
    return newNode; 
} 
  
// A utility function that creates a graph of V vertices 
struct Graph* createGraph(int V) 
{ 
    struct Graph* graph =  
        (struct Graph*) malloc(sizeof(struct Graph)); 
    graph->V = V; 
  
    // Create an array of adjacency lists.  Size of  
    // array will be V 
    graph->array =  
      (struct AdjList*) malloc(V * sizeof(struct AdjList)); 
  
    // Initialize each adjacency list as empty by  
    // making head as NULL 
    int i; 
    for (i = 0; i <= V; ++i) 
        graph->array[i].head = NULL; 
  
    return graph; 
} 
  
// Adds an edge to an undirected graph 
void addEdge(struct Graph* graph, int src, int dest) 
{ 
  if(src == dest){
    return;
  }
    struct AdjListNode* newNode = newAdjListNode(dest); 
    newNode->next = graph->array[src].head; 
    graph->array[src].head = newNode; 
  
    // Since graph is undirected, add an edge from 
    // dest to src also 
    newNode = newAdjListNode(src); 
    newNode->next = graph->array[dest].head; 
    graph->array[dest].head = newNode; 
} 
  
// A utility function to print the adjacency list  
// representation of graph 
void printGraph(struct Graph* graph) 
{ 
    int v; 
    for (v = 1; v <= graph->V; ++v) 
    { 
        struct AdjListNode* pCrawl = graph->array[v].head; 
        printf("Head[%d] ", v); 
        while (pCrawl) 
        { 
            printf("-> %d", pCrawl->dest); 
            pCrawl = pCrawl->next; 
        } 
        printf("\n"); 
    } 
} 

int read_nodes(){
  char file_name[20];
  printf("Node´s file:");
  scanf(" %s",file_name);
  FILE *file = fopen(file_name, "r");
  int i = 0;
  if(NULL == file){
    printf("Cannot open file");
    }
  size_t buffer_size = 20;
   char *buffer = malloc(buffer_size * sizeof(char));
  while(-1 != getline(&buffer, &buffer_size, file))
  {
    i++;
  }
  fflush(stdout);

    // make sure we close the file and clean up the buffer when we're
    // finished
  fclose(file);
  free(buffer);
  return i;
}

int read_edges(Graph* graph){
  char file_name[20];
  printf("Edge´s file:");
  scanf(" %s",file_name);
  int w,z, i = 0;
  FILE *file = fopen(file_name, "r");
  if(NULL == file){
    printf("Cannot open file");
  }
 size_t buffer_size = 10;
   char *buffer1 = malloc(buffer_size * sizeof(char));
  while(-1 != getline(&buffer1, &buffer_size, file))
  {
    fscanf(file,"%d,%d",&w,&z);
    addEdge(graph,w,z);
    i++;
  }
  fflush(stdout);

    // make sure we close the file and clean up the buffer when we're
    // finished
  fclose(file);
  free(buffer1);
  return i;
}

void ranking_graph(Graph* graph){
      int v,i[graph->V],counter,j; 
    for (v = 0; v <= graph->V; ++v) 
    { 
       counter = 0;
        struct AdjListNode* pCrawl = graph->array[v].head; 
        while (pCrawl) 
        {
            pCrawl = pCrawl->next;   
            counter++;
        }
        i[v] = counter;
    }
    for(j = 1; j < graph->V ; j++){
      printf("\nID:%d - Colaboraciones:%d",j,i[j]);
      }
}
    


void ver_nodo(Graph* graph, int V){
        struct AdjListNode* pCrawl = graph->array[V].head; 
        printf("Head[%d] ", V); 
        while (pCrawl) 
        { 
            printf("-> %d", pCrawl->dest); 
            pCrawl = pCrawl->next; 
        } 
        printf("\n"); 

}

int main(void) {
  int i,j,s,d;
  int nodes = read_nodes();
  Graph* graph = createGraph(nodes);
  int edges = read_edges(graph);
  printf("\nCantidad de nodos:%d",nodes);
  printf("\nCantidad de enlaces:%d",edges);
  do{
  printf("\n(1)Desplegar listas adyacentes");
  printf("\n(2)Mostrar Ranking");
  printf("\n(3)Ver nodo X");
  printf("\n(5)Salir");
  printf("\n             Opcion:");
  scanf("%d",&i);
  switch(i){
    case 1:
    printGraph(graph);
    break;
    case 2:
    ranking_graph(graph);
    break;
    case 3:
    printf("Ingrese ID:");
    scanf("%d",&s);
    ver_nodo(graph,s);
    break;
    case 4:
    printf("Ingrese origen:");
    scanf("%d",&s);
    printf("Ingrese destino:");
    scanf("%d",&d);
    addEdge(graph,s,d);
    break;
  }
  }while(i != 5);
}