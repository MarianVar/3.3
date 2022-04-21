#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <Windows.h> 
using namespace std;



struct Student {
    string lastname;
    string inizials;
    unsigned math;
    unsigned phsic;
    unsigned informatic;
    unsigned history;
    unsigned english;
};

void Create(Student* s, const int N);
void Print(Student* s, const int N);

Student* AddNewStudent(Student* s, const int N);
Student* DeletStudent(Student* s, const int N);
void EditStudent(Student* s, const int N);

Student* Exelent(Student* s, const int N);
Student* StudentWithOneTree(Student* s, const int N);
Student* OnlyOneTwo(Student* s, const int N);


void SaveToFile(Student* s, const int N, const char* filename);
void LoadFromFile(Student*& s, int& N, const char* filename);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    cout << "Введіть к-сть студентів: "; cin >> N;
    Student* s = new Student[N];
    char filename[100];


    int menuItem;
    do {
        cout << endl;
        cout << "Виберіть дію:" << endl << endl;
        cout << " [1] - введення даних з клавіатури" << endl;
        cout << " [11] - добавити нового студента" << endl;
        cout << " [12] - вилучити студента" << endl;
        cout << " [13] - редагувати дані студента" << endl;
        cout << " [2] - вивід списоку всіх студентів" << endl;
        cout << " [3] - вивід студентів ,що склали іспити на 5" << endl;
        cout << " [4] - вивід студентів , що мають 3" << endl;
        cout << " [5] - список студентів, що мають двійки. " << endl
            << "При цьому студент, що має більш ніж одну"
            << "двійку, виключається із списку." << endl;
        cout << " [7] - запис даних у файл" << endl;
        cout << " [8] - зчитування даних із файлу" << endl;
        cout << " [0] - завершення роботи" << endl << endl;
        cout << "Введіть значення: "; cin >> menuItem;
        cout << endl;
        switch (menuItem)
        {
        case 1:
            Create(s, N);
            break;
        case 11:

            s = AddNewStudent(s, N);
            N++;

            break;
        case 12:
            s = DeletStudent(s, N);
            N--;
            break;
        case 13:
            EditStudent(s, N);
            break;
        case 2:
            Print(s, N);
            break;
        case 3:
            Print(Exelent(s, N), N);
            break;
        case 4:
            Print(StudentWithOneTree(s, N), N);
            break;
        case 5:
            Print(OnlyOneTwo(s, N), N);
            break;
        case 7:
            cin.get();
            cin.sync();

            cout << "Введіть ім'я файлу: "; cin.getline(filename, 99);
            SaveToFile(s, N, filename);
            break;
        case 8:
            cin.get();
            cin.sync();

            cout << "Введіть ім'я файлу: "; cin.getline(filename, 99);
            LoadFromFile(s, N, filename);
            break;
        case 0:
            break;
        default:
            cout << "Ви ввели помилкове значення! "
                "Слід ввести число - номер вибраного пункту меню" << endl;
        }
    } while (menuItem != 0);

    return 0;
}

void Create(Student* s, const int N)
{
    for (int i = 0; i < N; i++) {
        cout << "Студент № " << i + 1 << ":" << endl;
        cout << "Прізвище студента: "; cin >> s[i].lastname;
        cout << "Ініціали студента (І.Б.): "; cin >> s[i].inizials;
        cout << "Оцінки з: " << endl;
        cout << "математики : "; cin >> s[i].math;
        cout << "фізики : "; cin >> s[i].phsic;
        cout << "інформатика : "; cin >> s[i].informatic;
        cout << "історія : "; cin >> s[i].history;
        cout << "англійська : "; cin >> s[i].english;
        cout << endl << endl;
    }
}

void Print(Student* s, const int N)
{
    cout << "============================================================="
        << endl;
    cout << "| № | Прізвище | Ініціали | мат | фіз | інф | іст | англ |"
        << endl;
    cout << "============================================================="
        << endl;

    for (int i = 0; i < N; i++)
    {
        if (s[i].lastname != "")
        {
            cout << "| " << setw(1) << right << i + 1
                << " | " << setw(8) << left << s[i].lastname
                << " | " << setw(8) << left << s[i].inizials
                << " | " << setw(3) << right << s[i].math
                << " | " << setw(3) << right << s[i].phsic
                << " | " << setw(3) << right << s[i].informatic
                << " | " << setw(3) << right << s[i].history
                << " | " << setw(4) << right << s[i].english << " |";
            cout << endl;
            cout << "-------------------------------------------------------------";
            cout << endl;
        }
    }
}

