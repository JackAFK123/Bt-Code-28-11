#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N = 100;

string a;
bool chk[MAX_N + 1];
int mat[MAX_N + 1][MAX_N + 1];
int w[MAX_N + 1];
int num[128];
int n, res, sum, maxV, t;

void dfs(int i) {
    chk[i] = true;
    sum += w[i];
    maxV = max(maxV, w[i]);
    for (int j = 1; j <= t; ++j) {
        if (mat[i][j] == 1 && !chk[j]) {
            dfs(j);
        }
    }
}

int main() {
    cin >> a;
    n = a.length();
    t = 0;

    for (char c = 'A'; c <= 'z'; ++c) {
        ++t;
        num[c] = t;
    }

    for (char c = '0'; c <= '9'; ++c) {
        ++t;
        num[c] = t;
    }

    for (int i = 1; i <= n / 2; ++i) {
        if (a[i - 1] != a[n - i]) {
            mat[num[a[i - 1]]][num[a[n - i]]] = 1;
            mat[num[a[n - i]]][num[a[i - 1]]] = 1;
        }
    }

    for (int i = 1; i <= n; ++i) {
        ++w[num[a[i - 1]]];
    }

    for (int i = 1; i <= t; ++i) {
        if (!chk[i]) {
            sum = 0;
            maxV = 0;
            dfs(i);
            res += sum - maxV;
        }
    }

    cout << res << endl;

    return 0;
}

