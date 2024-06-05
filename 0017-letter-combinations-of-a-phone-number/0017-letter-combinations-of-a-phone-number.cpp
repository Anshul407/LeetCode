class Solution {
public:
    void solve(string digits,string op,int ind,vector<string>&ans,string mapp[]){
        if(ind>=digits.size()){
            ans.push_back(op);
            return ;}
        int num=digits[ind]-'0';
        string val=mapp[num];
        for(int i=0;i<val.length();i++){
            op.push_back(val[i]);
            solve(digits,op,ind+1,ans,mapp);
            op.pop_back();
        } 

    }
    vector<string> letterCombinations(string digits) {
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","xyz"};
        vector<string>ans;
        if(digits.size()==0)return ans;
        string op="";
        int index=0;
        solve(digits,op,index,ans,mapping);
        return ans;
    }
};