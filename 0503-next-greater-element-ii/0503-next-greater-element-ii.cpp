class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        map<int,int>mp;
        int i=0;
        int f=0;
        while(i<nums.size()*2){
            while(st.size()&&nums[st.top()]<nums[i%nums.size()]){
                if(mp.find(st.top())==mp.end())
                mp[st.top()]=nums[i%nums.size()];
                st.pop();
            }
            if(i<nums.size())
            st.push(i);
            i++;
        }
        
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(mp.find(i)!=mp.end())ans.push_back(mp[i]);
            else ans.push_back(-1);
        }return ans;
    }
};