#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <cryptopp/cryptlib.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h>
#include <cryptopp/pwdbased.h>
#include <cryptopp/filters.h>
#include <cryptopp/modes.h>
#include <cryptopp/osrng.h>
#include <cryptopp/sha.h>
#include <cryptopp/des.h>

using namespace std;
using namespace CryptoPP;

class mod_DES {
    private:
        string FileIn;
        string FileOut;
        string psw;
        string salt = "Harry Potter";

    public:
        mod_DES() = delete;
        mod_DES(const string& Input, const string& Output, const string& Pass);
        bool encrypt ();
        bool decrypt ();
};