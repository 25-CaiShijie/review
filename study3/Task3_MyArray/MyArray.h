#ifndef MYARRAY_H
#define MYARRAY_H

#include <iostream>

class MyArray {
private:
    int *p; // 指向动态数组首地址
    int N;  // 数组元素个数

public:
    // 构造与析构
    MyArray(); // 默认构造
    MyArray(int n, int value = 0); // 带默认参数构造
    MyArray(const MyArray &other); // 拷贝构造 (深拷贝)
    ~MyArray(); // 析构函数

    // 基本操作
    int size() const;
    int get(int index) const;
    void set(int index, int value);
    void display() const;

    // 合并与运算
    MyArray merge(const MyArray &other) const;
    MyArray add(const MyArray &other) const;
    MyArray subtract(const MyArray &other) const;
    MyArray multiply(const MyArray &other) const;
    MyArray divide(const MyArray &other) const;
};

#endif
