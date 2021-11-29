

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool condition(int n);
void count_Apples_Oranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges);

int main()
{
    int s, t, a, b;
    int m, n;


    cout << "\nEnter the coordinates of the house:  \nEnter starting position:  ";
    cin >> s;
    cout << "Enter ending position of the house:  ";
    cin >> t;

    cout << "Enter position of the apple tree:  ";
    cin >> a;
    cout << "Enter position of the orange tree: ";
    cin >> b;


    cout << "\nEnter number of apples:  ";
    cin >> m;

    cout << "\nEnter number of oranges: ";
    cin >> n;

    if (condition(m) == true && condition(n) == true)
    {
        vector<int> apples(m);
        vector<int> oranges(n);

        cout << "\n\nEnter the distances apples fall from apple tree:  \n";

        for(size_t i=0; i<m; ++i)
            cin >> apples[i];

        cout << "\n\nEnter the distances oranges fall from orange tree: \n";

        for(int j=0; j<n; ++j)
            cin >> oranges[j];

        count_Apples_Oranges(s, t, a, b, apples, oranges);
    }
    else
    {
        cout << "WRONG data!";
        return -1;
    }

    return 0;
}

void count_Apples_Oranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges)
{
    size_t count_apples = 0;
    size_t count_oranges = 0;

    for(size_t i=0; i<apples.size(); ++i)
        if ( a + apples[i] >= s && a + apples[i] <= t )
            ++count_apples;
    for(size_t j=0; j<oranges.size(); ++j)
        if ( b + oranges[j] >= s && b + oranges[j] <= t )
            ++count_oranges;
    cout << "Number of apples:  " << count_apples << endl;
    cout << "Number of oranges: " << count_oranges << endl;
}

bool condition(int n)
{
    if (n >= 1 && n <= pow(10, 5))
       return true;
    return false;
}
