class Solution {
public:
   static bool cmp(pair<int,int>p,pair<int,int>q){
        return p.first<q.first;
    }
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int,int>>v;
        for(int i=0;i<=n;i++){
           
            v.push_back({i-ranges[i],i+ranges[i]});
        }
        sort(v.begin(),v.end(),cmp);

       
        for(int i=0;i<v.size();i++){
            if(v[i].first>0)continue;
            int num=v[i].second;
            if(num==n)return 1;
            int cnt=0;
            int j=i+1;
            if(j>=v.size())return -1;
           for( j=i+1;j<v.size();j++){
            if(v[j].first==num){
                num=v[j].first;
                cnt++;
            }
            if(num==n)return cnt;
           }
        }
        return -1;
        
    }
};