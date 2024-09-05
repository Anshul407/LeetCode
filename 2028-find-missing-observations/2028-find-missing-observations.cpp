class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size();
        int s=m+n;
        int total=mean*s;
        int sum=0;
        for(auto i:rolls)sum+=i;
        int req=total-sum;

        int ans=req/n;
        int h=req%n;
        if(ans>6)return {};
        if(ans==6&&h>0)return {};
        vector<int>v;
        for(int i=0;i<n;i++){
            if(h>0){
            v.push_back(ans+1);
            h--;}
            
            else v.push_back(ans);
           
        }
        return v;


    }
};