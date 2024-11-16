class Solution {
public:
    bool isFascinating(int n) {
        string a=to_string(n);
        int x=n*2;
        string b=to_string(x);
        x=n*3;
        string c=to_string(x);
        map<char,int>mp;
        
        for(auto i:a)mp[i]++;
        for(auto i:b)mp[i]++;
        for(auto i:c)mp[i]++;
        
        for(char i='1';i<='9';i++){
                if(mp[i]>1)return 0;
                if(mp.find(i)==mp.end())return 0;
        }
        return mp.size()==9;
        
        return 0;
    }
};