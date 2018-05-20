#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

int main() {
    int times;
    cin >> times;
    while(times--) {
        int L, n;
        int ants[1000005];
        memset(ants, 0, sizeof(ants));
        cin >> L >> n;
        for(int i=0; i<n; ++i) {
            cin >> ants[i];
        }

        int ans_min = 0, ans_max = 0;

        for(int i=0; i<n; ++i) {
            int temp_min = min(ants[i], L-ants[i]);
            ans_min = max(ans_min, temp_min);
            int temp_max = max(ants[i], L-ants[i]);
            ans_max = max(temp_max, ans_max);
        }
        cout << ans_min << " " << ans_max << endl;
    }
    return 0;
}