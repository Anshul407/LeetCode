class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
       vector<int>temp=nums;
       sort(temp.begin(),temp.end());
       map<int,int>mp;
       for(int i=0;i<temp.size();i++){
            if(mp.find(temp[i])==mp.end())
            mp[temp[i]]=i;
       }
       int x=0;
       for(auto i:nums){
            temp[x]=mp[i];
            x++;
       }
       return temp;
    }
};