Student* AddNewStudent(Student* s, const int N)
{
    int temp = N;
    Student* newS = new Student[temp + 1];
    for (int i = 0; i < N; i++)
    {
        newS[i] = s[i];
    }
    cout << "Студент № " << temp + 1 << ":" << endl;
    cout << "Прізвище студента: "; cin >> newS[temp].lastname;
    cout << "Ініціали студента (І.Б.): "; cin >> newS[temp].inizials;
    cout << "Оцінки з: " << endl;
    cout << "математики : "; cin >> newS[temp].math;
    cout << "фізики : "; cin >> newS[temp].phsic;
    cout << "інформатика : "; cin >> newS[temp].informatic;
    cout << "історія : "; cin >> newS[temp].history;
    cout << "англійська : "; cin >> newS[temp].english;
    cout << endl << endl;
    return newS;
}

Student* DeletStudent(Student* s, const int N)
{
    int temp = N;
    int num = 0;
    cout << "№ студента що хочете видалити : "; cin >> num;
    Student* newS = new Student[temp - 1];
    for (int i = 0; i < N; i++)
    {
        if (i < num)
            newS[i] = s[i];
        if (i > num)
            newS[i] = s[i - 1];
    }
    return newS;
}

void EditStudent(Student* s, const int N)
{
    int num = 0;
    cout << "Студент № що хочете редагувати ";
    cin >> num;
    num--;
    cout << endl << endl;

    int item;

    cout << endl;
    cout << "[1]Прізвище студента: " << endl;
    cout << "[2]Ініціали студента (І.Б.): " << endl;
    cout << "  Оцінки з: " << endl;
    cout << "[3]математики : " << endl;
    cout << "[4]фізики : " << endl;
    cout << "[5]інформатика : " << endl;
    cout << "[6]історія : " << endl;
    cout << "[7]англійська : " << endl << endl;
    cout << "Введіть значення: "; cin >> item;
    switch (item)
    {
    case 1:
        cout << "Прізвище студента: "; cin >> s[num].lastname;
        break;
    case 2:
        cout << "Ініціали студента (І.Б.): "; cin >> s[num].inizials;
        break;
    case 3:
        cout << "математики : "; cin >> s[num].math;
        break;
    case 4:
        cout << "фізики : "; cin >> s[num].phsic;
        break;
    case 5:
        cout << "інформатика : "; cin >> s[num].informatic;
        break;
    case 6:
        cout << "історія : "; cin >> s[num].history;
        break;
    case 7:
        cout << "англійська : "; cin >> s[num].english;
        break;
    default:
        cout << "Ви ввели помилкове значення! "
            "Слід ввести число - номер вибраного пункту меню" << endl;
    }
}

Student* Exelent(Student* s, const int N)
{
    Student* I = new Student[N]; // створили масив студентів
    for (int i = 0; i < N; i++)
        if (s[i].math == 5 && s[i].informatic == 5
            && s[i].phsic == 5 && s[i].english == 5
            && s[i].history == 5)//вибираємо відміників
            I[i] = s[i]; // додаємо в масив
    return I;
}

Student* StudentWithOneTree(Student* s, const int N)
{
    Student* I = new Student[N]; // створили масив студентів
    for (int i = 0; i < N; i++)
        if (s[i].math == 3 || s[i].informatic == 3
            || s[i].phsic == 3 || s[i].english == 3
            || s[i].history == 3)//вибираємо тих хто має 3 
            I[i] = s[i]; // додаємо в масив
    return I;
}

Student* OnlyOneTwo(Student* s, const int N)
{

    Student* I = new Student[N]; // створили масив студентів
    for (int i = 0; i < N; i++)
    {
        //оскільки звичайна перевірка за довга 
        //будемо підраховувати кількість двійок через прості перевірки 

        int count = 0;
        if (s[i].math == 2)
            count++;
        if (s[i].informatic == 2)
            count++;
        if (s[i].phsic == 2)
            count++;
        if (s[i].english == 2)
            count++;
        if (s[i].history == 2)
            count++;
        //відбираємо студента в якого ЛИШЕ ОДНА двійка 
        if (count == 1)
            I[i] = s[i]; // додаємо в масив
    }
    return I;
}

void SaveToFile(Student* s, const int N, const char* filename)
{
    ofstream fout(filename, ios::binary); // відкрили бінарний файл запису
    fout.write((char*)&N, sizeof(N)); // записали кількість елементів
    for (int i = 0; i < N; i++)
        fout.write((char*)&s[i], sizeof(Student)); // записали елементи масиву
    fout.close();
}

void LoadFromFile(Student*& s, int& N, const char* filename)
{
    delete[] s; // знищили попередні дані
    ifstream fin(filename, ios::binary); // відкрили бінарний файл зчитування
    fin.read((char*)&N, sizeof(N)); // прочитали кількість елементів
    s = new Student[N]; // створили динамічний масив
    for (int i = 0; i < N; i++)
        fin.read((char*)&s[i], sizeof(Student)); // прочитали елементи масиву
    fin.close();
}
