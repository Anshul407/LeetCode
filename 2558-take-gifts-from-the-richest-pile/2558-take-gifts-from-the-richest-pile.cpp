class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int,vector<int>>pq;
        for(auto i:gifts){
            pq.push(i);
        }
        while(k){
            k--;
            int num=pq.top();
            pq.pop();
            num=sqrt(num);
            pq.push(num);

        }
        long long ans=0;
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};