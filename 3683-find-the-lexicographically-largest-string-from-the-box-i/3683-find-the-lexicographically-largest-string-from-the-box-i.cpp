class Solution {
public:
    // string solve(string &w,int n,string cur,int j){
    //     if(n==0){
    //         if(j>=w.size())return cur;
    //         return "";
    //     }
    //     if(j>=w.size())return "";
    //     string ans="";
    //     for(int i=j;i<w.size();i++){
    //         string l;
    //         string s=w.substr(j,i-j+1);
    //         if(cur.empty()||s>cur)l=solve(w,n-1,s,i+1);
    //         else l=solve(w,n-1,cur,i+1);

    //         if(l>ans)ans=l;
    //     }

    //     return ans;
    // }
    string answerString(string word, int numFriends) {
        if(numFriends==1)return word;
        int s=word.size()-numFriends+1;
        string ans="";
        for(int i=0;i<word.size();i++){
            string cur;
            if(i+s>=word.size())cur=word.substr(i);
            else cur=word.substr(i,s);
            int f=0;
            for(int j=0;j<i;j++){
                if(word[j]>cur[0]){
                    f=1;
                    break;
                }
            }for(int j=i+s;j<word.size();j++){
                if(word[j]>cur[0]){
                    f=1;
                    break;
                }
            }
            if(!f){
                if(ans<cur)ans=cur;
            }
        }
        return ans;
    }
};