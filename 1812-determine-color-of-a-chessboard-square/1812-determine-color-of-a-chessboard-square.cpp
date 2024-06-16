class Solution {
public:
    bool squareIsWhite(string coordinates) {
        // if(coordinates[0]%2==1&&coordinates[1]%2==1){
        //     return 0;

        // }
        // else if (coordinates[0]%2==0&&coordinates[1]%2==1){
        //     return 1;
        // }
        return coordinates[0]%2!=coordinates[1]%2;
    }
};