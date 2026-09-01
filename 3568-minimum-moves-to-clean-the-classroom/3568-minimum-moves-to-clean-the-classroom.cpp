class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        
        int startX = -1, startY = -1;
        int litterCount = 0;
        vector<vector<int>> litterIdx(m, vector<int>(n, -1));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') {
                    startX = i;
                    startY = j;
                } else if (classroom[i][j] == 'L') {
                    litterIdx[i][j] = litterCount++;
                }
            }
        }
        
        int targetMask = (1 << litterCount) - 1;
        
        vector<vector<vector<int>>> bestEnergy(m, vector<vector<int>>(n, vector<int>(1 << litterCount, -1)));
        
        struct State {
            int x, y, mask, e, steps;
        };
        
        queue<State> q;
        q.push({startX, startY, 0, energy, 0});
        bestEnergy[startX][startY][0] = energy;
        
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        
        while (!q.empty()) {
            auto [x, y, mask, e, steps] = q.front();
            q.pop();
            
            if (mask == targetMask) {
                return steps;
            }
            
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && classroom[nx][ny] != 'X') {
                    int ne = e - 1;
                    
                    if (ne < 0) continue;
                    
                    int nmask = mask;
                    if (classroom[nx][ny] == 'L') {
                        nmask |= (1 << litterIdx[nx][ny]);
                    }
                    
                    int next_e = ne;
                    if (classroom[nx][ny] == 'R') {
                        next_e = energy;
                    }
                    
                    if (next_e > bestEnergy[nx][ny][nmask]) {
                        bestEnergy[nx][ny][nmask] = next_e;
                        q.push({nx, ny, nmask, next_e, steps + 1});
                    }
                }
            }
        }
        
        return -1;
    }
};