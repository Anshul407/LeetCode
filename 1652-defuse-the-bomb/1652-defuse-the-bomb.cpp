class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        
       if(k>0){
           vector<int>ans;
           int i=0;
           int window=0;
           int it=1;
           int size=code.size();
           int currans=0;
           while(i<size){
             currans+=code[it%size];
             it++;
             window++;
             if(window==k){

                
                ans.push_back(currans);
                i++;
                currans-=code[i%size];
         
                window--;
                
             }
           }
           return ans;
       }
       else if(k<0){
                 vector<int>ans;
           reverse(code.begin(),code.end());
           k*=-1;
           int i=0;
           int window=0;
           int it=1;
           int size=code.size();
           int currans=0;
           while(i<size){
             currans+=code[it%size];
             it++;
             window++;
             if(window==k){

                
                ans.push_back(currans);
                i++;
                currans-=code[i%size];
         
                window--;
                
             }
           }
           reverse(ans.begin(),ans.end());
           return ans;
       }
       else{
        vector<int>ans;
        for(int i=0;i<code.size();i++)ans.push_back(0);
        return ans;
       }
    }
};