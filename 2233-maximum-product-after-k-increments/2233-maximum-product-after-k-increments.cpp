class Solution {
public:
    const int MOD=1e9+7;
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto i:nums){
            pq.push(i);
        }
        while(k){
            k--;
            auto it=pq.top();
            it++;
            pq.pop();
            pq.push(it);
        }
        long long ans=1;
        while (!pq.empty()) {
            ans = (ans % MOD) * (pq.top() % MOD) % MOD;
            pq.pop();
        }

        return ans%MOD;
    }
};