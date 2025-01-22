class Solution {
public:
    void solve(int op,int cl,string temp,vector<string>&ans){
        if(op==0&&cl==0){
            ans.push_back(temp);
            return ;
        }

        if(op==cl&&op!=0){
            string cur=temp;
            cur+="(";
            solve(op-1,cl,cur,ans);
        }else if(op!=0&&cl!=0){
            string cur=temp;
            cur+="(";
            solve(op-1,cl,cur,ans);
            cur.pop_back();
            cur+=')';
            solve(op,cl-1,cur,ans);

        }else if(cl!=0){
            string cur=temp;
            cur+=')';
            solve(op,cl-1,cur,ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp="";
        solve(n,n,temp,ans);
        return ans;
    }
};