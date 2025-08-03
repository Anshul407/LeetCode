class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int ans=0;
        int cur=0;
        for(auto i:weight){
            cur=max(cur,i);
            if(i<cur){
                ans++;
                cur=INT_MIN;
            }
        }return ans;
    }
};