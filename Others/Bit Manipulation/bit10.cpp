#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

void print_vec(vector<int> v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void print_set(set<vector<int>> mySet)
{
    for (const auto &vec : mySet)
    {
        cout << "[ ";
        for (const int &element : vec)
        {
            cout << element << " ";
        }
        cout << "] " << endl;
    }
    cout << "\n";
}

set<vector<int>> generateSubsets(vector<int> nums)
{
    set<vector<int>> ans;
    int n = nums.size();
    sort(nums.begin(), nums.end());

    for (int mask = 0; mask < (1 << n); mask++)
    {
        vector<int> S;
        for (int i = 0; i < n; i++)
        {
            if ((mask & (1 << i)) != 0)
                S.push_back(nums[i]);
        }
        ans.insert(S);
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3, 3, 4};
    set<vector<int>> Subsets = generateSubsets(nums);
    print_set(Subsets);
    return 0;
}