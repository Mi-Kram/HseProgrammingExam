/*
В социальной сети Footprint грянули перемены — её основатель Иван Умнов
объявил цифры вне закона! Теперь любой пользователь, использующий цифры
в своих сообщениях, получает пожизненный бан в сети.

Для Вовы Footprint — это не просто очередная социальная сеть. Здесь он
общается со своей подругой Ариной.

Вова настолько увлёкся процессом сочинения письма, что забыл про запрет
на использование цифр в сообщениях в Footprint. К сожалению, убрать все
цифры из своего сообщения он не может, ведь от этого изменится смысл
послания. Но и лишиться доступа в социальную сеть Вова тоже не хочет,
ведь ему еще нужно получить ответ от Арины.

Как истинный программист, Вова придумал выход из этой очень непростой ситуации:
он решил заменить все цифры на соответствующие им названия на английском языке:

0 - zero
1 - one
2 - two
3 - three
4 - four
5 - five
6 - six
7 - seven
8 - eight
9 - nine

При этом Вова не нарушает никаких правил Footprint и не изменяет смысл сообщения для Арины.

Вова не очень хорошо знает английский, поэтому просит вас помочь ему заменить
все цифры в сообщении на их названия на английском языке.

Формат ввода
В единственной строке введена строка S — сообщение Вовы для Арины.
В строке могут встречаться любые символы с ASCII-кодами от 32 до 126.
Длина строки не превосходит 4×10^6


Формат вывода
Выведите измененное сообщение Вовы, в котором каждая цифра
заменена наеё название на английском языке.
*/

#include <iostream>
#include <sstream>

int main() {
  std::string s;
  std::getline(std::cin, s);

  std::ostringstream os;

  for (char ch : s) {
    switch (ch) {
      case '0': os << "zero"; break;
      case '1': os << "one"; break;
      case '2': os << "two"; break;
      case '3': os << "three"; break;
      case '4': os << "four"; break;
      case '5': os << "five"; break;
      case '6': os << "six"; break;
      case '7': os << "seven"; break;
      case '8': os << "eight"; break;
      case '9': os << "nine"; break;
      default: os << ch; break;
    }
  }

  std::cout << os.str() << '\n';

  return 0;
}
