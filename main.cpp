#include <bits/stdc++.h>
#include <fstream> 
#include <cstring>
#include <sstream>


#include "auth.hpp"
#include "linked_list.hpp"

#define C "clear"

using UMSL = unordered_map<string, vector<string>>;
using UMSVVS = unordered_map<string, vector<vector<int>> >;

using namespace std;

queue<int> q;

// class
class doc_details {
    public:
    int ID;
    string NAME;
    string DEPARTMENT;
    string PHONE;
    string EMAIL;
    string PATIENTS;
    int EMERGENCY;
    int SLOT_1;
    int SLOT_2;
    int SLOT_3;
    string FEEDBACK;

};

class node{
    public:
    doc_details data;
    node* next;
    node(doc_details d){
        data = d;
        next = NULL;
    }
};

void push_back(node** head, doc_details d){
    if(*head == NULL) {
        *head = new node(d);
        return;
    }
    node* newnode = new node(d);
    node* temp = *head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newnode;

}


// FUNCTION PROTOTYPES
void doctor_main(my_list<string> &doctor_list);
void option_to_function(int option, node* head);
int choose_doc();
int choose_main(node** head);
void doctor_operations(int option_doc, node* head);
void doctor_show(node* head);
void doctor_add(node* head);
void doctor_delete(node* head);
void exit_directory(node* head);
void make_appointment(node* head);
void space();


// COMMON UTILITIES

void space(){
    cout << endl << endl << endl; 
}



// DOCTORS DIRECTORY

void option_to_function(int option, node* head){

    if(option == 1) {
        system(C);
        int option_doc = choose_doc();
        doctor_operations(option_doc, head);
    }
    if(option == 3){
        system(C);
        make_appointment(head);

    }
    if(option == 5){
        system(C);
        q.push(1);
    }


}

int choose_doc(){
    cout << "Choose one of the following: " << endl;
    cout << "1.Show details" << endl;
    cout << "2.Delete doctor details" << endl;
    cout << "3.Add a doctor" << endl;
    cout << "4.Update a doctor" << endl;
    cout << "5.Exit directory" << endl;
    int i = -1;
    while(i < 0 or i > 5){
        cout<<"please choose an option: ";
        cin>> i;
        if(i > 0 and i < 6){
            cout<<"you have chosen option "<<i<<endl;
            return i;
        }
        cout<<"you have chosen an invalid option, please try again"<<endl;  
  }
  return i;
}


// void doctor_main(my_list<string> &doctor_list){
    

    
// }

void doctor_operations(int option_doc, node* head){
    switch(option_doc){
        case 1:
            doctor_show(head);
            break;
        case 2:
            doctor_delete(head);
            break;
        case 3:
            doctor_add(head);
            break;
        case 4:
            // doctor_update();
            // break;
        case 5:
            exit_directory(head);
            break;
        default:
            cout << "Invalid";
        
    }

}

void doctor_show(node* head){
    system(C);
    unordered_map<int, string> dep_map;
    int index = 1;
    node* lhead = head;
    cout << "List of departments under our hospital: " << endl;
    set<string> s;
    while(lhead != NULL){
        
        doc_details d = lhead -> data;
        auto pos = s.find(d.DEPARTMENT);
        if(pos != s.end()){
        
        lhead = lhead -> next;
        }
        else{
            dep_map[index] = d.DEPARTMENT;
            s.insert(d.DEPARTMENT);
            cout << index << "." << d.DEPARTMENT << endl;
            index += 1;
            lhead = lhead -> next;
        }
    }
    int dep_name;
    index = 1;
    cout << "Select which department of doctors you want to know about: " << endl;
    cin >> dep_name;
    cout << "List of avalable doctors in this department: " << endl;
    node* lhead1 = head;
    unordered_map<int, string> doc_map;
    while(lhead1 != NULL){
        doc_details d = lhead1 -> data;
        if(d.DEPARTMENT == dep_map[dep_name]){
            doc_map[index] = d.NAME;
            cout << index << "." << d.NAME << endl;
             index++;
        }
        lhead1 = lhead1 -> next;
    }
    int doc_num;
    cout << "Select the doctor: " << endl;
    cin >> doc_num;
    node* lhead2 = head;
    while(lhead2 != NULL){
        doc_details d = lhead2 -> data;
        if(d.NAME == doc_map[doc_num]){
            system(C);
            cout << "Details of Doctor: " << d.NAME << endl;
            cout << "DOCTOR ID: " << d.ID << endl;
            cout << "DOCTOR NAME: " << d.NAME << endl;
            cout << "DEPARTMENT: " << d.DEPARTMENT << endl;
            cout << "PHONE NUMBER: " << d.PHONE << endl;
            cout << "EMAIL ID: " << d.EMAIL << endl;
            cout << "NUMBER OF PATIENTS TREATED: " << d.PATIENTS << endl;
            cout << "IS THE DOCTOR CURRENTLY INVOLVED IN EMERGENCY TREATMENT: " << d.EMERGENCY << endl;
            cout << "SLOT 1 STATUS: " << d.SLOT_1 << endl;
            cout << "SLOT 2 STATUS: " << d.SLOT_2 << endl;
            cout << "SLOT 3 STATUS: " << d.SLOT_3 << endl;
            cout << "RATING: " << d.FEEDBACK << endl;
        }
        lhead2 = lhead2 -> next;
        }
        string opt = "";
        cout << "Press any key to exit" << endl;
        cin >> opt;
        option_to_function(1, head); 
}

