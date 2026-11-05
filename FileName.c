#define _USE_MATH_DEFINES
#define M_PI 3.14159265358979323846
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <math.h>
#include <locale.h>

#define ROW 9
#define COL 9
#define N_1 5

int Task1(int r, int c);
int Task1_3(int r, int c);
int Task2(long long num);
char Task3(int r, int c, int side, char sym);
int ClearInput();

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");

    int row, col, result;

    // Task1
    printf("Задание 1\n\n");

    for (row = 1; row <= ROW; row++)
    {
        for (col = 1; col <= COL; col++)
        {
            result = Task1(row, col);
            printf("%5d", result);
        }
        printf("\n");
    }

    // Task1.2
    printf("\nЗадание 1.2\n\n");

    for (row = 1; row <= ROW; row++)
    {
        for (col = 1; col <= row; col++)
        {
            result = Task1(row, col);
            printf("%5d", result);
        }
        printf("\n");
    }

    // Task1.3 (вариант 10)
    printf("\nЗадание 1.3\n\n");

    for (row = 0; row < N_1; row++)
    {
        for (col = 0; col <= row; col++)
        {
            result = Task1_3(row, col);
            printf("%3d", result);
        }
        printf("\n");
    }

    // Task2
    long long number;
    int ok, has_pair;
    char answer;

    printf("\nЗадание 2\n\n");

    do
    {
        printf("Введите длинное целое число: ");
        ok = scanf("%lld", &number);

        if (ok == 1)
        {
            has_pair = Task2(number);

            if (has_pair == 1)
                printf("Результат: В числе ЕСТЬ рядом расположенные одинаковые цифры.\n");
            else
                printf("Результат: В числе НЕТ рядом расположенных одинаковых цифр.\n");
        }
        else if (ok == 0)
            printf("Ошибка ввода! Ожидалось целое число.\n");

        ClearInput();

        if (ok == EOF)
            answer = 'n';
        else
        {
            printf("\nПродолжить? (Да - y, нет - n): ");

            if (scanf(" %c", &answer) != 1)
                answer = 'n';

            ClearInput();
        }
    } while (answer != 'n');

    // Task3 (вариант 10: правильный четырёхугольник, контур, параметр r)
    int r, side;
    char sym, cell;

    printf("\nЗадание 3\n\n");

    do
    {
        printf("Введите символ для рисования контура: ");
        ok = scanf(" %c", &sym);

        if (ok == 1)
        {
            printf("Введите r (количество символов): ");
            ok = scanf("%d", &r);
        }

        if (ok == 1 && r > 0)
        {
            side = 2 * r;

            printf("\nВаша фигура:\n\n");

            for (row = 0; row < side; row++)
            {
                for (col = 0; col < side; col++)
                {
                    cell = Task3(row, col, side, sym);
                    printf("%c", cell);
                }
                printf("\n");
            }
        }
        else if (ok != EOF)
            printf("Ошибка ввода: r должно быть целым числом больше нуля\n");

        ClearInput();

        if (ok == EOF)
            answer = 'n';
        else
        {
            printf("\nПродолжить? (Да - y, нет - n): ");

            if (scanf(" %c", &answer) != 1)
                answer = 'n';

            ClearInput();
        }
    } while (answer != 'n');

    return 0;
}

int Task1(int r, int c)
{
    return r * c;
}

int Task1_3(int r, int c)
{
    if (c == r)
        return 0;
    else if (c % 2 == 0)
        return r;
    else
        return r - c;
}

int Task2(long long num)
{
    int prev_digit = -1;
    int current_digit;

    if (num < 0)
        num = -num;

    while (num > 0)
    {
        current_digit = num % 10;

        if (current_digit == prev_digit)
            return 1;

        prev_digit = current_digit;
        num /= 10;
    }

    return 0;
}

char Task3(int r, int c, int side, char sym)
{
    if (r == 0 || r == side - 1 || c == 0 || c == side - 1)
        return sym;
    else
        return ' ';
}

int ClearInput()
{
    int ch = getchar();

    while (ch != '\n' && ch != EOF)
        ch = getchar();

    return ch;
}