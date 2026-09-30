#include <iostream>
using namespace std;

int main()
{
    int n;
    int data[200], destuffed[200];
    int i, j = 0, count = 0;

    cout << "Enter length of stuffed data: ";
    cin >> n;

    cout << "Enter stuffed data bits (0 or 1): ";
    for (i = 0; i < n; i++)
        cin >> data[i];

    // Bit destuffing
    for (i = 0; i < n; i++)
    {
        destuffed[j++] = data[i];

        if (data[i] == 1)
            count++;
        else
            count = 0;

        // If five consecutive 1s occur,
        // skip the next 0
        if (count == 5)
        {
            if (i + 1 < n && data[i + 1] == 0)
                i++;

            count = 0;
        }
    }

    cout << "\nData after bit destuffing: ";
    for (i = 0; i < j; i++)
        cout << destuffed[i];

    return 0;
}
