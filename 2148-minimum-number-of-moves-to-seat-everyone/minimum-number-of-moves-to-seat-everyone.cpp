class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(students.begin(),students.end());
        sort(seats.begin(),seats.end());
        int moves = 0;
        for(int i=0;i<seats.size();i++){
            moves += abs(seats[i] - students[i]);
        }
        return moves;
        
    }
};