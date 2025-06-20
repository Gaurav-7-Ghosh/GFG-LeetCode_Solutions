class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        character = [0]*255
        i=0
        mx = 0
        for k in range (len(s)):
            if(character[ord(s[k])]==0):
                character[ord(s[k])]+=1
                mx= max(mx,k-i+1)
            else:
                while(character[ord(s[k])]!=0):
                    character[ord(s[i])]-=1
                    i+=1
                character[ord(s[k])]+=1

        return mx  