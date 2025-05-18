class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int>st;
        vector<int>ans;
        int i=0,j=0;
        while(j<nums.size()){
            st.insert(nums[j]);
            if(j-i+1==k){
                ans.push_back(*st.rbegin());
                auto x=st.find(nums[i]);
                st.erase(x);
                i++;
            }j++;
        }return ans;
    }
};