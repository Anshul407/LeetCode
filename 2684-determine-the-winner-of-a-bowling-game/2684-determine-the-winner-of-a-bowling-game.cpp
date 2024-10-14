class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int sum=0;
        int sum2=0;
        int cur=0,prev=0;
        
        for(int i=0;i<player1.size();i++){
            if(cur==10||prev==10){
                prev=cur;
                cur=player1[i];
                sum+=(2*player1[i]);
            }else{
                prev=cur;
                cur=player1[i];
                sum+=(player1[i]);
            }
        }
        cur=0,prev=0;
        for(int i=0;i<player2.size();i++){
            if(cur==10||prev==10){
                prev=cur;
                cur=player2[i];
                sum2+=(2*player2[i]);
            }else{
                prev=cur;
                cur=player2[i];
                sum2+=(player2[i]);
            }
        }
        if(sum==sum2)return 0;
        if(sum>sum2)return 1;
        return 2;


    }
};