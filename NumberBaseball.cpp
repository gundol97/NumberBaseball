#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

std::string Answer, GuessNumber;
int Ball, Strike;
std::string MakeAnswer() { //컴퓨터가 3자리 숫자 생성
    std::string S;
    std::srand((unsigned int)time(NULL));
    char C;
    for (int i = 0; i < 3; i++) {
        while (true) {
            bool Check = true;
            C = (std::rand() % 10) + '0';
            for (int j = 0; j < S.length(); j++) {
                if (S[j] == C) Check = false;
            }
            if (C == '0') Check = false;
            if (Check) break;
        }
        S += C;
    }
    return S;
}

std::string GetGuessNumber() { // 사용자가 입력 및 제대로 입력했는지 검증
    std::string S;
    std::cout << "숫자를 입력하세요" << "\n";
    while (true) {
        bool Check = true;
        std::cin >> S;
        if (S.length() != 3) {
            std::cout << "세자리 숫자를 입력하세요" << "\n";
            Check = false;
        }
        else {
            for (int i = 0; i < 3; i++) {
                if (S[i] - '0' > 10 || S[i] - '0' <= 0) {
                    Check = false;
                }
            }
            if (!Check) std::cout << "1 ~ 9 사이의 숫자만을 입력하세요" << "\n";
            else if (S[0] == S[1] || S[1] == S[2] || S[0] == S[2]) {
                std::cout << "모든 숫자가 달라야합니다." << "\n";
                Check = false;
            }
        }
        if (Check) break;
    }
    return S;
}

void Count(std::string S1, std::string S2) { // 스트라이크, 볼 카운트
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (S1[i] == S2[j]) {
                if (i == j) Strike++;
                else Ball++;
            }
        }
    }
}

bool Result() { //결과 출력 및 정답이면 종료
    if (Strike == 3) {
        std::cout << "정답입니다!";
        return false;
    }
    else {
        std::cout << Strike << "스트라이크 " << Ball << "볼 입니다." << "\n";
        return true;
    }
}
int main() {
    bool Continue = true;
    Answer = MakeAnswer();
    while (Continue) {
        Ball = 0;
        Strike = 0;
        GuessNumber = GetGuessNumber();
        Count(Answer, GuessNumber);
        Continue = Result();
    }
}