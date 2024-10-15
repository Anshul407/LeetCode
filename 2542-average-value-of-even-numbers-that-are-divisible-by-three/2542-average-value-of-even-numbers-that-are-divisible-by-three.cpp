class Solution {
public:
    int averageValue(vector<int>& nums) {
        int cnt=0;
        int cur=0;
        int ans=0;
        for(auto i:nums){
            if(i%2==0&&i%3==0){
                cur+=i;
                cnt++;
            }
        }
        if(cnt==0)return 0;
        return (cur/cnt);
    }
};