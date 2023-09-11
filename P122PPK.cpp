#include <iostream>
#include <cstdlib>
#include <string>

int main()
{
    std::string p12;
    std::string pem;
    std::string ppk;
    std::string password;

    std::cout << "Enter the .p12 directory: ";
    std::cin >> p12;
    std::cout << "Enter the .pem output directory: ";
    std::cin >> pem;
    std::cout << "Enter the .ppk output directory: ";
    std::cin >> ppk;
    std::cout << "Enter your .p12 password: ";
    std::cin >> password;

    std::string extractPem = "openssl pkcs12 -in \"" + p12 + "\" -clcerts -nokeys -out \"" + pem + "\" -passin pass:" + password;

    int extractResult=std::system(extractPem.c_str());
}