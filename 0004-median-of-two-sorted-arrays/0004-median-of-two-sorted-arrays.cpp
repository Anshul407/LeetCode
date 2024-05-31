class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<double>v;
        for(auto i:nums1){
            v.push_back(i);
        }
        for(auto i:nums2){
            v.push_back(i);
        }
        sort(v.begin(),v.end());
        if(v.size()%2==1){
            return v[v.size()/2];
        }
        return (v[v.size()/2-1]+v[v.size()/2])/2;
        
    }
};