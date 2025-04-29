class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0])return a[1]>b[1];
        return a[0]<b[0];
    }
    int find(vector<vector<int>>&e,int cur){
        int i=0,j=e.size()-1;
        int ans=e.size();
        while(i<=j){
            auto mid=(i+j)/2;
            if(e[mid][1]<cur)i=mid+1;
            else ans=mid,j=mid-1;
        }return ans;
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<vector<int>>ans;
        sort(envelopes.begin(),envelopes.end(),cmp);
        ans.push_back({envelopes[0][0],envelopes[0][1]});
        for(int i=1;i<envelopes.size();i++){
            if(ans[ans.size()-1][1]<envelopes[i][1]){
                ans.push_back(envelopes[i]);
            }else{
                auto x=find(ans,envelopes[i][1]);
                if(x!=ans.size())
                ans[x]=envelopes[i];
            }
        }return ans.size();
    }
};