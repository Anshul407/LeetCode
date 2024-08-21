class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        for(auto i:asteroids){
            if(i<=mass){
                mass+=i;
            }else return 0;
        }
        return 1;
    }
};