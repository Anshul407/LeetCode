class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>ans(nums.size(),-1);
        stack<pair<int,int>>st;
        st.push({0,nums[0]});
        for(int i=1;i<nums.size();i++){
            while(!st.empty()&&st.top().second<nums[i]){
                ans[st.top().first]=nums[i];
                st.pop();
            }st.push({i,nums[i]});
        }
        if(st.empty())return ans;
        for(int i=0;i<nums.size();i++){
            if(i>=st.top().first)break;
            while(!st.empty()&&st.top().second<nums[i]){
                ans[st.top().first]=nums[i];
                st.pop();
            }

        }
        return ans;
    }
};