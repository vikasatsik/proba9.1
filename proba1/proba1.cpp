#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> // ������������ ����������� ��������
using namespace std;

enum Specialnist { KOMPUTERNI_NAUKY, INFORMATYKA, MATEMATYKA_TA_EKONOMIKA, FIZYKA_TA_INFORMATYKA, TRUDOVE_NAVCHANYA };
// ��������Ͳ �����, �����������, ���������� � �����̲��, Բ���� � �����������, ������� ��������

string specialnistStr[] = { "��������Ͳ �����", "�����������", "���������� � �����̲��", "Բ���� � �����������", "������� ��������" };

struct Student
{
    string prizv;
    unsigned kurs;
    Specialnist specialnist;
    unsigned fizyka;
    unsigned matematika;
    union
    {
        unsigned programming;
        unsigned chiselni_metody;
        unsigned pedagogika;
    };
};

void Create(Student* s, const int N);
void Print(Student* s, const int N);
int Average(Student* s, const int N);

int main()
{
    SetConsoleCP(1251); // ������������ ������� win-cp1251 � ���� �����
    SetConsoleOutputCP(1251); // ������������ ������� win-cp1251 � ���� ������

    int N;
    cout << "������ �-��� �������� N: "; cin >> N;

    Student* s = new Student[N];

    int count;

    int menultem;
    do {
        cout << endl << endl << endl;
        cout << "������� ��:" << endl << endl;
        cout << " [1] - �������� ����� � ���������" << endl;
        cout << " [2] - ���� ����� �� �����" << endl;
        cout << " [3] - ���� ���������� ���� � ��� ��������������" << endl;
        cout << " [0] - ����� �� ���������� ������ ��������" << endl << endl;
        cout << "����� ��������: "; cin >> menultem;
        cout << endl << endl << endl;
        switch (menultem)
        {
        case 1:
            Create(s, N);
            break;
        case 2:
            Print(s, N);
        case 3:
            count = Average(s, N);
            cout << "ʳ������ ������� ����, ����� �� 4: " << count << endl;
            break;
        case 0:
            break;
        default:
            cout << "�� ����� ��������� ��������! "
                "��� ������ ����� - ����� ��������� ������ ����" << endl;
        }
    } while (menultem != 0);
    return 0;
}


