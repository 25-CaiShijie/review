#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

class Triangle {
private:
    double a, b, c;

public:
    // 1. 构造函数
    Triangle(double a = 1, double b = 1, double c = 1) : a(a), b(b), c(c) {}

    // 2. 初始化成员函数
    void Init(double a, double b, double c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    // 3. 构成判断函数
    bool isTriangle() const {
        return (a > 0 && b > 0 && c > 0) && (a + b > c && a + c > b && b + c > a);
    }

    // 4. 读写接口
    double getSideA() const { return a; }
    double getSideB() const { return b; }
    double getSideC() const { return c; }

    void setSideA(double val) {
        if (val > 0) a = val; else cout << "提示: 边长必须为正数" << endl;
    }
    void setSideB(double val) {
        if (val > 0) b = val; else cout << "提示: 边长必须为正数" << endl;
    }
    void setSideC(double val) {
        if (val > 0) c = val; else cout << "提示: 边长必须为正数" << endl;
    }

    // 5. 周长计算函数
    double perimeter() const {
        if (!isTriangle()) return 0;
        return a + b + c;
    }

    // 6. 面积计算函数 (海伦公式)
    double area() const {
        if (!isTriangle()) return 0;
        double p = perimeter() / 2.0;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    // 7. 类型判断函数
    int typeTriangle() const {
        if (!isTriangle()) return 0;

        // 找出最大值，以及两条较小边
        double arr[3] = {a, b, c};
        sort(arr, arr + 3);
        double x = arr[0], y = arr[1], z = arr[2];

        // 浮点数比较精度处理
        double diff = x * x + y * y - z * z;
        
        // 提高要求：等腰/等边判断
        bool isEq = (fabs(x - y) < 1e-6 && fabs(y - z) < 1e-6); // 等边
        bool isIso = (fabs(x - y) < 1e-6 || fabs(y - z) < 1e-6 || fabs(x - z) < 1e-6); // 等腰

        if (fabs(diff) < 1e-6) {
            if (isIso) return 4; // 等腰直角三角形 (优先于普通直角)
            return 1; // 直角三角形
        } else if (diff > 0) {
            if (isEq) return 5;  // 等边三角形 (肯定也是锐角)
            if (isIso) return 6; // 等腰锐角三角形
            return 2; // 锐角三角形
        } else {
            if (isIso) return 7; // 等腰钝角三角形
            return 3; // 钝角三角形
        }
    }

    // 8. 输出函数
    void display() const {
        cout << fixed << setprecision(2);
        cout << "Sides: " << a << " " << b << " " << c << endl;
        if (!isTriangle()) {
            cout << "Error: cannot form a triangle" << endl;
            return;
        }
        cout << "Perimeter: " << perimeter() << endl;
        cout << "Area: " << area() << endl;
        
        int type = typeTriangle();
        cout << "Type: ";
        switch (type) {
            case 1: cout << "直角三角形"; break;
            case 2: cout << "锐角三角形"; break;
            case 3: cout << "钝角三角形"; break;
            case 4: cout << "等腰直角三角形"; break;
            case 5: cout << "等边三角形"; break;
            case 6: cout << "等腰锐角三角形"; break;
            case 7: cout << "等腰钝角三角形"; break;
        }
        cout << endl;
    }
};

int main() {
    double a, b, c;
    if (cin >> a >> b >> c) {
        Triangle t(a, b, c);
        t.display();
    }
    return 0;
}
