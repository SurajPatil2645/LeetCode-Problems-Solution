class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;

        unordered_map<int, vector<int>> valueToIndices;
        for (int i = 0; i < n; ++i) {
            valueToIndices[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<bool> visited(n, false);

        q.push(0);
        visited[0] = true;
        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int curr = q.front();
                q.pop();

                if (curr == n - 1) return steps;

                if (curr + 1 < n && !visited[curr + 1]) {
                    visited[curr + 1] = true;
                    q.push(curr + 1);
                }

                if (curr - 1 >= 0 && !visited[curr - 1]) {
                    visited[curr - 1] = true;
                    q.push(curr - 1);
                }

                if (valueToIndices.count(arr[curr])) {
                    for (int nextIndex : valueToIndices[arr[curr]]) {
                        if (nextIndex != curr && !visited[nextIndex]) {
                            visited[nextIndex] = true;
                            q.push(nextIndex);
                        }
                    }
                    valueToIndices.erase(arr[curr]);
                }
            }
            steps++;
        }

        return -1;
    }
};