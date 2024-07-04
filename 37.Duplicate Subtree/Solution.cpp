   string solve(Node* root,vector<Node*>&ans,unordered_map<string,int>&mp)
  {
      
      if(root==NULL)
      return "@";
      string str=solve(root->left,ans,mp)+" "+solve(root->right,ans,mp)+to_string(root->data);
      mp[str]++;
      if(mp[str]==2)
      ans.push_back(root);
      return str;
  }
    vector<Node*> printAllDups(Node* root) 
    {
        unordered_map<string,int>mp;
        vector<Node*>ans;
        
        solve(root,ans,mp);
        return ans;
        
    }