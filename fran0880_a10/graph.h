
#ifndef graph_h
#define graph_h
#define INFINITY 99999

#include <stdio.h>

typedef struct adjnode  {
    int vertex; // node id
    int weight; // edge weight from parent
    struct adjnode *next; // next node that is connected to index number node on graph
} ADJNODE;

typedef struct graph {
    int order;         //number of nodes
    int size;          //number of edges
    ADJNODE **adjlist; //pointer to an array of pointers of neighbor adjacency list
} GRAPH;

/* create and return a new adjacent list graph of order n */
GRAPH *new_graph(int n);

/* add a new edge (from, to, weight) to the graph passed by GRAPH *g,
 * if the edge (from, to) exists, update its weight,
 * else add the new adjacency node to the end of the linked list of the from node
 */
void add_edge(GRAPH *g, int from, int to, int weight);

/* return the weight of edge (from, to) if exists,
 * otherwise return INFINITY
 */
int get_weight(GRAPH *g, int from, int to);

/* display the graph the proper format*/
void display_graph(GRAPH *g);

/* clean the graph by free all dynamically allocated memory*/
void clean_graph(GRAPH **gp);


#endif /* graph_h */
