
class Solution {
public:
void leftboundary(Node* root,vector<int>&v)
{
    if((root==nullptr)||(root->left==nullptr && root->right==nullptr))
    {
        return;
    }
    // if(!(root->left==nullptr && root->right==nullptr))
    v.push_back(root->data);
     if(root->left!=nullptr)
    {
        leftboundary(root->left,v); 
    }
    else {
    leftboundary(root->right,v);
    }
}
void leaf(Node* root,vector<int>&v)
{
    if(root==nullptr)return;
    if(root->left==nullptr && root->right==nullptr)
    {
        v.push_back(root->data);
    }
     leaf(root->left,v);
     leaf(root->right,v);
}
void rightboundary(stack<int>&st,Node* root)
{
     if((root==nullptr)||(root->left==nullptr && root->right==nullptr))
    {
        return;
    }
    if(!(root->left==nullptr && root->right==nullptr))
    st.push(root->data);
      if(root->right!=nullptr)
    {
       rightboundary(st,root->right); 
    }
    else if(root->left!=nullptr)
    {
   rightboundary(st,root->left);
    }
//   return;
}
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int>v;
        if(root==nullptr)return v;
        v.push_back(root->data);
        if(root->left==nullptr && root->right==nullptr)
        {
            return v;
        }
        leftboundary(root->left,v);
        leaf(root,v);
        stack<int>st;
        rightboundary(st,root->right);
        while(!st.empty())
        {
            v.push_back(st.top());
            st.pop();
        }
        return v;
    }
};
