class Solution {
public:
    int gcd(int a,int b){
        if(b==0)return a;
        return gcd(b,a%b);
    }
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        long long cur=numsDivide[0];
        for(int i=1;i<numsDivide.size();i++){
            cur=gcd(cur,numsDivide[i]);
            if(cur==1)break;
        }
        map<int,int>mp;
        int ans=0;
        cout<<cur;
        for(auto i:nums)mp[i]++;
        for(auto i:mp){
            if(cur%i.first==0)return ans;
            ans+=i.second;
        }return -1;
    }
};