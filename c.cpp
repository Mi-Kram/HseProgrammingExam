/*
Петя очень любит шоколад. И Маша очень любит шоколад. Недавно Петя купил
шоколадку и теперь хочет поделиться ею с Машей. Шоколадка представляет
собой прямоугольник n×m, который полностью состоит из маленьких шоколадных
долек — прямоугольников 2×1.

Петя делит шоколадку на две части, разламывая её вдоль некоторой прямой,
параллельной одному из краев шоколадки. Ни Петя, ни Маша не любят ломаные
дольки, поэтому Петя хочет разломать шоколадку так, чтобы ни одна долька
не была повреждена.

Помогите Пете поделиться шоколадкой с Машей.

Формат ввода
В первой строке входного файла два целых числа n и m (1 ≤ n,m ≤ 20);
хотя бы одно из чисел n и m — четно). Далее следуют n строк по m чисел
в каждой — номера долек, в которые входят соответствующие кусочки шоколадки.
Дольки имеют номера от 1 до n×m/2, и никакие две дольки не имеют одинаковых номеров.

Формат вывода
В выходной файл выведите ”Yes”, если Петя может разломать шоколадку,
не повредив дольки.Иначе выведите ”No”.

Пример
Ввод
2 3
1 1 2
3 3 2

Вывод
Yes
*/

#include <iostream>

bool canSplit(int** arr, int n, int m);

// time: O(n+m)
int main() {
  int n, m;
  std::cin >> n >> m;

  // Входные данные.
  int** arr = new int*[n];
  for (int i = 0; i < n; ++i) {
    arr[i] = new int[m];
    for (int j = 0; j < m; ++j) {
      std::cin >> arr[i][j];
    }
  }
  
  std::cout << (canSplit(arr, n, m) ? "YES" : "NO") << '\n';

  // Освобождение ресурсов.
  for (int i = 0; i < n; ++i) {
    delete[] arr[i];
  }
  delete[] arr;

  return 0;
}

bool canSplit(int** arr, int n, int m) {
  // Проверка деление шоколадки по горизонтали.
  for (int i = 1; i < n; ++i) {
    bool flag = true;  // флаг: можно ли поделить шоколадку.

    for (int j = 0; j < m; ++j) {
      // Если одна плитка лежит в двух строках, то деление невозможно.
      if (arr[i][j] == arr[i-1][j]) {
        flag = false;
        break;
      }
    }
    if (flag) return true;
  }
  
  // Проверка деление шоколадки по вертикали.
  for (int j = 1; j < m; ++j) {
    bool flag = true;  // флаг: можно ли поделить шоколадку.

    // Если одна плитка лежит в двух столбцах, то деление невозможно.
    for (int i = 0; i < n; ++i) {
      if (arr[i][j] == arr[i][j-1]) {
        flag = false;
        break;
      }
    }
    if (flag) return true;
  }
  
  return false;
}
