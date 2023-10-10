#include "element.cpp"
#include "hash_table.cpp"
#include "usecase.cpp"
#include <string>
#include <iostream>

using namespace std;

   void test_login() {
    try {
        HashTable<string>* ht = create_table<string>("logins.csv", 10);
        string username = "IEv";
        string password = "7170790290";
        if(!login(ht, username, password)){cout << "Incorrect result validating accurate login information" << endl;}
        username = "bad-user";
        password = "98213873";
        if(login(ht, username, password)){cout << "Incorrect result validating inaccurate login information" << endl;}
        cout << "Enter a username" << endl;
        cin >> username;
        cout << "Enter a password" << endl;
        cin >> password;
        if(login(ht, username, password)){cout << "username and password in csv" << endl;}else{cout << "username and password not in csv" << endl;}
    } catch(exception& e) {
        cerr << "Error in accomplishing login validation : " << e.what() << endl;
    }
}

int main(){
    test_login();
    return 0;
}
