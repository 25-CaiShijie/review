#include <iostream>
#include <iomanip>
#include <string>
#include <stdexcept>
#include <cstdlib>

using namespace std;

// ================== 1. 声明部分 ==================
const double FEE_RATE = 0.02;        
const double WARNING_BALANCE = 10.0; 

struct Card {
    int id;           
    string name;      
    double balance;   
    int transactions; 
};

namespace card {
    void printLine(char c = '=', int len = 60);
    void title(const string& s);
    Card* createCards(int n);
    void destroyCards(Card* p);
    void inputCards(Card* arr, int n);
    void deposit(Card& c, double amount, double fee = FEE_RATE);
    bool spend(Card& c, double cost);
    bool spend(Card& c, double cost, const string& item);
    void showBalance(const Card& c);
    void viewStudentID(const Card* p);
    int toCent(double amount); // 单位换算函数声明
    void printReport(const Card* arr, int n);
}

// ================== 2. 实现部分 ==================
namespace card {

    void printLine(char c, int len) {
        for (int i = 0; i < len; ++i) {
            cout << c;
        }
        cout << endl;
    }

    void title(const string& s) {
        cout << "==== " << s << " ====" << endl;
    }

    Card* createCards(int n) {
        try {
            Card* p = new Card[n];
            return p;
        } catch (const bad_alloc& e) {
            cerr << "内存分配失败：" << e.what() << endl;
            exit(EXIT_FAILURE);
        }
    }

    void destroyCards(Card* p) {
        delete[] p;
    }

    void inputCards(Card* arr, int n) {
        for (int i = 0; i < n; ++i) {
            cout << "请输入学号、姓名和初始余额：";
            try {
                cin >> arr[i].id >> arr[i].name >> arr[i].balance;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    throw runtime_error("输入格式错误，请输入正确的数据类型（学号为整数，余额为数字）。");
                }
                if (arr[i].balance < 0) {
                    throw invalid_argument("初始余额不能为负数！");
                }
                arr[i].transactions = 0;
            } catch (const exception& e) {
                cout << "输入异常：" << e.what() << ",请重新输入。" << endl;
                i--; 
            }
        }
    }

    void deposit(Card& c, double amount, double fee) {
        try {
            if (amount <= 0) {
                throw invalid_argument("充值金额必须为正数！");
            }
            c.balance += amount * (1.0 - fee);
            c.transactions++;
        } catch (const exception& e) {
            cout << "充值异常：" << e.what() << endl;
        }
    }

    bool spend(Card& c, double cost) {
        try {
            if (cost < 0) {
                throw invalid_argument("消费金额不能为负数！");
            }
            if (c.balance < cost) {
                throw runtime_error("余额不足，消费失败！");
            }
            c.balance -= cost;
            c.transactions++;
            return true;
        } catch (const exception& e) {
            cout << "消费异常：" << e.what() << endl;
            return false;
        }
    }

    bool spend(Card& c, double cost, const string& item) {
        cout << "消费项目：" << item << endl;
        return spend(c, cost);
    }

    void showBalance(const Card& c) {
        cout << fixed << setprecision(2);
        cout << c.name << "当前余额为：" << c.balance << " 元" << endl;
    }

    void viewStudentID(const Card* p) {
        cout << "账户ID（学号）为：" << p->id << endl;
    }

    // 单位换算：元转分
    int toCent(double amount) {
        return static_cast<int>(amount * 100);
    }

    void printReport(const Card* arr, int n) {
        printLine('=');
        cout << left << setw(8) << "ID" 
             << setw(12) << "Name" 
             << right << setw(14) << "Balance(元)" 
             << setw(14) << "Transactions" << endl;
        printLine('=');
        
        cout.setf(ios::fixed); 
        cout << setprecision(2);
        
        for (int i = 0; i < n; ++i) {
            cout << left << setw(8) << arr[i].id 
                 << setw(12) << arr[i].name 
                 << right << setw(14) << arr[i].balance 
                 << setw(14) << arr[i].transactions << endl;
        }
        printLine('=');
    }
} 

// ================== 3. 主程序部分 ==================
int main() {
    cout << "==== Campus Card System - 校园一卡通消费管理系统 ====" << endl;
    card::printLine('-');

    cout << "请输入学生数量：";
    int n;
    cin >> n;

    Card* accounts = card::createCards(n);

    cout << "\n开始录入" << n << "名学生的账户信息：" << endl;
    card::inputCards(accounts, n);
    card::printLine('-');

    cout << "\n【示例操作】对第一个账户执行充值和消费：" << endl;
    card::deposit(accounts[0], 100.0); 
    card::spend(accounts[0], 8.5, "食堂午餐");
    card::spend(accounts[0], 2.0, "超市矿泉水");
    card::printLine('-');

    cout << "\n【账户查询结果】" << endl;
    card::showBalance(accounts[0]);
    card::viewStudentID(&accounts[0]); 
    
    cout << accounts[0].name << "当前余额（分）：" << card::toCent(accounts[0].balance) << " 分" << endl;
    
    card::printLine('-');

    cout << "\n【所有账户报表】" << endl;
    card::printReport(accounts, n);

    card::destroyCards(accounts);

    system("pause");
    return 0;
}