 int BST(Node* root, int n, int ans)
    {
        if(root==NULL)
        {
            return ans;
        }
        
        if(root->key > n)
        {
            return BST(root->left,n,ans);
        }
        else
        {
            ans = root->key;
            return BST(root->right,n,ans);
        }
    }
    int findMaxForN(Node* root, int n) {
        // code here
        return BST(root,n,-1);
    }