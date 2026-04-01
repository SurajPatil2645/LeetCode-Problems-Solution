class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
        int st = 0, end = arr.size()-1;
        while(st < end){
            int mid = st + (end - st)/2;
            if(arr[mid] == target){
                return mid;
            }
            if(arr[mid] < target){
                st = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        if(arr[st] < target){
            return ++st;
        }
        return st;
    }
};