class Solution:
    

    def maximumGain(self, s: str, x: int, y: int) -> int:
        def remove_pattern(s, first, second,rewards):
            stack = deque()
            local_score = 0
            for ch in s:
                if stack and stack[-1] == first and ch == second:
                    stack.pop()
                    local_score += rewards
                else:
                    stack.append(ch)
            return ''.join(stack), local_score
        
        check = False
        if y >x:
            check = True
        score = 0

        if check:
            while True:
                s,local_Score = remove_pattern(s,'b','a',y)
                if local_Score == 0:
                    break
                score+=local_Score
            while True:
                s,local_Score = remove_pattern(s,'a','b',x)
                if local_Score == 0:
                    break
                score+=local_Score
        if not check:
            while True:
                s,local_Score = remove_pattern(s,'a','b',x)
                if local_Score == 0:
                    break
                score+=local_Score
            while True:
                s,local_Score = remove_pattern(s,'b','a',y)
                if local_Score == 0:
                    break
                score+=local_Score
        return score   
            
        

        