void doctor_add(node* head){
    system(C);
    doc_details d;
    cout << "Enter the name of the doctor: " << endl;
    cin >> d.NAME;
    cout << "Enter the name of the department: " << endl;
    cin >> d.DEPARTMENT;
    cout << "Enter the phone number: " << endl;
    cin >> d.PHONE;
    cout << "Enter the email address: " << endl;
    cin >> d.EMAIL;
    cout << "Enter the number of patients that the doctor has treated at this hospital: " << endl;
    cin >> d.PATIENTS;
    cout << "Emergency status: " << endl;
    cin >> d.EMERGENCY;
    cout << "Slot 1 status: " << endl;
    cin >> d.SLOT_1;
    cout << "Slot 2 status: " << endl;
    cin >> d.SLOT_2;
    cout << "Slot 3 status: " << endl;
    cin >> d.SLOT_3;
    system(C);
    cout <<  "Name: " << d.NAME << endl;
    cout <<  "Department: " << d.DEPARTMENT << endl;
    cout <<  "Phone number: " << d.PHONE << endl;
    cout <<  "Email: " << d.EMAIL << endl;
    cout <<  "Number of patients treated at this hospital so far: " << d.PATIENTS << endl;
    cout <<  "Emergency status: " << d.EMERGENCY << endl;
    cout <<  "Slot 1 status: " << d.SLOT_1 << endl;
    cout <<  "Slot 2 status: " << d.SLOT_2 << endl;
    cout <<  "Slot 3 status: " << d.SLOT_3 << endl;
    space();
    cout << "These are the details you entered, are you sure you want to save these (y|n): " << endl;
    string choose;
    cin >> choose; 
    if(choose == "y") {
        push_back(&head, d);
        exit_directory(head);
        }
    else{
        exit_directory(head);
    }
}

void doctor_delete(node* head){
    LoginManager l;
    l.login();
    string doctor_name = "";
    cout << "Enter the name of the doctor which is to be deleted: " << endl; 
    cin >> doctor_name;
    doctor_name = " " + doctor_name;
    fstream fin, fout;
    fin.open("data.csv", ios::in);
    fout.open("data_new.csv", ios::out);
    int flag = 0;
    string line, word;
    vector<string> row;
    while(!fin.eof()){
        row.clear();
        getline(fin, line);
        stringstream s(line);
  
        while (getline(s, word, ',')) {
            row.push_back(word);
        }
        int row_size = row.size();
        string name = row[1];
        if (name != doctor_name) {
            if (!fin.eof()) {
                for (int i = 0; i < row_size - 1; i++) {
                    fout << row[i] << ",";
                }
                fout << row[row_size - 1] << "\n";
            }
        }
        else {
            flag = 1;
        }
        if (fin.eof())
            break;
    }
    if (flag == 1)
        cout << "Doctor deleted\n";
    else
        cout << "Doctor not found\n";
    fin.close();
    fout.close();
    remove("data.csv");
    rename("data_new.csv", "data.csv");
    
}


void exit_directory(node* head){
    system(C);
    int option_main = choose_main( &head);
    option_to_function(option_main, head);
}


// main display

int choose_main(node** head){
    *head = NULL;
    fstream fs;
    fs.open("data.csv", ios::in);
    vector<string> row;
    string line, word, temp;
    int index = 0;
    
    getline(fs, line);
    while(fs >> temp){
        doc_details d;
        index++;
        row.clear();
        getline(fs, line);
        stringstream s(line);
        while(getline(s, word, ',')){
            
            row.push_back(word);
        }
        d.ID = index;
        d.NAME = row[0];
        d.DEPARTMENT = row[1];
        d.PHONE = row[2];
        d.EMAIL = row[3];
        d.PATIENTS = row[4];
        d.EMERGENCY = stoi(row[5]);
        d.SLOT_1 = stoi(row[6]);
        d.SLOT_2 = stoi(row[7]);
        d.SLOT_3 = stoi(row[8]);
        d.FEEDBACK = row[9];
        push_back(&*head, d);
    }
        system(C);
    cout<<"HOSPITAL MANAGEMENT DATA"<<endl;
    cout<<"Please choose one of the following"<<endl;
    cout<<"1.DOCTOR DIRECTORY"<<endl;
    cout<<"2.PATIENT DIRECTORY"<<endl;
    cout<<"3.MANAGE APPOINTMENT"<<endl;
    cout<<"4.FEEDBACK"<<endl;  
    cout << "5.EXIT" << endl;
    int i = -1;
    while(i < 0 or i > 7){
        cout<<"please choose an option: ";
        cin>> i;
        if(i > 0 and i < 6){
            cout<<"you have chosen option "<<i<<endl;
            return i;
        }
        cout<<"you have chosen an invalid option, please try again"<<endl;  
  }
  return i;
}


