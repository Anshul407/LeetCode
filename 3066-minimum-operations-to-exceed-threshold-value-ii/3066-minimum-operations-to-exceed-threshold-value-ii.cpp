class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto i:nums)pq.push(i);
        int cnt=0;
        while(!pq.empty()&&pq.top()<k){
            int num1=pq.top();
            pq.pop();
            int num2=pq.top();
            pq.pop();
            int newnum=min(num1,num2)*2+max(num1,num2);
            pq.push(newnum);
            cnt++;
        }
        return cnt;
    }

};