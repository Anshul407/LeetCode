class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<int,int>mp;
        map<vector<int>,int>st;
        sort(nums.begin(),nums.end());
        for(auto i:nums)mp[i]++;
        for(int i=0;i<nums.size();i++){
            int p=INT_MAX;
            for(int j=i+1;j<nums.size();j++){
                if(p!=nums[j])
                p=nums[j];
                else continue;
                auto cur=nums[i]+nums[j];
                auto req=-1*cur;
                if(mp.find(req)!=mp.end()){
                    if(nums[i]==req&&nums[j]==req&&mp[req]<=2)continue;
                    cout<<req<<" ";
                    if((nums[i]==req||nums[j]==req)&&mp[req]<=1)continue;
                    vector<int>v;
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                    v.push_back(req);
                    sort(v.begin(),v.end());
                    cout<<v[0]<<v[1]<<v[2];
                    st[v]++;
                }
            }
        }
        vector<vector<int>>ans;
        for(auto i:st)ans.push_back(i.first);
        return ans;
    }
};