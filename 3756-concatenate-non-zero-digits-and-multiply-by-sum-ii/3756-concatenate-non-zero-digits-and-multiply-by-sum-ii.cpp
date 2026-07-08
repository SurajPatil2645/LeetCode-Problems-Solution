class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        long long MOD = 1e9 + 7;
        
        vector<int> V;
        vector<int> I;
        
        for (int i = 0; i < n; ++i) {
            if (s[i] != '0') {
                V.push_back(s[i] - '0');
                I.push_back(i);
            }
        }
        
        int k = V.size();
        
        vector<long long> pref_sum(k + 1, 0);
        vector<long long> pref_val(k + 1, 0);
        vector<long long> p10(k + 1, 1);
        
        for (int i = 0; i < k; ++i) {
            pref_sum[i + 1] = pref_sum[i] + V[i];
            pref_val[i + 1] = (pref_val[i] * 10 + V[i]) % MOD;
            p10[i + 1] = (p10[i] * 10) % MOD;
        }
        
        vector<int> ans;
        ans.reserve(queries.size());
        
        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            
            int L = lower_bound(I.begin(), I.end(), l) - I.begin();
            int R = upper_bound(I.begin(), I.end(), r) - I.begin() - 1;
            
            if (L > R) {
                ans.push_back(0);
            } else {
                long long cur_sum = pref_sum[R + 1] - pref_sum[L];
                
                long long cur_val = (pref_val[R + 1] - (pref_val[L] * p10[R - L + 1]) % MOD) % MOD;
                if (cur_val < 0) {
                    cur_val += MOD;
                }
                
                long long res = (cur_val * (cur_sum % MOD)) % MOD;
                ans.push_back(res);
            }
        }
        
        return ans;
    }
};