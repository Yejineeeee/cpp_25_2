// domyself_7_3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
using namespace std;

class character {
public :
    character() : hp(100), power(100) {
};
void get_damage(int _damage) {};
protected:
    int hp;
    int power;
};

// player 클래스
class player : public character {
public:
    player() {};
};

// 기본 monster 클래스
class monster {
public:
    virtual ~monster() {};
    void attack(player target_player) {};
    virtual void attack_special(player target_player) {
        cout << "기본 공격 : 데미지 - 10hp" << endl;
    }
};

// 몬스터 A는 기본 monster 클래스로부터 상속
class monster_b : public monster {
public:
    monster_b(player& attach_target)
    : monster_type("일반"), // 직접 초기화
        location{ 0,0 },  // 유니폼 초기화
        unique_id(++total_count),  // 상수 변수 초기화
        target(attach_target) { // 레퍼런스 변수 초기화
        difficult_level = 10; // 복사 초기화
        quiz = new char[1024];  // 동적 메모리 할당
};

virtual ~monster_b() {
    delete[] quiz;
    total_count--;
}

monster_b(const monster_b& ref);

// 상속받은 함수 오버라이딩
virtual void attach_special(player target_player) override
{
    cout << "가상 공격 : 데미지 - 0 hp" << endl;
};

void set_quiz(const char* new_quiz) {
    strcpy_s(quiz, 1024, new_quiz);
void set_

int main()
{
    std::cout << "Hello World!\n";
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
