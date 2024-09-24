class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double,vector<double>>pq;
        double sum=0.0;
        for(auto i:nums){
            sum+=i;
            pq.push(double(i));
        }
        double cur=sum;
        int ans=0;
        while(!pq.empty()){
            if(cur<=sum/2)return ans;
            auto it=pq.top();
            pq.pop();
            it/=2;
            cur-=it;
            pq.push(it);
            ans++;
        }
        return ans;
    }
};