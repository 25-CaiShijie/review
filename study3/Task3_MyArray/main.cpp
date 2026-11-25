#include <iostream>
#include "MyArray.h"

using namespace std;

int main() {
    // 测试基础构造
    MyArray A(3, 0);
    A.set(0, 6); A.set(1, 8); A.set(2, 9);
    
    MyArray B(3, 0);
    B.set(0, 3); B.set(1, 2); B.set(2, 4);

    cout << "A = "; A.display(); cout << endl;
    cout << "B = "; B.display(); cout << endl;

    cout << "A merge B = "; A.merge(B).display(); cout << endl;
    cout << "A + B = "; A.add(B).display(); cout << endl;
    cout << "A - B = "; A.subtract(B).display(); cout << endl;
    cout << "A * B = "; A.multiply(B).display(); cout << endl;
    cout << "A / B = "; A.divide(B).display(); cout << endl;

    cout << "\n--- 测试长度不一致及深拷贝 ---" << endl;
    MyArray C(3);
    C.set(0, 1); C.set(1, 2); C.set(2, 3);
    
    MyArray D(2);
    D.set(0, 4); D.set(1, 5);

    cout << "C + D = "; C.add(D).display(); cout << endl;

    // 测试深拷贝
    MyArray E = C; // 拷贝构造
    E.set(0, 999);
    cout << "深拷贝测试 - 修改E后: " << endl;
    cout << "C = "; C.display(); cout << endl;
    cout << "E = "; E.display(); cout << endl;

    return 0;
}
