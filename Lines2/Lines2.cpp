/*
Задание 1. Дополните свою библиотеку функций реализациями нижеследующих функций:
■ int mystrcmp (const char * str1, const char * str2); —
функция сравнивает две строки, и , если строки равны
возвращает 0, если первая строка больше второй, то
возвращает 1, иначе –1.
■ int StringToNumber(char * str); — функция конвертирует строку в число и возвращает это число.
■ char * NumberToString (int number); — функция конвертирует число в строку и возвращает указатель на
эту строку.
■ char * Uppercase (char * str1); — функция преобразует
строку в верхний регистр.
■ char * Lowercase (char * str1); — функция преобразует
строку в нижний регистр.
■ char * mystrrev (char * str); — функция реверсирует
строку и возвращает указатель на новую строку.
*/

#include <iostream>

using namespace std;

void printMassiv(char const* massiv, int massivSize);
int mystrcmp(char const* str1, char const* str2); //-функция сравнивает две строки, и, 
//если строки равны возвращает 0, если первая строка больше второй, то возвращает 1, иначе - 1.
int stringToNumber(char const* str); //-функция конвертирует строку в число и возвращает это число.
char* numberToString(int number); //-функция конвертирует число в строку и возвращает указатель на эту строку.
char* upperCase(char* str1); //-функция преобразует строку в верхний регистр.
char* lowerCase(char* str1); //-функция преобразует строку в нижний регистр.
char* mystrrev(char* str); //-функция реверсирует строку и возвращает указатель на новую строку.


int main()
{
    setlocale(LC_ALL, "Rus");
    int const massivSize = 11;
    char const str1[massivSize] = { 'z', 'a', 'd', 'a', 'c', 'h', 'a', '1', '2', '3' };
    char const str2[massivSize] = { 'z', 'a', 'd', 'a', 'c', 'h', 'a', '1', '3', '3' }; // 2 и 3 массив одинаковы для проверки функции сравнения
    char const str3[massivSize] = { 'z', 'a', 'd', 'a', 'c', 'h', 'a', '1', '3', '3' };
    cout << "Массив1: ";
    printMassiv(str1, massivSize);
    cout << "Массив2: ";
    printMassiv(str2, massivSize);
    cout << "Массив3: ";
    printMassiv(str3, massivSize);
    //-функция сравнивает две строки
    cout << "Результат сравнения массивов 1 и 2 = " << mystrcmp(str1, str2) << endl;
    cout << "Результат сравнения массивов 2 и 3 = " << mystrcmp(str2, str3) << endl;
    //-функция конвертирует строку в число и возвращает это число.
    char const str4[massivSize] = "1234565432";
    cout << "Массив в строку = ";
    printMassiv(str4, massivSize);
    cout << "Массив в число = " << stringToNumber(str4) << endl;
    //-функция конвертирует число в строку и возвращает указатель на эту строку.
    int number = 151515;
    cout << "Значение в число = " << number << endl <<
        "Значение в строку = " << numberToString(number) << endl;
    //-функция преобразует строку в верхний регистр.
    char str5[massivSize] = "zadachaA1a";
    cout << "Оригинал = " << str5 << endl <<
        "Вверхний регистр = " << upperCase(str5) << endl;
    //-функция преобразует строку в нижний регистр.
    char str6[massivSize] = "ZADACHAb1b";
    cout << "Оригинал = " << str6 << endl <<
        "Нижний регистр = " << lowerCase(str6) << endl;
    //-функция реверсирует строку и возвращает указатель на новую строку.
    cout << "Оригинал = " << str6 << endl <<
        "В обратку = " << mystrrev(str6) << endl;

}

void printMassiv(char const* massiv, int massivSize)
{
    for (int i = 0; i < massivSize; i++)
    {
        cout << massiv[i];
    }
    cout << endl;
}
int mystrcmp(char const* str1, char const* str2)
{
    int result = 0;
    for (int i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
    {
        if ((int)str1[i] > (int)str2[i])
        {
            result = 1;
            break;
        }
        else if ((int)str1[i] < (int)str2[i])
        {
            result = -1;
            break;
        }
    }
    return result;
}
int stringToNumber(char const* str)
{
    int result = 0;
    int number;
    for (int i = 0; str[i] != '\0'; i++)
    {
        number = str[i];
        if (number >= 48 || number <= 57)
        {
            result = result * 10 + (number - 48);
        }
    }
    return result;
}
char* numberToString(int number)
{
    int numberCount = 0;
    int number1 = number;
    do
    {
        number1 /= 10;
        numberCount++;
    } while (number1 % 10 != 0);
    cout << "Количество = " << numberCount << endl;
    char* stringNumber = new char[numberCount + 1];
    stringNumber[numberCount] = '\0';
    for (int i = numberCount - 1; i >= 0; i--)
    {
        stringNumber[i] = (char)(48 + number % 10);
        number /= 10;
    }
    return stringNumber;
    delete[] stringNumber;
}
char* upperCase(char* str1)
{
    int length = strlen(str1);
    char* bigLettersStr = new char[length + 1];
    bigLettersStr[length] = '\0';
    for (int i = 0; str1[i] != '\0'; i++)
    {
        if ((int)str1[i] >= 97 && (int)str1[i] <= 122)
        {
            bigLettersStr[i] = (char)((int)str1[i] - 32);
        }
        else
        {
            bigLettersStr[i] = str1[i];
        }
    }
    return bigLettersStr;
    delete[] bigLettersStr;
}
char* lowerCase(char* str1)
{
    int length = strlen(str1);
    char* smallLettersStr = new char[length + 1];
    smallLettersStr[length] = '\0';
    for (int i = 0; str1[i] != '\0'; i++)
    {
        if ((int)str1[i] >= 65 && (int)str1[i] <= 90)
        {
            smallLettersStr[i] = (char)((int)str1[i] + 32);
        }
        else
        {
            smallLettersStr[i] = str1[i];
        }
    }
    return smallLettersStr;
    delete[] smallLettersStr;
}
char* mystrrev(char* str)
{
    int length = strlen(str);
    char* reverseStr = new char[length + 1];
    reverseStr[length] = '\0';
    for (int i = 0; str[i] != '\0'; i++)
    {
        reverseStr[length - 1 - i] = str[i];
    }
    return reverseStr;
    delete[] reverseStr;
}