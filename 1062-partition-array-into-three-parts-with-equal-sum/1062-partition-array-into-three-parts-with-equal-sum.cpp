class Solution {
public:
    int solve(vector<int>&arr,int i,int cur,int cnt){
        if(i>=arr.size())return cnt==3;
        int k=0;
        for(int j=i;j<arr.size();j++){
            k+=arr[j];
            if(k==cur){
                if(solve(arr,j+1,cur,cnt+1))return 1;
            }
        }return 0;
    }
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum=0;
        for(auto i:arr)sum+=i;
        if(sum%3)return 0;
        return solve(arr,0,sum/3,0);
    }
};