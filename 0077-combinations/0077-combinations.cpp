class Solution {
public:
    void mp(vector<int>nums,vector<int>&op,vector<vector<int>>&ans,int k,int g){
        if(op.size()==k||nums.empty()){
            
            ans.push_back(op);
            return ;
           
        }
     
        if(nums.empty())return ;
        for(int i=0;i<nums.size();i++){
            if((op.size()!=0&&op[op.size()-1]<nums[i])||op.empty()){
         
          vector<int>opp(op);
          op.push_back(nums[i]);
          vector<int>nums2(nums);
          nums2.erase(nums2.begin()+i);
          mp(nums2,op,ans,k,g+1);
          op.pop_back();

          }
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int>nums;
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }
        vector<int>op;
        vector<vector<int>>ans;
        mp(nums,op,ans,k,0);
        
        return ans;
    }
};