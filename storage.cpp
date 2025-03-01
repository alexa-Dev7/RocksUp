#include "storage.h"
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

std::string readJSONFile(const std::string& filename) {
    std::ifstream file("data/" + filename);
    if (!file) return "{}";
    return std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
}

void writeJSONFile(const std::string& filename, const std::string& content) {
    std::ofstream file("data/" + filename);
    file << content;
}

json loadJSON(const std::string& filename) {
    return json::parse(readJSONFile(filename));
}

void saveJSON(const std::string& filename, const json& data) {
    writeJSONFile(filename, data.dump(4));
}
