#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>

#include "graphs.h"

/* graphs - adjaceny matrix
-whenever there's a sparse graph -> wasted space
-as matrix gets big too many edges to test
-will have to resize if u want to add more nodes
*/

struct mygraph{
    int numnodes;
    bool **edges; //2d array
};

graph *create_graph(int numnodes){
    graph *g = malloc(sizeof(*g));

    if(g == NULL){
        return NULL;
    }

    g->numnodes = numnodes;

    //allocate matrix
    g->edges = calloc(sizeof(bool*), g->numnodes); //calloc inits everything to 0
    if (g->edges == NULL){
        free(g);
        return NULL;
    }

    for (int i = 0; i < numnodes; i++){
        g->edges[i] = calloc(sizeof(bool), g->numnodes);
        if(g->edges[i] == NULL){
            //cleanup again
            destroy_graph(g);
            return NULL;
        }
    }

    return g;
} //returns pointer

void destroy_graph(graph *g){
    if (g->edges == NULL){
        return;
    }

    for (int i = 0; i < g->numnodes; i++){
        if (g->edges[i] != NULL){
            free(g->edges[i]);
        }
    }

    free(g->edges);
    free(g);
}

void print_graph(graph *g){
    printf("digraph {\n");
    for (int from = 0; from < g->numnodes; from++){
        for (int to = 0; to < g->numnodes; to++){
            if (g->edges[from][to]){
                printf("%d -> %d;\n", from, to);
            }
        }
    }
    printf("}\n");
}

bool add_edge(graph *g, unsigned int from_node, unsigned int to_node){
    assert(g != NULL);
    assert(from_node < g -> numnodes);
    assert(to_node < g->numnodes);
    if (has_edge(g, from_node, to_node)){ //if the edge already exists don't make a new one
        return false;
    }
    g->edges[from_node][to_node] = true;
    return true;
}
bool has_edge(graph *g, unsigned int from_node, unsigned int to_node){
    assert(g != NULL);
    assert(from_node < g -> numnodes);
    assert(to_node < g->numnodes);
    return g->edges[from_node][to_node];
}

int main(){
    graph *g1 = create_graph(5);

    add_edge(g1, 0, 1);
    add_edge(g1, 0, 2);
    add_edge(g1, 0, 0);
    add_edge(g1, 1, 2);
    add_edge(g1, 1, 3);
    add_edge(g1, 3, 4);
    add_edge(g1, 4, 1);
    add_edge(g1, 4, 0);

    print_graph(g1);

    destroy_graph(g1);


}