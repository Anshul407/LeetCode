class Solution {
public:
    int solve(vector<vector<int>>&tiles,int next,int i){
        i++;
        int ans=-1;
        int j=tiles.size()-1;
        while(i<=j){
            auto mid=(i+j)/2;
            if(tiles[mid][0]<=next)ans=mid,i=mid+1;
            else j=mid-1;
        }return ans;
    }
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(),tiles.end());
        vector<long long>pre(tiles.size(),0);
        for(int i=0;i<tiles.size();i++){
            if(i==0)pre[i]=(tiles[i][1]-tiles[i][0]+1);
            else pre[i]=pre[i-1]+tiles[i][1]-tiles[i][0]+1;
        }

        int ans=0;
        for(int i=0;i<tiles.size();i++){
            auto cur=tiles[i][0];
            auto nex=tiles[i][1];
            auto temans=carpetLen-(nex-cur+1);
            if(temans<=0)return carpetLen;
            auto next=cur+carpetLen-1;
            auto calc=solve(tiles,next,i);
            if(calc==-1){ans=max(ans,nex-cur+1);continue;}
            long long curans=pre[calc];
            if(i!=0)curans=pre[calc]-pre[i-1];
            if(tiles[calc][1]>next)curans-=(tiles[calc][1]-next);
            ans=max(ans,(int)curans);
            if(ans==carpetLen)return ans;
        }
        return ans;
        
    }
};