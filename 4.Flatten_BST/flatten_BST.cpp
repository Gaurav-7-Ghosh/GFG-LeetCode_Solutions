#include<stdio.h>
#include<bits/stdc++.h>
#include <vector>
#include <valarray>
#include <string>
#include <iostream>

/* Node of the binary search tree 
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution
{
public:
    void dfsTraversal(Node* root, vector<int>& numbers)
    {
        if(root==NULL)
        {
            return;
        }
        
        numbers.push_back(root->data);
        if(root->left!=NULL)
        {
            dfsTraversal(root->left,numbers);
        }
        if(root->right!=NULL)
        {
            dfsTraversal(root->right,numbers);
        }
        
        
    }
    Node *flattenBST(Node *root)
    {
        // code here
        vector<int> numbers;
        dfsTraversal(root,numbers);
        
        sort(numbers.begin(),numbers.end());
        
        Node *newhead = new Node(numbers[0]);
        Node *curr=newhead;
        for(int i=1; i<numbers.size();i++)
        {
            Node *temp = new Node(numbers[i]);
            curr->right=temp;
            curr=curr->right;
        }
        return newhead;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string str;
        getline(cin, str);
        Node *root = buildTree(str);
        Solution ob;
        auto ans = ob.flattenBST(root);
        printList(ans);
    }
    return 0;
}
