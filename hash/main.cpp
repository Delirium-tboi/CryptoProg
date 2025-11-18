#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cryptopp/sha.h>
#include <cryptopp/hex.h>
#include <cryptopp/filters.h>

using namespace CryptoPP;

std::string HashFile(const std::string& filename) {
    SHA256 hash;
    std::string digest;
    
    // Читаем файл вручную
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        throw std::runtime_error("Cannot open file: " + filename);
    }
    
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string content = buffer.str();
    
    // Хэшируем строку
    StringSource(content, true,
        new HashFilter(hash,
            new HexEncoder(
                new StringSink(digest)
            )
        )
    );
    
    return digest;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }
    
    std::string filename = argv[1];
    
    try {
        std::string hash = HashFile(filename);
        std::cout << "SHA-256 Hash: " << hash << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
