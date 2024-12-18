class Solution {
public:
    int f1(vector<int>&ages,int k){
        int i=0,j=ages.size()-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(ages[mid]>k)j=mid-1;
            else if(ages[mid]>100&&k<100)j=mid-1;
            else i=mid+1;
        }
        return j;
    }
    int f2(vector<int>&ages,float k){
        int i=0,j=ages.size()-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(ages[mid]>k)j=mid-1;
            else if(ages[mid]>100&&k<100)j=mid-1;
            else i=mid+1;
        }
        return i;
    }
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(),ages.end());
        int ans=0;
        for(int i=0;i<ages.size();i++){
          
            int a=f1(ages,ages[i]);
            float s=0.5*ages[i]+7;
            int b=f2(ages,s);
            if(a>=b)
            ans+=(a-b);
        }
        return ans;
    }
};