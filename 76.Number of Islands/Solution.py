class Solution:
    def isSafe(self, i:int , j:int, m:int,n:int) -> bool:
        if i>=0 and i < m and j>=0 and j<n:
            return True
        return False
    
    def markSurrounding(self,i:int, j:int, grid: List[List[str]],visited:List[List[int]]):
        visited[i][j]=1
        rowT = [0, 0,-1,+1]
        colT = [1,-1, 0, 0]
        m = len(grid)
        n = len(grid[0])

        for a in range(4):
            if self.isSafe(i+rowT[a],j+colT[a],m,n) and visited[i+rowT[a]][j+colT[a]]==0 :
                newR = i+rowT[a]
                newC = j+colT[a]
                if grid[newR][newC] == "1":
                    self.markSurrounding(newR,newC,grid,visited)
                

    
    def numIslands(self, grid: List[List[str]]) -> int:
        
        m = len(grid)
        n = len(grid[0])
        visited = [[0 for _ in range(n)] for _ in range(m)]
        count =0
        for i in range(m):
            for j in range(n):
                if(visited[i][j]==0 and grid[i][j]=="1"):
                    self.markSurrounding(i,j,grid,visited)
                    count+=1
        
        return count 