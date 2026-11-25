#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

class Point {
private:
    double x, y, z;

public:
    Point(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}

    void Init(double x, double y, double z) {
        this->x = x; this->y = y; this->z = z;
    }

    double getX() const { return x; }
    double getY() const { return y; }
    double getZ() const { return z; }
    void setX(double x) { this->x = x; }
    void setY(double y) { this->y = y; }
    void setZ(double z) { this->z = z; }

    void display() const {
        cout << fixed << setprecision(2);
        cout << "(" << x << ", " << y << ", " << z << ")" << endl;
    }

    double distanceTo(const Point &other) const {
        return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2) + pow(z - other.z, 2));
    }

    friend double euclideanDistance(const Point &a, const Point &b);
    friend double manhattanDistance(const Point &a, const Point &b);
    friend double chebyshevDistance(const Point &a, const Point &b);
    friend Point midpoint(const Point &a, const Point &b);
};

double euclideanDistance(const Point &a, const Point &b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2));
}

double manhattanDistance(const Point &a, const Point &b) {
    return fabs(a.x - b.x) + fabs(a.y - b.y) + fabs(a.z - b.z);
}

double chebyshevDistance(const Point &a, const Point &b) {
    double dx = fabs(a.x - b.x);
    double dy = fabs(a.y - b.y);
    double dz = fabs(a.z - b.z);
    return max(dx, max(dy, dz)); 
}

Point midpoint(const Point &a, const Point &b) {
    return Point((a.x + b.x) / 2.0, (a.y + b.y) / 2.0, (a.z + b.z) / 2.0);
}

int main() {

    double x1, y1, z1, x2, y2, z2;
    
    if (cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2) {
        Point p1(x1, y1, z1);
        Point p2(x2, y2, z2);

        p1.display();

        p2.display();

        cout << "Å·ÊÏ¾àÀë: " << euclideanDistance(p1, p2) << endl;
        cout << "Âü¹þ¶Ù¾àÀë: " << manhattanDistance(p1, p2) << endl;
        cout << "ÇÐ±ÈÑ©·ò¾àÀë: " << chebyshevDistance(p1, p2) << endl;
        
        cout << "ÖÐµã×ø±ê: ";
        midpoint(p1, p2).display();

        cout << "³ÉÔ±º¯Êý¼ÆËãÅ·ÊÏ¾àÀë: " << p1.distanceTo(p2) << endl;
    } else {
        cout << "Î´ÊäÈëÊý¾Ý£¡" << endl;
    }

    return 0;
}
