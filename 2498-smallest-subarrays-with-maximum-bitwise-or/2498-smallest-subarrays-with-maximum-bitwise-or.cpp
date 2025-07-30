class Solution {
public:
    void help(int cur,vector<vector<int>>&mp,int ind){
        for(int i=0;i<32;i++){
            if((cur>>i)&1==1)mp[i].push_back(ind);
        }
        return ;
    }
    int help3(vector<int>&v,int cur,int p){
        int i=0,j=v.size()-1;
        int ans=1e6;
        while(i<=j){
            auto mid=(i+j)/2;
            if(v[mid]>cur){
                ans=v[mid];
                j=mid-1;
            }else i=mid+1;
        }
      
        return ans;
    }
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<vector<int>>mp(33);
        int j=0;
        for(auto i:nums){
            help(i,mp,j);
            j++;
        }
        for(int i=0;i<32;i++)sort(mp[i].begin(),mp[i].end());
        vector<int>ans;
        for(int j=0;j<nums.size();j++){
            auto cur=nums[j];
            int curans=1;
            for(int i=0;i<32;i++){
                if(((cur>>i)&1)==0){
                    if(mp[i].size()>0){
                        int tempans=help3(mp[i],j,i);
                        if(tempans!=1e6)
                        curans=max(curans,tempans-j+1);
                    }
                }
            }
            if(curans==INT_MAX)curans=1;
            ans.push_back(curans);
        }
        return ans;
    }
};