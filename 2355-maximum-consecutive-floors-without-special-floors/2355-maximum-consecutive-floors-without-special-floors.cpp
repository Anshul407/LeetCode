class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int ans=0;
        sort(special.begin(),special.end());
        for(int i=0;i<special.size()-1;i++){
            ans=max(ans,special[i+1]-special[i]-1);
        }
        ans=max(special[0]-bottom,ans);
        ans=max(top-special.back(),ans);
        return ans;

    }
};