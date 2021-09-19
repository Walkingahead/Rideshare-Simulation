/**
 * @file simple_parser.cpp
 * @brief Parse location from the command line, or use a default.
 *
 * @copyright Copyright (c) 2021, Michael Virgo, released under the MIT License.
 *
 */

#include "simple_parser.h"

#include <iostream>
#include <string>
#include <unordered_map>

namespace rideshare {

std::unordered_map<std::string, std::string> SimpleParser::ParseArgs(int argc, char *argv[]) {

    // Set to defaults first
    auto settings = SetDefaults();

    // Loop through and parse all valid args
    for (int i = 0; i < argc; ++i) {
        if (argv[i] == std::string("-h")) {
            PrintHelper();
        } else if (argv[i] == std::string("-m")) {
            if (i+1 < argc) {
                settings["map"] = argv[i+1];
            } else {
                MissingArgValue(argv[i]);
            }
        }
    }

    return settings;
}

void SimpleParser::MissingArgValue(std::string arg) {
    std::cout << "Missing value for given arg: " << arg << ", exiting." << std::endl;
    PrintHelper();
}

void SimpleParser::PrintHelper() {
    std::cout << "Rideshare Simulation - Valid Arguments" << std::endl;
    std::cout << "-h : Display this helper text. Program will exit." << std::endl;
    std::cout << "-m : Map data file and image name, in /data dir.  Default: downtown-kc" << std::endl;
    // Do not continue the program
    exit(0);
}

std::unordered_map<std::string, std::string> SimpleParser::SetDefaults() {
    std::unordered_map<std::string, std::string> settings;

    // Place all default values
    settings.emplace("map", DEFAULT_MAP);

    return settings;
}

}  // namespace rideshare
