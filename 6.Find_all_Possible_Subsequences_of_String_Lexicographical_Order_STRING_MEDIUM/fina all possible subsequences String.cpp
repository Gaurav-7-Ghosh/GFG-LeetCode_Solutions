#include<stdio.h>
#include<bits/stdc++.h>
#include <vector>
#include <valarray>
#include <string>
#include <iostream>


// } Driver Code Ends
class Solution{
	public:
	
	    static bool myCmp(string a, string  b)
	    {
	        return a<b;
	    }
	    
	    void Recurhelp (string s,string curr, int index, int n, vector<string>& answers)
	    {
	        if(index==n)
	        {
	            if(curr=="")
	            {
	                return;
	            }
	            answers.push_back(curr);
	        }
	        
	        else 
	        {
	            string temp = curr+s[index];
	            Recurhelp(s,temp,index+1,n,answers);
	            Recurhelp(s,curr,index+1,n,answers);
	            
	        }
	        return ;
	        
	    }
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> answers;
		    int n = s.length();
		    string init ="";
		    Recurhelp(s,init,0,n,answers);
		    sort(answers.begin(),answers.end(),myCmp);
		    
		    return answers;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends