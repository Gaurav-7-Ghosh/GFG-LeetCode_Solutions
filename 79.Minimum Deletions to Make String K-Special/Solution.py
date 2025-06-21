class Solution:
     def minimumDeletions(self, word: str, k: int) -> int:
        cnt = defaultdict(int)
        ## creating a default dictionary to store the character count of each character
        for c in word:
            cnt[c] += 1
        ## res is the worst case number of deletions to satisfy the problem by deleting all 
        ## charcaters
        res = len(word)
        ## here in each loop we take a as the base index trying to set the difference
        ## between a and a+k
        for a in cnt.values():
            deleted = 0
        ## for all values to see if b if less than a then delete all characters since it cannot
        ## be increased to the base a here we are trying else trim the extras
            for b in cnt.values():
                if a > b:
                    deleted += b
                elif b > a + k:
                    deleted += b - (a + k)
        ## taking the min in each iteration 
            res = min(res, deleted)
        return res