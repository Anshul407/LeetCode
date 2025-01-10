class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string,int>mp1,mp2;
        for(int i=0;i<list1.size();i++){
            mp1[list1[i]]=i;
        }
        int prev=INT_MAX;
        vector<string>ans;
        for(int i=0;i<list2.size();i++){
            auto cur=list2[i];
            if(mp1.find(cur)!=mp1.end()){
                if(mp1[cur]+i<prev){prev=mp1[cur]+i;
                    ans.clear();
                    ans.push_back(cur);
                }else if(mp1[cur]+i==prev)ans.push_back(cur);
            }
        }
        return ans;
    }
};