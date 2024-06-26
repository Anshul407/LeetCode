class Solution {
public:
   string reverseWords(string s) {
    string ans="";
    string temp="";
    for(int i=s.length()-1;i>=0;i--){
        if(s[i]==' '){
           reverse(temp.begin(),temp.end());
           ans+=temp;
           if(temp.length())
           ans.push_back(' ');
           temp="";
        }
        else{
            temp.push_back(s[i]);
        }
    }
     reverse(temp.begin(),temp.end());
     ans+=temp;
     string ans2="";
     int flag=1;
     for(int i=ans.length()-1;i>=0;i--){
        if(ans[i]==' '&&flag)continue;
        else{
            ans2.push_back(ans[i]);
            flag=0;
        }
     }
     reverse(ans2.begin(),ans2.end());
    

    return ans2;
}

};