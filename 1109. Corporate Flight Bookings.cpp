class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n, 0);
        
        for (int i = 0; i < bookings.size(); i++) {
            int start = bookings[i][0];         // Start point of the booking
            int end = bookings[i][1];           // End point of the booking
            int seatsReserved = bookings[i][2]; // Number of seats reserved

            res[start - 1] += seatsReserved;    // Add the number of seats to the start point
            if (end < n) {                      // If the end point is less than n
                res[end] -= seatsReserved;      //     Mark res[i] as the end point, start -> res[end]
            }                                   //     So when we sum up the number of seats for each flight
        }                                       //     Anything after that marked end point, will not articulate
                                                //     at and after the end point.

        // "Prefix sum"
        for (int i = 1; i < n; i++) {
            res[i] += res[i - 1];
        }

        return res;
    }
};