#include<stdio.h>
#include<bits/stdc++.h>
#include <vector>
#include <valarray>
#include <string>
#include <iostream>


class Solution{
public:
	// The main function that returns the arrangement with the largest value as
	// string.
static bool compare(string &s,string &st){
        return (s + st) > (st + s);
        
    }
    string printLargest(int n, vector<string> &arr) {
        // code here
        sort(arr.begin(), arr.end(), compare);
        
        string ans = "";
        
        for(string x : arr){
            ans+=x;
        }
        return ans;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<string> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printLargest(n, arr);
        cout << ans << "\n";
    }
    return 0;
}