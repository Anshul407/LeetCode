class Solution {
public:
    void solve(map<char,int>&mp){
        mp['Q']=1;
        mp['W']=1;
        mp['E']=1;
        mp['R']=1;
        mp['T']=1;
        mp['Y']=1;
        mp['U']=1;
        mp['I']=1;
        mp['O']=1;
        mp['P']=1;

        mp['A']=2;
        mp['S']=2;
        mp['D']=2;
        mp['F']=2;
        mp['G']=2;
        mp['H']=2;
        mp['J']=2;
        mp['K']=2;
        mp['L']=2;
        
        mp['Z']=3;
        mp['X']=3;
        mp['C']=3;
        mp['V']=3;
        mp['B']=3;
        mp['N']=3;
        mp['M']=3;
       


    }
    vector<string> findWords(vector<string>& words) {
        map<char,int>mp;
        solve(mp);
        vector<string>ans;
        for(auto i:words){
            int x=mp[toupper(i[0])];
            for(auto j:i){
                if(mp[toupper(j)]!=x){x=INT_MAX;break;}
            }
            if(x!=INT_MAX)ans.push_back(i);
        }
        return ans;
    }
};