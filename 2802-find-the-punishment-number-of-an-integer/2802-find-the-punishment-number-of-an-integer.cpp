class Solution {
public:
    int solve(int dest,string s,int &cur,int j){
        if(cur==dest&&j==s.size())return 1;
        if(j>=s.size())return 0;

        for(int k=j;k<s.length();k++){
            int p=cur;
            cur+=stoi(s.substr(j,k-j+1));
            if(solve(dest,s,cur,k+1))return 1;
            cur=p;
            
        }
        return 0;

    }
    int punishmentNumber(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            int k=i*i;
            cout<<k<<" ";
            string x=to_string(k);
            int c=0;
            if(solve(i,x,c,0)){ans+=(i*i);}
        }
        return ans;
    }
};