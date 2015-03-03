#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using std::cout;
using std::cerr;
using std::vector;
using std::reverse;
using std::swap;

int main(int argc, char** argv) {
        vector<int> perm;
        for (int i = 1; i < argc; ++i) {
                perm.push_back(atoi(argv[i]));
        }
        int i = -1;
        for (i = perm.size() - 1; i > 0; --i) {
                if (perm[i-1] < perm[i]) {
                        break;
                }
        }
        if (i == -1) {
                return 0;
        }
        if (i == 0) {
                reverse(perm.begin(), perm.end());
        } else {
                int j = -1;
                int minj = -1;
                int mindiff = perm.size();
                for (j = i; j < perm.size(); ++j) {
                        if (perm[j] > perm[i-1] && perm[j] - perm[i-1] < mindiff) {
                                mindiff == perm[j] - perm[i-1];
                                minj = j;
                        }
                }
                swap(perm[i-1], perm[minj]);
                reverse(perm.begin() + i, perm.end());
        }
        for (int x : perm) {
                cout << x << ' ';
        }
        cout << '\n';
        
        return 0;
}
