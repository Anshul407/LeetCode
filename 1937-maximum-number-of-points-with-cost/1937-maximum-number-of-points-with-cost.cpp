class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        if (m == 1) {
            long long maxi=0;
            for(int j=0;j<points[0].size();j++){
                maxi=max(maxi,(long long)points[0][j]);
            }
            return maxi;
        }
        
       vector<int> left(n, 0), right(n, 0), ans(n, 0);
        
      
        vector<int> prev(n, 0);
        
       
        for (int j = 0; j < n; ++j) {
            prev[j] = points[0][j];
        }
        
      
        for (int i = 1; i < m; ++i) {
           
            left[0] = prev[0];
            right[n - 1] = prev[n - 1];
            
        
            for (int j = 1; j < n; ++j) {
                left[j] = max(prev[j], left[j - 1] - 1);
            }
            
         
            for (int j = n - 2; j >= 0; --j) {
                right[j] = max(prev[j], right[j + 1] - 1);
            }
            
          
            for (int j = 0; j < n; ++j) {
                ans[j] = max(points[i][j] + left[j], points[i][j] + right[j]);
            }
            
            
            prev = ans;
        }
        
        return *max_element(ans.begin(), ans.end());
    }
};
