bool compareBinaryStrings(const std::string& a, const std::string& b) {
    
    return std::lexicographical_compare(b.begin(), b.end(), a.begin(), a.end());
}
class Solution{
public:
   
    

    void permutations(int index,int remCount,string current, vector<string>& results,int zCount,int oCount)
    {
        if(zCount>oCount)
        {
            return;
        }
        if(index==current.length())
        {
            //cout<<current<<" "<<remCount<<endl;
            if(remCount<=0)
            {
                results.push_back(current);
            }
            return;
        }
        
        
        
        current[index]='0';
        
        permutations(index+1,remCount,current,results,zCount+1,oCount);
        
        
        current[index]='1';
        permutations(index+1,remCount-1,current,results,zCount,oCount+1);
        
        
    }
	vector<string> NBitBinary(int n)
	{
	    // Your code goes here
	    vector<string> results;
	    int index = 1;
	    
	    string current;
	    current="1";
	    for(int i =1;i<n;i++)
	    {
	        current+="0";
	    }
	    int remCount;
	    if(n%2==0)
	    {
	       remCount= n/2-1;
	    }
	    else
	    {
	        remCount=n/2;
	    }
	     
	    permutations(1,remCount,current,results,0,1);
	    
	     std::sort(results.begin(), results.end(), compareBinaryStrings);
	    
	    
	    return results;
	}
};