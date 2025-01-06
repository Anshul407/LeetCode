class Solution {
public:
    static bool cmp(pair<int,int>&a,pair<int,int>&b){
        if(a.second==b.second)return a.first<b.first;
        return a.second<b.second;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int,int>>v;

        for(auto i:arr){
           v.push_back({i,abs(i-x)});
        }
        sort(v.begin(),v.end(),cmp);
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(v[i].first);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};