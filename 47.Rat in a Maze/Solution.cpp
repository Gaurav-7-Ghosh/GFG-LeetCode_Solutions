 vector<string> results;
    int    row[4] = {0,0,1,-1};
    int    col[4] = {1,-1,0,0};
    char shift[4]  ={'R','L','D','U'};
    
    bool isValid(int i, int j, int n)
    {
        if(i<0 || j <0 || i>=n || j>=n)
        {
            return false;
        }
        else
        return true;
    }
    void tracer (vector<vector<int>>& mat, vector<vector<int>>& visited,int i, int j,string path)
    
    { int n = mat.size();
      visited[i][j]=0;
            if(i==n-1 && j == n-1)
            {
                results.push_back(path);
                
            }
            
            for(int a =0; a<4;a++)
            {
                int r=i+row[a];
                int c=j+col[a];
                //cout<<"i: "<<i<<" j: "<<j<<" r: "<<i<<" c: "<<c<<endl;
                if( isValid(r,c,n) && visited[r][c]==-1 && mat[r][c]!=0)
                {
                    visited[r][c]=0;
                    //cout<<shift[a]<<" i:"<<i<<" j:"<<j<<endl;
                    tracer(mat,visited,r,c,path+shift[a]);    
                    visited[r][c]=-1;
                }
                
                
            
        
           
        }
         visited[i][j]=-1;
        
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        int n = mat.size();
        vector<vector<int>> visited(n,vector<int>(n,-1));
        if(mat[0][0]==0)
        {
            return results;
        }
        tracer(mat,visited,0,0,"");
        
        return results;
        
        
    }