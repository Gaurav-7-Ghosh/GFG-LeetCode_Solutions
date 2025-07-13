class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        buckets = defaultdict(list) ## This dictionary (ans) will be used to store lists of anagrams grouped by a common key.
        for word in strs:
            buckets[tuple(sorted(word))].append(word) ## here we sort the word in lexiographical order and then take a tuple of the list since tuples can be used as hashkeys as they are immutable. Using the tuple value of the sorted word we append it. 
            ## The idea here is that any angram when sorted is the same and thus its tuple will be same for all 
        # print(buckets.values())
        return list(buckets.values())