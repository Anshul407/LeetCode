class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i=0;i<flowerbed.size();i++){
            if(n==0)break;
            if(flowerbed[i]==1)i++;
            else if(i==flowerbed.size()-1){
                n--;
            }
            else{
                if(flowerbed[i+1]==0){
                    n--;
                    i++;
                }
            }
        }
        return !n;
    }
};