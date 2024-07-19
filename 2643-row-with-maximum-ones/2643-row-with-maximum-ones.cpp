class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        map<int,int>mp;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1)mp[i]++;
            }
        }
        int a=INT_MIN,b=-1;
        for(auto i:mp){
            if(i.second>a){
                a=i.second;
                b=i.first;
            }
        }
        if(a==INT_MIN)return{0,0};
        return {b,a};
    }
};