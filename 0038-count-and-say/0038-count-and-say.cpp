class Solution {
public:
    string solve(int n,string t){
        if(n==0)return t;

        string temp="";
        int cur=0;
        char p='#';
        for(int i=0;i<t.size();i++)
        {
            if(p!=t[i]){
                if(p!='#'){
                    temp.push_back(cur+'0');
                    temp.push_back(p);
                }cur=1;
                p=t[i];
            }else cur++;
        }temp.push_back(cur+'0');
        temp.push_back(p);
        return solve(n-1,temp);
    }
    string countAndSay(int n) {
        string t="1";
        return solve(n-1,t);
    }
};