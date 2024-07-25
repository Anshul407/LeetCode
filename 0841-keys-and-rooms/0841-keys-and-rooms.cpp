class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool>vis(rooms.size(),false);
        queue<int>q;
        for(auto i:rooms[0]){
            vis[i]=1;
            q.push(i);

        }
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            for(auto x:rooms[it]){
                if(!vis[x]){
                vis[x]=1;
                q.push(x);}
            }
        }
        vis[0]=1;
        for(auto i:vis){
            if(i==0)return 0;
        }
        return 1;
        

        
       
    }
};