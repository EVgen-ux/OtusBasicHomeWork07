#include "OneListContainer.hpp"

#include <gtest/gtest.h>

//создание контейнера
TEST(OneList, Creat) {
    // Arrange
    OneListContainer<int> list;

    // Act (empty for this test)

    // Assert
    ASSERT_EQ(list.sizeContainer(), 0);
}

class OneList_f : public ::testing::Test { // инициализация контейнера
protected:
    void SetUp() override {

        for (auto i = 0; i < count; ++i) {
            list.push_back(i);
        }
    }

    void TearDown() override {}

    OneListContainer<int> list;
    const int count = 10;
};

TEST(OneList, Empty) {
    OneListContainer<int> list;
    ASSERT_EQ(list.sizeContainer(), 0);
}

TEST_F(OneList_f, PushBack) {
 
    int 
    sample[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    ASSERT_EQ(list.sizeContainer(), count);
    for (auto i = 0; i < count; ++i) {
        ASSERT_EQ(list.element(i), sample[i]);
    }
}

TEST_F(OneList_f, PushFirst) {
 
int sample[] = {10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    list.push_first(10);

    ASSERT_EQ(list.sizeContainer(), count + 1);
    for (int i = 0; i < list.sizeContainer(); ++i) {
        ASSERT_EQ(list.element(i), sample[i]);
    }
}

TEST_F(OneList_f, InsertMid) {
    int sample[] = {0, 1, 2, 3, 4, 30, 5, 6, 7, 8, 9};

    list.push_to_position(5, 30);

    ASSERT_EQ(list.sizeContainer(), count + 1);
    for (auto i = 0; i < list.sizeContainer(); ++i) {
        ASSERT_EQ(list.element(i), sample[i]);
    }
}


TEST_F(OneList_f, EraseBack) {
    int sample[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    int del[] {10}; // номера элементов в массиве, которые необходимо удалить (отсчет с 1, 0 вводить нельзя)
    int *begin {std::begin(del)};      
    int *end {std::end(del)};
    list.eraseElement(begin, end);

    ASSERT_EQ(list.sizeContainer(), count - 1);
    for (auto i = 0; i < list.sizeContainer(); ++i) {
        ASSERT_EQ(list.element(i), sample[i]);
    }
}

// TEST_F(OneList_f, EraseFront) {
//     int sample[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//     int del[] {1}; // номера элементов в массиве, которые необходимо удалить (отсчет с 1, 0 вводить нельзя)
//     int *begin {std::begin(del)};      
//     int *end {std::end(del)};
//     list.eraseElement(begin, end);

//     //ASSERT_EQ(list.sizeContainer(), count - 1);
//     for (auto i = 0; i < list.sizeContainer(); ++i) {
//         ASSERT_EQ(list.element(i), sample[i]);
//     }
// }

TEST_F(OneList_f, EraseMidle) {
    int sample[] = {0, 1, 2, 3, 5, 6, 7, 8, 9};
    int del[] {5}; // номера элементов в массиве, которые необходимо удалить (отсчет с 1, 0 вводить нельзя)
    int *begin {std::begin(del)};      
    int *end {std::end(del)};
    list.eraseElement(begin, end);

    ASSERT_EQ(list.sizeContainer(), count - 1);
    for (auto i = 0; i < list.sizeContainer(); ++i) {
        ASSERT_EQ(list.element(i), sample[i]);
    }
}


