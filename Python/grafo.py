#!/usr/bin/python
# -*- coding: utf-8 -*-

#   Made by Gilmar Soares

from pprint import pprint

def dijkstra(graph,start,target):
    inf = 0
    for u in graph:
        for v ,w in graph[u]:
           inf = inf + w
    dist = dict([(u,inf) for u in graph])
    prev = dict([(u,None) for u in graph])
    q = graph.keys()
    dist[start] = 0

    def x(v):
        return dist[v]

    while q != []:
        u = min(q, key=x)
        q.remove(u)
        for v,w in graph[u]:
            alt = dist[u] + w
            if alt < dist[v]:
                dist[v] = alt
                prev[v] = u

    trav = []
    temp = target
    while temp != start:
        trav.append(prev[temp])
        temp = prev[temp]
    trav.reverse()
    trav.append(target)
    return ' -> '.join(trav),dist[target]
graph = {
    'A' : [('B',5), ('D', 5), ('E', 7)],
    'B' : [('C', 4)],
    'C' : [('D', 8), ('E', 2)],
    'D' : [('C', 8), ('E', 6)],
    'E' : [('B', 3)],
    }

def main():
    soma = 0

    primeiro = ['A', 'B', 'C']
    segundo  = ['A', 'D']
    terceiro = ['A', 'D', 'C']
    quarto   = ['A', 'E', 'B', 'C', 'D']
    quinto   = ['A', 'E', 'D']
    sexto    = ['C', 'D', 'C']
    setimo   = ['A', 'C']
    oitavo   = []
    nono     = []
    decimo   = []

    rota = setimo

    for i in range(len(rota) - 1):
            if (i < len(rota)):
                inicio = rota[i]
                fim = rota[(i + 1) if i < (len(rota)) else i]
                traverse, dist = dijkstra(graph,inicio,fim)
                soma += dist

    print 'CUSTO DA ROTA --> ' + str(soma)

if __name__ == '__main__':
    main()

# Output #1: 9
# Output #2: 5
# Output #3: 13
# Output #4: 22
# Output #5: NO SUCH ROUTE
# Output #6: 2
# Output #7: 3
# Output #8: 9
# Output #9: 9
# Output #10: 7
