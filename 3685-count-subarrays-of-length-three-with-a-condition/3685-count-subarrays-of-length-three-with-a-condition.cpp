class Solution {
public:
    int countSubarrays(vector<int>& arr) {
        int ans=0;
        for(int i=0;i<=arr.size()-3;i++){
            int a=arr[i];
            int b=arr[i+1];
            int c=arr[i+2];
            if(a+c==b/2.0)ans++;
        }
        return ans;
    }
};