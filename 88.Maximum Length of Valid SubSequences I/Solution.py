class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        mxEv,mxOdd,mxInterE,mxInterO=0,0,0,0
        indFE,indFO=-1,-1

        for i in range(len(nums)):
            if(nums[i]%2==0):
                if(indFE==-1):
                    indFE=i
                mxEv+=1
            if(nums[i]%2!=0):
                if(indFO==-1):
                    indFO=i
                mxOdd+=1
        
        if indFE !=-1:
            mxInterE=1
            turn = 1
            for i in range(indFE+1,len(nums)):
                if turn ==1:
                    if nums[i] %2 !=0:
                        mxInterE+=1
                        turn = 0
                if turn == 0:
                    if nums[i] % 2 == 0:
                        mxInterE+=1
                        turn = 1

        if indFO!= -1:
            mxInterO=1
            turn = 0
            for i in range(indFO+1,len(nums)):
                if turn ==1:
                    if nums[i] %2 !=0:
                        mxInterO+=1
                        turn = 0
                if turn == 0:
                    if nums[i] % 2 == 0:
                        mxInterO+=1
                        turn = 1  

        
        return max(mxInterO,max(mxInterE,max(mxEv,mxOdd)))  



        