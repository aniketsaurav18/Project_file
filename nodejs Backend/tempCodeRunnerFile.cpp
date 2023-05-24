#include <iostream>
using namespace std;
class shape{
    public:
    int sides;
    void number_of_sides(int x){
       cout<<"number of sides in the shape is: "<<x<<endl;
   };
};

class triangle:public shape{
    public:
    
    void getSides(){
        
        cout<<"enter the number of sides: ";
        cin>>sides;

    }
    
};
class trapezium:public shape{
    public:
    
    void getSides(){
        
        cout<<"enter the number of sides: ";
        cin>>sides;

    }
    
};
class hexagon:public shape{
    public:
    
    void getSides(){
        
        cout<<"enter the number of sides: ";
        cin>>sides;

    }
    
};

int main(){
    triangle t;
    t.getSides();
    t.number_of_sides(t.sides);
   trapezium tr;
    tr.getSides();
    tr.number_of_sides(tr.sides);
    hexagon h;
    h.getSides();
    h.number_of_sides(h.sides);



    return 0;
}