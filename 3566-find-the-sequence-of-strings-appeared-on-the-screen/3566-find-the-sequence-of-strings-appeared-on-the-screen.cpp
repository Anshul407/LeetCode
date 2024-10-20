class Solution {
public:
    void solve(string t,string temp,vector<string>&ans,int i){
        ans.push_back(temp);
        if(temp==t){
            return ;
        }

        if(t[i]==temp[i]){
            temp+="a";
            solve(t,temp,ans,i+1);
        }else {
            char x=temp[i];
            x++;
            temp[i]=x;
            solve(t,temp,ans,i);
        }
    }
    vector<string> stringSequence(string target) {
        vector<string>ans;
        solve(target,"a",ans,0);
        return ans;
    }
};