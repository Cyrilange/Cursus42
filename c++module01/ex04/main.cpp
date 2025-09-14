/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalamit <csalamit@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-14 13:58:30 by csalamit          #+#    #+#             */
/*   Updated: 2025-09-14 13:58:30 by csalamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

std::string replace_fn(std::string file, const std::string& s1, const std::string& s2) {
    std::string result;
    size_t pos = 0;
    size_t len = s1.length();

    while (true) {
        size_t found_pos = file.find(s1, pos);
        if (found_pos == std::string::npos) {
            break; 
        }
        result.append(file, pos, found_pos - pos);
        result.append(s2);
        pos = found_pos + len;
    }
    result.append(file, pos, file.length() - pos);
    return result;
}

void fn_filename(const std::string& fn, const std::string& s1, const std::string& s2) {
    std::string file_content;
    std::string line;
    std::ifstream infile(fn.c_str());


    if (!infile.is_open()) {
        std::cerr << "issue with the file " << fn << std::endl;
        return;
    }

    while (std::getline(infile, line)) {
        file_content += line + "\n";
    }
    infile.close();
    std::string modified_content = replace_fn(file_content, s1, s2);
    std::string output_fn = fn + ".replaced";
    std::ofstream outfile(output_fn.c_str());
    if (!outfile.is_open()) {
        std::cerr << "issue with the output" << std::endl;
        return;
    }
    outfile << modified_content;
    outfile.close();
    std::cout << "file modified in " << output_fn << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cout << "Usage: " << argv[0] << " <file> <string to replace> <new string>" << std::endl;
        return 1;
    }
    fn_filename(argv[1], argv[2], argv[3]);
    return 0;
}
