class Solution {
public:
    static bool cmp(pair<int,int>p,pair<int,int>q){
        return p.second>q.second;
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        vector<pair<int,int>>v;
        for(auto i:boxTypes){
             v.push_back(make_pair(i[0],i[1]));
             sort(v.begin(),v.end(),cmp);
        }
        int ans=0;
        for(auto i:v){
            if(i.first>truckSize){
                ans=ans+(i.second*truckSize);
                truckSize=0;
            }else{
                ans+=(i.first*i.second);
                truckSize-=i.first;
            }
        }
        return ans;
    }
};