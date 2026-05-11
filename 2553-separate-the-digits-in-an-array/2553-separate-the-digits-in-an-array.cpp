// class Solution {
// public:
//     vector<int> separateDigits(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> answer;
//         for(int i=0;i<n;i++){
//             int num=nums[i];
//             vector<int> ans;
//             while(num>0){
//                 int dig = num%10;
//                 ans.push_back(dig);
//                 num /= 10;
//             }
//             reverse(ans.begin(), ans.end());
//             answer.insert(answer.end(), ans.begin(), ans.end());
//         }
//         return answer;
//     }
// };

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> answer;
        answer.reserve(nums.size() * 4); 

        for (int num : nums) {
            if (num < 10) {
                answer.push_back(num);
            } else {
                int digits[6]; 
                int i = 0;
                while (num > 0) {
                    digits[i++] = num % 10;
                    num /= 10;
                }
                while (i > 0) {
                    answer.push_back(digits[--i]);
                }
            }
        }
        return answer;
    }
};