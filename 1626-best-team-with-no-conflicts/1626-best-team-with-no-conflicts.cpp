class Solution {
public:
    int solve(vector<vector<int>>&v,int i,int p){
        if(i>=v.size())return 0;

        int tk=0;
        if(p==-1||v[i][1]>=v[p][1]){
            tk=v[i][1]+solve(v,i+1,i);
        }
        int ntk1=solve(v,i+1,p);
        
        return max({tk,ntk1});
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
       vector<vector<int>>v;
       for(int i=0;i<scores.size();i++){
        v.push_back({ages[i],scores[i]});
       }
       sort(v.begin(),v.end());
        return solve(v,0,-1);
    }
};