class Solution:
    ## Here the solution we use is instead of checking every cell for the possibility of reaching both oceans we work from the outside in.
    ## Since in the problem statement Pacific Ocean is connected on the top left side (row == 0 && col ==0) and Atlantic ocean is connected on the right side(row==n-1,col==n-1)

    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        ## We perform a DFS from each border cell to a ocean and check all reachable cells which
        def dfs(cell, visited):
            if cell in visited:
                return
            visited.add(cell)
            r, c = cell
            ## evaluating all 4 possiblities(move top,bottom,left,right)
            for nr, nc in [(r-1, c), (r+1, c), (r, c-1), (r, c+1)]:
                if 0 <= nr < rows and 0 <= nc < cols and heights[nr][nc] >= heights[r][c]:
                    dfs((nr, nc), visited)

        rows, cols = len(heights), len(heights[0])
        pacific, atlantic = set(), set()

        for r in range(rows):
            dfs((r, 0), pacific)
            dfs((r, cols - 1), atlantic)
        for c in range(cols):
            dfs((0, c), pacific)
            dfs((rows - 1, c), atlantic)

        return list(pacific & atlantic)