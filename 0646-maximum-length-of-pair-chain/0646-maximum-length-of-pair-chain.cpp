class Solution {
public:
   static bool cmp(vector<int> p,vector<int>q){
    return p[1]<q[1];
   }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),cmp);
        int end=pairs[0][1];
        int cnt=1;
        for(int i=1;i<pairs.size();i++){
            if(pairs[i][0]>end){
                cnt++;
                end=pairs[i][1];
            }
        }
        return cnt;
    }
};