import heapq

def prims(graph, start=0):
    n=len(graph)
    visited = [False]*n
    mst_edges=[]
    total_wt = 0
    min_heap =[]    # wt,from,to
    visited[start]= True
    for vertex in range(n):
        wt = graph[start][vertex]
        if wt !=0:
            heapq.heappush(min_heap,(wt,start,vertex))   #wt = graph[start][vertex]

    while len(mst_edges)<n-1:

        weight,u,v = heapq.heappop(min_heap)

        #to avoid cycle 
        if visited[v]:
            continue
        else:
            visited[v]=True

        mst_edges.append((u,v,weight))
        total_wt += weight
        for next_vertex in range(n):
            if graph[v][next_vertex] !=0:
                if visited[next_vertex]==False:
                    heapq.heappush(min_heap, (graph[v][next_vertex],v,next_vertex)) 

    return mst_edges, total_wt

graph = [
    [0, 1, 0, 0, 3],
    [1, 0, 2, 0, 7],
    [0, 2, 0, 7, 5],
    [0, 0, 7, 0, 1],
    [3, 7, 5, 1, 0]
]
result = prims(graph, 0)

mst = result[0]

total = result[1]

print("---Prims Algorithm---")
print("Edges in minimum Spanning Tree:")

for u, v, weight in mst:

    print(u,"-", v, ":", weight)


print("\nTotal weight of MST is:", total)