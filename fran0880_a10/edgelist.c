#include <stdio.h>
#include <stdlib.h>
#include "edgelist.h"

EDGELIST *new_edgelist() {
// your implementation
    EDGELIST *el = malloc(sizeof(EDGELIST));
    el->size = 0;
    el->start = NULL;
    el->end = NULL;
    return el;
}

void add_edge_end(EDGELIST *g, int from, int to, int weight) {
// your implementation
    if(!(g)) return;
    EDGE *ne = malloc(sizeof(EDGE));
    ne->from = from;
    ne->to = to;
    ne->weight = weight;
    ne->next = NULL;
    if(g->end == NULL) {
        g->end = ne;
        g->start = ne;
    }
    else {
        g->end->next = ne;
        g->end = ne;
    }
    g->size++;
}

void add_edge_start(EDGELIST *g, int from, int to, int weight) {
// your implementation
    if(!(g)) return;
    EDGE *ne = malloc(sizeof(EDGE));
    ne->from = from;
    ne->to = to;
    ne->weight = weight;
    if(g->start == NULL) {
        g->end = ne;
        g->start = ne;
    }
    else {
        ne->next = g->start;
        g->start = ne;
    }
    g->size++;
}

int weight_edgelist(EDGELIST *g) {
// your implementation
    int weightE = 0;
    EDGE *ptr = g->start;
    while(ptr) {
        weightE += ptr->weight;
        ptr = ptr->next;
    }
    return weightE;
}

void clean_edgelist(EDGELIST **gp) {
// your implementation
    if(!(*gp)) {printf("edgelist doesnt exist"); return;}
    EDGE *temp, *ptr = (*gp)->start;
    while(ptr) {
        temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
    (*gp)->start = NULL;
    (*gp)->end = NULL;
    free(*gp);
    *gp = NULL;
}

void display_edgelist(EDGELIST *g) {
    if (g == NULL) {printf("\ngraph does not exist"); return;}
  printf("\nweighted graph in edge list");
  printf("\nsize: %d", g->size);
  printf("\nformat: (from, to, weight)");
  EDGE *p = g->start;
  while (p) {
    printf("\n(%d, %d, %d)", p->from, p->to, p->weight);
    p = p->next;
  }
}

