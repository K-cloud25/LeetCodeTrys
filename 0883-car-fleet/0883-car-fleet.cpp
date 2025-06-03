class Solution {
public:

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> cars;
        for(int i=0;i<position.size();i++){
            double time = (target-position.at(i))/(float)speed.at(i);
            cars.push_back({position.at(i), time});
        } 

        sort(cars.rbegin(), cars.rend());
        double maximum=-1.0; int count=0;
        for(auto&[pos,t] : cars){
            if ( maximum==-1 || t>maximum ){
                maximum=t;
                count++;
            }
        }
        return count;
    }
};