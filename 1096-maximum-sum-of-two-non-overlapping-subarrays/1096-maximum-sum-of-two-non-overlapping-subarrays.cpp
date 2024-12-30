class Solution {
public:
    vector<int>mp;
    int solve(int i,int turn,int f,int s){
        if(turn==2)return 0;
        if(i>=mp.size()){
            return -1e6;
        }
        if(turn==0){
            int op1=solve(i+1,turn,f,s);
            int op2=0;
            if(i+f<=mp.size()){
                int cur=mp[i+f-1]-(i>0?mp[i-1]:0);
                op2=solve(i+f,turn+1,f,s)+cur;
            }
            return max(op1,op2);
        }
        else{
            int op1=solve(i+1,turn,f,s);
            int op2=0;
            if(i+s<=mp.size()){
                int cur=mp[i+s-1]-(i>0?mp[i-1]:0);
                op2=solve(i+s,turn+1,f,s)+cur;
            }
            return max(op1,op2);
        }
        
        
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int f, int s) {
       
        mp.resize(nums.size()+1,0);
        for (int i = 0; i < nums.size(); ++i) {
            mp[i + 1] = mp[i] + nums[i];
        }
        return max(solve(0,0,f,s),solve(0,0,s,f));
    }
};