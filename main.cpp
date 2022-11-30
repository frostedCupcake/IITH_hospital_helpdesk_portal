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

class pat_details {
    public:
    int ID;
    string NAME;
    string DEPARTMENT;
    string DOCTOR;
    string EMAIL;
    string PHONE;
    int EMERGENCY;
    int SLOT;
    string FEEDBACK;
    int UID;
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
class node_p{
    public:
    pat_details data;
    node_p* next;
    node_p(pat_details p){
        data = p;
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
void push_back_p(node_p** head, pat_details p){
    if(*head == NULL) {
        *head = new node_p(p);
        return;
    }
    node_p* newnode = new node_p(p);
    node_p* temp = *head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newnode;

}


// FUNCTION PROTOTYPES
void doctor_main(my_list<string> &doctor_list);
void option_to_function(int option, node* head, node_p* another_head);
int choose_doc();
int choose_main(node** head, node_p** another_head);
void doctor_operations(int option_doc, node* head, node_p* another_head);
void doctor_show(node* head, node_p* another_head);
void doctor_add(node* head, node_p* another_head);
void doctor_delete(node** head, node_p* another_head);
void doctor_update(node* head, node_p* another_head);
void exit_directory(node* head, node_p* another_head);
void make_appointment(node* head, node_p* another_head);
void space();
void feedback_thingy(node* head, node_p* another_head);
// patients funtions
int choose_pat();
void patient_delete(node_p* another_head);
void patient_show(node* head, node_p* another_head);
void patient_operations(int option_doc, node* head, node_p* another_head);

// COMMON UTILITIES

void space(){
    cout << endl << endl << endl; 
}
void exit_directory(node* head, node_p* another_head){
    system(C);
    // cout << "Enter the name of the doctor which is to be deleted: " << endl; 
    // cin >> doctor_name;
    // doctor_name = " " + doctor_name;
    // fstream fin, fout;
    // fin.open("doctors_data.csv", ios::in);
    // fout.open("doctors_data_new.csv", ios::out);
    // int flag = 0;
    // string line, word;
    // vector<string> row;
    // while(!fin.eof()){
    //     row.clear();
    //     getline(fin, line);
    //     stringstream s(line);
  
    //     while (getline(s, word, ',')) {
    //         row.push_back(word);
    //     }
    //     int row_size = row.size();
    //     string name = row[1];
    //     if (name != doctor_name) {
    //         if (!fin.eof()) {
    //             for (int i = 0; i < row_size - 1; i++) {
    //                 fout << row[i] << ",";
    //             }
    //             fout << row[row_size - 1] << "\n";
    //         }
    //     }
    //     else {
    //         flag = 1;
    //     }
    //     if (fin.eof())
    //         break;
    // }
    int option_main = choose_main( &head, &another_head);
    option_to_function(option_main, head, another_head);
}



// DOCTORS DIRECTORY

void option_to_function(int option, node* head, node_p* another_head){

    if(option == 1) {
        system(C);
        int option_doc = choose_doc();
        doctor_operations(option_doc, head, another_head);
    }
    if(option == 3){
        system(C);
        make_appointment(head, another_head);

    }if(option == 2){
        system(C);
        int option_pat = choose_pat();
        patient_operations(option_pat, head, another_head);
    }
    if(option == 4){
        system(C);
        feedback_thingy(head, another_head);
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
    while(i < 0 || i > 5){
        cout<<"please choose an option: ";
        cin>> i;
        if(i > 0 && i < 6){
            cout<<"you have chosen option "<<i<<endl;
            return i;
        }
        cout<<"you have chosen an invalid option, please try again"<<endl;  
  }
  return i;
}


void doctor_operations(int option_doc, node* head, node_p* another_head){
    switch(option_doc){
        case 1:
            doctor_show(head, another_head);
            break;
        case 2:
            doctor_delete(&head, another_head);
            break;
        case 3:
            doctor_add(head, another_head);
            break;
        case 4:
            doctor_update(head, another_head);
            break;
        case 5:
            exit_directory(head, another_head);
            break;
        default:
            cout << "Invalid";
        
    }

}

void doctor_show(node* head, node_p* another_head){
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
        option_to_function(1, head, another_head); 
}

void doctor_add(node* head, node_p* another_head){
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
        exit_directory(head, another_head);
        }
    else{
        exit_directory(head, another_head);
    }
}

void doctor_delete(node** head, node_p* another_head){
    LoginManager l;
    l.login();
    string doctor_name = "";
    cout << "Enter the name of the doctor which is to be deleted: " << endl; 
    cin >> doctor_name;
    doctor_name = " " + doctor_name;
    // node* lhead1 = *head;
    // doc_details d;
    // node* prev = NULL;
    // while(lhead1 != NULL){
    //     d = lhead1 -> data;
    //     if(d.NAME == doctor_name){
    //         if(prev == NULL){
    //             node* temp = lhead1;
    //             *head = (*head) -> next;
    //             delete temp;
    //         }
    //         else{
    //             node* temp = lhead1;
    //             node* next_node = lhead1 -> next;
    //             prev -> next = next_node;
    //             delete temp;
    //         }
    //         break;

    //     }
    //     prev = lhead1;
    //     lhead1 = lhead1 -> next;
    // }
    fstream fin, fout;
    fin.open("doctors_data.csv", ios::in);
    fout.open("doctors_data_new.csv", ios::out);
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
    remove("doctors_data.csv");
    rename("doctors_data_new.csv", "doctors_data.csv");
    
}

void doctor_update(node* head, node_p* another_head){
cout << "hi" << endl;
}


// PATIENTS
void patient_operations(int option_doc, node* head, node_p* another_head){
    switch(option_doc){
        case 1:
            patient_show(head, another_head);
            break;
        case 2:
            patient_delete(another_head);
            break;
        case 3:
            exit_directory(head, another_head);
            break;
        default:
            cout << "Invalid";
        
    }

}


int choose_pat(){
    cout << "Choose one of the following: " << endl;
    cout << "1.Show details" << endl;
    cout << "2.Delete patient details" << endl;
    cout << "3.Exit directory" << endl;
    int i = -1;
    while(i < 0 || i > 3){
        cout<<"please choose an option: ";
        cin>> i;
        if(i > 0 && i < 4){
            cout<<"you have chosen option "<<i<<endl;
            return i;
        }
        cout<<"you have chosen an invalid option, please try again"<<endl;  
  }
  return i;
}

void patient_delete(node_p* another_head){
    LoginManager l;
    l.login();
    string patient_name = "";
    cout << "Enter the name of the patient which is to be deleted: " << endl; 
    cin >> patient_name;
    patient_name = " " + patient_name;
    fstream fin, fout;
    fin.open("patients_data.csv", ios::in);
    fout.open("patients_data_new.csv", ios::out);
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
        if (name != patient_name) {
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
        cout << "Patient deleted\n";
    else
        cout << "Patient not found\n";
    fin.close();
    fout.close();
    remove("patients_data.csv");
    rename("patients_data_new.csv", "patients_data.csv");
}

void patient_show(node* head, node_p* another_head){
    system(C);
    unordered_map<int, string> dep_map;
    int index = 1;
    node_p* lhead = another_head;
    cout << "List of departments under our hospital: " << endl;
    set<string> s;
    while(lhead != NULL){
        pat_details p = lhead -> data;
        auto pos = s.find(p.DEPARTMENT);
        if(pos != s.end()){
        
        lhead = lhead -> next;
        }
        else{
            dep_map[index] = p.DEPARTMENT;
            s.insert(p.DEPARTMENT);
            cout << index << "." << p.DEPARTMENT << endl;
            index += 1;
            lhead = lhead -> next;
        }
    }
    int dep_name;
    index = 1;
    cout << "Select which department of doctors you want to know about: " << endl;
    cin >> dep_name;
    cout << "List of avalable doctors in this department: " << endl;
    node_p* lhead1 = another_head;
    unordered_map<int, string> pat_map;
    while(lhead1 != NULL){
        pat_details p = lhead1 -> data;
        if(p.DEPARTMENT == dep_map[dep_name]){
            pat_map[index] = p.NAME;
            cout << index << "." << p.NAME << endl;
             index++;
        }
        lhead1 = lhead1 -> next;
    }
    int pat_num;
    cout << "Select the patient: " << endl;
    cin >> pat_num;
    node_p* lhead2 = another_head;
    while(lhead2 != NULL){
        pat_details p = lhead2 -> data;
        if(p.NAME == pat_map[pat_num]){
            system(C);
            cout << "Details of Patient: " << p.NAME << endl;
            cout << "Patient department: " << p.DEPARTMENT<< endl;
            cout << "Doctor NAME: " << p.DOCTOR << endl;
            cout << "Email: " << p.EMAIL << endl;
            cout << "PHONE NUMBER: " << p.PHONE << endl;
            cout << "slot: " << p.SLOT << endl;
            cout << "UID: " << p.UID << endl;
        }
        lhead2 = lhead2 -> next;
        }
        string opt = "";
        cout << "Press any key to exit" << endl;
        cin >> opt;
        option_to_function(1, head, another_head); 
}

// main display

int choose_main(node** head, node_p** another_head){
    fstream fs;
    fs.open("doctors_data.csv", ios::in);
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
    fs.close();
    fstream fin;
    fin.open("patients_data.csv", ios::in);
    vector<string> row_p;
    string line_p, word_p, temp_p;
    int index_p = 0;
    
    getline(fin, line_p);
    while(fin >> temp_p){
        pat_details p;
        index_p++;
        row_p.clear();
        getline(fin, line_p);
        stringstream s(line_p);
        while(getline(s, word_p, ',')){
            
            row_p.push_back(word_p);
        }
        p.ID = index;
        p.NAME = row_p[0];
        p.DEPARTMENT = row_p[1];
        p.DOCTOR = row_p[2];
        p.EMAIL = row_p[3];
        p.PHONE = row_p[4];
        p.EMERGENCY = stoi(row_p[5]);
        p.SLOT = stoi(row_p[6]);
        p.FEEDBACK = row_p[7];
        p.UID = stoi(row_p[8]);
        push_back_p(&*another_head, p);
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
    while(i < 0 || i > 7){
        cout<<"please choose an option: ";
        cin>> i;
        if(i > 0 && i < 6){
            cout<<"you have chosen option "<<i<<endl;
            return i;
        }
        cout<<"you have chosen an invalid option, please try again"<<endl;  
  }
  return i;
}


// APPOINTMENT
void make_appointment(node* head, node_p* another_head){
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
    set<string> doc_set;
    for(auto i: dep_doctors){
        doc_set.insert(i);
    }
    for(auto it: doc_set){
        cout << index << "." << it << endl;
        index++;
    }
    string choose;
    cout << "Do you want to book an appointment(y|n): ";
    cin >> choose;
    if(choose == "y"){
        pat_details p;
        cout << "Enter the name of the patient: " << endl;
        cin >> p.NAME;
        p.DEPARTMENT = choosen_dep;
        cout << "Enter the email address: " << endl;
        cin >> p.EMAIL;
        cout << "Enter your phone number: " << endl;
        cin >> p.PHONE;
        cout << "do you need any emergency treatment: " << endl;
        cin >> p.EMERGENCY;
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
            cout << "Your appointment under" << choosen_dep << " Department with Dr." << appoint_doc << " at " << given_slot << " booked." << endl;
            space();
            p.DOCTOR = appoint_doc;
            p.SLOT = col_slot + 1;
            push_back_p(&another_head, p);
            char out;
            cout << "Press any key && enter to exit: " << endl;
            cin >> out;
            exit_directory(head, another_head);          

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
        exit_directory(head, another_head);
    }    
}

// Give Feedback
void feedback_thingy(node* head, node_p* another_head){
    system(C);
    int choose;
    space();
    system("banner feedback");
    space();
    cout << "1. Give Feedback" << endl;
    cout << "2. View all Feedbacks" << endl;
    cin >> choose;
    stack<string> s;
    stack<string> s_names;
    string text = "";
    node_p* lanother_head1 = another_head;
    if(choose == 1){
        int verified = 0;
        int uid;
        cout << "Enter your uid(which was given at the time of appointment)" << endl;
        cin >> uid;
        node_p* lanother_head = another_head;
        while(lanother_head != NULL){
            pat_details p = lanother_head -> data;
            if(p.UID == uid){
                cout << "Welcome " <<  p.NAME << " to feedback section. please give your feedback under" << p.DEPARTMENT << " on Dr." << p.DOCTOR << endl;
                verified = 1;
            }
            lanother_head = lanother_head -> next;
        }
            if(verified == 1){
                space();
                string line;
                cout << "Please give your feedback: ";
                char ch; 
                while((ch=getchar())=='\n'){}
                if((ch >= 48 and ch <= 57) or (ch >= 65 and ch <= 90) or (ch >= 97 and ch <= 122) or (ch==32) or (ch==46)){
                    text += ch;
                }
                while((ch = getchar()) != '\n'){
                    if((ch >= 48 and ch <= 57) or (ch >= 65 and ch <= 90) or (ch >= 97 and ch <= 122) or (ch==32) or (ch==46)){
                    text += ch;
                    }
                }
                s.push(text);
                while(lanother_head != NULL){
                    pat_details p = lanother_head -> data;
                    if(p.UID == uid){
                        if(p.FEEDBACK == " none"){
                            p.FEEDBACK = text;
                        }
                    }
                    lanother_head = lanother_head -> next;
                }

                cout << "thank you for your valuable feedback, have a good day:) " << endl;
                string e;
                cout << "press any key and enter to exit: " << endl; 
                cin >> e;
                exit_directory(head, another_head);
            }
            else{
                cout << "UID invalid" << endl;
                exit_directory(head, another_head);
            }
    }
        if(choose == 2){
            system(C);
            system("banner all");
            system("banner feedbacks");
            node_p* lanother_head2 = another_head;
            while(lanother_head2 != NULL){
                pat_details p = lanother_head2 -> data;
                if(p.FEEDBACK != " none"){
                    cout << p.FEEDBACK << " given by" << p.NAME << endl;
                }
                lanother_head2 = lanother_head2 -> next;
            }
            string e;
            cout << "press any key and enter to exit: " << endl; 
            cin >> e;
            exit_directory(head, another_head);
        }

    
}
// main
int main(){
        node* head = NULL;
        node_p* another_head = NULL;
        int option_main = choose_main(&head, &another_head);
        option_to_function(option_main, head, another_head);
    return 0;
}
