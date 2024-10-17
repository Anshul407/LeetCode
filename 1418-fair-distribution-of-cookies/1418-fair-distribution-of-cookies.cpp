class Solution {
public:
    int solve(vector<int>&cookies,vector<int>&vec,int i){
        if(i>=cookies.size()){
            int h=0;
            for(auto ii:vec)h=max(h,ii);
            return h;
        }
        int ans=INT_MAX;
        for(int j=0;j<vec.size();j++){
            vec[j]+=cookies[i];
            ans=min(ans,solve(cookies,vec,i+1));
            vec[j]-=cookies[i];
        }
        return ans;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>vec(k,0);
        return solve(cookies,vec,0);
    }
};