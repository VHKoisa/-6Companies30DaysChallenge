#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int avg = img[i][j];
                int denominator = 1;
                if (i && j) {
                    avg += img[i - 1][j - 1];
                    denominator++;
                }
                if(j){
                    avg += img[i][j - 1];
                    denominator++;
                }
                if(i){
                    avg += img[i-1][j];
                    denominator++;
                }
                if (i < m - 1 && j < n - 1) {
                    avg += img[i + 1][j + 1];
                    denominator++;
                }
                if(i < m-1){
                    avg += img[i + 1][j];
                    denominator++;
                }
                if(j < n-1){
                    avg += img[i][j+1];
                    denominator++;
                }
                if (i < m - 1 && j) {
                    avg += img[i + 1][j - 1];
                    denominator++;
                }
                if (i && j < n - 1) {
                    avg += img[i - 1][j + 1];
                    denominator++;
                }
                ans[i][j] = avg/denominator;

            }
        }
        return ans;
    }
};