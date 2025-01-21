class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        map<int,int>mp1,mp2;
        for(auto i:indices){
            mp1[i[0]]++;
            mp2[i[1]]++;
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((mp1[i]+mp2[j])%2!=0)ans++;
            }
        }return ans;

    }
};