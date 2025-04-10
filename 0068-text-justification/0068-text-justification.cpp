class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        string cur="";
        vector<string>temp;
        vector<string>ans;
        int prev=0;
        for(int i=0;i<words.size();i++){
            if(cur.size()+words[i].size()>maxWidth){
                string tans="";
                int rem=maxWidth-cur.size()+1;
                int k=0;
                
                if(temp.size()==1)k=rem,rem=0;
                else {
                    if(rem%(temp.size()-1)>0)k=rem%(temp.size()-1);
                    rem/=(temp.size()-1);
                }
                string x="";
                while(rem--){
                    x+=" ";
                }
                for(int j=0;j<temp.size();j++){
                    tans+=temp[j];
                    if(j<temp.size()-1)
                    tans+=x,tans+=" ";
                    if(k)tans+=" ",k--; 
                    if(k&&temp.size()==1)while(k--)tans+=" "; 
                    
                }
                temp={};
                cur="";
                ans.push_back(tans);
                prev=i;
            }
            cur+=words[i];
            cur+=" ";
            temp.push_back(words[i]);
        }
        
        if(temp.size()){
            int curr=temp.size()-1;
            if(curr==0){
                string tans=temp[0];
                while(tans.size()!=maxWidth)tans+=" ";
                ans.push_back(tans);
                return ans;
            }else{
                int rem=maxWidth-cur.size()+1;
                string tans="";
                for(int j=0;j<temp.size();j++){tans+=temp[j];if(j!=temp.size()-1)tans+=" ";}
                while(tans.size()<maxWidth)tans+=" ";
                ans.push_back(tans);
            }
        }
        return ans;
    }
};