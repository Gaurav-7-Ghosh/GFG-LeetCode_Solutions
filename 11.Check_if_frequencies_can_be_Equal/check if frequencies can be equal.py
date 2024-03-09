#User function Template for python3
class Solution:
    def sameFreq(self, s):
        # code here
        a = [0]*26
        for c in s:
            a[ord(c) - ord('a')] +=1
        
        if self.check(a):
            return True
        
        for i in range(26):
            if a[i]>0:
                a[i]-=1
                if self.check(a):
                    return True
                a[i]+=1
        
        return False
    
    
    def check (self,freq):
        n=-1
        for f in freq:
            if f >0:
                if n == -1:
                    n = f
                elif f!=n:
                    return False
        return True
            
        


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == "__main__":
	T=int(input())

	for _ in range(T):
		s = input()
		ob = Solution()
		answer = ob.sameFreq(s)
		if answer:
			print(1)
		else:
			print(0)
