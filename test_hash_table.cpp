// ================================================
// test_hashtable_example.cpp
// Author: Niranjan Reji, Khoa Nguyen, Phuc Nguyen
// Date: 10-02-2023
// Last Update: 10-09-2023
// Test file for correctness of 
// class template Element, HashTable, and usecase,cpp
// ================================================

#include "element.cpp"
#include "hash_table.cpp"
#include "usecase.cpp"
#include <string>
#include <iostream>

using namespace std;


void test_get_key() {
    try {
        //empty element
        Element<int> e;
        if(e.get_key()!=-1){cout << "Incorrect result from get key. Expected -1 but got : " << e.get_key() << endl;}

        //int element
        Element<int> e_int(10, 6);
         if(e_int.get_key()!=6){cout << "Incorrect result from get key. Expected 6 but got : " << e_int.get_key() << endl;}

        //string element
        Element<string> e_string("hi", 6);
        if(e_string.get_key()!=6){cout << "Incorrect result from get key. Expected 6 but got : " << e_string.get_key() << endl;}
    
        //bool element
        Element<bool> e_bool(false, 2);
        if(e_bool.get_key()!=2){cout << "Incorrect result from get key. Expected 2 but got : " << e_bool.get_key() << endl;}

        //char element
        Element<char> e_char('a', 1);
        if(e_char.get_key()!=1){cout << "Incorrect result from get key. Expected 1 but got : " << e_char.get_key() << endl;}

        //float element
        Element<float> e_float(4.2, 7);
        if(e_float.get_key()!=7){cout << "Incorrect result from get key. Expected 7 but got : " << e_float.get_key() << endl;}
    
    } catch(exception& e) {
        cerr << "Error getting key from element : " << e.what() << endl;
    }
       
}

void test_get_data() {
    try {
         //empty element
        Element<int> e;
        if(e.get_data()!=NULL){cout << "Incorrect result from get key. Expected -1 but got : " << e.get_data() << endl;}
        
        //int element
        Element<int> e_int(10, 6);
        if(e_int.get_data()!=10){cout << "Incorrect result from get data. Expected 10 but got : " << e_int.get_data() << endl;}

        //string element
        Element<string> e_string("hi", 6);
        if(e_string.get_data()!="hi"){cout << "Incorrect result from get data. Expected 'hi' but got : " << e_string.get_data() << endl;}
    
        //bool element
        Element<bool> e_bool(false, 2);
        if(e_bool.get_data()!=false){cout << "Incorrect result from get data. Expected false but got : " << e_bool.get_data() << endl;}

        //char element
        Element<char> e_char('a', 1);
        if(e_char.get_data()!='a'){cout << "Incorrect result from get data. Expected 'a' but got : " << e_char.get_data() << endl;}

        //float element
        Element<float> e_float(4.2, 7);
        if(e_float.get_data()!= 4.2){cout << "Incorrect result from get data. Expected 4.2 but got : " << e_float.get_data() << endl;}

    
    } catch(exception& e) {
        cerr << "Error getting data from element : " << e.what() << endl;
    }
}

void test_insert() {
    try {
        HashTable<int> empty_ht(0);
        empty_ht.insert(10, 6);
        if(empty_ht.to_string()!="") {
            cout << "Incorrect result of inserting into table. Expected and empty string But got\n\n" << empty_ht.to_string() << endl;
        }
    } catch(exception& e) {
        cout << "Error caused by trying to insert into empty table : " << e.what() << endl;
    }
    try {
        HashTable<int> ht(5);
        ht.insert(10, 6);
        if(ht.to_string()!="0: \n1: (10,6) \n2: \n3: \n4: \n") {
            cout << "Incorrect result of inserting into table. Expected\n\n0: \n1: (10,6) \n2: \n3: \n4: \n\nBut got\n\n" << ht.to_string() << endl;
        }
        ht.insert(1, 21);
        if(ht.to_string()!="0: \n1: (1,21) (10,6) \n2: \n3: \n4: \n") {
            cout << "Incorrect result of inserting into table" << endl;
        }
    } catch(exception& e) {
        cerr << "Error inserting into non-empty table : " << e.what() << endl;
    }
}

void test_remove() {
    try {
        HashTable<int> empty_ht(0);
        empty_ht.remove(6);
        if(empty_ht.to_string()!="") {
            cout << "Incorrect result of removing from empty table. Expected and empty string But got\n\n" << empty_ht.to_string() << endl;
        }
    } catch(exception& e) {
        cout << "Error caused by trying to remove from empty table : " << e.what() << endl;
    }
    try {
        HashTable<int> ht(5);
        ht.insert(10, 6);
        ht.remove(5);
        if(ht.to_string()!="0: \n1: (10,6) \n2: \n3: \n4: \n") {
            cout << "Incorrect result of removing non-member from table. Expected\n\n0: \n1: (10,6) \n2: \n3: \n4: \n\nBut got\n\n" << ht.to_string() << endl;
        }
    } catch(exception& e) {
        cerr << "Error removing non-member from table : " << e.what() << endl;
    }
    try {
        HashTable<int> ht2(5);
        ht2.insert(10, 6);
        ht2.remove(6);
        if(ht2.to_string()!="0: \n1: \n2: \n3: \n4: \n") {
            cout << "Incorrect result removing member from table. Expected\n\n0: \n1: \n2: \n3: \n4: \n\nBut got\n\n" << ht2.to_string() << endl;
        }
    } catch(exception& e) {
        cerr << "Error removing member from table : " << e.what() << endl;
    }
}

void test_member() {
    try {
        HashTable<int> empty_ht(0);
        if(empty_ht.member(10, 6)) {cout << "Incorrect membership in empty table" << endl;}
    } catch(exception& e) {
        cout << "Error caused by trying to determine membership in empty table : " << e.what() << endl;
    }
    try {
        HashTable<int> ht(5);
        ht.insert(10, 6);
        if(ht.member(11, 6)){cout << "Incorrect membership in table" << endl;}
        if(!ht.member(10, 6)){cout << "Incorrect non-membership in table" << endl;}
    } catch(exception& e) {
        cerr << "Error determining membership from table : " << e.what() << endl;
    }
}

/*void test_login() {
    try {
        HashTable<string>* ht = create_table<string>("logins.csv", 10);
        string username = "IEv";
        string password = "7170790290";
        if(!login(ht, username, password)){cout << "Incorrect result validating accurate login information" << endl;}
        username = "bad-user";
        password = "98213873";
        if(login(ht, username, password)){cout << "Incorrect result validating inaccurate login information" << endl;}
    } catch(exception& e) {
        cerr << "Error in accomplishing login validation : " << e.what() << endl;
    }
}
*/

int main() {
    test_get_key();
    cout << "test_get_key complete" << endl;
    test_get_data();
    cout << "test_get_data complete" << endl;
    test_insert();
    cout << "test_insert complete" << endl;
    test_remove();
    cout << "test_remove complete" << endl;
    test_member();
    cout << "test_member complete" << endl;
    //test_login();
    
    cout << "Testing completed" << endl;
    
    return 0;
}