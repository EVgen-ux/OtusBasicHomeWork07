#pragma once
#include <algorithm>
#include <iostream>

template <typename T>
class MassContainer {
    T *m_data = NULL;
    int m_size = 0;

public:

    ~MassContainer() {}

    void push_back(const T next) {
        T* new_region = new T[m_size + 1]; // новая область памяти
        for (int i = 0; i < m_size; ++i) 
            new_region[i] = m_data[i]; // копирование элементов
        new_region[m_size] = next; // добавление нового элемента
        delete [] m_data; // удаление старой области
        m_data = new_region; // сохранение новой в мембер
        m_size += 1; // обновление информации о размере
    }

    void printContainer() {
        std::cout << "Содержание последовательного контейнера: ";
        for (int i = 0; i < m_size; i++) {
        std::cout << *(m_data+ i)  << " ";
        }
        std::cout << std::endl;
    }

    int sizeContainer() {

       return m_size;

    } 

    void printSizeContainer() {

        std::cout << "Размер контейнера: " << m_size << " элементов" << std::endl;

    }   

    void eraseElement(int* begin, int* end) {
        int d_size = 0;
        int ii = 0;
        int j = 0;
        
        for (int *ptr {begin}; ptr != end; ptr++) {         
             d_size += 1;
         }

        std::sort(begin, begin+d_size);
 
        T* new_region = new T[m_size-d_size];

        for (int *ptr {begin}; ptr != end; ptr++) {
            for (int i = ii; i < m_size; i++) {
                if (*ptr != i+1) {
                    new_region[j] = m_data[i]; // копирование элементов
                    j++;
                }
                else { ii = i+1; break;}
            }
          
        }
        for (int i = ii; i < m_size; i++) {
                new_region[j] = m_data[i]; // копирование элементов
                j++;
            }

        m_size = m_size - d_size;
        delete [] m_data; // удаление старой области
        m_data = new_region; // сохранение новой в мембер
  
    }

    void push_first(const T first) {
        T* new_region = new T[m_size+1];
        *(new_region) = first;
        for (int i = 0; i < m_size+1; ++i) {         
            new_region[i+1] = m_data[i]; // копирование элементов          
        }
        delete [] m_data; // удаление старой области
        m_data = new_region; // сохранение новой в мембер
        m_size += 1; // обновление информации о размере
    }

    void push_to_position(int pos, const T value) {
        int j = 0;
        pos -= 1;
        T* new_region = new T[m_size+1];
        for (int i = 0; i < m_size+1; ++i) {         
            if (i == pos) {*(new_region+pos) = value;}
            else {new_region[i] = m_data[j]; j++;} // копирование элементов          
        }
        delete [] m_data; // удаление старой области
        m_data = new_region; // сохранение новой в мембер
        m_size += 1; // обновление информации о размере
    }

    T element(int n) {
   //     std::cout << "Элемент = " << *(m_data+n-1) << std::endl;
        return *(m_data+n);                         
    }

};

