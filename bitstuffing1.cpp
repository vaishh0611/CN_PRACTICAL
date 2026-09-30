#include <iostream>
using namespace std;

int main()
{
    int n;
    int data[100], stuffed[200];
    int i, j = 0, count = 0;

    cout << "Enter length of data: ";
    cin >> n;

    cout << "Enter data bits (0 or 1): ";
    for (i = 0; i < n; i++)
        cin >> data[i];

    // Bit stuffing
    for (i = 0; i < n; i++)
    {
        stuffed[j++] = data[i];

        if (data[i] == 1)
            count++;
        else
            count = 0;

        // Insert 0 after five consecutive 1s
        if (count == 5)
        {
            stuffed[j++] = 0;
            count = 0;
        }
    }

    cout << "\nData after bit stuffing: ";
    for (i = 0; i < j; i++)
        cout << stuffed[i];

    return 0;
}
