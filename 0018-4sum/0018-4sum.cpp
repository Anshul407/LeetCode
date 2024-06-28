class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>>ans;
         if(nums.size()<4)return ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-3;i++){
            if(i>0&&(nums[i-1]==nums[i]))continue;
            for(int j=i+1;j<nums.size()-2;j++){
                // if(j>1&&nums[j]==nums[j-1])continue;
                 int x=j+1,y=nums.size()-1;
               long long newtarget= (long long)target - (long long)nums[i] - (long long)nums[j];
                 while(x<y){

                    if(nums[x]+nums[y]==newtarget){
                        ans.push_back({nums[i],nums[j],nums[x],nums[y]});
                        int ind2=x;
                        while(x<y&&nums[x]==nums[ind2])x++;
                        int ind=y;
                        while(x<y&&nums[y]==nums[ind])y--;
                        // x++;
                        // y--;
                    }else if(nums[x]+nums[y]>newtarget){
                        y--;
                    }else{
                        x++;
                    }
                 }
                 while(j+1 < nums.size() && nums[j] == nums[j+1]) j++;
            }
            //  while(i+1 < nums.size() && nums[i] == nums[i+1]) i++;

        }
        return ans;
    }
};