class Solution {
public:
    static bool cmp(vector<string>&a,vector<string>&b){
        auto x=stoi(a[1]);
        auto y=stoi(b[1]);
        if(x!=y)return x<y;
        else{
            return a[0]=="OFFLINE";
        }
        

      
        
    }
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        sort(events.begin(),events.end(),cmp);
      
        vector<int>mp(numberOfUsers,0);
        map<int,int>offline;
        int all=0;
        for(auto i:events){
            cout<<i[0]<<i[1]<<" ";
            if(i[0]=="MESSAGE"){
                if(i[2]=="ALL")all++;
                else if(i[2]=="HERE"){
                    auto x=stoi(i[1]);
                    for(auto &p:offline){
                        if(p.second<=x){
                            p.second=0;
                        }
                    }
                    int user=0;
                    for(auto &x:mp){
                        if(offline[user]==0){
                            x+=1;  
                        }
                        user++;
                    }
                }else {
                    stringstream x(i[2]);
                    string cur;
                    while(x>>cur){
                        auto curnum=stoi(cur.substr(2));
                        mp[curnum]++;
                    }
                }
            }else {
                offline[stoi(i[2])]=stoi(i[1])+60;
            }
            
        }
        for(auto &i:mp)i+=all;
        return mp;
    }
};