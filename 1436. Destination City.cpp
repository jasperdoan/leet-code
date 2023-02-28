class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, string> m;
        string location = paths[0][0];
        
        // Build map, with key:cityA | val:cityB
        for (auto& path : paths) {
            m[path[0]] = path[1];
        }
        
        // Go wherever the wind blows
        while (m.count(location)) {
            location = m[location];
        }

        return location;        
    }
};