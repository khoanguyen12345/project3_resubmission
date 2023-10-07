#include <iostream>
#include <string>
#include <sstream>

using namespace std;
template <class T> 
class Element
{
    private:
        struct Node
        {
            T item;
            Node *prev;
            Node 	*next;
            int key;
            
        };
    public:
        Element(void); //constructor
        ~Element(void); //destructor
        Element(const Element<T> &copied_element); //copy constructor from another element
        Element(T inputData,int inputKey); //copy constructor by inserting in data and a key value
        void get_key () const; //returns numeric value stored inside element
        void get_data () const; //returns string data stored inside element
};  