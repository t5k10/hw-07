#include <iostream>

template<typename T>
struct Node {
    Node *next;
    T data;
};

template<typename T>
class LinkedList {
private:
    Node<T> *head;
    Node<T> *tail;
    size_t list_size; 
public:
    LinkedList() : head(nullptr), tail(nullptr), list_size(0) {}
  
    ~LinkedList() { clear(); }     

    LinkedList(const LinkedList<T> &other) : LinkedList() {
        Node<T> *tmp = other.head;
        size_t i = 1;
        while (i <= other.list_size) {
            push_back(tmp->data);    
            tmp = tmp->next;
            ++i;
        }
    } 

    LinkedList<T>& operator=(const LinkedList<T>& other) {
        if (this != &other) {
            Node<T> *tmp = other.head;
            size_t i = 1;
            while (i <= other.list_size) {
                push_back(tmp->data);    
                tmp = tmp->next;
                ++i;
            }
        }
        return *this;
    }

    LinkedList(LinkedList<T>&& other) {
        head = other.head;
        other.head = nullptr;
        tail = other.tail;
        other.tail = nullptr;
        list_size = other.list_size;
        other.list_size = 0;
    }
     
    LinkedList<T>& operator=(LinkedList<T>&& other) { 
        LinkedList<T> tmp(std::move(other));
        return *this = tmp;
    }

    void push_back(const T &value) {
        Node<T> *node = new Node<T>;
        node->data = value;
        node->next = nullptr;
        if (is_empty()) { head = tail = node; }
        else {
            tail->next = node;
            tail = node;
        }
        ++list_size;
    }
    
    void push_front(const T &value) {
        Node<T> *node = new Node<T>;
        node->data = value;
        node->next = nullptr;
        if (is_empty()) { head = tail = node;}
        else {
            node->next = head;
            head = node;
        }
        ++list_size;
    }

    T pop_front() {
        if (!is_empty()) {
            Node<T> *node = head;
            T data = head->data;
            head = head->next;
            delete node;
            --list_size;
            return data;
        }
        return 0;
    }
    
    T pop_back() {
        Node<T> *node = head;
        Node<T> *prev_node;
        size_t i = 1;
        while (i < list_size)  {
            prev_node = node;
            node = node->next;
            ++i;
        }
        T node_data = node->data;
        tail = prev_node;
        delete_node(i); 
        return node_data;
    } 
        
    void insert(const T &data, const size_t position) {
        if (position < 0) return;
        if (position == 1 || is_empty()) { push_front(data); return; }
        if (position == list_size + 1) { push_back(data); return; }
        size_t i = 1;
        Node<T> *prev_node = head;
        while (i < position - 1) {
            prev_node = prev_node->next;
            ++i;
        }
        Node<T> *new_node = new Node<T>;
        new_node->data = data;
        new_node->next = prev_node->next; 
        prev_node->next = new_node;
        ++list_size;
    }
    
    bool is_empty() { return head == nullptr; }
    
    size_t size() const { return list_size; }
    
    void erase(const size_t pos) { delete_node(pos); }  
    
    void clear() { while (head != nullptr) { delete_node(1); }}

    void delete_node(const size_t position) {
        if (is_empty() || position < 1 || position > list_size) return;
        if (position == 1) {
            Node<T> *current_node = head;
            head = head->next;
            delete current_node;
        }
        else {
            Node<T> *current_node = head;
            Node<T> *prev_node = nullptr;
            size_t i = 1;
            while (i < position) {
                prev_node = current_node;
                current_node = current_node->next;
                ++i;
            }
            if (position == list_size) tail = prev_node;       
            prev_node->next = current_node->next;
            delete current_node;
        }         
        --list_size;
    }
    
    void print() {
        if (is_empty()) return;
        Node<T> *tmp = head;
        while (tmp) {
            std::cout << tmp->data;
            if(tmp->next) std::cout  << ", ";
            tmp = tmp->next;
        }
        std::cout << '\n';
    }

    size_t operator[](const size_t i) {
        if (is_empty() || i == 0) return 0;
        Node<T> *node = head;
        size_t j = 1;
        while (j < i) {
            node = node->next;
            if (!node) return 0;
            ++j;
        }
        return node->data;
    }
    
    bool operator==(const LinkedList<T>& obj) {
        if (list_size != obj.size()) return false;
        Node<T> *tmp = head;
        Node<T> *tmp_obj = obj.head; 
        for (size_t i = 0; i < list_size; ++i) {
            if (tmp->data != tmp_obj->data) return false;
            tmp = tmp->next;
            tmp_obj = tmp_obj->next;
        }
        return true;
    }
};
