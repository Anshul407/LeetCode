class Solution {
public:
    string reverseWords(string s) {
        int i=s.length()-1;
        string ans="";
        while(i>=0){
            while(i>=0&&s[i]==' ')i--;
            if(i<0)break;
           int j=i;
            while(i>=0&&s[i]!=' ')i--;
           ans+= s.substr(i+1,j-i);
           if(i>=0)
           ans+=' ';
            
        }
        if(!ans.empty()&&ans.back()==' ')ans.pop_back();
        return ans;
    }
};