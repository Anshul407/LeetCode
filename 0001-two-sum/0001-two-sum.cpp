class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
         int n=arr.size();
        int i=0,j=n-1;
        int x,y;
        
        vector<int>yy;
        for(int i=0;i<n;i++){
           yy.push_back(arr[i]);
        }
        sort(arr.begin(),arr.end());
        while(i<=j){
            
            if(arr[i]+arr[j]==target){
                x=arr[i];
                y=arr[j];
                break;
            }
            if(arr[i]+arr[j]>target){
                j--;
            }
            if(arr[i]+arr[j]<target){
                i++;
            }
            
            
        }
        vector<int>xx;
        for(i=0;i<n;i++){
            if(yy[i]==x){
                xx.push_back(i);
                break;
            }
        }
        for(i=0;i<n;i++){
            if(yy[i]==y&&i!=xx[0]){
                xx.push_back(i);
                break;
            }
        }
        return xx;
        
    }
};