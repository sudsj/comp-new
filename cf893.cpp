#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i = n; i >= 1; i--){
        if ( n % i == 0) {
            for (int k = 1; k <= i; k++) {
                if (i == (pow(2, k)-1) * (pow(2, k-1))){
                    cout << i;
                    i = 0;
                    break;
                }
            }
        }
    }
    return 0;
}