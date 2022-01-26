
#include <iostream>

#include <string.h>
#include <string>
#include <sstream>
#include <ctype.h>
#include <stdlib.h>
#include <vector>

using namespace std;


string play(string S)
{
    vector<string> v;
    stringstream copy;
    copy << S;

    string tripple = "";
    char temp;
    string output_final = "";
    while (copy >> temp)
    {
        if(isalnum(temp))
        {
            tripple += temp;

            if(tripple.size() == 3)
            {
                output_final += tripple;
                output_final += " ";
                v.push_back(tripple);
                tripple.clear();
                
            }   
        }
    }

    output_final += tripple;
    v.push_back(tripple);

    string last;
    string last_vefore;
    string l;
    string l_b;
    if(v[v.size() - 1].size() == 1)
    {
        last = v[v.size() - 1];
        v.pop_back();

        last_vefore = v[v.size() - 1];
        v.pop_back();

        l_b += last_vefore[0];
        l_b += last_vefore[1];

        l += last_vefore[2];
        l += last;

        v.push_back(l_b);
        v.push_back(l);

    }

    output_final.clear();

    for(int i=0; i<v.size(); ++i)
    {
        output_final += v[i];
        output_final += " ";
    }


    return output_final;
    
}

int main()
{
    string S = "0 -  22 1985--324";

    cout << play(S) << endl;

    return 0;
}
