class Solution {
public:
    vector<int> getAns(int x, vector<int>&v) {
      if(x == v.size())return {};
      if(x == 0)return v;
      vector<int>ans;
      for (auto p : v) {
            if (x == 0 || ans.empty()) {
                  ans.push_back(p);
                  continue;
            }
            while (x > 0 && !ans.empty() && ans.back() < p) {
                  ans.pop_back();
                  x--;
            }
            ans.push_back(p);
      }
      while (x--)ans.pop_back();
      return ans;
    }
    vector<int> merge(vector<int> a, vector<int> b) {
        int i = 0, j = 0, k = 0;
        int n = a.size(), m = b.size();
        vector<int>ans(n + m); 
        while(i < n && j < m) {
            if(a[i] > b[j]) {
                ans[k++] = a[i++];
            }
            else if(a[i] < b[j]) {
                ans[k++] = b[j++];
            }
            else {
                if(i + 1 < n && j + 1 < m) {
                    if(a[i + 1] > b[j + 1]) {
                        ans[k++] = a[i++];
                    }
                    else if(a[i + 1] < b[j + 1]){
                        ans[k++] = b[j++];
                    }
                    else {
                        int x = i + 1, y = j + 1;
                        while(x < n && y < m && a[x] == b[y])x++,y++;
                        if(x >= n) {
                            ans[k++] = b[j++];
                        }
                        else if(y >= m) {
                            ans[k++] = a[i++];
                        }
                        else {
                            if(a[x] > b[y]) {
                                ans[k++] = a[i++];
                            }
                            else {
                                ans[k++] = b[j++];
                            }
                        }
                    }
                   
                }
                else {
                    if(j + 1 >= m)
                        ans[k++] = a[i++];
                    else {
                        ans[k++] = b[j++];
                    }
                }
            }
        }
        while(i < n)ans[k++] = a[i++];
        while(j < m)ans[k++] = b[j++];
        return ans;
    }
    vector<int> maxNumber(vector<int>& A, vector<int>& B, int k) {
        vector<int>ans(k, -1);
        int n = A.size(), m = B.size();
        for(int i=0;i<=min(n, k);i++) {
            int rem = k - i;
            if(rem <= m)
                ans = max(ans, merge(getAns(n - i, A), getAns(m - rem, B)));
            
        }
        return ans;
    }
};