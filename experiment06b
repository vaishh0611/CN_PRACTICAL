#include <iostream>
using namespace std;

int main() {
    int rmsg[40], d[10], temp[40], i, j, m, n;
    
    cout << "Enter size of received message: ";
    cin >> m;
    cout << "Enter size of divisor: ";
    cin >> n;
    
    cout << "Enter bits of received message: ";
    for (i = 0; i < m; i++) {
        cin >> rmsg[i];
        temp[i] = rmsg[i];
    }
    
    cout << "Enter bits of divisor: ";
    for (j = 0; j < n; j++) {
        cin >> d[j];
    }
    
    int data_bits = m - n + 1;
    for (i = 0; i < data_bits; i++) {
        if (temp[i] == 1) {
            for (j = 0; j < n; j++) {
                temp[i + j] = temp[i + j] ^ d[j];
            }
        }
    }
    
    bool error = false;
    for (i = data_bits; i < m; i++) {
        if (temp[i] != 0) {
            error = true;
            break;
        }
    }
    
    if (error) {
        cout << "Error detected in transmission.";
    } else {
        cout << "No error detected. Data is valid.";
    }
    
    return 0;
}
