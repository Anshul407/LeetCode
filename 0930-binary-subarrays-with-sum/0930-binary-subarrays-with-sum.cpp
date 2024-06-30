class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        map<int,int>prf;

        int sum=0,count=0;
        // prf[0]=1;
        for(auto i:nums){
            prf[sum]++;
            sum+=i;
            int diff=sum-goal;
            if(prf.find(diff)!=prf.end()){
                count+=prf[diff];
            }
            
        }
        return count;
    }
};