#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include <sequence/sequence.h>

using namespace sequence;
using namespace std;

const int MENU_FIRST_LEVEL_SIZE = 3;
const int MENU_SECOND_LEVEL_SIZE = 4;
const int MENU_REPLACE = 3;

const char* menu_first_level[MENU_FIRST_LEVEL_SIZE] = {
    "Взоимодействие с массивом",
    "Получить результат",
    "Выход",
};

const char* menu_second_level[MENU_SECOND_LEVEL_SIZE] = {
    "Добавить запись по указанному индексу",
    "Удалить текущую запись",
    "Изменить текущую запись",
    "Назад",
};

const char* menu_replace_arithmetic[MENU_REPLACE] = {
    "Первый член прогрессии: ",
    "Шаг прогрессии: ",
    "Назад",
};

const char* menu_replace_geometric[MENU_REPLACE] = {
    "Первый член прогрессии: ",
    "Знаменатель прогрессии: ",
    "Назад",
};

//Функции для работы с консолью
void clear_console() {
    COORD topLeft = { 0, 0 };
    DWORD written;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
    FillConsoleOutputAttribute(console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE, screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
    SetConsoleCursorPosition(console, topLeft);
}

void clear_current_line() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    if (GetConsoleScreenBufferInfo(console, &csbi)) {
        DWORD written;
        COORD cursor_pos;
        cursor_pos.X = 0;
        cursor_pos.Y = csbi.dwCursorPosition.Y;
        FillConsoleOutputCharacter(console, ' ', csbi.dwSize.X - csbi.dwCursorPosition.X, cursor_pos, &written);
        SetConsoleCursorPosition(console, cursor_pos);
    }
}

// Функции для работы с меню
void main_draw_menu(const char** menu_items, int menu_size, int current_menu_item, SequanceContainer& arr, int current_item, int arr_size) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
    cout << "Меню\n";
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);

    if (menu_size == 4 && arr_size > 0) { cout << arr[current_item]; }
    for (int i = 0; i < menu_size; i++) {
        if (i == current_menu_item) {
            cout << "> ";
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            cout << menu_items[current_menu_item] << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
        }
        else {
            cout << "  " << menu_items[i] << endl;
        }
    }
}

int main_menu_logic(const char** menu_items, int menu_size, SequanceContainer& arr, int current_item, int arr_size) {
    int current_menu_item = 0;
    while (true) {
        clear_console();
        main_draw_menu(menu_items, menu_size, current_menu_item, arr, current_item, arr_size);
        switch (_getch()) {
        case 72: current_menu_item--; if (current_menu_item < 0) { current_menu_item = menu_size - 1; } break;
        case 80: current_menu_item++; if (current_menu_item >= menu_size) { current_menu_item = 0; } break;
        case 75: return 'l'; break;
        case 77: return 'r'; break;
        case 13: return current_menu_item;
        }
    }
}

void draw_menu(const char** menu_items, int menu_size, int current_menu_item, SequanceContainer& arr, int current_item) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
    cout << "Дополнительное Меню\n Тип: ";
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    cout << (arr[current_item]->get_type() == 0 ? "ARITHMETIC" : "GEOMETRIC") << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    for (int i = 0; i < menu_size; i++) {
        if (i == current_menu_item) {
            cout << "> ";
            cout << menu_items[i];
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            auto seq = arr[current_item];
            auto arith_seq = dynamic_cast<ArithmeticSequance*>(seq.get());
            auto geom_seq = dynamic_cast<GeometricSequance*>(seq.get());
            if (arith_seq != nullptr) {
                switch (i) {
                    case 0: cout << arith_seq->get_first_number_progression() << endl; break;
                    case 1: cout << arith_seq->get_step_progression() << endl; break;
                }
            }
            else if (geom_seq != nullptr) {
                switch (i) {
                    case 0: cout << geom_seq->get_first_number_progression() << endl; break;
                    case 1: cout << geom_seq->get_denominator_progression() << endl; break;
                }
            }
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
        }
        else {
            cout << "  ";
            cout << menu_items[i];
            auto seq = arr[current_item];
            auto arith_seq = dynamic_cast<ArithmeticSequance*>(seq.get());
            auto geom_seq = dynamic_cast<GeometricSequance*>(seq.get());
            if (arith_seq != nullptr) {
                switch (i) {
                    case 0: cout << arith_seq->get_first_number_progression() << endl; break;
                    case 1: cout << arith_seq->get_step_progression() << endl; break;
                }
            }
            else if (geom_seq != nullptr) {
                switch (i) {
                    case 0: cout << geom_seq->get_first_number_progression() << endl; break;
                    case 1: cout << geom_seq->get_denominator_progression() << endl; break;
                }
            }
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
        }
    }
}

