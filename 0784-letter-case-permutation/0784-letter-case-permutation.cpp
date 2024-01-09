class Solution {
public:
    void mp(string s,string op,vector<string>&ans){
    if(s.length()==0&&find(ans.begin(),ans.end(),op)==ans.end()){
        ans.push_back(op);
        return ;
    }
    if(!s.empty()){
    string op1=op;
    string op2=op;
    op1.push_back(s[0]);
    if(s[0]>=65&&s[0]<=90)
    op2.push_back(tolower(s[0]));
    else if(s[0]>=90)
        op2.push_back(toupper(s[0]));
    
    else{
       
        op2.push_back((s[0]));
    }
s.erase(s.begin()+0);
 mp(s,op1,ans);
    mp(s,op2,ans);
    }
   
}
    vector<string> letterCasePermutation(string s) {
        string op;
        vector<string>ans;
        mp(s,op,ans);
        return ans;

    }
};