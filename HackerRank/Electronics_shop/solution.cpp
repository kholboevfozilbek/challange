
#include <iostream>
#include <vector>

using namespace std;

int getMoneySpent(vector<int> keyboards, vector<int> drives, int b) {
    
    int keyboard_i=0;
    int drives_j = 0;
    int max_possible=0;
    for(int i=0; i<keyboards.size(); ++i)
    {
        for(int j=0; j<drives.size(); ++j)
        {
            if(keyboards[i] + drives[j] > max_possible && keyboards[i] + drives[j] <= b)
            {
                max_possible = keyboards[i] + drives[j];
                keyboard_i = i;
                drives_j = j;
            }
        }
    }
    
    if(b <= keyboards[keyboard_i] || b <= drives[drives_j])
        return -1;
    return max_possible;

}