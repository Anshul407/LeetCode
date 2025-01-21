class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        vector<long long>a(grid[0].size()),b(grid[0].size());

        a[0]=grid[0][0];
        b[0]=grid[1][0];
        for(int i=1;i<grid[0].size();i++){
            a[i]=a[i-1]+grid[0][i]*1LL;
            b[i]=b[i-1]+grid[1][i]*1LL;
        }
        long long ans=LLONG_MAX;
        for(int i=0;i<grid[0].size();i++){
            long long curop=0;
            curop=max(curop,a.back()-a[i]);
            if(i-1>=0){
                curop=max(curop,b[i-1]);
            }
            ans=min(ans,curop);
        }
        return ans;
    }
};