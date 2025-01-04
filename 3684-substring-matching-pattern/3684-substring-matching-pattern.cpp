class Solution {
public:
    bool hasMatch(string s, string p) {
        int t=0;
        string a="",b="";
        for(int i=0;i<p.size();i++){
            if(p[i]=='*'){
                t=i;
                break;
            }
            a+=p[i];
        }
        for(int i=t+1;i<p.size();i++){
            
            b+=p[i];
        }
        if(a.empty()&&b.empty())return 1;
        cout<<b<<" ";
        for(int i=0;i<s.size();i++){
            if(a.empty()){
                if(b.empty())return 1;
                for(int j=i;j<s.size();j++){
                    if(s.substr(j,b.size())==b||b.empty())return 1;
                }
            }
            else if(s.substr(i,a.size())==a){
                if(b.empty())return 1;
                for(int j=i+a.size();j<s.size();j++){
                    if(s.substr(j,b.size())==b||b.empty())return 1;
                }
            }
        }
        return 0;
    }
};