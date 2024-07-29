def findIndex(self,arr):
        
        breaker = False
        answer =-1
        low =0
        high =len(arr)-1
        while low <=high:
            
            mid = (low + high) // 2
            if arr[mid] == 0:
                low=mid+1
            elif arr[mid]==1:
                answer= mid
                high=mid-1
        
        return answer    

	def rowWithMax1s(self,arr):
		# code here
		value =-1
		current = 99999
		arraycounter =0
		for array in arr:
		    index = self.findIndex(array)
		    if index != -1 and index < current:
		        current = index
		        value = arraycounter
		    arraycounter+=1
		
		return value        