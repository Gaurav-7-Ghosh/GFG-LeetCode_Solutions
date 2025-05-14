class Solution:
    mod = 10**9 + 7

    ## Method for performing a matrix Multiplication of Two matrixes A and B
    def multiplyMatrices(self, A, B):
        rowsA, colsA, colsB = len(A), len(A[0]), len(B[0])
        result = [[0]*colsB for _ in range(rowsA)]
        for i in range(rowsA):
            for j in range(colsB):
                tmp = 0
                for k in range(colsA):
                    tmp += A[i][k] * B[k][j]
                result[i][j] = tmp % self.mod
        return result

    ## Method to use Matrix Exponentiation to raise a matrix to power 
    def powerMatrix(self, matrix, exponent):
        n = len(matrix)
        result = [[1 if i==j else 0 for j in range(n)] for i in range(n)]
        while exponent > 0:
            if exponent & 1:
                result = self.multiplyMatrices(result, matrix)
            matrix = self.multiplyMatrices(matrix, matrix)
            exponent >>= 1
        return result

    ## Here the logic is simply that when there are t>=1000008 transformations then 
    ## simply performing sequential operations would lead to TLE and memory issues
    ## So we use the concept of matrix exponentiation where we create a matrix of 
    ## 26 X 26 (26 small case letters in our domain as specified in the question)
    ## and initialize it as a Identity Matrix. 
    ## We create a 26×26 matrix where transform[i][j] is the count of ways letter i can become letter j in one step.
    ## (i + shift) % 26 handles the circular shift through ‘a’–‘z’. 
    ## then for the frequency of each character in the string we perform a matMul with the Transition Matrx raised to the power of T for the answer
    def lengthAfterTransformations(self, s, t, nums):
        transform = [[0]*26 for _ in range(26)]
        for i in range(26):
            for shift in range(1,nums[i]+1):
                transform[i][(i + shift) % 26] += 1
        transform = self.powerMatrix(transform, t)
        freq = [[0]*26]
        for ch in s:
            freq[0][ord(ch) - ord('a')] += 1
        freq = self.multiplyMatrices(freq, transform)
        return sum(freq[0]) % self.mod
        