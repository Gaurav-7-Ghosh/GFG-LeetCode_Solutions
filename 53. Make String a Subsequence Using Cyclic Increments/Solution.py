class Solution:
    def canMakeSubsequence(self, str1: str, str2: str) -> bool:
        i = 0
        j = 0

        if(i<j):
            return False
        
        while i < len(str1) and j < len(str2):
            if str1[i] == str2[j] or (ord(str1[i]) - ord('a')+1)%26 + ord('a') == ord(str2[j]):
                i=i+1
                j=j+1
            else:
                i=i+1
        
        if j == len(str2):
            return True
        else:
            return False