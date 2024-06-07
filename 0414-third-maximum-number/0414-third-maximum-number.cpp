class Solution {
public:
    int thirdMax(vector<int>& nums) {
       set<int>st(nums.begin(),nums.end());
       vector<int>v;
       for(auto i :st){
        v.push_back(i);
       }
       if(v.size()==1){
        return v[0];
       }
       if(v.size()==2){
        return v[1];
       }
       return v[v.size()-3];
        
    }
};