class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int n=tokens.size();
        int i=0,j=n-1;
        int ans=0;
        int score=0;
        while(i<=j){
            if(power>=tokens[i]){
                power-=tokens[i];
                i++;
                ans++;
                score=max(score,ans);
                
            }else if(ans>0){
                ans--;
                power+=tokens[j];
                j--;
            }
            else{
                return score;
            }
        }
        return score;
    }
};