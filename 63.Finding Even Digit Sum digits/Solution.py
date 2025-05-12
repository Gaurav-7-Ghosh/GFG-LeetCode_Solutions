class Solution:
    def findEvenNumbers(self, digits: List[int]) -> List[int]:
        ## Creating a map to store the frequency of the digits appearing the digit array
        mpp=[0]*10
        ## Storing the frequency of each digit while traversing through the array
        for d in digits:
            mpp[d] += 1
        res = []
        ## Looping over every digit for the hundred and tenth's place but only even numbers
        ## for the unit's place since the question only requires 3 digit nums which are even
        for i in range(1, 10):
            if mpp[i] == 0: continue
            mpp[i] -= 1
            for j in range(10):
                if mpp[j] == 0: continue
                mpp[j] -= 1
                for k in range(0, 10, 2):
                    if mpp[k] == 0: continue
                    mpp[k] -= 1
                    ## for each digit if a certain combination exists then we add to res 
                    res.append(i*100 + j*10 + k)
                    mpp[k] += 1
                mpp[j] += 1
            mpp[i] += 1
        return res

        