class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int left = 0, right = n - 1;
        //dist from first color
        while (colors[n - 1] == colors[left]) left++;
        int dist1 = (n - 1) - left;
        //dist from last color
        while (colors[0] == colors[right]) right--;
        int dist2 = right;

        return max(dist1, dist2);
    }
};
