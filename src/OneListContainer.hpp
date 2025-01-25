#pragma once
#include <algorithm>  
#include <iostream>

template <typename T>
class OneListContainer {
   
    struct Node {
    T data;
    Node* next = NULL;
    };

    Node *head = NULL; //начало связанного списка
    int m_size = 0;
    Node *m_last = NULL;

public:
    void push_back(T const value) {
            Node* new_node = new Node; // создание нового узла
            new_node->data = value; // сохраняем пользовательские данные
            new_node->next = nullptr; // следующего элемента пока нет

            if(head == NULL) {    //если создаем первый узел
                head = new_node;
                m_last = new_node;
            }
            else {
                m_last->next = new_node;
                m_last = new_node; // обновляем указатель на последний              
            }
            m_size += 1; // обновляем размер
        }
   // метод, выводящий связанный список на экран
    void printContainer()
    {
        Node *current = head;
        std::cout << "Содержание контейнера односвязанного списка: ";
        while(current != NULL)
        {
            std::cout << current->data << " ";
            current = current->next;
        }

        std::cout << std::endl;
        delete current;
    }
      
    void printSizeContainer() {

        std::cout << "Размер контейнера: " << m_size << " элементов" << std::endl;

    }   

    void eraseElement(int* begin, int* end) {
        int d_size = 0;
        
        for (int *ptr {begin}; ptr != end; ptr++) {         
             d_size += 1;
        }
        int sw_size = d_size;
        while(sw_size--) {
            bool swapped = false;
    
            for(int i = 0; i < sw_size; i++) {
                if(*(begin+i) < *(begin+i+1)) {
                    std::swap(*(begin+i), *(begin+i+1));
                    swapped = true;
                }
            }
           
            if(swapped == false)
                break;
        }   
 
        for (int *ptr {begin}; ptr != end; ptr++) {
 
            if ((*ptr == 1) and (head->next)) {                     //Если удаляем первый, но есть и другие
                Node *temp = head;	                        
                head = head->next;	                            
                delete temp;		                            
                m_size--;		                                //Уменьшаем счетчик
            } 
            else if ((*ptr == 1) and (head == m_last)) {            //Если удаляем первый, но в списке только 1 элемент
                head->next = NULL;	                           
                head = NULL;
                delete head;		                            //Удаляем указатель на начало
                m_size = 0;		                                //Обозначаем, что в списке ноль элементов
            }


            else if (*ptr==m_size){             //удаляемый элемент последний элемент списка
                Node *temp = head;
                for (int i=1; i<((*ptr)-1); i++) temp = temp->next;  //Идем к адресу удаляемого элемента	                            
                m_last = temp;
                delete temp->next;	 
                m_last->next = NULL;	                                                                                 
                m_size--;		                                    
            }

            else {
            Node *temp = head;    //Если  удаляемый элемент лежит где-то в середине списка
            for (int i=1; i<((*ptr)-1); i++) temp = temp->next;  //Идем к адресу удаляемого элемента
                temp->next = temp->next->next;
                m_size--;
            }      

        }

    }

    void push_first(T const value) {   // Вставить элемент в начало списка
    Node* new_node = new Node; 
    new_node->data = value;
    new_node->next = head;
    head = new_node;
    m_size += 1; // обновляем размер
    }

    void push_to_position(int pos, const T value) {  // Вставить элемент в указанную позицию
        Node *temp = head;
        for (int i=1; i<pos; i++) temp = temp->next;  //Идем к адресу 
        Node* new_node = new Node;
        new_node->data = value;
        new_node->next = temp->next;
        temp->next = new_node;    
        m_size += 1;
    }

    void print_element(int n) {   //вывод элемента
        Node *temp = head;
        for (int i=1; i<n; i++) temp = temp->next;  //Идем к адресу 
        std::cout << "Элемент = " << temp->data << std::endl;                                        
    }

    int sizeContainer() {
        return m_size;
    }

    int element(int n) {
        Node *temp = head;
        for (int i=0; i<n; i++) temp = temp->next;  
        return temp->data;
    }
};