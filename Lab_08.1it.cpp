#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int CountStars(char* str) {
    if (strlen(str) < 3)
        return 0;
    int count = 0;
    for (int i = 0; str[i + 2] != 0; i++) {
        if (str[i] == '*' && str[i + 1] == '*' && str[i + 2] == '*')
            count++;
    }
    return count;
}

char* ReplaceStars(char* str) {
    size_t len = strlen(str);
    if (len < 3)
        return str;
    char* result = new char[len + 1];
    char* temp = result;
    temp[0] = '\0';

    for (size_t i = 0; i < len; ) {
        if (str[i] == '*' && str[i + 1] == '*' && str[i + 2] == '*') {
            strcat(temp, "!!");
            temp += 2;
            i += 3;
        }
        else {
            *temp++ = str[i++];
            *temp = '\0';
        }
    }
    strcpy(str, result);
    return result;
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);
    cout << "String contains " << CountStars(str) << " groups of '***'" << endl;
    char* modifiedStr = ReplaceStars(str);
    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << modifiedStr << endl;
    delete[] modifiedStr;
    return 0;
}
