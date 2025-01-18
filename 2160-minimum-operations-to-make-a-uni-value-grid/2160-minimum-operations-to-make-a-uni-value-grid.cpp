class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>temp;
        for(auto i:grid){
            for(auto j:i)temp.push_back(j);
        }
        sort(temp.begin(),temp.end());
        int n=temp.size();
        int mid=temp[n/2];
        int ans=0;
        for(auto i:temp){
            int req=abs(mid-i);
            if(req%x!=0)return -1;
            ans+=req/x;
        }
        return ans;
    }
};