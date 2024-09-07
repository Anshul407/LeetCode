class Solution {
public:
   

    long long maxStrength(vector<int>& nums) {
       if(nums.size()==1)return nums[0];
       int cnt=0;
       int mini=INT_MAX;
       long long prod=1;
       int pos=0;
       int z=0;
       for(auto &i:nums){
            if(i>0)pos++;
            if(i<0){
                cnt++;
                i*=-1;
                mini=min(i,mini);
            }
            
            if(i!=0)
            prod*=i;
            else z++;
            
       }
       if(z==nums.size())return 0;
       if(pos==0&&z&&cnt==1)return 0;
       if(cnt%2!=0)return prod/mini;
       else return prod;
       
    }
};
