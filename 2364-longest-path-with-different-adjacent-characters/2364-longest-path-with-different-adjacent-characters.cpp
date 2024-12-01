class Solution {
public:
 vector<vector<int>>mp;
 int ans;
    int dfs(int i,string &s,int p){
        int a=0,b=0;
        for(auto v:mp[i]){
            if(v!=p){
                int cur=dfs(v,s,i);
                if(s[v]==s[i])continue;
                if(cur>b)b=cur;
                if(b>a)swap(a,b);
            }
        }
        int op1=max(a,b)+1;//ya to left ya to right and root
        int op2=1; //sirf root
        int op3=a+b+1; //left+right+root
        ans=max({ans,op1,op2,op3});
        return max(op2,op1); //kyuki op3 ka path straight ni hai
        
    }
    int longestPath(vector<int>& parent, string s) {
        mp.resize(parent.size());
        ans=0;
        for(int i=1;i<parent.size();i++){
            mp[parent[i]].push_back(i);
            mp[i].push_back(parent[i]);
        }
        dfs(0,s,-1);
        return ans;
    }
};