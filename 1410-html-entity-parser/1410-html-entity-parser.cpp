class Solution {
public:
    string entityParser(string text) {
        string ans="";
        string temp="";
        int n=text.length();
        map<string,string>mp;
        mp["&quot;"]="\"";
        mp["&apos;"]="\'";
        mp["&amp;"]="&";
        mp["&gt;"]=">";
        mp["&lt;"]="<";
        mp["&frasl;"]="/";


        for(int i=0;i<n;i++){
            if(text[i]=='&'&&i<n-1&&text[i+1]!='&'){
                int j=i+1;
                int cnt=0;
                temp="";
                temp+="&";
                while(j<n&&cnt<7&&mp.find(temp)==mp.end()){
                    if(text[j]=='&')break;
                    temp.push_back(text[j]);
                    cnt++;
                    j++;
                }
                if(mp.find(temp)!=mp.end()){
                    ans+=mp[temp];
                }else ans+=temp;

                i=j-1;
            }
            
            else
            ans.push_back(text[i]);
        }
        return ans;
    }
};