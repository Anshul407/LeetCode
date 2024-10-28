class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queen, vector<int>& king) {
        vector<vector<int>>queens(8,vector<int>(8,0));
        vector<vector<int>>ans;
        queens[king[0]][king[1]]=1;
        for(auto i:queen){
            queens[i[0]][i[1]]=2;
        }
        int x=king[0],y=king[1];
        int i=x-1;
        while(i>=0){
            if(queens[i][y]==2){
                ans.push_back({i,y});
                break;
            }
            i--;
        }
        i=x+1;
        while(i<8){
            
            if(queens[i][y]==2){
                ans.push_back({i,y});
                break;
            }
            i++;
        }
        int j=y-1;
        while(j>=0){
            if(queens[x][j]==2){
                ans.push_back({x,j});
                break;
            }
            j--;
        }
        j=y+1;
        while(j<8){
            if(queens[x][j]==2){
                ans.push_back({x,j});
                break;
            }
            j++;
        }
        i=x-1,j=y-1;
        while(i>=0&&j>=0){
            if(queens[i][j]==2){
                ans.push_back({i,j});
                break;
            }
            j--;
            i--;
        }
        i=x+1,j=y+1;
        while(i<8&&j<8){
            if(queens[i][j]==2){
                ans.push_back({i,j});
                break;
            }
            j++;
            i++;
        }
        i=x+1,j=y-1;
        while(i<8&&j>=0){
            if(queens[i][j]==2){
                ans.push_back({i,j});
                break;
            }
            j--;
            i++;
        }
        i=x-1,j=y+1;
        while(i>=0&&j<8){
            if(queens[i][j]==2){
                ans.push_back({i,j});
                break;
            }
            j++;
            i--;
        }
        return ans;


    }
};