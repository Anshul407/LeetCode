class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        map<int,int>row,col;
        map<int,pair<int,int>>mp;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                mp[mat[i][j]]={i,j};
            }
        }
        int cnt=0;
        for(cnt=0;cnt<arr.size();cnt++){
            auto x=mp[arr[cnt]];
            auto i=x.first;
            auto j=x.second;
            row[i]++;
            col[j]++;
            if(col[j]==mat.size()||row[i]==mat[0].size())return cnt;
        }
        return cnt;
    }
};
