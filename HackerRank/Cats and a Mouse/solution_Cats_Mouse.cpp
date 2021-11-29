

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool positive(int distance);
string catandMouse(int x, int y, int z);

int main()
{
    int x, y, z;

    cin >>x; /// Cat A
    cin >>y; /// Cat B
    cin >>z; /// Mouse C
    string result = catandMouse(x, y, z);

    cout << result << endl;

    return 0;
}

string catandMouse(int x, int y, int z)
{
    int CatA_distance;
    int CatB_distance;

    int neg_CatA_diff=0, pos_CatA_diff=0;
    int pos_CatB_diff=0, neg_CatB_diff=0;

    if ( z > x)  /// Cat A
        pos_CatA_diff = z - x;
    else
        neg_CatA_diff = x - z;

    if ( z > y )
        pos_CatB_diff = z- y;
    else
        neg_CatB_diff = y - z;

    if (positive(pos_CatA_diff) == true)
        CatA_distance = pos_CatA_diff;
    else
        CatA_distance = neg_CatA_diff;

    if (positive(pos_CatB_diff) == true)
        CatB_distance = pos_CatB_diff;
    else
        CatB_distance = neg_CatB_diff;

    if (CatA_distance == CatB_distance)
        return "Mouse C";
    else if (CatA_distance < CatB_distance)
        return "Cat A";
    else
        return "Cat B";

}

bool positive(int distance)
{
    if (distance > 0)
        return true;
    return false;
}
