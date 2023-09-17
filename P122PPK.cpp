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

    if (extractResult == 0) {
        std::cout << "Extraction of .pem files successful. Your .pem file is saved at: " << pem << std::endl;

        // Command to run PuTTYgen to convert .pem to .ppk
        std::string puttygenCommand = "puttygen \"" + pem + "\" -o \"" + ppk + "\"";

        // Execute the PuTTYgen command
        int puttygenResult = std::system(puttygenCommand.c_str());

        if (puttygenResult == 0) {
            std::cout << "Conversion to .ppk successful. Your .ppk file is saved at: " << ppk << std::endl;
        } else {
            std::cerr << "Conversion to .ppk failed. Please check your inputs and try again." << std::endl;
        }
    } else {
        std::cerr << "Extraction of .pem files failed. Please check your inputs and try again." << std::endl;
    }

    return 0;
}