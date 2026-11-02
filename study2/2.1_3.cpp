#include <iostream>
#include <iomanip>

using namespace std;

// 1. 内联函数计算平方
inline double square(double x) {
    return x * x;
}

// 2. 带默认参数值的函数，默认计算平方 (指数为2)
double power(double base, int exponent = 2) {
    double result = 1.0;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

// 3. 重载函数：处理 double 类型的四则运算
double calc(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) {
                cout << "Error: divide by zero" << endl;
                return 0.0;
            }
            return a / b;
        default: return 0.0;
    }
}

// 3. 重载函数：处理 int 类型的四则运算
double calc(int a, int b, char op) {
    return calc(static_cast<double>(a), static_cast<double>(b), op);
}

int main() {
    // 设置浮点数输出格式：固定小数位，保留两位
    cout << fixed << setprecision(2); 

    double num1, num2;
    char op;
    
    // 完全对应你截图里的输入提示语
    cout << "请输入两个操作数和运算符: ";
    cin >> num1 >> num2 >> op;

    // 完全对应你截图里的输出格式（注意中英文冒号的区别）
    cout << num1 << "的平方: " << square(num1) << endl;
    cout << num1 << "的默认乘幂 (平方): " << power(num1) << endl;
    cout << num1 << "的3次幂: " << power(num1, 3) << endl;

    double res = calc(num1, num2, op);
    
    // 如果是除零错误，calc 函数内部已经输出了错误提示，这里就不再输出等号
    if (op == '/' && num2 == 0) {
        // 什么都不做，等待暂停
    } else {
        // 完全对应截图最后的等式输出
        cout << num1 << " " << op << " " << num2 << " = " << res << endl;
    }

    // 暂停，防止黑框一闪而过方便截图
    system("pause");
    
    return 0;
}