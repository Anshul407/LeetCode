class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int,vector<int>>pq;
        for(auto i:nums){
            pq.push(i);
        }
        long long ans=0;
        while(!pq.empty()&&k){
            k--;
            ans+=pq.top();
            int num=pq.top();
            pq.pop();
            int fl=0;
            if(num%3!=0)fl=1;
            num/=3;
            if(fl)num++;
            
            pq.push(num);
        }
        return ans;
    }
};