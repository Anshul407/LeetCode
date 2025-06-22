class Solution {
public:
    void help(vector<int>&pr){
        pr[0]=0;
        pr[1]=0;
        for(long long i=2;i<pr.size();i++){
            if(pr[i]==0)continue;
            for(long long j=i*i;j<pr.size();j+=i)pr[j]=0;
                
        }
    }
    int primeSubarray(vector<int>& nums, int k) {
        multiset<int>st;
        int fl=0;
        int i=0,j=0;
        vector<int>pr(50001,1);
        help(pr);
        int ans=0;
        int sl=0;
        while(j<nums.size()){
            if(pr[nums[j]]){
               
                st.insert(nums[j]);
                sl=fl;
                fl=j;
            }
            while(st.size()>=2&&*st.rbegin()-*st.begin()>k){
                if(pr[nums[i]]){
                auto x=st.find(nums[i]);
                if(x!=st.end())
                st.erase(x);
                }
                i++;
                
            }
            if(st.size()>=2)
            ans+=(sl-i+1);
            j++;   
        }return ans;
    }
};