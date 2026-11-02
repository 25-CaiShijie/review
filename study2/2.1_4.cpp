#include <iostream>

using namespace std;

// 1. 使用引用交换两个整数
void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

// 2. 重载函数：使用指针交换两个整数
void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a, b;
    
    // 提示语与截图完全一致
    cout << "请输入两个整数: ";
    cin >> a >> b;

    cout << "交换前: a = " << a << ", b = " << b << endl;

    // 调用引用版本，交换 a 和 b 的值
    swap(a, b); 
    cout << "引用交换后: a = " << a << ", b = " << b << endl;

    // 再次调用指针版本（传入地址），把值交换回去，展示重载效果
    swap(&a, &b); 
    cout << "指针交换后: a = " << a << ", b = " << b << endl;

    // 暂停，防止黑框一闪而过方便截图
    system("pause");
    
    return 0;
}