#include <iostream>
#include <string>
#include <regex>
#include <array>
#include <format> // 프로젝트 -> 속성 -> C언어 표준을 C++20으로 변경

using namespace std;

double check_pattern(string text); // 배열에 들어갈 숫자가 올바른지 확인

template <size_t T>
void input(array<double, T>& arr); // 배열에 숫자 넣기

template <size_t T>
double sum(array<double, T>& arr); // 배열 합

template <size_t T>
double average(array<double, T>& arr); // 배열 평균

int main()
{
    array<double, 5> arr;
    input(arr);
    cout << "점수 : ";
    for (double value : arr) {
        cout << value << "  ";
    }
    cout << endl;
    cout << "합   : " << sum(arr) << endl;
    cout << "평균 : " << average(arr) << endl;
}

double check_pattern(string text = "") {
    string num = "";
    regex positive_pattern("^[0-9]+(\\.[0-9]+)?$"); // 소수인지 확인
    regex numeric_pattern("^-?[0-9]+(\\.[0-9]+)?$"); // 소수인지 확인
    /*
      ^ : 문자열 시작
      $ : 문자열 끝
      ? : ? 앞의 문자가 있어도, 없어도 됨
      [0-9] : 0부터 9까지
      + : +앞의 문자가 하나 이상 있어야 함
      \\. : 소수점
    */
    while (true) {
        cout << text << " 숫자를 입력하세요 : ";
        getline(cin, num);
        if (regex_match(num, positive_pattern)) {
            break;
        }
        else if (regex_match(num, numeric_pattern)) {
            cout << "음수는 입력할 수 없습니다!" << endl;
        }
        else {
            cout << "숫자만 입력해주세요!" << endl;
        }
    }
    return stod(num);
}

template <size_t T>
void input(array<double, T>& arr) {
    int index = 1;
    for (double& value : arr) {
        string txt = to_string(index) + "번째";
        value = check_pattern(txt);
        index++;
    }
}

template <size_t T>
double sum(array<double, T>& arr) {
    double total = 0;
    for (double index : arr) {
        total += index;
    }
    return total;
}

template <size_t T>
double average(array<double, T>& arr) {
    double avr = sum(arr) / T;
    return avr;
}