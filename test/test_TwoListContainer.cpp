#include "TwoListContainer.hpp"

#include <gtest/gtest.h>

// создание контейнера
TEST(TwoList, Creat) {
    // Arrange
    ListContainer<int> list;
    
    // Act (empty for this test)

    // Assert
    ASSERT_EQ(list.sizeContainer(), 0);
}

class TwoList_f : public ::testing::Test { // инициализация контейнера
protected:
    void SetUp() override {

        for (auto i = 0; i < count; ++i) {
            list.push_back(i);
        }
    }

    void TearDown() override {}

    ListContainer<int> list;
    const int count = 10;
};

TEST(TwoList, Empty) {
    ListContainer<int> list;
    ASSERT_EQ(list.sizeContainer(), 0);
}

TEST_F(TwoList_f , PushBack) {
 
    int sample[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    ASSERT_EQ(list.sizeContainer(), count);
    for (auto i = 0; i < count; ++i) {
        ASSERT_EQ(list.element(i), sample[i]);
    }
}

TEST_F(TwoList_f , PushFirst) {
 
int sample[] = {10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    list.push_first(10);

    ASSERT_EQ(list.sizeContainer(), count + 1);
    for (int i = 0; i < list.sizeContainer(); ++i) {
        ASSERT_EQ(list.element(i), sample[i]);
    }
}

TEST_F(TwoList_f , InsertMid) {
    int sample[] = {0, 1, 2, 3, 4, 30, 5, 6, 7, 8, 9};

    list.push_to_position(5, 30);

    ASSERT_EQ(list.sizeContainer(), count + 1);
    for (auto i = 0; i < list.sizeContainer(); ++i) {
        ASSERT_EQ(list.element(i), sample[i]);
    }
}


TEST_F(TwoList_f , EraseBack) {
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

TEST_F(TwoList_f , EraseFront) {
    int sample[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int del[] {1}; // номера элементов в массиве, которые необходимо удалить (отсчет с 1, 0 вводить нельзя)
    int *begin {std::begin(del)};      
    int *end {std::end(del)};
    list.eraseElement(begin, end);

    ASSERT_EQ(list.sizeContainer(), count - 1);
    for (auto i = 0; i < list.sizeContainer(); ++i) {
        ASSERT_EQ(list.element(i), sample[i]);
    }
}

TEST_F(TwoList_f, EraseMidle) {
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


