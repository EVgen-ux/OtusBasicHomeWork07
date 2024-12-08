#include <iostream>
#include "MassContainer.hpp"
#include "TwoListContainer.hpp"
#include "OneListContainer.hpp"

int main(){

    int size = 10; //размер контейнера/массива

    MassContainer<int> myMass; // Создаем последовательный контейнер из 10 элементов
      for (int i = 0; i < size; i++) {
        myMass.push_back(i);
      }   
  
    myMass.printContainer(); // вывод содежимого контейнера в консоль
    myMass.printSizeContainer(); //вывод размера контейнера в консоль
 
    int del[] {7, 5, 3}; // номера элементов в массиве, которые необходимо удалить (отсчет с 1, 0 вводить нельзя)
    int *begin {std::begin(del)};      
    int *end {std::end(del)}; 
    myMass.eraseElement(begin, end); //удаление третьего (по счёту), пятого и седьмого элементов 0, 1, 3, 5, 7, 8, 9
    myMass.printContainer(); //вывод размера контейнера в консоль
   
    myMass.push_first(10);  // передаем значение  элемента, которое необходимо вставить в начало
    myMass.printContainer(); //вывод размера контейнера в консоль

    myMass.push_to_position(5, 20); //вставка элемента в указанную позицию, первая цифра позиция (отсчет с 1) вторая значение
    myMass.printContainer(); //вывод размера контейнера в консоль

    myMass.push_back(30); // передаем значение  элемента, которое необходимо вставить в конец
    myMass.printContainer();

    std::cout << myMass.element(5) << std::endl; // вывод элемента по счету с 1

    // ОДНОСВЯЗАННЫЙ СПИСОК//
    OneListContainer<int> myListOne;
      for (int i = 0; i < size; i++) {
      myListOne.push_back(i);
    }   
    myListOne.printContainer();

    myListOne.eraseElement(begin,end);
    myListOne.printContainer();

    myListOne.push_first(10);
    myListOne.printContainer();

    myListOne.push_to_position(4, 20);
    myListOne.printContainer();

    myListOne.push_back(30);
    myListOne.printContainer();

    myListOne.element(5);
  


    ListContainer<int> myList;

    for (int i = 0; i < size; i++) {
      myList.push_back(i);
    }   
    myList.printContainer();
    myList.printSizeContainer();

    myList.eraseElement(begin, end); //удаление третьего (по счёту), пятого и седьмого элементов 0, 1, 3, 5, 7, 8, 9
    myList.printContainer();

    myList.push_first(10);  // передаем значение  элемента
    myList.printContainer();


    myList.push_to_position(4, 20);
    myList.printContainer();


    myList.push_back(30);
    myList.printContainer();

    myList.element(5);



}
