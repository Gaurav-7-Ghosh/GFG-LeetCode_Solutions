 int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        queue<pair<Node*,int>> q;
        
        int level = -1;
        int mxlevel =0;
        int mxsum=0;
        q.push({root,root->data});
        while(!q.empty())
        {
            level++;
           
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                Node* temp = q.front().first;
                
                int currsum = q.front().second;
                
                q.pop();
                if(temp->right==NULL && temp->left==NULL)
                {
                    
                    if(level==mxlevel)
                    {
                         
                        mxsum= max(mxsum,currsum);    
                    }
                    else if(level>mxlevel)
                    {
                        mxlevel=level;
                        mxsum=currsum;
                    }
                    
                }
                
                if(temp->left!=NULL)
                {
                    q.push({temp->left,currsum+temp->left->data});
                }
                
                if(temp->right!=NULL)
                {
                    q.push({temp->right,currsum+temp->right->data});
                }
                
            }
            //cout<<endl;
        }
        return mxsum;
    }