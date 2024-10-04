class Solution {
public:
    bool ans(vector<int>&p,int m,int k){
        int x=0;
        for(auto i:p){
            x+=(i/m);
            if(i%m)x++;
        }
        return x<=k;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int i=1;
        int j=0;
        for(auto x:piles)j=max(j,x);
        while(i<j){
            int mid=(i+j)/2;
            if(ans(piles,mid,h)){
                j=mid;
            }else i=mid+1;
        }
        return i;
    }
};