// Arup Guha
// 8/20/2020
// Solution to UCF Locals Round 1A Problem: Unique Values

#include <iostream>
#include <set>

using namespace std;

int main(void) {

    int n;
    cin >> n;
    int* vals = new int[n];

    // Read in the numbers.
    for (int i=0; i<n; i++)
        cin >> vals[i];

    // Will store answer here.
    long long res = 0;

    // Low ptr for our sweep.
    int low = 0;

    // Store the set of values in the current interval.
    set<int> myset;

    // Sweep high ptr.
    for (int high=0; high<n; high++) {

        // Keep on removing stuff until vals[high] isn't in the set.
        while (myset.count(vals[high])== 1) myset.erase(vals[low++]);

        // Add this item.
        myset.insert(vals[high]);

        // Add in all contiguous subsequences ending at high.
        res = res + (high-low+1);
    }

    // Ta da!
    cout << res << endl;

    return 0;
}
