class Solution {
public:
    bool canpossible(vector<int>&c,long long cur,long long k){
        for(int i=0;i<c.size();i++){
            k-=(c[i]/cur);
        }
        return k<=0;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        sort(candies.begin(),candies.end());
        long long i=1,j=1e7;
        int ans=0;
        while(i<=j){
            int mid=(i+j)/2;

            if(canpossible(candies,mid,k)){
                ans=mid;
                i=mid+1;
            }else j=mid-1;
        }
        return ans;

    }
};