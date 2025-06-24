class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int>st;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==key){
                int j=i;
                while(abs(i-j)<=k&&j>=0){
                    st.insert(j);
                    j--;
                }
                j=i;
                while(abs(i-j)<=k&&j<nums.size()){
                    st.insert(j);
                    j++;
                }
            }
        }
        vector<int>ans;
        for(auto i:st)ans.push_back(i);
        return ans;
    }
};