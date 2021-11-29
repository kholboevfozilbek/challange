#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    std::vector<int> scores;
    std::set<int> ints = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for(auto i: ints)
    {
        cout << i << endl;
    }

    set<int>::iterator itr;
    int* arr = new int[ints.size()];
	int i = 0;
    for(itr = ints.begin(); itr != ints.end(); itr++)
    {
        arr[i] = *itr;
        ++i;
    }

    cout << "\n\nArray: \n";
    for(int i=0; i<ints.size(); ++i)
        cout << arr[i] << " ";

    return 0;
}