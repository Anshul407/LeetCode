class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        map<char,int>mp;
        for(auto i:brokenLetters){
            mp[i]++;
        }
        string cur=" ";
        int ans=0;
        int i=0;
        while(i<text.size()){
            while(i<text.size()&&text[i]==' ')i++;
            int j=i;
            while(i<text.size()&&text[i]!=' ')i++;
            string s=text.substr(j,i-j+1);
            int f=1;
            for(auto ii:s){
                if(mp.find(ii)!=mp.end()){f=0;break;}
            }
            ans+=f;

        }
        return ans;
    }
};