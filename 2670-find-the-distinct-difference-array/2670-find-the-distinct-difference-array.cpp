class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        unordered_map<int,int>mp1,mp2;
        for(auto i:nums){
            mp2[i]++;
        }
        vector<int>ans;
        for(auto i:nums){
            mp1[i]++;
            int flag=1e9;
            int occ=1e9;
            if(mp2[i]>1){
                occ=mp2[i];
                occ--;
                flag=i;
            }
            mp2.erase(i);
            if(flag!=1e9)
            mp2[flag]=occ;

            cout<<mp2.size()<<" ";
            ans.push_back(mp1.size()-mp2.size());
        }
        return ans;
    }
};