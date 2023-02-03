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

        for (int i = 1; i < n; i++) {
            res[i] += res[i - 1];
        }

        return res;
    }

    // Walkthrough of the entire process
    // 1. bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5
    // 2. res = [0, 0, 0, 0, 0]
    // 3. i = 0, start = 1, end = 2, seatsReserved = 10
    //    res[0] += 10
    //    if (2 < 5) True -> res[2] -= 10
    //    res = [10, 0, -10, 0, 0]
    // 4. i = 1, start = 2, end = 3, seatsReserved = 20
    //    res[1] += 20
    //    if (3 < 5) True -> res[3] -= 20
    //    res = [10, 20, -10, -20, 0]
    // 5. i = 2, start = 2, end = 5, seatsReserved = 25
    //    res[1] += 25
    //    if (5 < 5) False
    //    res = [10, 45, -10, -20, 0]
    // 6. i = 3, end of the loop
    //
    // 7.   i = 1, res[1] = 45 + 10 = 55
    //      i = 2, res[2] = 55 + -10 = 45
    //      i = 3, res[3] = 45 + -20 = 25
    //      i = 4, res[4] = 25 + 0 = 25
    //      res = [10, 55, 45, 25, 25]
};