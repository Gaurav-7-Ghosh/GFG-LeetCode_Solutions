 bool BSTTraversal(Node* root, int left, int right)
    {
        if(root==NULL)
        {
            return true;
        }
        if(root->data <= left || root->data >= right)
        {
            return false;
        }
        
        return (BSTTraversal(root->left,left,root->data) && BSTTraversal(root->right,root->data,right));
        
    }
    
    
    
    
    bool isBST(Node* root) {
        // Your code here
        
        int leftMAX = INT_MIN;
        int rightMAX = INT_MAX;
        
        return BSTTraversal(root,leftMAX,rightMAX);
        
       
    }