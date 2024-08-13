class Solution {
public:
    int strStr(string h, string n) {
       int ans = -1;
    int cnt = 0;
    int j = n.length() - 1;

    for (int i = h.length() - 1; i >= 0; i--) {
        if (j>=0&&h[i] == n[j]) {
            cnt++;
            j--;
        } else {
            cnt = 0;
            j = n.length() - 1;
            if (j>=0&&h[i] == n[j]) {
            cnt++;
            j--;
        }
        }
        if (cnt == n.length()) {
            ans = i;
            cnt = 0;
            j = n.length() - 1;
            if (j>=0&&h[i] == n[j]) {
            cnt++;
            j--;
        }
            
            
        }
    }
    cnt=0;
    j=0;
   
        for(int i=0;i<h.length();i++){
                 
                   if(h[i]==n[j]){
                       cnt++;
                       j++;
                   }
                   else{
                       cnt=0;
                       j=0;
                        if (j>=0&&h[i] == n[j]) {
            cnt++;
            j++;
        }
                   }
                     if(cnt==n.length()){
                       ans=i-n.length()+1;
                       break;
                   }
        }return ans;
    }
};