class Solution {
public:
    bool mp(vector<int>nums,int k){
        int x=nums.size();
        int t[x+1][k+1];
        for(int i=0;i<k+1;i++){
            t[0][i]=0;
        }
        for(int i=0;i<=nums.size();i++){
            t[i][0]=1;
        }
        for(int i=1;i<=nums.size();i++){
            for(int j=1;j<k+1;j++){
                if(nums[i-1]<=j){
                    t[i][j]=(t[i-1][j-nums[i-1]])||(t[i-1][j]);
                }
                else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return t[x][k];
        
    }
    bool canPartition(vector<int>& nums) {
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2!=0)return false;
        else{
            return mp(nums,sum/2);
        }
    }
};