void Create(Student* s, const int N)
{
    int specialnist;
    for (int i = 0; i < N; i++)
    {
        cout << "������� � " << i + 1 << ":" << endl;
        cin.get();
        cin.sync();
        cout << " �������: "; getline(cin, s[i].prizv);
        cout << " ����: "; cin >> s[i].kurs;
        cout << " ������������(0 - ��������Ͳ �����, 1 - �����������, 2 - ���������� � �����̲��, 3 - Բ���� � �����������, 4 - ������� ��������): ";
        cin >> specialnist;
        s[i].specialnist = (Specialnist)specialnist;
        switch (s[i].specialnist)
        {
        case KOMPUTERNI_NAUKY:
            cout << " ������ � ������: "; cin >> s[i].fizyka;
            cout << " ������ � ����������: "; cin >> s[i].matematika;
            cout << " ������ � �������������: "; cin >> s[i].programming;
            break;
        case INFORMATYKA:
            cout << " ������ � ������: "; cin >> s[i].fizyka;
            cout << " ������ � ����������: "; cin >> s[i].matematika;
            cout << " ������ � ��������� ������: "; cin >> s[i].chiselni_metody;
            break;
        case MATEMATYKA_TA_EKONOMIKA:
        case FIZYKA_TA_INFORMATYKA:
        case TRUDOVE_NAVCHANYA:
            cout << " ������ � ������: "; cin >> s[i].fizyka;
            cout << " ������ � ����������: "; cin >> s[i].matematika;
            cout << " ������ � ���������: "; cin >> s[i].pedagogika;
            break;
        }
        cout << endl;
    }
}
void Print(Student* s, const int N)
{
    cout << "                                                                                                                                                    " << endl;
    cout << "                                                                                                                                                    " << endl;
    cout << "                                                        г���� �) � ������ �������:                                                               " << endl;
    cout << "                              (1) � ���������� ����� �������� � ����, (2) � �������, (3) � ����,(4) � ������������,                              " << endl;
    cout << "                    ������ � (5) � ������, (6) � ���������� (������� ��� ������ �������� ��� �������� ��� ��������������),                      " << endl;
    cout << "                                      ������ � (7) � �������������, (8) � ��������� ������, (9) � ���������                                       " << endl;
    cout << "                              (��������� ���� ���� � ������� ��� ������ � ������� �� ������������ ������ ��������).                              " << endl;
    cout << "                                                                                                                                                    " << endl;
    cout << "  ================================================================================================================================================  " << endl;
    cout << " |   |                  |      |                                 |                                       ������                                   | " << endl;
    cout << " | � |     �������     | ���� |          ������������          |--------------------------------------------------------------------------------| " << endl;
    cout << " |   |                  |      |                                 | � ������ | � ���������� | � ������������� | � ��������� ������ | � ��������� | " << endl;
    cout << "  ================================================================================================================================================  " << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(3) << right << i + 1 << " ";
        cout << "| " << setw(12) << right << s[i].prizv << " "
            << "| " << setw(4) << right << s[i].kurs << " "
            << "| " << setw(13) << right << specialnistStr[s[i].specialnist];

        switch (s[i].specialnist)
        {
        case KOMPUTERNI_NAUKY:
            cout << "| " << setw(7) << right
                << s[i].fizyka << right;
            cout << "| " << setw(10) << right
                << s[i].matematika << right;
            cout << "| " << setw(13) << right
                << s[i].programming << right << endl;
            break;
        case INFORMATYKA:
            cout << "| " << setw(7) << right
                << s[i].fizyka << right;
            cout << "| " << setw(10) << right
                << s[i].matematika << right;
            cout << "| " << setw(15) << right << "|" << setw(16) << right
                << s[i].chiselni_metody << " |" << right << endl;
            break;
        case MATEMATYKA_TA_EKONOMIKA:
        case FIZYKA_TA_INFORMATYKA:
        case TRUDOVE_NAVCHANYA:
            cout << "| " << setw(7) << right
                << s[i].fizyka << right;
            cout << "| " << setw(10) << right
                << s[i].matematika << right;
            cout << "| " << setw(15) << right << "|" << setw(18) << right << "|" << setw(11) << right
                << s[i].pedagogika << " |" << right << endl;
            break;
        }
    }
    cout << "  ================================================================================================================================================  " << endl;

    cout << endl;
}


int Average(Student* s, const int N)
{
    cout << "������� ��� ��� ������� ��������:" << endl;

    cout << "====================================="
        << endl;
    cout << "|  �  |   �������   | ������� ��� |"
        << endl;
    cout << "-------------------------------------"
        << endl;

    int aver = 0, count = 0, n = 0;
    for (int i = 0; i < N; i++)
    {
        switch (s[i].specialnist)
        {
        case KOMPUTERNI_NAUKY:
            n++;
            aver = round(s[i].fizyka + s[i].matematika + s[i].programming) / 3;

            if (aver < 4)
                count++;

            cout << "| " << setw(3) << right << n << " | " << setw(12) << right << s[i].prizv << " | "
                << setw(12) << aver << " |" << right << endl;
            break;
        case INFORMATYKA:
            n++;

            aver = round(s[i].fizyka + s[i].matematika + s[i].chiselni_metody) / 3;

            if (aver < 4)
                count++;
            cout << "| " << setw(3) << right << n << " | " << setw(12) << right << s[i].prizv << " | "
                << setw(12) << aver << " |" << right << endl;
            break;
        case MATEMATYKA_TA_EKONOMIKA:
        case FIZYKA_TA_INFORMATYKA:
        case TRUDOVE_NAVCHANYA:
            n++;

            aver = round(s[i].fizyka + s[i].matematika + s[i].pedagogika) / 3;

            if (aver < 4)
                count++;
            cout << "| " << setw(3) << right << n << " | " << setw(12) << right << s[i].prizv << " | "
                << setw(12) << aver << " |" << right << endl;
            break;
        
        
        }
    }
    cout << "==================================" << endl;
    cout << endl;

    return count;
}