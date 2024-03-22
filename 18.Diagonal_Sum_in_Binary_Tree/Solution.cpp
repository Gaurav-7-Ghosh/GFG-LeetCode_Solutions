void assignValues(Node* root,int value, vector<pair<int,Node*>>& values)
    {
        if(root==NULL)
        {
            return;
        }
        //cout<<value<<endl;
        values.push_back({value,root});
        // if(root->left==NULL && root->right==NULL)
        // {
        //     return ;
        // }
        int current = value+1;
        assignValues(root->left,current,values);
        current = value;
        assignValues(root->right,current,values);
        //cout<<"Right"<<endl;      
        // return;
    }
    vector<int> diagonalSum(Node* root) {
        // Add your code here
        vector<pair<int,Node*>> values;
        assignValues(root,0,values);
        
        vector<int> results;
        
        //cout<<values.size();
        int mx =0;
        for(auto i : values)
        {
            mx = max(mx,i.first);
        }
        vector<int> sums(mx+1,0);
        
        for(auto i : values)
        {
            sums[i.first]+=i.second->data;
        }
        
        for(int i=0;i<=mx;i++)
        {
            results.push_back(sums[i]);
        }
        return results;
    }