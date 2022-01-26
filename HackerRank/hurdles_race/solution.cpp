

#include <iostream>
#include <vector>

using namespace std;

int hurdleRace(int k, vector<int> height) {
    
    int max=height[0];
    for(int i=0; i<height.size(); ++i)
    {
        if(height[i] > max)
            max = height[i];
    }
    
    if(k >= max)
        return 0;
    return max - k;
}