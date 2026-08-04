class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        if source== destination:
            return True 
        graph=defaultdict(list)
        for u,v in edges :
            graph[u].append(v)
            graph[v].append(u)
        seen={source}
        queue=[source]
        while queue:
            node=queue.pop(0)
            if node==destination:
                return True
            for neighbour in graph[node]:
                if neighbour not in seen :
                    seen.add (neighbour)
                    queue.append(neighbour)
        return False
        