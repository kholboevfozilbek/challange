


#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int count_tallest(vector<int> candles);

int main()
{
    int n;

    cin >> n;


    if ( n >= 1 && n <= pow(10, 5))
    {
        vector<int> candles(n);

        for(size_t i=0; i<n; ++i)
            cin >> candles[i];

        cout << "Number of tallest candles:  " << count_tallest(candles) << endl;

    }

    return 0;
}

int count_tallest(vector<int> candles)
{
    int tallest = candles[0];
    int count_candles = 0;

    for (int i=0; i<candles.size(); ++i)
    {
        if (candles[i] > tallest)
            tallest = candles[i];
    }

    for (int i=0; i<candles.size(); ++i)
    {
        if (candles[i] == tallest)
            ++count_candles;
    }

    return count_candles;
}
