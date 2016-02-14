/*
 * =====================================================================================
 *
 *                      Copyright 2015 Manoel Vilela
 *
 *
 *       Filename:  dijkstra.c
 *
 *    Description:  A implementation of dijkstra's algorithm in ANSI C
 *
 *         Author:  Manoel Vilela
 *        Contact:  manoel_vilela@engineer.com
 *   Organization:  UFPA
 *
 * =====================================================================================
**/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define X 6
#define Y 6
#define INFINITY INT_MAX
#define SELF 0
#define ROUTE_SIZE 7



/*===========================================================
 *
 *  -*-         The end of universe begin here          -*-
 *
 *===========================================================
 */


//      THE GRAPH
// .    A  B  C  D  E  F
//
// A    0 10  5  ∞  ∞  ∞
// B    ∞  0  2  1  ∞  ∞
// C    ∞  3  0  9  2  ∞
// D    ∞  ∞  ∞  0  2  6
// E    ∞  ∞  ∞  6  0  2
// F    ∞  ∞  ∞  ∞  ∞  0


// What the shortest path beteween A->F?


typedef enum {
    A, B, C, D, E, F
} Node;

int route[] = {A, E, C, D, F, B, A};

int graph[X][Y] = {
    { 0, 10,  5, INT_MAX, INT_MAX, INT_MAX},
    {INT_MAX,  0,  2,  1, INT_MAX, INT_MAX},
    {INT_MAX,  3,  0,  9,  2, INT_MAX},
    {INT_MAX, INT_MAX, INT_MAX,  0,  2,  6},
    {INT_MAX, INT_MAX, INT_MAX,  6,  0,  2},
    {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX,  0},
};


const char getNodeName(Node node) {
    switch (node) {
        case A: return 'A';
        case B: return 'B';
        case C: return 'C';
        case D: return 'D';
        case E: return 'E';
        case F: return 'F';
        default: return '-';
    }
}

int min(int array[X], int *index) {
    int smallest = INT_MAX;
    for (int i = 0; i < X; i++) {
        if (array[i] > 0 && array[i] < smallest) {
            smallest = array[i];
            *index = i;
        }
    }
    return smallest != INT_MAX ? smallest: -1;
}

void print_distance(int distance) {
    switch (distance) {
        case SELF:
            printf("SELF");
            break;
        case INFINITY:
            printf("∞");
            break;
        default:
            printf("%d", distance);
            break;
    }

    printf("\n");
}

void print_routes(char node, int edges[X]) {
    for (int i = 0; i < X; i++) {
        char neighbor = getNodeName(i);
        int distance = edges[i];
        printf("%c -> %c: ", node, neighbor);
        print_distance(distance);
    }
}

void join_route(int *route, const char *string, int size) {
    printf("Route: ");
    for (int i = 0; i < size; i++) {
        char node = getNodeName(route[i]);
        printf("%c", node);
        if (i + 1 < size) {
            printf("%s", string);
        }
    }
    printf("\n");
}

int exists(int distance){
    return distance != SELF && distance != INFINITY;
}

void init(int array[X]) {
    for (int x = 0; x < X; x++) {
        array[x] = INFINITY;
    }
}


// lol fu[n]ck_tion (not finished yet)
const char* dijkstra(int graph[X][Y], int start, int target) {
    int neighbor;
    int nodes[X];
    init(nodes);
    for (int i = 0; i < X; i++) {
        int dist = min(graph[i], &neighbor);
        if (!exists(dist)) {
            continue;
        } 
        for (int j = 0; j < Y; j++){
            //fucked ?!?!?
        }
    }
    return "NO_ROUTE";
}
int main(int argc, char *argv[]){
    int smallest;
    join_route(route, " -> ", ROUTE_SIZE);
    //printf("Len: %d\n", ilen(route));
    for (int i = 0; i < ROUTE_SIZE; i++) {
        char node = getNodeName(route[i]);
        print_routes(node, graph[route[i]]);
        int dist = min(graph[route[i]], &smallest);
        char neighbor = getNodeName(smallest);
        printf("Short distance: %c -> %c: %d\n\n", node, neighbor, dist);
    }
    return 0;
}