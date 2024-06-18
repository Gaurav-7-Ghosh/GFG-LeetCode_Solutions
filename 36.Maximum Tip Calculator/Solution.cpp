class Solution {
  public:
    
  
    
    
    
   static bool cmp(pair<long long, long long> i, pair<long long, long long> j) {
        return abs(i.first - i.second) > abs(j.first - j.second);
    }

    long long maxTip(int n, int x, int y, vector<int>& arr, vector<int>& brr) {
        // Pairing tips from A and B arrays
        vector<pair<long long, long long>> a;
        for (int i = 0; i < n; i++) {
            a.push_back({arr[i], brr[i]});
        }
        
        // Sorting pairs by the absolute difference in descending order
        sort(a.begin(), a.end(), cmp);
        
        long long ans = 0;

        // Iterating through the sorted pairs and picking maximum tips
        for (int i = 0; i < n; i++) {
            if (a[i].first > a[i].second) {
                if (x > 0) {
                    x--;
                    ans += a[i].first;
                } else {
                    y--;
                    ans += a[i].second;
                }
            } else if (a[i].first < a[i].second) {
                if (y > 0) {
                    y--;
                    ans += a[i].second;
                } else {
                    x--;
                    ans += a[i].first;
                }
            } else {
                if (x > y) {
                    ans += a[i].first;
                    x--;
                } else {
                    ans += a[i].second;
                    y--;
                }
            }
        }
        
        return ans;
        
        
        
    }
};