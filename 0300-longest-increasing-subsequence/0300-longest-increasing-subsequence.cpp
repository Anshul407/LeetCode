class Solution {
public:
    int solve(vector<int>&c,int num){
        int i=0,j=c.size()-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(c[mid]==num)return mid;
            if(c[mid]>num)j=mid-1;
            else i=mid+1;
        }
        return i;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int>cur;
        for(auto i:nums){
            if(cur.empty()||cur.back()<i){
                cur.push_back(i);
            }else {
                int f=solve(cur,i);
                cur[f]=i;
            }
        }return cur.size();
    }
};