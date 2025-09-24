#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<bool>> all(N, vector<bool>(M, false));
    vector<int> aller;
    vector<bool> isall(N, false);

    for (int i = 0; i < K; i++){
        int A, B;
        cin >> A >> B;
        int who = A - 1;
        int which = B - 1;
        all[who][which] = true;
        if (!isall[who]) {
            bool alls = true;
            for (int j = 0; j < M; j++){
                if (!all[who][j]) {
                    alls = false;
                    break;
                }
            }
            if (alls){
                aller.push_back(A);
                isall[who] = true;
            }
        }
    }
    for (size_t i = 0; i < aller.size(); ++i) {
        cout << aller[i] << (i == aller.size() - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}
