class Solution {
public:
    string getHint(string secret, string guess) {
        map<int,int>mp,mp2;
        int a=0,b=0;
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]){secret[i]=INT_MAX;a++;}
            else
            mp[guess[i]]++;
        }
        for(auto i:secret){
            if(mp.find(i)!=mp.end()){
                b++;
                mp[i]--;
                if(mp[i]==0)mp.erase(i);
            }
        }
        return to_string(a)+"A"+to_string(b)+"B";
    }
};