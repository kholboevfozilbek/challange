


#include <iostream>
#include <string>

using namespace std;


int countingValleys(int steps, string path) {

    int level;
    int counter=0;
    
    for(int i=0; i<path.size(); ++i)
    {
        if(path[i] == 'D')
        {
            --level;
            continue;
        }
        
        if(path[i] == 'U') {
            ++level;
            if(level == 0)
                ++counter;
        }
    }
    
    return counter;

}