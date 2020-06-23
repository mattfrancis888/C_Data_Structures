
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

GRAPH *new_graph(int vertex_number) {
// your implementation
    GRAPH *gp = malloc(sizeof(GRAPH));
    ADJNODE **np = malloc(vertex_number * sizeof(ADJNODE*));
    int i;
    for (i = 0;i<vertex_number; i++) np[i] = NULL;
    
    gp->adjlist = np;
    gp->order = vertex_number;
    gp->size = 0;
    return gp;
}

void add_edge(GRAPH *g, int from, int to, int weight) {
// your implementation
    if(0 > from || 0 > to || from > g->order || to > g->order) return;
    
    ADJNODE *prev = NULL, *ptr = g->adjlist[from];
    while(ptr) {
        if(ptr->vertex == to) return; //update weight
        else {
        prev = ptr;
        ptr = ptr->next;
        }
    }
    if(!(ptr)) {//add new adj node if to cannot be found or ptr is null to begin with
        ADJNODE *an = malloc(sizeof(ADJNODE));
        an->vertex = to;
        an->weight = weight;
        an->next = NULL;
        if(!(prev)) g->adjlist[from] = an;// if prev is null
        else prev->next = an; //if prev was not null, where prev was the last element, it should be assigned to adj node
    }
    g->size++;
    return;
}

int get_weight(GRAPH *g, int from, int to) {
// your implementation
    ADJNODE *ptr = g->adjlist[from]; //start for from and search for to and get it's weight
    while(ptr->vertex != to) ptr = ptr->next; 
    return ptr->weight;
}

void clean_graph(GRAPH **gp) {
// your implementation
    ADJNODE *temp, *ptr;
    for(int i = 0; i < (*gp)->order; i++) {
        ptr = (*gp)->adjlist[i];
        while(ptr) {
            temp = ptr;
            ptr = ptr->next;
            free(temp);
        }
        (*gp)->adjlist[i] = NULL;
    }
    free((*gp)->adjlist);
    free((*gp));
    (*gp) = NULL;
}

void display_graph(GRAPH *g) {
    if (g == NULL) {printf("\ngraph does not exist"); return; }
  printf("\nweighted graph in adjacency list");
  printf("\norder: %d", g->order);
  printf("\nsize: %d", g->size);
  printf("\nnode from: (to weight)");
  int i;
  ADJNODE *ptr;
  for (i = 0; i < g->order; i++) {
    printf("\nnode %d:", i);
    ptr = g->adjlist[i];
    while (ptr != NULL) {
      printf(" (%d, %d)", ptr->vertex, ptr->weight);
      ptr = ptr->next;
    }
  }
}

