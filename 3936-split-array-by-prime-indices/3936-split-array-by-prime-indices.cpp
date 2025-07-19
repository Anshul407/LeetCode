class Solution {
public:
    vector<int>prime;
    void init(){
        prime.resize(1e5+1,1);
        prime[0]=0;
        prime[1]=0;
        for(long long i=2;i<prime.size();i++){
            if(prime[i]==1){
                for(long long j=i*i;j<prime.size();j+=i){
                    prime[j]=0;
                }
            }
        }
    }
    long long splitArray(vector<int>& nums) {
        long long a=0,b=0;
        init();
        for(int i=0;i<nums.size();i++){
            if(prime[i]){
                a+=nums[i];
            }else b+=nums[i];
        }
        return abs(a-b);
    }
};