#include <iostream>
#include <string>

using namespace std;

// 冰箱类
class Fridge {
private:
    string brand;
    bool doorOpen;

public:
    Fridge(string name = "海尔") : brand(name), doorOpen(false) {}

    void openDoor() {
        doorOpen = true;
        cout << "冰箱门已打开" << endl;
    }

    void closeDoor() {
        doorOpen = false;
        cout << "冰箱门已关闭" << endl;
    }

    bool isDoorOpen() {
        return doorOpen;
    }

    void showStatus() {
        cout << "当前冰箱门状态：" << (doorOpen ? "开启" : "关闭") << endl;
    }
};

// 大象类
class Elephant {
private:
    string name;

public:
    Elephant(string n = "大象") : name(n) {}

    void enterFridge(Fridge& fridge) {
        if (fridge.isDoorOpen()) {
            cout << name << "走进了冰箱" << endl;
        } else {
            cout << "门是关着的，" << name << "进不去" << endl;
        }
    }
};

int main() {
    cout << "【大象装进冰箱程序】" << endl;
    cout << "----------------------------------" << endl;

    Fridge fridge;
    Elephant elephant;

    cout << "第一步：打开冰箱门" << endl;
    fridge.openDoor();
    cout << "-> ";
    fridge.showStatus();
    cout << endl;

    cout << "第二步：大象走进冰箱" << endl;
    elephant.enterFridge(fridge);
    cout << endl;

    cout << "第三步：关闭冰箱门" << endl;
    fridge.closeDoor();
    cout << "-> ";
    fridge.showStatus();
    cout << "----------------------------------" << endl;

    cout << "程序执行完毕。" << endl;

    return 0;
}