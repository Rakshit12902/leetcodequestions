import heapq
from typing import List

class Solution:
    def countPaths(self, n: int, roads: List[List[int]]) -> int:
        mod = 1_000_000_007
        
        # 1. Fix adjacency list: append tuples correctly
        adj = [[] for _ in range(n)]
        for u, v, t in roads:
            adj[u].append((v, t))
            adj[v].append((u, t))
        
        # 2. Initialize Dijkstra's variables
        pq = [(0, 0)]  # (current_time, node)
        shortest_time = [float("inf")] * n
        shortest_time[0] = 0  # Missing initialization
        
        path_count = [0] * n  # Fix array declaration
        path_count[0] = 1
        
        while pq:
            ct, u = heapq.heappop(pq)
            
            if ct > shortest_time[u]:
                continue
                
            for v, road_time in adj[u]:
                new_time = ct + road_time
                
                # Found a strictly shorter path to v
                # Fix variable typos: 'shotrest_time' / 'shortes_time' -> 'shortest_time'
                if new_time < shortest_time[v]:
                    shortest_time[v] = new_time
                    path_count[v] = path_count[u]
                    heapq.heappush(pq, (new_time, v))
                
                # Found another shortest path to v
                elif new_time == shortest_time[v]:
                    path_count[v] = (path_count[v] + path_count[u]) % mod
                    
        # 3. Fix return statement: return the target node's path count
        return path_count[n - 1]
