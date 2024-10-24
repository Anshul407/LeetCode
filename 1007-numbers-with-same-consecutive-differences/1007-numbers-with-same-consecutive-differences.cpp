class Solution {
public:
    vector<int>ans;
    int solve(int n,int k,int i,string &cur){
        if(cur.size()==n){
            return stoi(cur);
        }
        for(int j=0;j<=9;j++){
            if(j==0&&cur.size()==0)continue;
            if(cur.size()==0||abs((cur.back()-'0')-j)==k){
                cur+=to_string(j);
               if(solve(n,k,0,cur))ans.push_back(solve(n,k,0,cur));
               cur.pop_back();
            }
        }

        return 0;

        

    }
    vector<int> numsSameConsecDiff(int n, int k) {
        string cur="";
        solve(n,k,0,cur);
        return ans;
    }
};