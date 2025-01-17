class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int cur=0;
        for(auto i:derived){
            cur^=i;
        }
        return cur==0;

    }
};