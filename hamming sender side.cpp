#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to calculate number of redundant bits
int calculateRedundantBits(int m)
{
    int r = 0;
    while ((1 << r) < (m + r + 1))
        r++;
    return r;
}

// ---------------- SENDER SIDE ----------------
string generateHammingCode(string data)
{
    int m = data.length();
    int r = calculateRedundantBits(m);
    int n = m + r;

    vector<int> hamming(n + 1, 0);

    // Place data bits in positions other than powers of 2
    int j = 0;
    for (int i = 1; i <= n; i++)
    {
        if ((i & (i - 1)) != 0)   // Not a power of 2
        {
            hamming[i] = data[j] - '0';
            j++;
        }
    }

    // Calculate redundant bits
    for (int p = 1; p <= n; p *= 2)
    {
        int parity = 0;

        for (int i = p; i <= n; i++)
        {
            if (i & p)
                parity ^= hamming[i];
        }

        hamming[p] = parity;
    }

    // Convert to string from right-to-left numbering
    string code = "";
    for (int i = n; i >= 1; i--)
        code += char(hamming[i] + '0');

    return code;
}

// ---------------- RECEIVER SIDE ----------------
string checkAndCorrect(string received)
{
    int n = received.length();

    vector<int> hamming(n + 1);

    // Store received bits.
    // Position 1 is the RIGHTMOST bit.
    for (int i = 1; i <= n; i++)
    {
        hamming[i] = received[n - i] - '0';
    }

    int errorPosition = 0;

    // Check parity bits
    for (int p = 1; p <= n; p *= 2)
    {
        int parity = 0;

        for (int i = 1; i <= n; i++)
        {
            if (i & p)
                parity ^= hamming[i];
        }

        if (parity != 0)
            errorPosition += p;
    }

    if (errorPosition == 0)
    {
        cout << "\nNo error detected.\n";
    }
    else
    {
        cout << "\nError detected at position: "
             << errorPosition << " (from right)\n";

        // Correct the error
        hamming[errorPosition] ^= 1;

        cout << "Error corrected.\n";
    }

    // Extract original data bits
    string data = "";

    for (int i = n; i >= 1; i--)
    {
        if ((i & (i - 1)) != 0)
        {
            data += char(hamming[i] + '0');
        }
    }

    return data;
}

// ---------------- MAIN FUNCTION ----------------
int main()
{
    string data;

    cout << "Enter data bits: ";
    cin >> data;

    // Sender
    string code = generateHammingCode(data);

    cout << "\n--- SENDER SIDE ---\n";
    cout << "Data bits       : " << data << endl;
    cout << "Hamming code    : " << code << endl;

    // Receiver
    string received;

    cout << "\nEnter received Hamming code: ";
    cin >> received;

    string correctedData = checkAndCorrect(received);

    cout << "Corrected data  : " << correctedData << endl;

    return 0;
}
