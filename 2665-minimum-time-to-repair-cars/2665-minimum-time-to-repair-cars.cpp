class Solution {
public:
    bool canplace(vector<int>&ranks,int n,long long cur){
        for(int i=0;i<ranks.size();i++){
            if(cur>=ranks[i]){
            long long x=cur/ranks[i];
            x=static_cast<long long>(sqrt(x));
            n-=x;}
            if(n<=0)return 1;
        }
        return 0;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long i=1;
        int maxi=0;
        for(auto x:ranks)maxi=max(maxi,x);
        long long j=1LL*maxi*cars*cars;
        long long ans=0;
        while(i<=j){
            auto mid=i+(j-i)/2;
            if(canplace(ranks,cars,mid)){
                ans=mid;
                j=mid-1;
            }else i=mid+1;
        }
        return ans;
    }
};