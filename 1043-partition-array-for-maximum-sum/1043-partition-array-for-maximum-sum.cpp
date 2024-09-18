class Solution {
public:
    vector<int>dp;
    int solve(vector<int>&arr,int i ,int k){
        if(i>=arr.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int tk=0;
        int maxi=0;
        
        for(int j=i;j < min((int)arr.size(), i + k);j++){
         
            maxi=max(arr[j],maxi);
            tk=max(tk,maxi*(j-i+1)+solve(arr,j+1,k));


        }
        return dp[i]=tk;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        dp.resize(arr.size(),-1);
       return solve(arr,0,k);
    }
};