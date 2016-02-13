#!/usr/bin/python3
# -*- coding: utf-8 -*-

#   Made by Gilmar Soares @ wwww.github.com/linuxsoares


def dijkstra(graph, start, target):
    inf = 0
    for u in graph:
        for v, w in graph[u]:
            inf = inf + w
    dist = dict([(u, inf) for u in graph])
    prev = dict([(u, None) for u in graph])
    q = [x for x in graph.keys()]
    dist[start] = 0

    while q != []:
        u = min(q, key=lambda x: dist[x])
        q.remove(u)
        for v, w in graph[u]:
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
    return ' -> '.join(trav), dist[target]


def main():
    graph = {
        'A': [('B', 5), ('D', 5), ('E', 7)],
        'B': [('C', 4)],
        'C': [('D', 8), ('E', 2)],
        'D': [('C', 8), ('E', 6)],
        'E': [('B', 3)],
    }

    routes = [
        ['A', 'B', 'C'],
        ['A', 'D'],
        ['A', 'D', 'C'],
        ['A', 'E', 'B', 'C', 'D'],
        ['A', 'E', 'D'],
        ['C', 'D', 'C'],
        ['A', 'C'],
        ['B', 'E'],
    ]

    print(":: Dijkstra's Algorithm Evaluation")
    for route in routes:
        soma = 0
        print('Route: {}'.format('->'.join(route)))
        for i in range(len(route) - 1):
                if (i < len(route)):
                    inicio = route[i]
                    fim = route[(i + 1) if i < (len(route)) else i]
                    traverse, dist = dijkstra(graph, inicio, fim)
                    print("{}: {}".format(traverse, dist))
                    soma += dist
        print('Route cost --> {}\n'.format(soma))

if __name__ == '__main__':
    main()
