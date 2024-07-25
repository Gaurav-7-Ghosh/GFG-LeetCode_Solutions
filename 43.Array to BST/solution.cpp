Node* findElement(vector<int>& nums,int low, int high)
    {
        if(high==low)
        {
            Node* root = new Node(nums[low]);
            return root;
        }
        
        if(low>high)
        {
            return NULL;
        }
        
        int mid = floor((low + high)/2);
        
        Node* root = new Node(nums[mid]);
        root->left  = findElement(nums,low,mid-1);
        root->right = findElement(nums,mid+1,high);
        return root;
        
        
        
    }
    Node* sortedArrayToBST(vector<int>& nums) {
        // Code here
        
        return findElement(nums,0,nums.size()-1);
    }