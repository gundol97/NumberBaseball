#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

std::string Answer, GuessNumber;
int Ball, Strike;
std::string MakeAnswer() { //��ǻ�Ͱ� 3�ڸ� ���� ����
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

std::string GetGuessNumber() { // ����ڰ� �Է� �� ����� �Է��ߴ��� ����
    std::string S;
    std::cout << "���ڸ� �Է��ϼ���" << "\n";
    while (true) {
        bool Check = true;
        std::cin >> S;
        if (S.length() != 3) {
            std::cout << "���ڸ� ���ڸ� �Է��ϼ���" << "\n";
            Check = false;
        }
        else {
            for (int i = 0; i < 3; i++) {
                if (S[i] - '0' > 10 || S[i] - '0' <= 0) {
                    Check = false;
                }
            }
            if (!Check) std::cout << "1 ~ 9 ������ ���ڸ��� �Է��ϼ���" << "\n";
            else if (S[0] == S[1] || S[1] == S[2] || S[0] == S[2]) {
                std::cout << "��� ���ڰ� �޶���մϴ�." << "\n";
                Check = false;
            }
        }
        if (Check) break;
    }
    return S;
}

void Count(std::string S1, std::string S2) { // ��Ʈ����ũ, �� ī��Ʈ
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (S1[i] == S2[j]) {
                if (i == j) Strike++;
                else Ball++;
            }
        }
    }
}

bool Result() { //��� ��� �� �����̸� ����
    if (Strike == 3) {
        std::cout << "�����Դϴ�!";
        return false;
    }
    else {
        std::cout << Strike << "��Ʈ����ũ " << Ball << "�� �Դϴ�." << "\n";
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