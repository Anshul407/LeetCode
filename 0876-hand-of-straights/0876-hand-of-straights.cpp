class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int>mp;
        for(auto i:hand)mp[i]++;
        sort(hand.begin(),hand.end());
        for(int i=0;i<hand.size();i++){
            while(mp[hand[i]]>0){
                for(int k=hand[i];k<groupSize+hand[i];k++){
                    if(mp[k]<=0)return 0;
                    mp[k]--;
                }
            }
        }return 1;

    }
};