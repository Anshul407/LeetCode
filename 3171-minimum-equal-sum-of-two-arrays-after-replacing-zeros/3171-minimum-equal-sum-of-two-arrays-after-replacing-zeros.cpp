class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long cur1=0;
        long long c1=0,c2=0;
        long long cur2=0;
        for(auto i:nums1){cur1+=i;if(i==0)c1++;}
        for(auto i:nums2){cur2+=i;if(i==0)c2++;}
        if(c1==0&&c2+cur2>cur1)return -1;
        if(c2==0&&c1+cur1>cur2)return -1;
        if(cur1!=cur2){
            if(c1==0&&c2==0)return -1;
        }
        if(cur1==cur2){ 
            auto diff=abs(c1-c2);
            cur1+=max(c1,c2);
            return cur1;

        }
        else if(cur1+c1>cur2+c2){
            if(c2==0){
                return -1;
            }return cur1+c1;
        }else{
             if(c1==0){
                return -1;
            }
            return cur2+c2;
        }
        return -1;
    }
};