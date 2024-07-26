def kPangram(self,string, k):
        
    # code here
        spaces = 0
        for ch in string:
            if ch == ' ':
                spaces=spaces+1
            
        if (len(string)-spaces) <26:
            return False
        
        my_list = [0] * 26
        
        for ch in string: 
            if ch == ' ':
                continue
            my_list[(ord(ch)-97)]+=1
        
        
        count =0
        
        for value in my_list:
            if value == 0:
                count=count+1
        
        
        if count >k:
            return False
        
        
        return True
        