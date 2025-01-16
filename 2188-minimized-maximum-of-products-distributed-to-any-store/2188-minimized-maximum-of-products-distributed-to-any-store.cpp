class Solution {
public:
    bool canpossible(vector<int>&q,long long cur,int n){
        for(int i=0;i<q.size();i++){
            n-=(q[i]+cur-1)/cur;
            if(n<0)return 0;
        }
        return n>=0;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        long long i=1,j=1e9;
        int ans=-1;
        while(i<=j){
            auto mid=(i+j)/2;

            if(canpossible(quantities,mid,n)){
                ans=mid;
                j=mid-1;
            }else i=mid+1;
        }
        return ans;
    }
};