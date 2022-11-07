#ifndef LIST
#define LIST

#include <iostream>

template <typename T>

class my_list{
    protected:
    int node_count;
    struct node{
        T data;
        node* link;
    }*head, *tail;
    public:
    my_list(){
        node_count = 0;
        head = nullptr;
        tail = nullptr;
    }
    ~my_list(){
        node* temp;
        while(head != nullptr){
            temp = head;
            head = head -> link;
            delete temp;
        }
        node_count = 0;
    }

    friend std::ostream& operator << (std::ostream& dout, my_list<T> &list){
        if(list.node_count == 0) {dout << "[]"; return dout;}
        node* temp = list.head;
        dout << "[" << temp -> data;
        for(int i = 1; i < list.node_count; i++){
            temp = temp -> link;
            dout << ", " << temp -> data;
        }
        dout << "]";
        return dout;
    }

    T& operator[] (int index){
        if(index < 0) exit(EXIT_FAILURE);
        node* temp = head;
        for(int i = 0; i<index; i++){
            temp = temp -> link;
        }
        return  temp -> data;
    }

    void insert(int index, int value){
        if((index > node_count) or (index < 0)) exit(EXIT_FAILURE);
        node* prev = head;
        node* next = nullptr;
        if(index != 0){
            for(int i = 0; i < index - 1; i++){
                prev = prev -> link;
            }
            next = prev -> link;
            node* temp = new node;
            temp -> data = value;
            temp -> link = next;
            prev -> link = temp;
        } else{
            node* temp = new node;
            temp -> link = head;
            temp -> data = value;
            head = temp;
            
        }
        node_count += 1;
        return;
    }

    void  append(int value){
        node* temp = new node;
        temp -> data = value;
        temp -> link = nullptr;
        if(head != nullptr){
            tail -> link = temp;
            tail = temp;
        } else {
            head = temp;
            tail = temp;
        }
        node_count += 1;
        return;
    }
    void append_array(T *arr, int size){
        if(size <  1) exit(EXIT_FAILURE);
        for(int i = 0; i < size; ++i){
            append(arr[i]);
        }
    }

    void insert_array(int index, T *arr, int size){
        if(size <  1) exit(EXIT_FAILURE);
        for(int i = 0; i < size; ++i){
            insert(index, arr[i]);
            index += 1;
        }
    }

    const int node_counter() const{
        return node_count;
    }
    void delete_node(int index){
        if(index == 0){
            node* temp = head;
            head = head -> link;
            delete temp;
        }
        if((index > node_count) or (index < 0)) exit(EXIT_FAILURE);
        else if(index == node_count -1){
            node* temp = head;
            for (int i = 0; i <(index - 1 ); i++){
                temp = temp -> link;
            }
            tail = temp;
            temp = temp -> link;
            tail -> link = nullptr;
            delete temp;
        } else{
            node* prev = head;
            node* next;
            for (int i = 0; i < (index - 1); i++){
                prev = prev -> link;
            }
            next = prev -> link;
            node* temp = next;
            next = next -> link;
            prev -> link = next; 
            delete temp;          

        }
        node_count -= 1;
        return;
    }
    node* reverse(){
        if(node_count <= 1) return head;
        node* prev = nullptr;
        node* curr = head;
        node* next = head -> link;
        while( next != nullptr ){
            curr -> link = prev;
            prev = curr;
            curr = next;
            next = next -> link;
        }
        curr -> link = prev;
        tail = head;
        head = curr;
        return head;
    }
    void clear(){
			node *temp;
			while(head != nullptr){
				temp = head;
				head = head->link;
				delete temp;
			}
			node_count = 0;
			return;
		}
};

#endif

/* 
 function name: Time complexity, Space complexty
 operator<< O(n) O(1)
 operator[] O(n) O(1)
 append O(n) O(1)
 insert O(n) O(1)
 delete_node O(n) O(1)
 append_array O(n) O(1)
 insert_array O(n) O(1)
 node_counter O(1) O(1)
 reverse O(n) O(1)
 clear O(n) O(1)
 Space complety is O(1) becaues no use of any ADT was used to store values.
*/