


#include <iostream>
#include <vector>
using namespace std;

class bulb
{
public:
    int number_bulb;
    bool ON;
    bool SHINE;



    bulb(int num_bulb, bool on=false): number_bulb{num_bulb}, ON{on}
    {   }
    bool get_SHINE() {return SHINE; }
    bool get_ON() {return ON; }
    bool implication_SHINE(bulb &previous_bulb)
    {
        if(ON == true)
        {
            if(previous_bulb.ON == true)
            {
                if(previous_bulb.SHINE == true)
                {
                    SHINE = true;
                    return true;
                }
                else {
                    SHINE = false;
                    return false;
                }
            }
            else
            {
                SHINE = false;
                return false;
            }
        }
        else{
            SHINE = false;
            return false;
        }
        
    }
};

int main()
{
    vector<int> A{2, 1, 3, 5, 4};
    bulb bulb1(1), bulb2(2), bulb3(3), bulb4(4), bulb5(5);

    int sum=0;
    vector<int> moments;
    for(int i=0; i<A.size(); ++i)
    {
        switch (A[i])
        {

        case 1:
            bulb1.ON = true;
            bulb1.SHINE = true;
            ++sum;
            moments.push_back(i);
            if(bulb1.ON == true)
                bulb1.SHINE = true;
            break;
        case 2:
            bulb2.ON = true;
            if(bulb2.implication_SHINE(bulb1) == true)
            {
                ++sum;
                moments.push_back(i);
                if(bulb3.ON == true)
                    bulb3.SHINE = true;
            }
            break;
        case 3:
            bulb3.ON = true;
            if(bulb3.implication_SHINE(bulb2) == true)
            {
                ++sum;
                moments.push_back(i);
                if(bulb4.ON == true)
                    bulb4.SHINE = true;
            }
            break;
        case 4:
            bulb4.ON = true;
            if(bulb4.implication_SHINE(bulb3) == true)
            {
                ++sum;
                moments.push_back(i);
                if(bulb5.ON == true)
                    bulb5.SHINE = true;
            }
            break;
        case 5:
            bulb5.ON = true;
            if(bulb5.implication_SHINE(bulb4) == true)
            {
                ++sum;
                moments.push_back(i);
            }
            break;
        default:
            break;
        } 
    }

    cout << "\nNumber of ON -> SHINE " << sum << endl;
    cout << "Moments: ";
    for(int i=0; i<moments.size(); ++i)
        cout << moments[i] << "  ";

    return 0;
}
