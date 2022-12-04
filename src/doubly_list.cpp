#include <iostream>

template<typename T>
struct Node2 {
    Node2 *next;
    Node2 *prev;
    T data;   
};

template<typename T>
class DoubleListContainer {
private:
    Node2<T> *head;
    Node2<T> *tail;
    size_t list_size;
public:
    DoubleListContainer() : head(nullptr), tail(nullptr), list_size(0) {}
      
    ~DoubleListContainer() { clear(); }

    DoubleListContainer(const DoubleListContainer<T> &other) : DoubleListContainer() {
        Node2<T> *tmp = other.head;
        size_t i = 1;
        while (i <= other.list_size) {
            push_back(tmp->data);
            tmp = tmp->next;
            ++i;
        }
    }
    
    DoubleListContainer<T>& operator=(const DoubleListContainer<T>& other) {
        if (this != &other) {
            Node2<T> *tmp = other.head;
            size_t i = 1;
            while (i <= other.list_size) {
                push_back(tmp->data);
                tmp = tmp->next;
                ++i;
            }
        }
        return *this;
    }

    DoubleListContainer(DoubleListContainer<T>&& other) {
        head = other.head;
        other.head = nullptr;
        tail = other.tail;
        other.tail = nullptr;
        list_size = other.list_size;
        other.list_size = 0;
    }
         
    DoubleListContainer<T>& operator=(DoubleListContainer<T>&& other) { 
        DoubleListContainer<T> tmp(std::move(other));
        return *this = tmp;
    }

    void push_back(const T &value) {
        Node2<T> *node = new Node2<T>;
        node->data = value;
        node->next = nullptr;
        node->prev = nullptr;
        if (is_empty()) {
            head = tail = node;
        }
        else {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
        ++list_size;
    }

    void push_front(const T &value) {
        Node2<T> *node = new Node2<T>;
        node->data = value;
        node->next = nullptr;
        node->prev = nullptr;
        if (is_empty()) {
            head = tail = node;
        }
        else {
            node->next = head;
            head->prev = node;
            head = node;
        }
        ++list_size;
    }

    T pop_back() {
        if (!is_empty()) {
            Node2<T> *node = tail;
            if (head == tail) head = nullptr; 
            T data = node->data;
            tail->next = nullptr;
            tail = tail->prev;
            delete node;
            --list_size;
            return data;
        }
        return 0;
    }

    T pop_front() {
        if (!is_empty()) {
            Node2<T> *node = head;
            if (head == tail) tail = nullptr;
            T data = node->data;
            head->prev = nullptr;
            head = head->next;
            delete node;
            --list_size;
            return data;
        }
        return 0;
    }

    void insert(const T &data, const size_t position) {
        if (position < 0) return;
        if (position == 1 || is_empty()) {push_front(data); return; }
        if (position == list_size + 1) {push_back(data); return; }
        size_t i = 1;
        Node2<T> *node = head;
        while (i < position) {
            node = node->next;
            ++i;
        }
        Node2<T> *prev_ins = node->prev;
        Node2<T> *new_node = new Node2<T>;
        new_node->data = data;
        if (prev_ins != nullptr && list_size != 1) prev_ins->next = new_node;
        new_node->next = node;
        new_node->prev = prev_ins;
        node->prev = new_node;
        ++list_size;
      }

      void erase(const size_t pos) { delete_node(pos); }  
       
      T operator[](const size_t i) {
          if (is_empty() || i == 0) return 0;
          Node2<T> *node = head;
          size_t j = 1;
          while (j < i) {
              node = node->next;
              if (!node) return 0;
              ++j;
          }
          return node->data;
      }

      bool operator==(const DoubleListContainer<T>& obj) {
          if (list_size != obj.list_size) return false;
          Node2<T> *tmp = head;
          Node2<T> *tmp_obj = obj.head;
          for (size_t i = 0; i < list_size; ++i) {
              if (tmp->data != tmp_obj->data) return false;
              tmp = tmp->next;
              tmp_obj = tmp_obj->next;
          }
          return true;
      }


      void print() {
          if (is_empty()) return;
          Node2<T> *tmp = head;
          while (tmp) {
              std::cout << tmp->data;
              if(tmp->next) std::cout  << ", ";
              tmp = tmp->next;
          }
          std::cout << '\n';
      }
      
      bool is_empty() { return head == nullptr; }

      size_t size() { return list_size; }
       
      void clear() { while (head != nullptr)  delete_node(1); }

      void delete_node(const size_t position) {     
          if (is_empty() || position < 1 || position > list_size) return;
          if (position == 1) {
              Node2<T> *current_node = head;
              if (head == tail) tail = nullptr;
              head = head->next; 
              delete current_node;
          }
          else if (position == list_size) {
              Node2<T> *current_node = tail;
              if (tail == head) head = nullptr;
              tail->next = nullptr;
              tail = tail->prev;
              delete current_node;
          }
          else {
              Node2<T> *current_node = head;
              size_t i = 1;
              while (i < position) {
                  current_node = current_node->next;
                  ++i;
              }   
              Node2<T> *prev_del = current_node->prev;
              Node2<T> *after_del = current_node->next;
              if ((prev_del != nullptr)) prev_del->next = after_del;    
              if ((after_del != nullptr)) after_del->prev = prev_del; 
              delete current_node;
          }          
          --list_size;
      }
};
