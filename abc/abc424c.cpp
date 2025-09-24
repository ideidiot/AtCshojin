#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<vector<int>> adj(N + 1);
    vector<pair<int, int>> from(N + 1);
    vector<int> getable(N + 1, 0);
    vector<bool> got(N + 1, false);
    queue<int> q;

    for (int i = 1; i <= N; i++){
        int a, b;
        cin >> a >> b;
        from[i] = {a, b};
        if (a != 0) adj[a].push_back(i);
        if (b != 0) adj[b].push_back(i);
    }

    int c = 0;
    for (int i = 1; i <= N; i++){
        if (from[i].first == 0 && from[i].second == 0){
            if (!got[i]){
                q.push(i);
                got[i] = true;
                c++;
            }
        }
    }

    while (!q.empty()){
        int u = q.front();
        q.pop();

        for (int v : adj[u]){
            if (!got[v]){
                getable[v]++;
                
                int req = 0;
                if (from[v].first != 0) req++;
                if (from[v].second != 0) req++;

                if (getable[v] >= 1){ //どっちかだけでも可
                    q.push(v);
                    got[v] = true;
                    c++;
                }
            }
        }
    }

    cout << c << endl;

    return 0;
}
