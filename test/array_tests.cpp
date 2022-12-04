#include "gtest/gtest.h"
#include "array.cpp"

class ArrayFixture : public testing::Test {    
public:
    const size_t count = 10000;
    ArrayContainer values;

    static void SetUpTestSuite() {}

    static void TearDownTestSuite() {}

    void SetUp() override { for (size_t i = 0; i < count; ++i) values.push_back(i);}

    void TearDown() override {}
};

TEST(Array, Empty) {
    //Arrange 
    ArrayContainer values;
    const size_t count = 0;
    //Act
    
    //Assert
    ASSERT_EQ(values.size(), count);
}

TEST(Array, PushFront) {
    const size_t count = 10000;
    ArrayContainer values;
    
    for (size_t i = 0; i < count; ++i) values.push_front(i);

    ASSERT_EQ(values.size(), count);
    ASSERT_EQ(values.get_value(count), 0);
}

TEST_F(ArrayFixture, PushBack) {
    ASSERT_EQ(values.size(), count);
    ASSERT_EQ(values.get_value(1), 0);
}

TEST_F(ArrayFixture, InsertInvalidIndex) {
    size_t invalid_index1 = -1;
    size_t invalid_index2 = 0;
    
    values.insert(33, invalid_index1);
    values.insert(22, invalid_index2);

    ASSERT_EQ(values.size(), count);
}

TEST_F(ArrayFixture, Insert) {
    const size_t position1 = 1;
    const size_t position2 = 5000;
    const size_t position3 = 10000;
    const int number = 999999999;
    const size_t new_size = 10003;
    
    values.insert(number, position1);
    values.insert(number, position2);
    values.insert(number, position3);

    ASSERT_EQ(values.get_value(position1), number);
    ASSERT_EQ(values.get_value(position2), number);
    ASSERT_EQ(values.get_value(position3), number);
    ASSERT_EQ(values.size(), new_size);
}

TEST_F(ArrayFixture, Erase) {
    const size_t count_after = count - 3;
    const size_t delete_position1 = 1;
    const size_t delete_position2 = 4000;
    const size_t delete_position3 = 9000;
    
    values.erase(delete_position1);
    values.erase(delete_position2);
    values.erase(delete_position3);

    ASSERT_EQ(values.size(), count_after);
}

TEST_F(ArrayFixture, EraseInvalidIndex) {
    const size_t delete_position1 = -1;
    const size_t delete_position2 = 0;
    const size_t delete_position3 = 61412153466;

    values.erase(delete_position1);
    values.erase(delete_position2);
    values.erase(delete_position3);

    ASSERT_EQ(values.size(), count);
}

TEST_F(ArrayFixture, QuantityElements) {
    ASSERT_GT(values.capacity(), count);
    ASSERT_EQ(values.size(), count);
}

TEST_F(ArrayFixture, PopBack) {
    const size_t count_after = 9997;

    values.pop_back();
    values.pop_back();
    values.pop_back();
    
    ASSERT_EQ(values.size(), count_after);
}

TEST_F(ArrayFixture, GetValueByIndex) {
    const int value1 = values.get_value(1);
    const int value2 = values.get_value(2);

    ASSERT_EQ(value1, 0);
    ASSERT_EQ(value2, 1);
}

TEST_F(ArrayFixture, CopyContainer) {
    ArrayContainer values2(values);  

    ASSERT_TRUE(values == values2);
}
