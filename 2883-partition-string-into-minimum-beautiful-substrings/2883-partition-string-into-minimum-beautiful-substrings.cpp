class Solution {
public:
    bool check(string s){
        cout<<s<<" ";
        long long x=stoll(s,nullptr,2);
        while(x>1&&x%5==0){
            x/=5;
        }
        cout<<x<<" ";
        return x==1;
    }
    int solve(string s,int i,int cnt,int ans){
        if(i>=s.length()){
            if(cnt>=s.length())return ans;
            return -1;
        }
        int cur=INT_MAX;
        for(int j=i;j<s.size();j++){
            if(s[i]=='0'&&j>i)break;
            cout<<endl;
            bool x=check(s.substr(i,j-i+1));
            if(x){
                int temp=solve(s,j+1,cnt+(j-i+1),ans+1);
                if(temp!=-1)
                cur=min(temp,cur);
            }
        }
        return cur;
    }
    int minimumBeautifulSubstrings(string s) {
        return solve(s,0,0,0)==INT_MAX?-1:solve(s,0,0,0);
    }
};