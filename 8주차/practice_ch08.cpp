// practice_ch08.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <random>
using namespace std;

class character {
protected:
    int likeability;
    character() : likeability(0) {};

public:
    virtual ~character() = default;            // 다형 삭제를 위한 가상 소멸자
    void add_likeability(int d = 1) { likeability += d; }
    int  get_likeability() const { return likeability; }

    virtual string name() const = 0;      // 각 캐릭터 이름
    virtual void nice_word() const = 0;        // 한마디 (순수 가상 → 반드시 오버라이드)
};

class Choco : public character {
public:
    string name() const override { return "Choco"; }
    void nice_word() const override {
        cout << "나중에 후회하지 않게 진짜 신 나는 추억을 만들자!\n";
    }
};

class Schubert : public character {
public:
    string name() const override { return "Schubert"; }
    void nice_word() const override {
        cout << "다들 각자의 스타일이 있는 법! 너도 네 방식대로 지내면 돼!\n";
    }
};

class Henry : public character {
public:
    string name() const override { return "Henry"; }
    void nice_word() const override {
        cout << "행복은 만들어지는 게 아니라, 만들어 가는 거라구!\n";
    }
};

class Apple : public character {
public:
    string name() const override { return "Apple"; }
    void nice_word() const override {
        cout << "...으앙~! 하고 싶은 말이 뒤엉켜서 전부 잊어버렸어! 좋아해!!\n";
    }
};

int main()
{
    vector<unique_ptr<character>> villagers;
    villagers.emplace_back(make_unique<Choco>());
    villagers.emplace_back(make_unique<Schubert>());
    villagers.emplace_back(make_unique<Henry>());
    villagers.emplace_back(make_unique<Apple>());

    mt19937 rng(random_device{}());
    uniform_int_distribution<size_t> pick(0, villagers.size() - 1);

    std::cout << " [당신과 잘 맞는 주민은?]\n";

    while (true) {
        size_t i = pick(rng);
        auto& v = *villagers[i];

        cout << "\n오늘의 주민: " << v.name() << "\n";
        v.nice_word();
        v.add_likeability();  // 호출될 때마다 호감도 +1
        cout << "호감도: " << v.get_likeability() << "\n";

        cout << "\n계속하려면 y, 종료하려면 다른 키: ";
        char ans; if (!(cin >> ans) || ans != 'y') break;
    }

    return 0;
}
/*
    구현하려고 하는 것 : 시작 -> 랜덤으로 번호 선택 -> 해당 번호의 주민과 주민의 속성, 한마디 출력하기 + 불릴 떄마다 호감도 상승
*/

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
