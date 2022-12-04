#include <iostream>

class ArrayContainer {
  public:
      ArrayContainer() {
          arr_size = quantity_elem = 0;
          array = new int[arr_size];
      }

      ~ArrayContainer() { delete[] array; }

      ArrayContainer(const ArrayContainer &other) : ArrayContainer() {
          array = new int[other.arr_size];
          quantity_elem = other.quantity_elem;
          for (size_t i = 0; i < other.arr_size; ++i) {
              array[i] = other.array[i];
          }
      }

      void push_back(int value) {
          if (quantity_elem == arr_size) increase_size_array();
          array[quantity_elem] = value;
          ++quantity_elem;    
      }
       
      void push_front(int value) {
          if (quantity_elem == arr_size) {
              if (arr_size < 2) { arr_size += 1; }
              else { arr_size *= 1.6; }
              int *new_array = new int[arr_size];
              new_array[0] = value;
              for (size_t i = 0; i < quantity_elem; ++i) { new_array[i + 1] = array[i]; }
              delete[] array;
              array = new_array;
          }
          else {
              int *new_array = new int[arr_size];
              new_array[0] = value;
              for (size_t i = 0; i < quantity_elem; ++i) { new_array[i + 1] = array[i]; }
              delete[] array;
              array = new_array;
          }
          ++quantity_elem; 
      }

      int pop_back() {
          int val = array[quantity_elem];
          erase(quantity_elem);
          return val;
      }
     
      void insert(int value, size_t index) {
          if (index < 1 || index > 2147483647) return; 
          if (index == 1) push_front(value);
          else {
              if (quantity_elem == arr_size) {
                  if (arr_size < 2) { arr_size += 1; }
                  else { arr_size *= 1.6; }
                  int *new_array = new int[arr_size];
                  for (size_t i = 0; i < index - 1; ++i ) new_array[i] = array[i];
                  new_array[index - 1] = value;
                  for (size_t i = index - 1; i < quantity_elem; ++i) new_array[i + 1] = array[i];
                  delete[] array;
                  array = new_array;
              }
              else {
                  int *new_array = new int[arr_size];
                  for (size_t i = 0; i < index - 1; ++i ) new_array[i] = array[i];
                  new_array[index - 1] = value;
                  for (size_t i = index - 1; i < quantity_elem; ++i) new_array[i + 1] = array[i];
                  delete[] array;
                  array = new_array;
              }
              ++quantity_elem;
          }

      }

      int get_value(size_t index) {
          if (index < 1 || index > 2147483647) return 0; 
          return array[index - 1]; 
      }
      
      size_t size() const { return quantity_elem; }
      
      size_t capacity() const { return arr_size; }

      void erase(size_t index) {
          if (index < 1 || index > arr_size) return;
          size_t new_quantity = quantity_elem - 1;
          int *new_array = new int[new_quantity];
          for (size_t i = 0, j = 0; i < quantity_elem; ++i) {
              if (i != index - 1) {
                  new_array[j] = array[i];
                  ++j;
              }
          }
          quantity_elem = new_quantity;
          delete[] array;
          array = new_array;
      }
      
      int& operator[](int index) { return array[index]; }  

      bool operator==(const ArrayContainer& obj) {
          if (quantity_elem != obj.size()) return false;
          for (size_t i = 0; i < quantity_elem; ++i) { 
              if (array[i] != obj.array[i]) return false;
          }
          return true;
      }

      friend std::ostream &operator<<(std::ostream &os, const ArrayContainer &item) {
          for (size_t i = 0; i < item.quantity_elem; ++i) {
              os << item.array[i]; 
              if (i < item.quantity_elem - 1) os << ", " ;        
          }
          return os;
      } 

  private:
      int *array;                   
      size_t arr_size;              
      size_t quantity_elem;            
      void increase_size_array() {
          if (arr_size < 2) { arr_size += 1; }
          arr_size *= 1.6;
          int *new_array = new int[arr_size];
          for (size_t i = 0; i < quantity_elem; ++i) { new_array[i] = array[i]; }
          delete[] array;
          array = new_array;
      }
};
