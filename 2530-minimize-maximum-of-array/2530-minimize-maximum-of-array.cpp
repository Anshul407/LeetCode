class Solution {
public:
    bool ans(vector<int>&nums, long long m){
        vector<long long> arr(begin(nums), end(nums));
        
        for(int i = 0; i<nums.size()-1; i++) {
            
            if(arr[i] > m)
                return false;
            
            long long buffer = m - arr[i];
            
            arr[i+1] = arr[i+1] - buffer;   
            
        }
        
        return arr[nums.size()-1] <= m;
    }
    int minimizeArrayValue(vector<int>& nums) {
        long long i=0;
        long long j= *max_element(begin(nums), end(nums));
        while(i<j){
            long long mid=(i+j)/2;
            if(ans(nums,mid)){
                j=mid;
            }else i=mid+1;
        }
        return i;
    }
};