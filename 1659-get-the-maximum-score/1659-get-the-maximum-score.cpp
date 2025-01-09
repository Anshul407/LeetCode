class Solution {
public:
    map<long long,long long>mp1;
    map<long long,long long>mp2;
    const long long mod=1e9+7;
    vector<vector<long long>>dp;
    long long solve(vector<long long>&a,vector<long long>&b,long long i,long long cur){
        if(cur==0&&i>=a.size()){
            return 0;
        }
        if(cur==1&&i>=b.size()){
            return 0;
        }
        if(dp[i][cur+1]!=-1)return dp[i][cur+1];
       
        long long op3=0,op4=0; 
        if(cur==0){
            if(mp2.find(a[i])!=mp2.end()){
                long long ct=mp2[a[i]];
                op3=(solve(a,b,ct+1,1)+a[i]);
             
            }
            op4=(solve(a,b,i+1,0)+a[i]);
           
        }else if(cur==1){
            if(mp1.find(b[i])!=mp1.end()){
                long long ct=mp1[b[i]];
                op3=(solve(a,b,ct+1,0)+b[i]);
              
            }
            op4=(solve(a,b,i+1,1)+b[i]);
            
        }

        return dp[i][cur+1]= (max({op3,op4}));
    }
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        for(long long i=0;i<nums1.size();i++)mp1[nums1[i]]=i;
        for(long long i=0;i<nums2.size();i++)mp2[nums2[i]]=i;
        long long maxi=max((long long)nums1.size(),(long long)nums2.size());
        dp.resize(maxi+1,vector<long long>(3,-1));
        vector<long long>n1,n2;
        for(auto i:nums1)n1.push_back(i);
        for(auto i:nums2)n2.push_back(i);
        auto ans= max(solve(n1,n2,0,0),solve(n1,n2,0,1));
        ans=ans%mod;
        return (int)ans;
        
    }
};