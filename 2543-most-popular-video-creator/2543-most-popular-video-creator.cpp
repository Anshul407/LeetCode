class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        map<string,long long>mp;
        for(int i=0;i<creators.size();i++){
            mp[creators[i]]=mp[creators[i]]+views[i];
        }
        long long maxi=LLONG_MIN;
        for(auto i:mp){
            maxi=max(maxi,i.second);
        }
        
        map<string,pair<int,string>>mp2;
        for(auto i:mp){
            if(i.second==maxi){
                mp2[i.first]={-1,"abc"};
            }
        }
        for(int i=0;i<creators.size();i++){
            if(mp2.find(creators[i])!=mp2.end()){
                if(views[i]==mp2[creators[i]].first){
                    mp2[creators[i]].second=min(mp2[creators[i]].second,ids[i]);
                }else if(views[i]>mp2[creators[i]].first){
                    mp2[creators[i]]={views[i],ids[i]};
                }
            }
        }

        vector<vector<string>>ans;
        for(auto i:mp2){
            ans.push_back({i.first,i.second.second});
        }
        return ans;
       
    }
};