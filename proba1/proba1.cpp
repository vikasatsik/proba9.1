#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> // забезпеченн€ в≥дображенн€ кирилиц≥
using namespace std;

enum Specialnist { KOMPUTERNI_NAUKY, INFORMATYKA, MATEMATYKA_TA_EKONOMIKA, FIZYKA_TA_INFORMATYKA, TRUDOVE_NAVCHANYA };
//  ќћѕё“≈–Ќ≤ Ќј” », ≤Ќ‘ќ–ћј“» ј, ћј“≈ћј“» ј ≤ ≈ ќЌќћ≤ ј, ‘≤«» ј ≤ ≤Ќ‘ќ–ћј“» ј, “–”ƒќ¬≈ Ќј¬„јЌЌя

string specialnistStr[] = { " ќћѕё“≈–Ќ≤ Ќј” »", "≤Ќ‘ќ–ћј“» ј", "ћј“≈ћј“» ј ≤ ≈ ќЌќћ≤ ј", "‘≤«» ј ≤ ≤Ќ‘ќ–ћј“» ј", "“–”ƒќ¬≈ Ќј¬„јЌЌя" };

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
    SetConsoleCP(1251); // встановленн€ стор≥нки win-cp1251 в пот≥к вводу
    SetConsoleOutputCP(1251); // встановленн€ стор≥нки win-cp1251 в пот≥к виводу

    int N;
    cout << "¬вед≥ть к-сть студент≥в N: "; cin >> N;

    Student* s = new Student[N];

    int count;

    int menultem;
    do {
        cout << endl << endl << endl;
        cout << "¬ибер≥ть д≥ю:" << endl << endl;
        cout << " [1] - введенн€ даних з клав≥атури" << endl;
        cout << " [2] - вив≥д даних на екран" << endl;
        cout << " [3] - вив≥д середнього бала з≥ вс≥х спец≥альностей" << endl;
        cout << " [0] - вих≥д та завершенн€ роботи програми" << endl << endl;
        cout << "¬ед≥ть значенн€: "; cin >> menultem;
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
            cout << " ≥льк≥сть середн≥х бал≥в, менше за 4: " << count << endl;
            break;
        case 0:
            break;
        default:
            cout << "¬и ввели помилкове значенн€! "
                "—л≥д ввести число - номер вибраного пункту меню" << endl;
        }
    } while (menultem != 0);
    return 0;
}


void Create(Student* s, const int N)
{
    int specialnist;
    for (int i = 0; i < N; i++)
    {
        cout << "—тудент є " << i + 1 << ":" << endl;
        cin.get();
        cin.sync();
        cout << " ѕр≥звище: "; getline(cin, s[i].prizv);
        cout << "  урс: "; cin >> s[i].kurs;
        cout << " —пец≥альн≥сть(0 -  ќћѕё“≈–Ќ≤ Ќј” », 1 - ≤Ќ‘ќ–ћј“» ј, 2 - ћј“≈ћј“» ј ≤ ≈ ќЌќћ≤ ј, 3 - ‘≤«» ј ≤ ≤Ќ‘ќ–ћј“» ј, 4 - “–”ƒќ¬≈ Ќј¬„јЌЌя): ";
        cin >> specialnist;
        s[i].specialnist = (Specialnist)specialnist;
        switch (s[i].specialnist)
        {
        case KOMPUTERNI_NAUKY:
            cout << " ќц≥нка з ф≥зики: "; cin >> s[i].fizyka;
            cout << " ќц≥нка з математики: "; cin >> s[i].matematika;
            cout << " ќц≥нка з програмуванн€: "; cin >> s[i].programming;
            break;
        case INFORMATYKA:
            cout << " ќц≥нка з ф≥зики: "; cin >> s[i].fizyka;
            cout << " ќц≥нка з математики: "; cin >> s[i].matematika;
            cout << " ќц≥нка з чисельних метод≥в: "; cin >> s[i].chiselni_metody;
            break;
        case MATEMATYKA_TA_EKONOMIKA:
        case FIZYKA_TA_INFORMATYKA:
        case TRUDOVE_NAVCHANYA:
            cout << " ќц≥нка з ф≥зики: "; cin >> s[i].fizyka;
            cout << " ќц≥нка з математики: "; cin >> s[i].matematika;
            cout << " ќц≥нка з педагог≥ки: "; cin >> s[i].pedagogika;
            break;
        }
        cout << endl;
    }
}
void Print(Student* s, const int N)
{
    cout << "                                                                                                                                                    " << endl;
    cout << "                                                                                                                                                    " << endl;
    cout << "                                                        –≥вень ¬) Ц девТ€ть кл≥тинок:                                                               " << endl;
    cout << "                              (1) Ц пор€дковий номер студента у груп≥, (2) Ц пр≥звище, (3) Ц курс,(4) Ц спец≥альн≥сть,                              " << endl;
    cout << "                    оц≥нки з (5) Ц ф≥зики, (6) Ц математики (кл≥тинки цих оц≥нок заповнен≥ дл€ студент≥в вс≥х спец≥альностей),                      " << endl;
    cout << "                                      оц≥нки з (7) Ц програмуванн€, (8) Ц чисельних метод≥в, (9) Ц педагог≥ки                                       " << endl;
    cout << "                              (заповнена лише одна з кл≥тинок цих оц≥нок Ц залежно в≥д спец≥альност≥ такого студента).                              " << endl;
    cout << "                                                                                                                                                    " << endl;
    cout << "  ================================================================================================================================================  " << endl;
    cout << " |   |                  |      |                                 |                                       ќц≥нка                                   | " << endl;
    cout << " | є |     ѕр≥звище     |  урс |          —пец≥альн≥сть          |--------------------------------------------------------------------------------| " << endl;
    cout << " |   |                  |      |                                 | з ф≥зики | з математики | з програмуванн€ | з чисельних метод≥в | з педагог≥ки | " << endl;
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
    cout << "—ередн≥й бал дл€ кожного студента:" << endl;

    cout << "====================================="
        << endl;
    cout << "|  є  |   ѕр≥звище   | —ередн≥й бал |"
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