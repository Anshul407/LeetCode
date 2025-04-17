class FindSumPairs {
public:
    vector<int>v,nums;
    unordered_map<int,int>mp;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        v=nums1,nums=nums2;
        mp.clear();
        for(auto i:nums2)mp[i]++;
    }
    
    void add(int index, int val) {
        mp[nums[index]]--;
        if(mp[nums[index]]==0)mp.erase(nums[index]);
        nums[index]+=val;
        mp[nums[index]]++;   
    }
    
    int count(int tot) {
        int ans=0;
        for(int i=0;i<v.size();i++){
            auto cur=v[i];
            auto req=tot-cur;
            ans+=mp[req];
        }return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */