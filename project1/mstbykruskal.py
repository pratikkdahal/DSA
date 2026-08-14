def kruskal(graph):
    n=len(graph)
    edges=[]  #for every edges of graph
    mst_edges=[]
    total_wt= 0
    for u in range(n):
        for v in range(u+1,n):
            wt = graph[u][v]
            if wt != 0:
                edges.append((wt,u,v))
    edges.sort()

    parent = list(range(n))

    def find(vertex):
        while parent[vertex] != vertex:
            vertex = parent[vertex]
        return vertex

    def union(u,v):
        root_u=find(u)
        root_v=find(v)

        #avoids cycle
        if root_u == root_v:
            return False
        parent[root_v] = root_u
        return True

    #from small wt to large
    for weight, u, v in edges:
        if union(u, v):
            mst_edges.append((u, v, weight))
            total_wt += weight

        if len(mst_edges) == n - 1:
            break
    return mst_edges, total_wt

graph = [
    [0, 1, 0, 0, 3],
    [1, 0, 2, 0, 7],
    [0, 2, 0, 7, 5],
    [0, 0, 7, 0, 1],
    [3, 7, 5, 1, 0]
]


result = kruskal(graph)

mst = result[0]

total = result[1]

print("---Kruskal Algorithm---")
print("Edges in Minimum Spanning Tree:")

for u, v, weight in mst:

    print(u, "-", v, ":", weight)


print("\nTotal weight of MST is:", total)