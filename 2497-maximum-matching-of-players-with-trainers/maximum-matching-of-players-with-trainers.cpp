class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers){
        int p_ptr = 0;
        int t_ptr = 0;
        int max_match_cnt = 0;
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        while(p_ptr!=players.size() && t_ptr != trainers.size()){
            if(trainers[t_ptr] >= players[p_ptr]){
                max_match_cnt++;
                p_ptr++;
                t_ptr++;
            }
            else{
                t_ptr++;
            }
        }
        return max_match_cnt;
    }
};