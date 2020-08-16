#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int>ans;
        vector<int>temp;
        unordered_map <int, int>um;
        for (int i : arr1)
            if (find(arr2.begin(), arr2.end(), i) != arr2.end()) um[i]++;
            else temp.push_back(i);
        for (int i : arr2)
            for (int j = 1; j <= um[i]; j++)
                ans.push_back(i);
        sort(temp.begin(), temp.end());
        for (int i : temp)
            ans.push_back(i);
        return ans;
    }
};
int main() {
    Solution sol;
    vector<int>arr1 = { 2,3,1,3,2,4,6,7,9,2,19 };
    vector<int>arr2 = { 2,1,4,3,9,6 };
    vector<int>ans = sol.relativeSortArray(arr1, arr2);
    for (int i : ans)cout << i << "   ";
    return 0;
}