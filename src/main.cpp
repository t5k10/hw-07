#include <iostream>
#include "list.cpp"
#include "doubly_list.cpp"
#include "array.cpp"

int main() {

    std::cout << "ArrayContainer\n";
    ArrayContainer values;
    std::cout << "size =  " << values.size() << '\n';
    for (size_t i = 0; i < 10; ++i) values.push_back(i);
    std::cout << values << '\n';
    std::cout << "size =  " << values.size() << '\n';
    values.erase(3);
    values.erase(4);
    values.erase(6);
    std::cout << values << '\n';
    std::cout << "size =  " << values.size() << '\n';
    values.insert(10, 1);
    std::cout << values << '\n';
    std::cout << "size =  " << values.size() << '\n';
    values.insert(20, 5);
    std::cout << values << '\n';
    std::cout << "size =  " << values.size() << '\n';
    values.push_back(30);
    std::cout << values << '\n';
    std::cout << "size =  " << values.size() << '\n';
    std::cout << '\n';
    
    std::cout << "Copy:" << '\n';
    ArrayContainer values2(values);
    std::cout << values2 << '\n';
    std::cout << "size =  ";
    std::cout << values2.size() << '\n';
    std::cout << '\n';



    std::cout << "LinkedList container\n";
    LinkedList<int> list2;
    std::cout << "size =  " <<  list2.size() << '\n';
    for (size_t i = 0; i < 10; ++i) list2.push_back(i);    
    list2.print();
    std::cout << "size =  " <<  list2.size() << '\n';
    list2.erase(3); 
    list2.print();
    std::cout << "size =  " << list2.size() << '\n';
    list2.push_front(10);
    list2.print(); 
    std::cout << "size =  " << list2.size() << '\n';
    list2.insert(20, 5);
    list2.print(); 
    std::cout << "size =  " << list2.size() << '\n';
    list2.push_back(30); 
    list2.print(); 
    std::cout << "size =  " << list2.size() << '\n' << '\n';

    std::cout << "Copy:" << '\n';
    LinkedList<int> l1 = list2;
    l1.print(); 
    LinkedList<int> l2;
    l2 = l1;
    l2.print(); 

    std::cout << "Move:" << '\n';
    LinkedList<int> list3 = std::move(list2);
    list3.print();

    std::cout << "\nDoublyLinkedList container\n";
    DoubleListContainer<int> d_list; 
    std::cout << "size =  " <<  d_list.size() << '\n';
    for (size_t i = 0; i < 10; ++i) d_list.push_back(i);    
    d_list.print();
    std::cout << "size =  " <<  d_list.size() << '\n';
    d_list.erase(3); 
    d_list.erase(4); 
    d_list.erase(5); 
    d_list.print();
    std::cout << "size =  " << d_list.size() << '\n';
    d_list.push_front(10);
    d_list.print();
    std::cout << "size =  " << d_list.size() << '\n';
    d_list.insert(20, 5);
    d_list.print();
    std::cout << "size =  " << d_list.size() << '\n';
    d_list.push_back(30); 
    d_list.print();
    std::cout << "size =  " << d_list.size() << '\n' << '\n';

    std::cout << "Copy:" << '\n';
    DoubleListContainer<int> d_list2 = d_list; 
    d_list2.print(); 
    
    DoubleListContainer<int> d_list3;
    d_list3 = d_list;
    d_list3.print();
    
    std::cout << "Move:" << '\n';
    DoubleListContainer<int> d_list4 = std::move(d_list2);
    d_list4.print();

}