int menu_logic(const char** menu_items, int menu_size, SequanceContainer& arr, int current_item) {
    int current_menu_item = 0;
    while (true) {
        clear_console();
        draw_menu(menu_items, menu_size, current_menu_item, arr, current_item);
        switch (getch()) {
        case 72: current_menu_item--; if (current_menu_item < 0) { current_menu_item = menu_size - 1; } break;
        case 80: current_menu_item++; if (current_menu_item >= menu_size) { current_menu_item = 0; } break;
        case 13: return current_menu_item;
        }
    }
}

//Вспомогательные функции для работы с дынными
int input_index(int arr_size) {
    bool flag = true;
    int index = 0;

    cout << "Для выхода в главное меню нажмите Esc, для продолжения, нажмите любую другую клавишу: " << endl;
    if (getch() == 27) { return -1; }

    while (flag) {
        cout << "Введите индекс: ";
        cin >> index;

        if (cin.fail() || index < 0 || index >= arr_size + 1) {
            cin.clear();
            clear_console();
            cout << "Неверный индекс или ввод!" << endl;
        }
        else {
            flag = false;
        }
    }
    return index;
}

//Функции меню первого уровня
void find_max_index(SequanceContainer& arr) {
    clear_console();
    if (arr.size() == 0) {
        cout << "Возникла ошибка, проверьте заполнен ли массив с данными" << endl;
    }
    else {
        int n;
        cout << "Введите n: ";
        cin >> n;

        int index = max_summ_nth_elem(arr, n);
        if (index != -1) { cout << "Последней последовательностью с максимальной суммой первых n элементов, при n = " << n << " является - " << "[" << index << "]" << endl; cout << arr[index]; }
        else { cout << "Возникла ошибка, проверьте заполнен ли массив с данными" << endl; }
        getch();
    }
}

//Функции меню второго 
void add_newSequence(SequanceContainer& arr) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    string menu_type[] = { "ARITHMETIC", "GEOMETRIC" };

    int current_menu_item = 0;
    int choose = 0;
    bool flag = true;

    int index = input_index(arr.size());

    while (flag) {
        clear_console();
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
        cout << "Меню выбора\n";
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
        for (int i = 0; i < 2; i++) {
            if (i == current_menu_item) {
                cout << "> ";
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            }
            else {
                cout << "  ";
            }
            cout << menu_type[i] << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
        }
        switch (getch()) {
        case 72: current_menu_item--; if (current_menu_item < 0) { current_menu_item = 2 - 1; } break;
        case 80: current_menu_item++; if (current_menu_item >= 2) { current_menu_item = 0; } break;
        case 13: flag = false; choose = current_menu_item; break;
        }
    }
    clear_console();
    if (choose == 0) {
        double num1 = 0, num2 = 0;
        cout << "Выбранный тип: ARITHMETIC" << endl;
        bool flag_cin = true;
        while (flag_cin) {
            cout << "Введите первый член прогрессии: ";
            cin >> num1;
            if (cin.fail() || num1 < 0) {
                cin.clear();
                cout << "Неверный ввод!" << endl;
            }
            else {
                flag_cin = false;
            }
        }
        bool flag_cin2 = true;
        while (flag_cin2) {
            cout << "Введите шаг прогрессии: ";
            cin >> num2;
            if (cin.fail() || num2 < 0) {
                cin.clear();
                cout << "Неверный ввод!" << endl;
            }
            else {
                flag_cin2 = false;
            }
        }
        if (index != -1) { arr.insert(make_shared<ArithmeticSequance>(num1, num2)); }
    }
    else {
        double num1, num2 = 0;
        cout << "Выбранный тип: GEOMETRIC" << endl;
        bool flag_cin = true;
        while (flag_cin) {
            cout << "Введите первый член прогрессии: ";
            cin >> num1;
            if (cin.fail() || num1 < 0) {
                cin.clear();
                cout << "Неверный ввод!" << endl;
            }
            else {
                flag_cin = false;
            }
        }
        bool flag_cin2 = true;
        while (flag_cin2) {
            cout << "Введите знаменатель прогрессии: ";
            cin >> num2;
            if (cin.fail() || num2 < 0) {
                cin.clear();
                cout << "Неверный ввод!" << endl;
            }
            else {
                flag_cin2 = false;
            }
        }
        if (index != -1) { arr.insert(make_shared<GeometricSequance>(num1, num2)); }
    }
}

