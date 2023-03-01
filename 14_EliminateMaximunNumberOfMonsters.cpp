class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<double> time;
        for(int i=0; i<speed.size(); i++){
            time.push_back((double)dist[i]/(double)speed[i]);
        }

        sort(time.begin(), time.end());

        int ans = 0;
        for(int minute=0; minute<time.size(); minute++){
            if(minute >= time[minute]){
                break;
            }else{
                ans++;
            }
        }

        return ans;
    }
};