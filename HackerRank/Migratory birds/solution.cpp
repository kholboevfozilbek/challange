
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Type_bird
{
  
private:
    int type_number=0;
    int number_appearance=0;
    
public:
    Type_bird(int type_num): type_number{type_num}
    {   }
    void set_typenum(int typenum){
        type_number = typenum;
    }
    int get_typenum() {return type_number; }
    int get_number_appearance() {return number_appearance; }
    void add() {++number_appearance; }
    void operator++ ();
    friend ostream& operator<< (ostream& stream, Type_bird& o);
};

void Type_bird::operator++ ()
{
    ++number_appearance;
}

ostream& operator<< (ostream& stream, Type_bird& o)
{
    stream << o.get_typenum() << " occurs " << o.get_number_appearance() << " times " << endl;
    return stream;
}

int migratoryBirds(vector<int> arr) {
    std::vector<Type_bird> birds;
    Type_bird bird1(1), bird2(2), bird3(3), bird4(4), bird5(5);
    birds.push_back(bird1); birds.push_back(bird2); birds.push_back(bird3); birds.push_back(bird4); birds.push_back(bird5);
    
    
    for(int i=0; i<arr.size(); ++i){
        switch (arr[i]) {
        case 1:
            birds[0].add();
            break;
        case 2:
            birds[1].add();
            break;
        case 3:
            birds[2].add();
            break;
        case 4:
            birds[3].add();
            break;;
        case 5:
            birds[4].add();
            break;
        default:
            return -1;
            break;
        }
    }

    
    //find the maxes
    std::vector<Type_bird> maxxes;
    int big_boy = birds[0].get_number_appearance(), big_boy_index=0, duplicate_big_index=0;
    for(int i=0; i<birds.size(); ++i)
    {
        if(birds[i].get_number_appearance() > big_boy)
        {
            big_boy = birds[i].get_number_appearance();
            big_boy_index = i;
        }
        else if(birds[i].get_number_appearance() == big_boy)
        {
            duplicate_big_index = i;
        }
    }

    maxxes.push_back(birds[big_boy_index]);
    if(birds[duplicate_big_index].get_number_appearance() == maxxes[0].get_number_appearance())
        maxxes.push_back(birds[duplicate_big_index]);

    
    //among the type bird maxxes we find the one with small type only if there a at least 2 elements in maxxes
    if(maxxes.size() == 1)
        return maxxes[0].get_typenum();
    else{
        int small_type_index=0, smallest_type = maxxes[0].get_typenum();
        for(int i=0; i<maxxes.size(); ++i)
        {
        if(maxxes[i].get_typenum() < smallest_type)
            {
                smallest_type = maxxes[i].get_typenum();
                small_type_index = i;
            }
        }
        return maxxes[small_type_index].get_typenum(); 
    }
    
}


int main()
{
    std::vector<int> arr{1, 4, 4, 4, 5, 3};
    cout << migratoryBirds(arr);
    return 0;

}