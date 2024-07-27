class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {

        vector<vector<long long>>dist(26,vector<long long>(26,LLONG_MAX));
        for(int i=0;i<original.size();i++){
            
            int x=original[i]-'a';
            int y=changed[i]-'a';
            dist[x][y]=min(dist[x][y],(long long)cost[i]);
        }
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(dist[i][k]!=LLONG_MAX&&dist[k][j]!=LLONG_MAX&&dist[i][j]>dist[i][k]+dist[k][j]){
                        dist[i][j]=dist[i][k]+dist[k][j];
                    }
                }
            }
        }
        long long ans=0;
        for(int i=0;i<source.length();i++){
            int x=source[i]-'a';
            int y=target[i]-'a';
            if(x==y)continue;
            if(dist[x][y]==LLONG_MAX)return -1;
            ans+=dist[x][y];
        }
        return ans;
    }
};