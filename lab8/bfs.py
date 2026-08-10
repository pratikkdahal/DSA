def BFS(G, start):
    queue = list()
    visited = list()
    # Enqueue the starting vertex into queue
    queue.append(start)

    while(queue):
        vertex = queue.pop(0)
        if vertex not in visited:
            visited.append(vertex)

            for neighbour in G[vertex]:
                if neighbour not in queue and neighbour not in visited:
                    queue.append(neighbour)
    return visited


G = {
    'A': ['B', 'Q'],
    'Q': ['T', 'A', 'Y'],
    'B': ['A','T'],
    'T': ['Q','Y','B','Z'],
    'Y': ['T','S','Q'],
    'Z': ['S','W','T'],
    'S': ['Y','Z','W'],
    'W': ['Z','S']
}

start = 'A'

print("BFS Traversal:", BFS(G, start))