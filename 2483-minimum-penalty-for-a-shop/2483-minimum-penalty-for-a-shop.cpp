class Solution {
public:
    int bestClosingTime(string customers) {
        int psum=0;
        int s=0;
        pair<int,int>mini;
        for(auto i:customers){
            if(i=='Y')s++;
        }
        mini.first=0;
        mini.second=s;
        if(s==0)return 0;
        int j=0;
        for(auto i:customers){
            if(i=='Y'){
                s--;
                if(mini.second>s){
                     mini.first=j;
                    mini.second=s;
                }
               
            }
            if(i=='N'){
                 s++;
                if(mini.second>s){
                     mini.first=j;
                    mini.second=s;
                }
            }
            j++;
        }
        return mini.first+1;
        return mini.first;
    }
};