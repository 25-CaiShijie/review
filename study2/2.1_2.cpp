#include <iostream>

using namespace std;

// 统计元音字母的函数
int countVowels(const char* p) {
    int count = 0;
    // 遍历字符串直到遇到结束符 '\0'
    while (*p != '\0') {
        char c = *p;
        // 判断是否为元音字母（包含大小写）
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            count++;
        }
        p++; // 指针后移
    }
    return count;
}

int main() {
    const int MAX_LENGTH = 1000;
    char str[MAX_LENGTH];

    cout << "请输入一行字符串: ";
    // 使用 cin.getline 读取包含空格的整行字符串
    cin.getline(str, MAX_LENGTH); 

    // 调用函数并输出结果
    int vowelCount = countVowels(str);
    cout << "元音字母个数为: " << vowelCount << endl;

    // 暂停，防止黑框一闪而过，方便截图
    system("pause");
    
    return 0;
}