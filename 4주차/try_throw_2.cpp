// try_throw_2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int main()
{
    try
    {
        int input;
        cout << "정수 중 하나를 입력해보세요 : ";
        cin >> input;

        if (input > 0)  // 입력받은 숫자가 양수이면
        {
            cout << "throw 1" << endl;
            throw 1;    // 예외 1 발생 (정수 형식 예외)
            cout << "after throw 1" << endl;
        }

        if (input < 0)  // 임력받은 숫자가 인수이면
        {
            cout << "throw -1.0f" << endl;
            throw - 1.0f;   // 예외 1.0f 발생 (부동 소수점 형식 예외)
            cout << "after throw -1.0f" << endl;
        }

        if (input == 0) // 임력받은 숫자가 음수이면
        {
            cout << "throw Z" << endl;
            throw 'Z';  // 예외 Z 발생 (문자 형식 예외)
            cout << "after throw -1.0f" << endl;
        }
    }

    catch (int a)   // 정수 형식 예외 받기
    {
        cout << "catch " << a << endl;
    }
    catch (...) // 처리되지 않은 나머지 예외 모두 받기
    {
        cout << "catch all" << endl;
    }

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
