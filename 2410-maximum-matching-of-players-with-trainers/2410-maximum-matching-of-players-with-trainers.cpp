class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
       
        int ans=0,j=0;
        for(auto i:trainers){
            if(ans==players.size())break;
            if(i>=players[j]){ans++;
            j++;}
        }
        return ans;
        }
};