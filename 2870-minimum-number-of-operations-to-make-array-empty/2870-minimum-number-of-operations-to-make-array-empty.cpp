class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto i:nums)mp[i]++;
        int ans=0;
        for(auto i:mp){
            if(i.second==1)return -1;

            if(i.second%3==0){
                ans+=i.second/3;
            }
            else if(i.second%3==2){
                int num=i.second;
                // while(num!=2){
                //    num-=3; 
                //    ans++;
                // }
                ans+=num/3;
                ans+=(num%3)/2;
                // if(num==2)ans++;
            }
            else if(i.second%3==1){
                int num=i.second;
                // while(num!=4){
                //    num-=3; 
                //    ans++;
                // }
                // if(num==4)ans+=2;
                int x=num/3;
                x--;
                ans+=x;
                if(x!=0)
                num-=(num/x);
                ans+=num/2;
            }
            else {
                //saara kaam hogya ab kuch baaki nahi hai thankyou !!
            }
        }

        return ans;
    }
};