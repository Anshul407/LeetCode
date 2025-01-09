class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int a=INT_MAX;
        for(int i=0;i<arr.size()-1;i++){
            if(a==INT_MAX)a=arr[i+1]-arr[i];
            else if(arr[i+1]-arr[i]!=a)return 0;
        }
        return 1;
    }
};