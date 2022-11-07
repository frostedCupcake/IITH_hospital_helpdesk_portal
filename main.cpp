#include <bits/stdc++.h>
#include <cstring>
#include "auth.hpp"
#include "linked_list.hpp"
using namespace std;

void doctor_main(){
    my_list<string> doctor_list;
    vector<string> vi{"Rahul", "Deva", "Tim", "Wall", "Singh"};
    for(int i = 0; i < vi.size(); i++){
        string data = vi[i]; 
        doctor_list.append(data);
    }
    cout << doctor_list << endl;
}


void option_to_function(int option){
    if(option == 1) {
        system("clear");
        doctor_main();
    }
}


int choose(){
    cout<<"HOSPITAL MANAGEMENT DATA"<<endl;
    cout<<"Please choose one of the following"<<endl;
    cout<<"1.DOCTOR DIRECTORY"<<endl;
    cout<<"2.PATIENT DIRECTORY"<<endl;
    cout<<"3.MANAGE APPOINTMENT"<<endl;
    cout<<"4.FEEDBACK"<<endl;  
    int i = -1;
    while(i < 0 or i > 4){
        cout<<"please choose an option: ";
        cin>> i;
        if(i > 0 and i < 5){
            cout<<"you have chosen option "<<i<<endl;
            return i;
        }
        cout<<"you have chosen an invalid option, please try again"<<endl;  
  }
  return i;
}

int main()
{
    int option = choose();
    option_to_function(option);
    return 0;
}
