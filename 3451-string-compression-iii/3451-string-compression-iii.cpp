class Solution {
public:
    string compressedString(string word) {
        string ans="";
        map<char,int>mp;
        for(auto i:word){
            if(mp.find(i)==mp.end()&&mp.size()){

                int cnt=mp.begin()->second;
                char x=mp.begin()->first;
                if(cnt>9){
                    int k=cnt/9;
                    cnt%=9;
                    string a=to_string(9)+x;
                    while(k--)ans+=a;
                    if(cnt>0){
                    string b=to_string(cnt)+x;
                    ans+=b;}
                }
                else{
                    string b=to_string(cnt)+x;
                    ans+=b;
                }

                mp.clear();
                mp[i]++;
            }
            else mp[i]++;
        }
        if(mp.size()){

                int cnt=mp.begin()->second;
                char x=mp.begin()->first;
                if(cnt>9){
                    int k=cnt/9;
                    cnt%=9;
                    string a=to_string(9)+x;
                    while(k--)ans+=a;
                    if(cnt>0){
                    string b=to_string(cnt)+x;
                    ans+=b;}
                }
                else{
                    string b=to_string(cnt)+x;
                    ans+=b;
                }

                mp.clear();
        }

        return ans;
    }
};