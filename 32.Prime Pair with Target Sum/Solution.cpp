 vector<int> getPrimes(int n) {
        // code here
        
        vector<bool> ear (n+1,true);
        ear[0]=false;
        ear[1]=false;
        for(int i=2;i*i<=n;i++)
        {
            if(ear[i])
            {
                
                for(int j = i*i;j<=n;j+=i)
                {
                    ear[j]=false;
                }
                
            }
        }
        
        unordered_set<int> s;
        
        vector<pair<int,int>> results;
        vector<int> last;
        
        int minindex=-1;
        int mini = -1;
        int mini2 =-1;
       
        for(int i=2;i<=n;i++)
        {
            int value = n-i;
            
                if(ear[value] && ear[i])
                {
                    
                    if(i<value)
                    {
                        mini =i;
                        mini2=value;
                        //results.push_back({i,value});
                        //results.push_back(value);
                    }
                    else
                    {
                        mini =value;
                        mini2=i;
                        //results.push_back({value,i});
                        
                    }
                    
                }
        
            
           
        }
        
       
        
        
      
            last.push_back(mini);
            last.push_back(mini2);
        
        
        return last;
    }