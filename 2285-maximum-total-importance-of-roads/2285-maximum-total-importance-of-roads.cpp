class Solution {
public:
    static bool cmp(pair<int,int>p,pair<int,int>q){
        return p.second>q.second;
    }
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>ind(n,0);
        for(auto i:roads){
            ind[i[0]]++;
            ind[i[1]]++;
        }
        vector<pair<int,int>>vp;
        int j=0;
        for(auto i:ind){
            vp.push_back({j,i});
            j++;
        }
        sort(vp.begin(),vp.end(),cmp);
        map<int,int>mp;
        for(auto i:vp){
            mp[i.first]=n;
            n--;
        }
        long long ans=0;
        for(auto i:roads){
            ans+=(mp[i[0]]+mp[i[1]]);
        }
        return ans;

    }
};