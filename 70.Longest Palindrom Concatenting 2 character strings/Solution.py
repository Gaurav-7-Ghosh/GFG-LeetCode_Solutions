class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        ## Creating frequency count of all the words on the list
        mpp = Counter(words)
        count = 0
        ## for tracking strings which are inherently a palindrome itself and are in odd freqeuncy
        alreadyPalindrome = 0
        for w, freq in mpp.items():
            ## Reversing the string 
            s = w[::-1]
            if w == s:
                ## if the string is itself a palidrome
                count += (freq // 2) * 4
                if freq % 2:
                    ## if there is a odd frequency of such strings then we can place the odd one in the middle of the complete string 
                    alreadyPalindrome = 1
            elif w < s and s in mpp:
                ## for words not palindrome itself we check the frequency of it and its reverse. Take the lower one and add them to the answer
                count += min(freq, mpp[s]) * 4
        return count + alreadyPalindrome * 2
