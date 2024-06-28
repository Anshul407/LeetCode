class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<nums.size();i++){
        if(i>0&&nums[i]==nums[i-1])continue;
           int x=i+1,y=nums.size()-1;
           while(x<y){
            if((nums[i]+nums[x]+nums[y]==0)&&(i!=x)&&(i!=y)){
                auto vec = vector<int>{nums[i], nums[x], nums[y]};
                // auto it = find(ans.begin(), ans.end(), vec);
                // if(it==ans.end())
                ans.push_back(vec);
                x++;
                y--;
            }
            else if(nums[i]+nums[x]+nums[y]>0){
                y--;
            }
            else{
                x++;
            }
           }

        }
        return ans;
    }
};