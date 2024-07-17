#include <iostream>
#include <cstdlib>
#include <filesystem>
#include <sys/stat.h>
#include <string>

int main(int argc, char** argv) {
    if (argc == 1) {
        std::cout << "Error!\nYou should enter type of affine transformation:\n";
        std::cout << "T - for translation, R - for rotation\n";
        return 0;
    }
    char affine_mode = argv[1][0];
    char buffer[1024];
    char concat_buffer[1024];
    int dataset_size;
    if (affine_mode == 'T') {
        if (argc < 5) {
            std::cout << "Error!\nTranslation parameters (x, y, z) are not passed!\nYou should enter x, y, z\n";
            return 0;
        }
        std::filesystem::create_directory("translations");
        int x = atoi(argv[2]);
        int y = atoi(argv[3]);
        int z = atoi(argv[4]);

        std::cout << "Generating object...\n";
        snprintf(buffer, sizeof(buffer), "python3 ../prj.cw/sift3d/translator_volume.py %d %d %d", x, y, z);
        system(buffer);
    }
    else if (affine_mode == 'R') {
        if (argc < 3) {
            std::cout << "Error!\nX axis degree rotation parameter is not passed!\nYou should enter deg\n";
            return 0;
        }
        std::filesystem::create_directory("rotations");
        int deg = atoi(argv[2]);

        std::cout << "Generating object...\n";
        snprintf(buffer, sizeof(buffer), "python3 ../prj.cw/sift3d/rotator_volume.py %d", deg);
        system(buffer);
    }
    else {
        std::cout << "Incorrect input\n";
    }
    return 0;
}