class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int>pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);
        int ans=0;
        while(pq.size()>1){
            ans++;
            auto x=pq.top();
            pq.pop();
            auto y=pq.top();
            pq.pop();
            x--;
            y--;
            if(x)pq.push(x);
            if(y)pq.push(y);
            
            
        }
        return ans;
    }
};