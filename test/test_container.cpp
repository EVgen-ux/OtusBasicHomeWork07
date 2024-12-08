#include "MassContainer.hpp"

#include <gtest/gtest.h>

// создание контейнера
TEST(Mass, Creat) {
    // Arrange
    MassContainer<int> mass;

    // Act (empty for this test)

    // Assert
    ASSERT_EQ(mass.sizeContainer(), 0);
}

class Vector_f : public ::testing::Test { // инициализация контейнера
protected:
    void SetUp() {

        for (auto i = 0; i < count; ++i) {
            vector.push_back(i);
        }
    }

    void TearDown() override {}

    MassContainer<int> vector;
    const int count = 10;
};


TEST_F(Vector_f, PushBack) {
 
    int sample[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

     ASSERT_EQ(vector.sizeContainer(), count);
    for (auto i = 0; i < count; ++i) {
        ASSERT_EQ(vector.element(i), sample[i]);
    }
}

TEST_F(Vector_f, PushFirst) {
 
int sample[] = {10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    vector.push_first(10);

    ASSERT_EQ(vector.sizeContainer(), count + 1);
    for (int i = 0; i < vector.sizeContainer(); ++i) {
        ASSERT_EQ(vector.element(i), sample[i]);
    }
}

TEST_F(Vector_f, InsertMid) {
    int sample[] = {0, 1, 2, 3, 4, 30, 5, 6, 7, 8, 9};

    vector.push_to_position(6, 30);

    ASSERT_EQ(vector.sizeContainer(), count + 1);
    for (auto i = 0; i < vector.sizeContainer(); ++i) {
        ASSERT_EQ(vector.element(i), sample[i]);
    }
}


TEST_F(Vector_f, EraseBack) {
    int sample[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    int del[] {10}; // номера элементов в массиве, которые необходимо удалить (отсчет с 1, 0 вводить нельзя)
    int *begin {std::begin(del)};      
    int *end {std::end(del)};
    vector.eraseElement(begin, end);

    ASSERT_EQ(vector.sizeContainer(), count - 1);
    for (auto i = 0; i < vector.sizeContainer(); ++i) {
        ASSERT_EQ(vector.element(i), sample[i]);
    }
}

TEST_F(Vector_f, EraseFront) {
    int sample[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int del[] {1}; // номера элементов в массиве, которые необходимо удалить (отсчет с 1, 0 вводить нельзя)
    int *begin {std::begin(del)};      
    int *end {std::end(del)};
    vector.eraseElement(begin, end);

    ASSERT_EQ(vector.sizeContainer(), count - 1);
    for (auto i = 0; i < vector.sizeContainer(); ++i) {
        ASSERT_EQ(vector.element(i), sample[i]);
    }
}

TEST_F(Vector_f, EraseMidle) {
    int sample[] = {0, 1, 2, 3, 5, 6, 7, 8, 9};
    int del[] {5}; // номера элементов в массиве, которые необходимо удалить (отсчет с 1, 0 вводить нельзя)
    int *begin {std::begin(del)};      
    int *end {std::end(del)};
    vector.eraseElement(begin, end);

    ASSERT_EQ(vector.sizeContainer(), count - 1);
    for (auto i = 0; i < vector.sizeContainer(); ++i) {
        ASSERT_EQ(vector.element(i), sample[i]);
    }
}






