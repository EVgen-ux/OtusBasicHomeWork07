#pragma once
#include <iostream>
#include <algorithm>    // подключаем sort

template <typename T>
class ListContainer {
   
    struct Node {
    T data;
    Node* next = NULL;
    Node* prev = NULL;
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
                new_node->prev = m_last;; // предыдущим элементом станет последний
                m_last->next = new_node;
                m_last = new_node; // обновляем указатель на последний              
            }
            m_size += 1; // обновляем размер
        }
    //метод, выводящий связанный список на экран
    void printContainer()
    {
        Node *current = head;
        std::cout << "Содержание контейнера спискового типа: ";
        while(current != NULL)
        {
            std::cout << current->data << " ";
            current = current->next;
        }

        std::cout << std::endl;
    }
      
    void printSizeContainer() {

        std::cout << "Размер контейнера: " << m_size << " элементов" << std::endl;

    }

    int sizeContainer() {

        return m_size;

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
 
            if ((*ptr == 1) and (head->next)) {                    
                Node *temp = head;	                       
                head = head->next;	                           
                head->prev = NULL;	                           
                delete temp;		                           
                m_size--;		                               
            } 
            else if ((*ptr == 1) and (head == m_last)) {          
                head->next = NULL;	                            
                head = NULL;
                delete head;		                           
                m_size = 0;		                               
            }

      
            if (*ptr==m_size){
                Node *temp = m_last;	                           
                m_last = m_last->prev;	                               
                m_last->next = NULL;	                                
                delete temp;	                                    
                m_size--;		                                    
            }

    
            Node *temp = head;                        
             for (int i=0; i<((*ptr)-1); i++) temp = temp->next;  //Идем к адресу удаляемого элемента
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;  
                m_size--;      
        }

    }

    void push_first(T const value) {
    Node* new_node = new Node;
    new_node->data = value;
    new_node->next = head;
    head->prev = new_node;
    head = new_node;
    m_size += 1; 
    }

    void push_to_position(int pos, const T value) {
        Node *temp = head;
        for (int i=1; i<pos; i++) temp = temp->next;
        Node* new_node = new Node;
        new_node->data = value;
        new_node->next = temp->next;
        temp->next = new_node;
        new_node->prev = temp;         
        m_size += 1;
    }

    void printElement(int n) {
        Node *temp = head;
        for (int i=1; i<n; i++) temp = temp->next;  
        std::cout << "Элемент = " << temp->data << std::endl;                                        
    }

    T element(int n) {
        Node *temp = head;
        for (int i=0; i<n; i++) temp = temp->next;  
        return temp->data;                                        
    }
};