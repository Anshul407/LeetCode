class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>>v;
        for(int i=0;i<nums1.size();i++){
            v.push_back({nums2[i],nums1[i]});
        }
        sort(v.rbegin(),v.rend());
        priority_queue<int,vector<int>,greater<int>>pq;
        long long cursum=0;
        long long ans=0;
        for(auto i:v){
            int a=i[0];
            int b=i[1];
            pq.push(b);
            cursum+=b;
            if(pq.size()>k){
                cursum-=pq.top();
                pq.pop();
            }
            if(pq.size()==k){
                ans=max(ans,cursum*a*1LL);
            }
        }
        return ans;
    }
};