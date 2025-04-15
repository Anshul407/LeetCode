class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        int b=0,k=0;
        vector<string> a (numRows);
        string ans;
        for(char i:s){
            a[b].push_back(i);
            if(b==0) k=1;
            else if(b==numRows-1) k=-1;
            b+=k;}
        for(string i:a) ans+=i;
        return ans;}
};