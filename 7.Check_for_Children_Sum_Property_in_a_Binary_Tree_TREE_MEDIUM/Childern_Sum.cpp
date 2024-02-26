#include<stdio.h>
#include<bits/stdc++.h>
#include <vector>
#include <valarray>
#include <string>
#include <iostream>


/*Complete the function below

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){80
        data = x;
        left = right = NULL;
    }
};
*/

class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    
    
    int isSumProperty(Node *root)
    {
     // Add your code here
     if(root==NULL)
     {
         return 1;
     }
     if(root->left==NULL && root->right==NULL)
     {
         return 1;
     }
     else
     {
         int temp =0; 
         if(root->left!=NULL)
         {
             temp+=root->left->data;
         }
         if(root->right!=NULL)
         {
             temp+=root->right->data;
         }
         
         
         if(temp == root->data && isSumProperty(root->left) && isSumProperty(root->right))
         {
             return 1;
         }
         
     }
     
     return 0;
     
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.isSumProperty(root) << endl;
    }
    return 0;
}