import math
G ={
    'A':{'M':2, 'S':1},
    'M':{'A':2,'S':3,'U':1,'Z':1},
    'S':{'A':1,'M':3,'U':7},
    'Z':{'U':3, 'M':1, 'W':4},
    'U':{'S':7,'M':1,'Z':3,'W':1},
    'W':{'U':1,'Z':4}
}

def initialize(G,start):
    cost=dict()
    previous= dict()
    for vertex in G.keys():
        cost[vertex]= math.inf
        previous[vertex]=None
    cost[start]=0
    return cost,previous

def relax(u,v,G,cost,previous):
    if cost[v] > cost[u]+G[u][v]:
        cost[v]=cost[u]+G[u][v]
        previous[v]=u
    return cost,previous

def dijkstra(G, start):
    cost,previous = initialize(G, start)
    visited = set()
    PQ = {}
    for vertex in G.keys():
        PQ[vertex] = cost[vertex]
    while(PQ):
        current = min(PQ, key=PQ.get)
        del PQ[current]
        visited.add(current)
        for neighbour in G[current].keys():
            if neighbour not in visited:
                old_cost=cost[neighbour]
                cost,previous = relax(current,neighbour,G,cost,previous)
                if old_cost > cost[neighbour]:
                    PQ[neighbour] = cost[neighbour]
    return cost,previous

def construct_path(previous, vertex):
    path = [ vertex]
    while(previous[vertex] != None):
        path.append(previous[vertex])
        vertex= previous[vertex]
        print(path)
    return "->".join(path[::-1])

start='A'
cost,previous = dijkstra(G,start)
for vertex in G.keys():
    print(f"Shortest path from {start} to {vertex} is {construct_path(previous,vertex)}|Cost={cost[vertex]}")

