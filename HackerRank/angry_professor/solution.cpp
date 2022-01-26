

#include <iostream>
#include <vector>
using namespace std;

string angryProfessor(int k, vector<int> a) {
    
    int count_on_time_students=0;
    for(int i=0; i<a.size(); ++i)
    {
        if(a[i] <= 0)
            ++count_on_time_students;
    }
    if(count_on_time_students >= k)
        return "NO";
    else
        return "YES";
}

int main()
{
    return 0;
}