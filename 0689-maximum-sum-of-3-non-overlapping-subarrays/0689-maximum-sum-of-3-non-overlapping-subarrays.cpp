class Solution {
public:
    vector<int>windowsum;
    vector<vector<int>>dp;
    int help(int cnt,int i,int k){
        if(cnt==0)return 0;
        if(i>=windowsum.size())return -1e6;;
        if(dp[i][cnt]!=-1)return dp[i][cnt];
        int op1=windowsum[i]+help(cnt-1,i+k,k);
        int op2=help(cnt,i+1,k);
        return dp[i][cnt]= max(op1,op2);
    }
    void solve(int cnt,int i,int k,vector<int>&ans){
        if(cnt==0)return ;
        if(i>=windowsum.size())return ;
        int op1=windowsum[i]+help(cnt-1,i+k,k);
        int op2=help(cnt,i+1,k);

        if(op1>=op2){
            ans.push_back(i);
            solve(cnt-1,i+k,k,ans);
        }else {
            solve(cnt,i+1,k,ans);
        }
    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int>ans;
        
        int i=0,j=0;
        int cur=0;
        while(j<nums.size()){
            cur+=nums[j];
            if(j-i+1==k){
                windowsum.push_back(cur);
                cur-=nums[i];
                i++;
            }
            j++;
        }
        dp.resize(windowsum.size()+1,vector<int>(3+1,-1));
        solve(3,0,k,ans);
        return ans;
    }
};