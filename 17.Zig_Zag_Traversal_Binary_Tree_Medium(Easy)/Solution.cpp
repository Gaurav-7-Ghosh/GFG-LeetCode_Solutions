vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector<int> results;
        queue<Node*> q;
    	q.push(root);
    	int turn = 0;
    	while(!q.empty())
    	{
    	    int n = q.size();
    	    vector<int> te;
    	        for(int i = 0; i<n;i++)
    	        {
    	            Node* temp = q.front();
    	            q.pop();
    	            if(temp->left!=NULL)
    	            {
    	                q.push(temp->left);
    	            }
    	            
    	            if(temp->right!=NULL)
    	            {
    	                q.push(temp->right);
    	            }
    	           
    	           if(turn%2==0)
    	           {
    	               results.push_back(temp->data);
    	           }
    	           else
    	           {
    	               te.push_back(temp->data);
    	           }
    	           
    	        }
    	        if(turn%2!=0)
    	        {
    	            for(int i = te.size()-1;i>=0;i--)
        	        {
        	            results.push_back(te[i]);
        	        }   
    	        }
    	        
    	        turn++;
    	        
    	    
    	}
    	
    	return results;
    }