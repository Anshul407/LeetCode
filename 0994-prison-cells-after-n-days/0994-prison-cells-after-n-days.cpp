class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        map<string,int>dp;
        map<int,string>dp2;
        int x=-1;
        int p=0;
        for(int j=0;j<n;j++){
            string cur="";
            for(auto j:cells){
                cur+=to_string(j);
            }
            cout<<cur<<endl;
            if(dp.find(cur)!=dp.end()){
                x=j;
                p=dp[cur];
                cout<<dp[cur]<<" "<<j<<" ";
                break;
            }
            dp[cur]=j;
            dp2[j]=cur;
            auto prev=cells;
            for(int i=1;i<cells.size()-1;i++){
                if(prev[i-1]==prev[i+1]){
                    cells[i]=1;
                }else cells[i]=0;
                
            }
            cells.back()=0;
            cells[0]=0;

        }
        if(x==-1)return cells;
        int rem=n-p;
        rem%=(x-p);
        auto ans=dp2[rem+p];
        int j=0;
        for(auto &i:cells){
            i=ans[j]-'0';
            j++;
        }
        return cells;
    }
};