class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>arr(n);
        for(auto b:bookings){
            int first = b[0]-1, last = b[1], seats = b[2];
            arr[first] += seats;
            if(last == n) continue;
            arr[last] -= seats;
        }
        for(int i=1; i<n; i++){
            arr[i] += arr[i-1];
        }
        return arr;
    }
};