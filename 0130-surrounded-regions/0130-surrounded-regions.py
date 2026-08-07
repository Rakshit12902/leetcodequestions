from typing import List

class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        if not board or not board[0]:
            return

        m = len(board)
        n = len(board[0])
        queue = []
        
        # 1. Find and enqueue all border 'O's
        for j in range(n):
            if board[0][j] == 'O':
                queue.append((0, j))
                board[0][j] = 'E'  # Mark as Escaped/Safe
            if board[m-1][j] == 'O':
                queue.append((m-1, j))
                board[m-1][j] = 'E'

        for i in range(m):
            if board[i][0] == 'O':
                queue.append((i, 0))
                board[i][0] = 'E'
            if board[i][n-1] == 'O':
                queue.append((i, n-1))
                board[i][n-1] = 'E'

        # 2. BFS from borders to find all connected safe 'O's
        directions = [[0, -1], [0, 1], [1, 0], [-1, 0]]
        while queue:
            x, y = queue.pop(0)
            for dr, dc in directions:
                u, v = x + dr, y + dc
                # Check grid boundaries and look for unvisited 'O's
                if 0 <= u < m and 0 <= v < n and board[u][v] == 'O':
                    board[u][v] = 'E'
                    queue.append((u, v))

        # 3. Post-process the board
        for i in range(m):
            for j in range(n):
                if board[i][j] == 'E':
                    board[i][j] = 'O'  # Revert safe regions back to 'O'
                elif board[i][j] == 'O':
                    board[i][j] = 'X'  # Flip surrounded regions to 'X'
