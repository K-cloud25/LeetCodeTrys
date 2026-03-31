class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
int ROWS = heights.size(), COLS = heights[0].size();
        vector<int> dist(ROWS * COLS, INT_MAX);
        dist[0] = 0;

        vector<bool> inQueue(ROWS * COLS, false);
        queue<int> q;
        q.push(0);
        inQueue[0] = true;

        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            inQueue[u] = false;

            int r = u / COLS, c = u % COLS;

            for (const auto& dir : directions) {
                int newR = r + dir[0], newC = c + dir[1];
                if (newR >= 0 && newC >= 0 && newR < ROWS && newC < COLS) {
                    int v = newR * COLS + newC;
                    int weight = abs(heights[r][c] - heights[newR][newC]);
                    int newDist = max(dist[u], weight);
                    if (newDist < dist[v]) {
                        dist[v] = newDist;
                        if (!inQueue[v]) {
                            q.push(v);
                            inQueue[v] = true;
                        }
                    }
                }
            }
        }

        return dist[ROWS * COLS - 1];
    }
};