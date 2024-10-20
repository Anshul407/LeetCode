class Solution {
public:
    // int solve(vector<int>&v,int n,int i){
    //     if(n<1){
    //         int ans=0;
    //         for(auto i:v){
    //             ans+=i;
    //         }
    //         return ans;
    //     }

    //     for(int j=i-1;j<v.size();j+=i){
    //         v[j]=!v[j];
    //     }
    //     return solve(v,n-1,i+1);



    // }
    int bulbSwitch(int n) {
    //     if(n==0)return 0;
    //     vector<int>v(n,1);
    //    return solve(v,n,2);
    return floor(sqrt(n));
    }
};