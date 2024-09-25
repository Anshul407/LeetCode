class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        map<char,int>odd;
        odd['a']=1;
        odd['c']=1;
        odd['e']=1;
        odd['g']=1;

        if(odd.find(coordinate1[0])!=odd.end()&&odd.find(coordinate2[0])!=odd.end()){
            return (coordinate1[1]-'0')%2==(coordinate2[1]-'0')%2;
        }else if(odd.find(coordinate1[0])==odd.end()&&odd.find(coordinate2[0])==odd.end()){
                        return (coordinate1[1]-'0')%2==(coordinate2[1]-'0')%2;
        }
        return (coordinate1[1]-'0')%2!=(coordinate2[1]-'0')%2;


    }
};