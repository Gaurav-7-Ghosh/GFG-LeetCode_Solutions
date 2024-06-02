  vector<int> constructList(int q, vector<vector<int>> &queries) {
        // code here
        vector<int> results;
        
        //results.push_back(0);
        
        int totalZOR =0;
        for(int i=q-1; i>=0;i--)
        {
            if(queries[i][0]==0)
            {
                results.push_back(queries[i][1] ^ totalZOR);
            }
            else
            {
               totalZOR = totalZOR ^ queries[i][1];
            }
        }
        
        results.push_back(0^totalZOR);
        sort(results.begin(),results.end());
        return results;
    }