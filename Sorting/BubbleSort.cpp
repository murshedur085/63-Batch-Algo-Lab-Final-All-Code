#include <iostream>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cout << "Enter array size: ";
    cin >> n;
    int arr[n]; // main array jeta user input dibe
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // user input nicchi
    }

    for (int i = 0; i < n; i++) // i holo number of passes
    {
        for (int j = 0; j < n - i - 1; j++) // j hocche comparison er jonno
        {
            if (arr[j] > arr[j + 1]) // jodi boro value paoa jai tahole swap kore
            {
                swap(arr[j], arr[j + 1]); // duita element adol bodol
            }
        }
    
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}