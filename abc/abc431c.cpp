#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    
    int N, M, K;
    cin >> N >> M >> K;
    vector<ll> H(N), B(M);
    for (int i = 0; i < N; i++) cin >> H[i];
    for (int i = 0; i < M; i++) cin >> B[i];
    sort(H.begin(), H.end());
    sort(B.begin(), B.end());
    
    int left = 0; int right = min(N,M); int A = 0;
    while(left <= right){
        int nibutan = (left + right) / 2;
        bool mid = true;
        for(int i = 0; i < nibutan; i++){
            if(H[i] > B[M - nibutan + i]){
                mid = false;
                break;
            }
        }
        if(mid){
            left = nibutan + 1;
            A=nibutan;
        }else{
            right = nibutan - 1;
        }
    }
    cout << (A >= K ? "Yes" : "No");
    return 0;
}