void del_itemSequence(SequanceContainer& arr, int index) {
    if (index >= 0) { arr.remove(index); }
}

void replace_currentSequance(SequanceContainer& arr, int current_item, int arr_size) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int current_menu_item = 0;
    int choose = 0;
    bool flag = true;
    bool exit_replace = false;

    while (!exit_replace) {
        SequancePtr current_sequence = arr[current_item];

        if (auto arithmetic_sequence = std::dynamic_pointer_cast<ArithmeticSequance>(current_sequence)) {
            int menu_item = menu_logic(menu_replace_arithmetic, MENU_REPLACE, arr, current_item);
            cout << endl;

            switch (menu_item) {
                case 0:
                    arithmetic_sequence = std::dynamic_pointer_cast<ArithmeticSequance>(current_sequence);
                    cout << "Введите новое значение для первого члена прогрессии: ";
                    double new_value_num1;
                    cin >> new_value_num1;
                    arithmetic_sequence->set_first_number_progression(new_value_num1);
                    break;

                case 1:
                    arithmetic_sequence = std::dynamic_pointer_cast<ArithmeticSequance>(current_sequence);
                    cout << "Введите новое значение для шага прогрессии: ";
                    double new_value_num2;
                    cin >> new_value_num2;
                    arithmetic_sequence->set_step_progression(new_value_num2);
                    break;

                case 2:
                    exit_replace = true;
                    break;
            }

        }
        else if (auto geometric_sequence = std::dynamic_pointer_cast<GeometricSequance>(current_sequence)) {
            int menu_item = menu_logic(menu_replace_geometric, MENU_REPLACE, arr, current_item);
            cout << endl;
            switch (menu_item) {
                case 0:
                    geometric_sequence = std::dynamic_pointer_cast<GeometricSequance>(current_sequence);
                    cout << "Введите новое значение для первого члена прогрессии: ";
                    double new_value_num1;
                    cin >> new_value_num1;
                    geometric_sequence->set_first_number_progression(new_value_num1);
                    break;
                case 1:
                    geometric_sequence = std::dynamic_pointer_cast<GeometricSequance>(current_sequence);
                    cout << "Введите новое значение для знаменателя прогрессии: ";
                    double new_value_num4;
                    cin >> new_value_num4;
                    geometric_sequence->set_denominator_progression(new_value_num4);
                    break;
                case 2:
                    exit_replace = true;
                    break;
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    SequanceContainer arr;
    int arr_size = 0;
    int current_item = 0;
    bool exit_program = false;
    bool exit_second_level = false;

    while (!exit_program) {
        int menu_item = main_menu_logic(menu_first_level, MENU_FIRST_LEVEL_SIZE, arr, current_item, arr.size());
        switch (menu_item) {
        case 0:
            clear_console();
            exit_second_level = false;
            while (!exit_second_level) {
                int menu_item = main_menu_logic(menu_second_level, MENU_SECOND_LEVEL_SIZE, arr, current_item, arr.size());
                switch (menu_item) {
                case 'l': if (current_item > 0) { current_item--; } break;
                case 'r': if (current_item < arr.size() - 1) { current_item++; } break;
                case 0:   clear_console(); add_newSequence(arr); break;
                case 1:   if (arr.size() > 0) { if (current_item >= 0) { del_itemSequence(arr, current_item); } if (arr.size() > 0) { current_item--; } }
                          else { cout << "Ошибка проверьте заполнен ли массив с данными"; } break;
                case 2:   if (arr.size() > 0) { clear_console(); replace_currentSequance(arr, current_item, arr.size()); }
                          else { break; }
                case 3:   exit_second_level = true;  break;
                }
            }
            clear_console();
            break;
        case 1:
            clear_console();
            cout << "Для выхода в главное меню нажмите Esc, для продолжения, нажмите любую другую клавишу: " << endl;
            if (getch() == 27) { break; }
            else { find_max_index(arr); }
            break;
        case 2:
            exit_program = true;
            break;
        }
    }
}