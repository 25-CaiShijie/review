#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Date {
private:
    int year;
    int month;
    int day;

    // 辅助函数：判断是否为闰年
    bool isLeap(int y) const {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    // 辅助函数：获取某月天数
    int getDaysInMonth(int y, int m) const {
        if (m == 2) return isLeap(y) ? 29 : 28;
        if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
        return 31;
    }

    // 辅助函数：校验日期合法性
    bool isValid(int y, int m, int d) const {
        if (y < 1900 || m < 1 || m > 12 || d < 1) return false;
        if (d > getDaysInMonth(y, m)) return false;
        return true;
    }

public:
    // 1. 构造函数
    Date(int y = 1900, int m = 1, int d = 1) : year(y), month(m), day(d) {
        if (!isValid(y, m, d)) {
            cout << "提示：非法的日期输入，已自动重置为默认日期 1900-01-01" << endl;
            year = 1900; month = 1; day = 1;
        }
    }

    // 2. 初始化成员函数
    void Init(int y, int m, int d) {
        if (!isValid(y, m, d)) {
            cout << "提示：非法的日期输入，初始化失败，保持原日期不变" << endl;
            return;
        }
        year = y; month = m; day = d;
    }

    // 3. 读接口
    int getYear() const { return year; }
    int getMonth() const { return month; }
    int getDay() const { return day; }

    // 4. 写接口
    void setYear(int y) {
        if (isValid(y, month, day)) year = y;
        else cout << "提示：非法年份，写入失败" << endl;
    }
    void setMonth(int m) {
        if (isValid(year, m, day)) month = m;
        else cout << "提示：非法月份，写入失败" << endl;
    }
    void setDay(int d) {
        if (isValid(year, month, d)) day = d;
        else cout << "提示：非法日，写入失败" << endl;
    }

    // 5. 输出函数
    void display() const {
        cout << "Date: " << year << "-" 
             << setfill('0') << setw(2) << month << "-" 
             << setw(2) << day << setfill(' ') << endl;
    }

    // 6. 星期计算函数 (基姆拉尔森公式)
    int calWeekday() const {
        int y = year;
        int m = month;
        int d = day;
        if (m == 1 || m == 2) {
            m += 12;
            y--;
        }
        int weekday = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400 + 1) % 7;
        return weekday;
    }

    // 提高要求：判断闰年
    bool isLeapYear() const {
        return isLeap(year);
    }

    // 提高要求：计算明日日期
    void nextDay() {
        day++;
        if (day > getDaysInMonth(year, month)) {
            day = 1;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
    }
};

int main() {
    int y, m, d;
    if (cin >> y >> m >> d) {
        Date date(y, m, d);
        date.display();
        
        int wd = date.calWeekday();
        string weekdays[] = {"星期日", "星期一", "星期二", "星期三", "星期四", "星期五", "星期六"};
        cout << "Weekday: " << weekdays[wd] << endl;
    }
    return 0;
}
