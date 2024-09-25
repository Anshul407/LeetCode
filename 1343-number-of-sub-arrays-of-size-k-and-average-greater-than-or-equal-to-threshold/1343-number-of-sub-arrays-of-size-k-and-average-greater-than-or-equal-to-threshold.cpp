class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
       int avg=0;
        int i=0,j=0;
        int x=0;
        int ans=0;
        while(i<arr.size()&&j<arr.size()){
            x++;
            avg+=arr[j];
            if(x==k){
                if(avg/k>=threshold)ans++;
                avg-=arr[i];
                i++;
                x--;
            }
            j++;
            
        }
        return ans;
    }
};