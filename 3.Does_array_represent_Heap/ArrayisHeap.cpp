#include<stdio.h>
#include<bits/stdc++.h>
#include <vector>
#include <valarray>
#include <string>
#include <iostream>

  bool isMaxHeap(int arr[], int n)
    {
        // Your code goes here
        bool flag = true;
        
        for(int i =0; i<n;i++)
        {
            bool child1=true;
            bool child2=true;
            int c1 = 2*i + 1;
            int c2 = 2*i + 2;
            if(c1<n && arr[c1]>arr[i])
            {
                child1=false;
                flag=false;
                break;
            }
            if(c2<n && arr[c2]>arr[i])
            {
                child1=false;
                flag=false;
                break;
            }
        }
        
        return flag;
    }
};

//{ Driver Code Starts.
int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
       int n;
       cin >> n;
       int a[4*n]={0};
       for(int i =0;i<n;i++){
           cin >> a[i];
       }
       Solution ob;
       cout<<ob.isMaxHeap(a, n)<<endl;
        
    }
    return 0;
}