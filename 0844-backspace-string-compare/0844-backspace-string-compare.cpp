class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string a="";
        string b="";
        for(auto i:s){
            if(i=='#'){
                if(a.length()!=0)
                a.pop_back();
                continue;
            }
            else{
                a.push_back(i);
            }
        }
        for(auto i:t){
            if(i=='#'){
                if(b.length()!=0)
                b.pop_back();
                continue;
            }
            else{
                b.push_back(i);
            }
        }
        return a==b;
    }
};