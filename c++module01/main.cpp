#include <iostream>
#include <string>
#include <fstream>

void fn_filename(const std::string& fn , std::string s1, std::string s2) {
    std::ifstream infile(fn.c_str());
    if (!infile.is_open()) {
        std::cerr << "issue with the filename " << fn << std::endl;
        return ;
    }
    std::ofstream outfile((fn + "./replace").c_str());
    if (!outfile.is_open()) {
        std::cerr << "output file issue"  << std::endl;
    }

}