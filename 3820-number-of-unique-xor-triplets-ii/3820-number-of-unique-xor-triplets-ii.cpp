class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        if(nums.size()==1)return 1;
        if(nums.size()==2)return 2;
        unordered_set<int>st;
        int maxi=0;
       
        

        for(auto i:nums)st.insert(i),maxi=max(maxi,i);
        int i=0;
        while(pow(2,i)<=maxi){
            i++;
        }
        auto cur=pow(2,i);
        for(int i=0;i<nums.size()-2;i++){
            for(int j=i+1;j<nums.size()-1;j++){
                for(int k=j+1;k<nums.size();k++){
                    st.insert(nums[i]^nums[j]^nums[k]);
                    if(st.size()==cur)break;
                }
            }
        }return st.size();
    }
};