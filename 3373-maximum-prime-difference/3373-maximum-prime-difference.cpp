class Solution {
public:
    void f(vector<int>&cur){
        cur[0]=0;
        cur[1]=0;
        for(int i=2;i<cur.size();i++){
            if(cur[i]==1){
                for(int j=i*i;j<=cur.size();j+=i)cur[j]=0;
            }
        }
    }
    int maximumPrimeDifference(vector<int>& nums) {
        vector<int>cur(101,1);
        f(cur);
        int a=-1,b=-1;
        for(int i=0;i<nums.size();i++){
            if(cur[nums[i]]){
                if(a==-1)a=i;
                b=i;
            }
        }return b-a;
    }
};