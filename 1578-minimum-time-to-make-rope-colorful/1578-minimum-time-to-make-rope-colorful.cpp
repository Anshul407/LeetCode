class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=neededTime.size();
        int ans=0;
        int x=0;
        
        for(int i=0;i<n;i++){
            if(i>0&&colors[i]!=colors[i-1]){
             x=0;
            }

            ans+=min(x,neededTime[i]);
            x=max(x,neededTime[i]);
        }

        return ans;
    }
};