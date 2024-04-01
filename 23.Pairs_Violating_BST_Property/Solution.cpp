void inorderTraversal(Node* root, vector<int>& inorder)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->left!=NULL)
        {
            inorderTraversal(root->left,inorder);
        }
        
        inorder.push_back(root->data);
        
        if(root->right!=NULL)
        {
            inorderTraversal(root->right,inorder);
        }
    }
    /*You are required to complete below function */
    int pairsViolatingBST(int n, Node *root) {
        // your code goes here
         vector<int>v;
        inorderTraversal(root,v);
        vector<int>tp;
        tp=v;
        sort(tp.begin(),tp.end());
        int ct=0;
        for(int i=0; i<v.size(); i++)
        {
            // The below lower_bound function is used to return the lower_bound is a standard library function in C++ 
            //provided by the <algorithm> header. It performs a binary search on a sorted range of elements 
            //(in this case, tp vector) and returns an iterator pointing to the first element that is not less than the given value (v[i]).
            
            // So when we get the index of the first element in the sorted array that is not smaller than the current value 
            // we are searching for then we subtract it from the start index and get the number of values which are less 
            // than the current value and thus get the no of pairs this value can form which are violating the BST property
            
            int ind=lower_bound(tp.begin(),tp.end(),v[i])-tp.begin();
            ct+=ind;
            tp.erase(tp.begin()+ind);
        }
        return ct;
    }