#include <iostream>
#include <cstdlib>
#include <filesystem>
#include <sys/stat.h>
#include <string>

int main() {
    // std::cout << "Please, enter your operational system\n";
    // std::cout << "L - for Linux, W - for Windows\n";
    char os = 'L'; 
    // std::cin >> os;
    std::cout << "Please, enter type of affine transformation: \n";
    std::cout << "T - for translation, R - for rotation\n";
    char affine_mode = 'T';
    std::cin >> affine_mode;
    char buffer[1024];
    int dataset_size;
    if (affine_mode == 'T') {
        std::filesystem::create_directory("translations");
        //mkdir("translations", 0777); // not sure it will work for Windows
        int x, y, z;
        std::cout << "Enter x, y, z:\n";
        std::cin >> x >> y >> z;

        snprintf(buffer, sizeof(buffer), "python3 ../prj.cw/sift3d/translator.py %d %d %d", x, y, z);
        system(buffer);
    }
    else if (affine_mode == 'R') {
        std::filesystem::create_directory("translations");
        // mkdir("rotations", 0777);
        // std::cout << "Enter amount of NIFTI files you want to generate:\n";
        // std::cin >> dataset_size;

        int deg;
        std::cout << "Enter degree for x axis rotation:\n";
        std::cin >> deg;
        snprintf(buffer, sizeof(buffer), "python3 ../prj.cw/sift3d/rotator.py %d", deg);
        system(buffer);
    }
    else {
        std::cout << "Incorrect input\n";
    }
    return 0;
}