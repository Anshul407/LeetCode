class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        map<int,vector<int>>mp;
        vector<int>ind(n,0);
        for(auto i:edges){
            mp[i[0]].push_back(i[1]);
            ind[i[1]]++;
        }
        int ans=-1;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!ind[i]){ans=i;cnt++;}
            if(cnt>1)return -1;

        }
        return ans;
        
    }
};