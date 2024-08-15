class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<pair<string,int>>q;
        q.push({startGene,0});
        map<string,int>mp;
        for(auto i:bank){
            mp[i]++;
        }
        map<string,int>vis;
        vis[startGene]=1;
        while(!q.empty()){
            auto it=q.front();
            string d=it.first;
           q.pop();
            int dist=it.second;
             if(d==endGene)return dist;
            for(int i=0;i<d.length();i++){
                char pr=d[i];
                d[i]='A';
                if(mp[d]&&!vis[d]){vis[d]=1;q.push({d,dist+1});}
                d[i]='C';
                if(mp[d]&&!vis[d]){vis[d]=1;q.push({d,dist+1});}
                d[i]='G';
               if(mp[d]&&!vis[d]){vis[d]=1;q.push({d,dist+1});}
                d[i]='T';
                if(mp[d]&&!vis[d]){vis[d]=1;q.push({d,dist+1});}
                d[i]=pr;
            }
        }
        return -1;


    }
};