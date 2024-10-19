class Solution {
public:
    void solve(int &n,string &temp){
        if(n<=1)return ;
        string x="";
        for(auto i:temp){
            if(i=='0')x+="1";
            else x+="0";
        }

        temp+="1";
        reverse(x.begin(),x.end());
        temp+=x;
        n--;
        solve(n,temp);
    }
    char findKthBit(int n, int k) {
        string temp="0";
        solve(n,temp);
        cout<<temp;
        return temp[k-1];
    }
};