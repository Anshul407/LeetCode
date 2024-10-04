class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(auto i:stones)pq.push(i);
        while(!pq.empty()){
            auto x=pq.top();
            pq.pop();
            if(pq.empty())return x;
            auto y=pq.top();
            pq.pop();
            if(pq.empty()){
                if(x==y)return 0;
                return x-y;
            }
            else {
                if(x!=y)pq.push(x-y);
            }

            

        }
        return -1;
    }
};