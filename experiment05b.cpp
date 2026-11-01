#include<iostream>
using namespace std;

int main()
{
    int C[11], D[7], i;
    int S0, S1, S2, S3;

    cout << "Enter the received 11-bit codeword: ";
    for(i = 0; i < 11; i++)
    {
        cin >> C[i];
	}
    S0 = C[10] ^ C[8] ^ C[6] ^ C[4] ^ C[2] ^ C[0];
    S1 = C[9]  ^ C[8] ^ C[5] ^ C[4] ^ C[1] ^ C[0];
    S2 = C[7]  ^ C[6] ^ C[5] ^ C[4];
    S3 = C[3]  ^ C[2] ^ C[1] ^ C[0];
	int error_pos = (S3 * 8) + (S2 * 4) + (S1 * 2) + S0;

    if (error_pos != 0) {
        cout << "Error detected at position: " << error_pos<<endl;
        if (error_pos <= 11) {
            C[11 - error_pos] = !C[11 - error_pos];
            cout << "Error corrected."<<endl;
        }
    } else {
        cout << "No error detected."<<endl;
    }

    D[0] = C[0];
    D[1] = C[1];
    D[2] = C[2];
    D[3] = C[4];
    D[4] = C[5];
    D[5] = C[6];
    D[6] = C[8];

    cout << "Decoded message: ";
    for (i = 0; i < 7; i++) {
        cout << D[i];
    }

    return 0;
}
