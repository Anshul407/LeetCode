class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        long long normal=0,ans=0;;
        for(int i=0;i<arr.size();i++){
                normal+=(abs(arr[i]-brr[i]*1LL));
        }
       sort(arr.begin(),arr.end());
       sort(brr.begin(),brr.end());
       for(int i=0;i<arr.size();i++){
            
            ans+=(abs(arr[i]-brr[i]*1LL));
       }
       return min(ans+k,normal);
    }
};