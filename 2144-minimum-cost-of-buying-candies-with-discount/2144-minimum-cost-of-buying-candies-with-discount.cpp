class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        reverse(cost.begin(),cost.end());
        int ans=0;
        for(int i=0;i<cost.size();i++){
            
            cout<<i%3<<" ";
            if(i%3==2)continue;
            
            ans+=cost[i];
        }
        return ans;
    }
};