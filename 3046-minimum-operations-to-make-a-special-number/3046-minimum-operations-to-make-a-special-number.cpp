class Solution {
public:
    //dp solution
    // vector<unordered_map<string,int>>dp;
    // int solve(string &num,string &t,int i){
    //     if(i>=num.size()){
            
    //         if(t.size()==1&&t[0]=='0')return num.size()-t.size();
    //         if(t.size()<2)return 1e6;

    //         auto cur= t.substr(t.size()-2);
            
    //         if(cur=="00"||cur=="25"||cur=="50"||cur=="75")return num.size()-t.size();
    //         return 1e6;
    //     }
    //     if(dp[i].find(t)!=dp[i].end())return dp[i][t];
    //     int ans=1e6;
    //     if(t.empty()){
    //         t.push_back(num[i]);
    //         int op1=solve(num,t,i+1);
    //         ans=min(ans,op1);
    //         t.pop_back();
    //     }else if(!t.empty()&&t[0]!='0'){
    //         t.push_back(num[i]);
    //         int op1=solve(num,t,i+1);
    //         ans=min(ans,op1);
    //         t.pop_back();
    //     }
    //     ans=min(ans,solve(num,t,i+1));
    //     return dp[i][t]= ans;
    // }
    int minimumOperations(string num) {
        vector<int>fv(num.size(),-1),sv(num.size(),-1),z(num.size(),-1),t(num.size(),-1);
        if(num[0]=='5')fv[0]=0;
        else if(num[0]=='2')t[0]=0;
        else if(num[0]=='7')sv[0]=0;
        for(int i=1;i<num.size();i++){
            if(num[i]=='0'){
                z[i]=i;
                
                fv[i]=fv[i-1];
                sv[i]=sv[i-1];
                t[i]=t[i-1];
            }else if(num[i]=='5'){
                z[i]=z[i-1];
                fv[i]=i;
                sv[i]=sv[i-1];
                t[i]=t[i-1];
            }else if(num[i]=='2'){
                z[i]=z[i-1];
                fv[i]=fv[i-1];
                sv[i]=sv[i-1];
                t[i]=i;
            }else if(num[i]=='7'){
                z[i]=z[i-1];
                fv[i]=fv[i-1];
                sv[i]=i;
                t[i]=t[i-1];
            }else{
                z[i]=z[i-1];
                fv[i]=fv[i-1];
                sv[i]=sv[i-1];
                t[i]=t[i-1];
            }
        }
        int ans=INT_MAX;
        for(int i=num.size()-1;i>=1;i--){
             if(num[i]=='0'){
                auto lef=fv[i-1];
                if(lef!=-1){
                    auto cur=i-lef-1;
                    cur+=(num.size()-i-1);
                    ans=min(ans,cur);
                }
                lef=z[i-1];
                if(lef!=-1&&lef!=0){
                    auto cur=i-lef-1;
                    cur+=(num.size()-i-1);
                    ans=min(ans,cur);
                }

            }else if(num[i]=='5'){
                auto lef=t[i-1];
                if(lef!=-1){
                    auto cur=i-lef-1;
                    cur+=(num.size()-i-1);
                    ans=min(ans,cur);
                }
                lef=sv[i-1];
                if(lef!=-1){
                    auto cur=i-lef-1;
                    cur+=(num.size()-i-1);
                    ans=min(ans,cur);
                }
            }
        }
        for(auto i:num)if(i=='0'){ans=min(ans,(int)num.size()-1);break;}
        return min(ans,(int)num.size());

    }
};