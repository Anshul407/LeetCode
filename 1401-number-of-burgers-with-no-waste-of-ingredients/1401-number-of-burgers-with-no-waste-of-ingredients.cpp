class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        int x=cheeseSlices*2;
        int y=tomatoSlices;
        int k=y-x;
        if(k<0)return {};
        if(k%2!=0)return {};
        if(cheeseSlices-(k/2)<0)return {};
        return {k/2,cheeseSlices-(k/2)};

    }
};