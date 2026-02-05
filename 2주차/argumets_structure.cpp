// argumets_structure.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

struct Person
{
    std::string name;    // 이름
    int age;    // 나이
    float height;   // 키
    float weight;   // 몸무게
};

void check_age(Person *_adult, int _count)
{
    for (int i = 0; i < _count; i++)
    {
        if (_adult[i].age >= 25)
        {
            cout << "name: " << _adult[i].name << endl;
            cout << "age: " << _adult[i].age << endl;
            cout << "height: " << _adult[i].height << endl;
            cout << "weight: " << _adult[i].weight << endl;
        }
    }
}

int main()
{
    Person adult[3] =
    {
        {"Brain", 24, 180, 70},
        {"Jessica", 22, 165, 55},
        { "Jessica", 30, 170, 65 },
    };
    check_age(adult, 3);

    return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
