 def spirallyTraverse(self, matrix):
        # code here
        n,m = len(matrix),len(matrix[0])
        ans = []
        l,r,t,b = 0,m,0,n
        while l<r and t<b:
            
            for i in range(l,r):
                ans.append(matrix[t][i])
            t += 1
            for i in range(t,b):
                ans.append(matrix[i][r-1])
            r -= 1
            if not (l<r and t<b):
                break
            for i in range(r-1,l-1,-1):
                ans.append(matrix[b-1][i])
            b -= 1
            for i in range(b-1,t-1,-1):
                ans.append(matrix[i][l])
            l += 1
        return ans