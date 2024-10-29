class Solution {
public:
    bool solve(string s,int i,int cnt,int size,long long p){
        if(i>=s.size())return cnt>=2;
        for(int j=i;j<s.size();j++){
            auto st=s.substr(i,j-i+1);
            if(st.size()>19||(st.size()==19&&st>"9223372036854775807"))break;
            auto x=stoll(s.substr(i,j-i+1));
            if(p==-1||(x==p-1)){
                cout<<x<<" ";
                if(solve(s,j+1,cnt+1,size+(j-i+1),x))return 1;
            }
        }
        return 0;
    }
    bool splitString(string s) {
        return solve(s,0,0,0,-1);
    }
};