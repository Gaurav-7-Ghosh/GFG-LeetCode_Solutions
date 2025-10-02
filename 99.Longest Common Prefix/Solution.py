class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 0:
            return ""
        prefix = strs[0]
        for i in range(1, len(strs)):
            ## .find method returns -1 if not found or else the starting index of the substring in the string 
            while strs[i].find(prefix) != 0:
                ## Shortening the prefix to now search for by 1 index from the right
                prefix = prefix[0 : len(prefix) - 1]
                if prefix == "":
                    return ""
        return prefix