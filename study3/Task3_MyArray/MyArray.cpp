#include "MyArray.h"
#include <iostream>

using namespace std;

// 默认构造
MyArray::MyArray() : p(nullptr), N(0) {}

// 带默认参数构造
MyArray::MyArray(int n, int value) : N(n) {
    if (N > 0) {
        p = new int[N];
        for (int i = 0; i < N; ++i) p[i] = value;
    } else {
        p = nullptr;
        N = 0;
    }
}

// 拷贝构造 (深拷贝)
MyArray::MyArray(const MyArray &other) : N(other.N) {
    if (N > 0) {
        p = new int[N];
        for (int i = 0; i < N; ++i) p[i] = other.p[i];
    } else {
        p = nullptr;
    }
}

// 析构函数
MyArray::~MyArray() {
    delete[] p;
    p = nullptr;
    N = 0;
}

// 基本操作
int MyArray::size() const {
    return N;
}

int MyArray::get(int index) const {
    if (index < 0 || index >= N) {
        cout << "提示: 数组下标越界" << endl;
        return -1;
    }
    return p[index];
}

void MyArray::set(int index, int value) {
    if (index < 0 || index >= N) {
        cout << "提示: 数组下标越界，忽略本次操作" << endl;
        return;
    }
    p[index] = value;
}

void MyArray::display() const {
    cout << "{";
    for (int i = 0; i < N; ++i) {
        cout << p[i];
        if (i < N - 1) cout << ", ";
    }
    cout << "}";
}

// 合并
MyArray MyArray::merge(const MyArray &other) const {
    MyArray res(N + other.N);
    for (int i = 0; i < N; ++i) res.p[i] = p[i];
    for (int i = 0; i < other.N; ++i) res.p[N + i] = other.p[i];
    return res;
}

// 辅助检查长度
static void checkSize(int size1, int size2) {
    if (size1 != size2) {
        cout << "Warning: different sizes (" << size1 << " vs " << size2 << "), use the shorter length" << endl;
    }
}

// 加
MyArray MyArray::add(const MyArray &other) const {
    checkSize(N, other.N);
    int minN = (N < other.N) ? N : other.N;
    MyArray res(minN);
    for (int i = 0; i < minN; ++i) res.p[i] = p[i] + other.p[i];
    return res;
}

// 减
MyArray MyArray::subtract(const MyArray &other) const {
    checkSize(N, other.N);
    int minN = (N < other.N) ? N : other.N;
    MyArray res(minN);
    for (int i = 0; i < minN; ++i) res.p[i] = p[i] - other.p[i];
    return res;
}

// 乘
MyArray MyArray::multiply(const MyArray &other) const {
    checkSize(N, other.N);
    int minN = (N < other.N) ? N : other.N;
    MyArray res(minN);
    for (int i = 0; i < minN; ++i) res.p[i] = p[i] * other.p[i];
    return res;
}

// 除
MyArray MyArray::divide(const MyArray &other) const {
    checkSize(N, other.N);
    int minN = (N < other.N) ? N : other.N;
    MyArray res(minN);
    for (int i = 0; i < minN; ++i) {
        if (other.p[i] == 0) {
            cout << "提示: 除数不能为0 (索引 " << i << ")，结果记为0" << endl;
            res.p[i] = 0;
        } else {
            res.p[i] = p[i] / other.p[i];
        }
    }
    return res;
}
