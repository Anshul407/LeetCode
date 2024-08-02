class Solution {
public:
    static bool cmp(pair<int,int>p,pair<int,int>q){
        return p.first>q.first;
    }
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        vector<pair<int,int>>v;
        for(int i=0;i<values.size();i++){
            v.push_back({values[i],labels[i]});
        }
    sort(v.begin(),v.end(),cmp);
       map<int,int>mp;
       for(auto i:labels){
        if(mp.find(i)==mp.end())
        mp[i]=1;
       }
       int ans=0;
       for(auto i:v){
            if(numWanted==0)break;
            cout<<i.first;
            if(mp[i.second]<=useLimit){ans+=i.first;numWanted--;mp[i.second]++;}

       }
       return ans;
    }
};