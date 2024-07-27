class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        map<int,int>mp;
        int sum=0;
        int sum2=0;
        int j=0;
        for(auto i:nums)sum2+=i;
        for(auto i:nums){
           
          
            mp.erase(sum2);
            sum2-=i;
           mp[sum2]++;
             if(mp.find(sum)!=mp.end())return j;
               sum+=i;
              
              j++;
        }
        return -1;
    }
};