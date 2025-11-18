#include "cipher.h"

int main () {
    unsigned op, alg;
    std::string file_in, file_out, key;
    
    do {
        std::cout << "Шифратор запущен. Выберите алгоритм шифрования (0-выход, 2-DES): ";
        std::cin >> alg;
        
        if (alg != 0) {
            std::cout << "Выберите операцию (0-выход, 1-зашифровать, 2-расшифровать): ";
            std::cin >> op;
        }
        
        if (alg > 2 || alg == 1) {
            std::cerr << "Неверный выбор алгоритма" << std::endl;
        }
        else if (alg == 2) {
            std::cout << "Введите путь к входному файлу: ";
            std::cin >> file_in;
            std::cout << "Введите путь к выходному файлу: ";
            std::cin >> file_out;
            std::cout << "Введите ключ: ";
            std::cin >> key;

            mod_DES des(file_in, file_out, key);
            if (op == 1) {
                if (des.encrypt())
                    std::cout << "Шифрование завершено" << std::endl;
                else
                    std::cout << "Сбой шифрования" << std::endl;
            } else if (op == 2) {
                if (des.decrypt())
                    std::cout << "Расшифровка завершена" << std::endl;
                else
                    std::cout << "Сбой расшифровки" << std::endl;
            }
        }
    } while (alg != 0);
    
    return 0;
}
