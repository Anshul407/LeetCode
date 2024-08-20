class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int window=0;
        int i=0;
        int j=0;
        int ans=0;
        while(i<colors.size()&&j<colors.size()){
            window++;
            
            if(window==3){
                if(j==0){
                    if(colors[j]!=colors.back()&&colors.back()!=colors[colors.size()-2]){
                        ans++;
                    }
                }
                else if(j==1){
                    if(colors[j]!=colors[j-1]&&colors.back()!=colors[j-1]){
                        ans++;
                    }
                }
                else{
                    if(colors[j]!=colors[j-1]&&colors[j-1]!=colors[j-2]){
                        ans++;
                    }
                }

                i++;
                window--;

            }

            j++;
            if(j==colors.size())j=0;
        }
        return ans;
    }
};