/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if(points.size() < 3) return points.size();
        
        int results = 0;
        unordered_map<double, int> slope_map;
        for(int i = 0; i < points.size(); i++){
            slope_map.clear();
            int maxPoint = 1;
            int samePoint = 0;
            
            for(int k = i+1; k < points.size(); k++){
                double slope;
                if(points[i].x == points[k].x){
                    slope = std::numeric_limits<double>::max();
                    if(points[i].y == points[k].y){
                        samePoint ++;
                        continue;
                    }
                }
                
                else{
                    slope = 1.0 * (points[i].y - points[k].y) / (points[i].x - points[k].x);
                }
                
                int index = 0;
                if(slope_map.find(slope) != slope_map.end()){
                    slope_map[slope] ++;
                    index = slope_map[slope];
                }
                else{
                    slope_map[slope] = 2;
                    index = 2;
                }
                maxPoint = max(maxPoint, index);
            }
            results = max(maxPoint + samePoint, results);
        }
        return results;
    }
};