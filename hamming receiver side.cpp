#include <iostream>
#include <string>
using namespace std;

int main()
{
    string received;

    cout << "Enter received Hamming code: ";
    cin >> received;

    int n = received.length();

    // Store bits with position 1 at the rightmost side
    int h[100];

    for (int i = 1; i <= n; i++)
    {
        h[i] = received[n - i] - '0';
    }

    // Calculate error position
    int errorPosition = 0;

    for (int p = 1; p <= n; p = p * 2)
    {
        int parity = 0;

        for (int i = 1; i <= n; i++)
        {
            if (i & p)
            {
                parity = parity ^ h[i];
            }
        }

        if (parity != 0)
        {
            errorPosition = errorPosition + p;
        }
    }

    // Display result
    if (errorPosition == 0)
    {
        cout << "\nNo error detected." << endl;
    }
    else
    {
        cout << "\nError detected at position: "
             << errorPosition << " from right." << endl;

        // Correct the error
        h[errorPosition] = h[errorPosition] ^ 1;

        cout << "Error corrected." << endl;
    }

    // Extract data bits
    string data = "";

    for (int i = n; i >= 1; i--)
    {
        // Ignore positions 1, 2, 4, 8...
        if ((i & (i - 1)) != 0)
        {
            data = data + char(h[i] + '0');
        }
    }

    cout << "Corrected data: " << data << endl;

    return 0;
}
