#include <iostream>
#include <cmath>

int main() 
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Проверка Великой теоремы Ферма" << std::endl;
    std::cout << "Ищем контрпримеры: a^n + b^n = c^n при n > 2" << std::endl;
    std::cout << "Диапазон проверки: a, b, c от 1 до 10" << std::endl;
    std::cout << "Степени: n = 3 и 4" << std::endl << std::endl;

    bool found = false;
    int combinations = 0;

    for (int a = 1; a <= 10; a++) {
        for (int b = 1; b <= 10; b++) {
            for (int c = 1; c <= 10; c++) {
                for (int n = 3; n <= 4; n++) {
                    combinations++;

                    double left = pow(a, n) + pow(b, n);
                    double right = pow(c, n);

                    if (fabs(left - right) < 0.001) {
                        std::cout << "НАЙДЕН КОНТРПРИМЕР!" << std::endl;
                        std::cout << "   " << a << "^" << n << " + "
                            << b << "^" << n << " = "
                            << c << "^" << n << std::endl;
                        std::cout << "   " << left << " ≈ "
                            << right << std::endl << std::endl;
                        found = true;
                    }
                }
            }
        }
    }


    std::cout << "РЕЗУЛЬТАТЫ ПРОВЕРКИ:" << std::endl;
    std::cout << "Проверено комбинаций: " << combinations << std::endl;

    if (!found)
    {
        std::cout << "Контрпримеров не найдено!" << std::endl;
        std::cout << "Теорема Ферма выполняется для проверенного диапазона." << std::endl;
    }
    else 
    {
        std::cout << "Обнаружены контрпримеры!" << std::endl;
        std::cout << "Требуется дополнительная проверка." << std::endl;
    }
}