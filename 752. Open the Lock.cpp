class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        queue<string> q;
        int ans = 0;
        
        // If the initial state is in the dead set, then return -1
        if (dead.find("0000") != dead.end()) return -1;
        
        q.push("0000");
        visited.insert("0000");
        
        while (!q.empty()) {
            int size = q.size();
            
            for (int i = 0; i < size; i++) {
                string curr = q.front();
                q.pop();
                
                if (curr == target) {
                    return ans;
                }
                
                for (int j = 0; j < 4; j++) {
                    string up = curr;
                    string down = curr;
                    
                    up[j] = (up[j] - '0' + 1) % 10 + '0';
                    down[j] = (down[j] - '0' + 9) % 10 + '0';
                    
                    if (visited.find(up) == visited.end() && dead.find(up) == dead.end()) {
                        q.push(up);
                        visited.insert(up);
                    }
                    
                    if (visited.find(down) == visited.end() && dead.find(down) == dead.end()) {
                        q.push(down);
                        visited.insert(down);
                    }
                }
            }
            
            ans++;
        }
        
        return -1;
    }
};