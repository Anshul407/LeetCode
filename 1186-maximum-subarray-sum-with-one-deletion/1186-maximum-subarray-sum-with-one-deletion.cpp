class Solution {
public:
   
    int maximumSum(vector<int>& arr) {
        int del=0,ntdel=arr[0];
        int ans=INT_MIN;
        for(int i=1;i<arr.size();i++){
            del=max(ntdel,del+arr[i]);
            ntdel=max(ntdel+arr[i],arr[i]);
            ans=max({ans,del,ntdel});
        }
        return ans;
    }
};