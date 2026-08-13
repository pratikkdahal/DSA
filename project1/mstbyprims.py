import heapq

def prim(graph, start=0):
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
    [0, 3 ,2, 0, 0],
    [3, 0, 4, 3, 4],
    [2, 4, 0, 5, 0],
    [0, 3, 5, 0, 6],
    [0, 4, 0, 6, 0]
]

result = prim(graph,0)
mst = result[0]  #mst edges in mst
total=result[1]  #total wt in total

print("Edges in Minimum Spanning Tree:")

for u, v, weight in mst:
    print(u, "-", v, ":", weight)


print(f"Total weight of MST of given graph is {total}")