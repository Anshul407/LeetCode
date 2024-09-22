class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i=0,j=0;
        while(i<name.size()&&j<typed.size()){
            char x=name[i];
            int cnt=0;
            while(i<name.size()&&name[i]==x){
                cnt++;
                i++;
            }
            while(j<typed.size()&&typed[j]==x){
                cnt--;
                j++;

            }
            if(cnt>0)return 0;
        }
        return j>=typed.size()&&i>=name.size();
       
    }
};