class Solution {
public:
    int l;
    set<pair<int,int>>st;
    bool solve(int i,int j,int s,int t,set<pair<int,int>>&mp){
        if(st.count({i,j})||i<0||j<0||i>=1e6||j>=1e6||mp.count({i,j}))return 0;
        if(i==s&&j==t)return 1;
        if(mp.size()>l)return 1;
        mp.insert({i,j});
        int op1=solve(i-1,j,s,t,mp);
        if(op1)return 1;
        int op2=solve(i+1,j,s,t,mp);
        if(op2)return op2;
        int op3=solve(i,j+1,s,t,mp);
        if(op3)return op3;
        int op4=solve(i,j-1,s,t,mp);
        
        return op1||op2||op3||op4;
    }
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        set<pair<int,int>>mp,mp2;
        for(auto b:blocked){
            st.insert({b[0],b[1]});
        }
        l=blocked.size()*(blocked.size()-1)/2;
        return solve(source[0],source[1],target[0],target[1],mp)&&solve(target[0],target[1],source[0],source[1],mp2);
    }
};