// APPOINTMENT
void make_appointment(node* head){
    node* lhead = head;
    UMSL dep_doc;
    set<string> dep_list;
    vector<vector<string>> doc_list;
    while(lhead != NULL){
        doc_details d = lhead -> data;
        dep_list.insert(d.DEPARTMENT);
        string dep = d.DEPARTMENT;
        lhead = lhead -> next;
    }
    for(auto i: dep_list){
        node* lhead1 = head;
        while(lhead1 != NULL){
            doc_details d_temp = lhead1 -> data;
            if(d_temp.DEPARTMENT == i){
                dep_doc[i].push_back(d_temp.NAME);
            }
            lhead1 = lhead1 -> next;
        }     
    }
    for(auto i: dep_list){
        doc_list.push_back(dep_doc[i]);
    }
    cout << "Avalable departments: " << endl;
    // print all the departments
    int index = 1;
    for( auto i: dep_list){
        cout << index << "." << i << endl;
        index++;
    }
    cout << "Please choose which department you want to make appointment: " << endl;
    int choosen_dep_index;
    cin >> choosen_dep_index;
    
    auto it = dep_list.begin();
    advance(it, choosen_dep_index-1);
    string choosen_dep = *it;
    vector<string> dep_doctors = dep_doc[choosen_dep];
    index = 1;
    cout << "List of all the doctors under" << choosen_dep << " department: " << endl;
    for(auto i: dep_doctors){
        cout << index << "." << i << endl;
        index++;
    }
    string choose;
    cout << "Do you want to book an appointment(y|n): ";
    cin >> choose;
    if(choose == "y"){
        node* lhead3 = head;
        UMSVVS dep_doc_slots;
        while(lhead3 != NULL){
            doc_details d = lhead3 -> data;
            vector<int> slots;
            slots.push_back(d.SLOT_1);
            slots.push_back(d.SLOT_2);
            slots.push_back(d.SLOT_3);
            if(d.DEPARTMENT == choosen_dep){
                dep_doc_slots[choosen_dep].push_back(slots);     
            }
            lhead3 = lhead3 -> next;
        }
        vector<vector<int>> dep_slots = dep_doc_slots[choosen_dep];
        int dep_doc_size = dep_doc[choosen_dep].size();
        int flag = 0;
        int row_doc = 0;
        int col_slot = 0;
        for(int i = 0; i < dep_doc_size; i++){
            for(int j = 0; j < 3; j++){
                if(dep_slots[i][j] == 0){
                    flag = 1;
                    row_doc = i;
                    col_slot = j;
                    break;
                }
            }
        }
        if(flag == 0){
            cout << "All the slots have been booked for today" << endl;
        }
        else{
            string appoint_doc = dep_doc[choosen_dep][row_doc];
            int appoint_slot = col_slot;
            string given_slot;
            switch(col_slot){
                case 0:
                    given_slot = "SLOT 1";
                    break;
                case 1:
                    given_slot = "SLOT 2";
                    break;
                case 2:
                    given_slot = "SLOT 3";
                    break;
                default:
                    break;
            }
            space();
            system("banner succesful");
            space();
            cout << "Your appointment under" << choosen_dep << " Department with Dr." << appoint_doc << " at " << given_slot << endl;
            space();
            char out;
            cout << "Press any key and enter to exit: " << endl;
            cin >> out;
            exit_directory(head);          

            // update the main data
            node* lhead4 = head;
            while(lhead4 != NULL){
                doc_details d = lhead4 -> data;
                if(d.NAME == appoint_doc){
                    switch(col_slot){
                        case 0:
                            d.SLOT_1 = 1;
                            break;
                        case 1:
                            d.SLOT_2 = 1;
                            break;
                        case 2:
                            d.SLOT_3 = 1;
                            break;
                        default:
                            break;
                    }
                }
                lhead4 = lhead4 -> next;
            }

        }
    }
    else{
        exit_directory(head);
    }
    
}
// main
int main(){
        node* head = NULL;
        int option_main = choose_main(&head);
        option_to_function(option_main, head);
    return 0;
}
