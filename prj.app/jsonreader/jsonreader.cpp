#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <chrono>
#include <filesystem>

#define chunk_size 108

using json = nlohmann::json;

using cl = std::chrono::high_resolution_clock;
using ns = std::chrono::nanoseconds;

class sax_event_consumer : public json::json_sax_t {
  public:
    std::vector<std::string> events;

    bool null() override { return true; }
    bool boolean(bool val) override { return true; }
    bool number_integer(number_integer_t val) override { return true; }
    bool number_float(number_float_t val, const string_t& s) override { return true; }
    bool parse_error(std::size_t position, const std::string& last_token, 
    const json::exception& ex) override { return false; }

    bool number_unsigned(number_unsigned_t val) override {
        events.push_back("number_unsigned: val=" + std::to_string(val));
        return true;
    }

    bool string(string_t& val) override {
        events.push_back("string: val=" + val);
        return true;
    }

    bool start_object(std::size_t elements) override {
        events.push_back("{");
        return true;
    }

    bool end_object() override {
        events.push_back("}");
        return true;
    }

    bool start_array(std::size_t elements) override {
        events.push_back("[\nelements=" + std::to_string(elements));
        return true;
    }

    bool end_array() override {
        events.push_back("]");
        return true;
    }

    bool key(string_t& val) override {
        events.push_back("key: val=" + val);
        return true;
    }
};

void DomProfiler(const std::string& path) {
    auto start = cl::now(); 
    std::fstream file(path);
    json j = json::parse(file);
    for (auto& it : j) {
        std::string user = it["user"];
        std::string question = it["question"];
        int score = it["score"];
    }
    file.close();
    auto end = cl::now(); 
    std::cout << "DOM-Parser from library takes " << std::chrono::duration_cast<ns>(end 
     - start).count() * 1e-9 << " sec" << std::endl; 
}

void SaxProfiler(const std::string& path) {
    auto start = cl::now(); 
    std::fstream file(path);
    sax_event_consumer sec;
    bool result = json::sax_parse(file, &sec);
    bool curr_event_is_user = true;
    for (auto& event : sec.events) {
        if (event[0] == 'k') {
            if (event[8] == 'u') { curr_event_is_user = true; }
            else { curr_event_is_user = false; }
        }
        if (event[0] == 's') {
            if (curr_event_is_user) { std::string user = event.substr(12); }
            else { std::string question = event.substr(12); }
        } 
        if (event[0] == 'n') { int score = event[21] - '0'; }
    }
    file.close();
    auto end = cl::now(); 
    std::cout << "SAX-Parser from library takes " << std::chrono::duration_cast<ns>(end 
     - start).count() * 1e-9 << " sec" << std::endl; 
}

void ChunksProfiler(const std::string& path) {
    auto start = cl::now(); 
    std::fstream file(path);
    file.seekg(1);
    char* buffer = new char[chunk_size];
    char* user = new char[36];
    char* question = new char[36];
    int score;
    while (buffer[chunk_size - 1] != ']') {
        file.read(buffer, chunk_size);
        strncpy(user, buffer + 9, 36);
        strncpy(question, buffer + 59, 36);
        score = buffer[105] - '0';
    }
    delete [] buffer, user, question;
    file.close();
    auto end = cl::now(); 
    std::cout << "Reading file by chunks takes " << std::chrono::duration_cast<ns>(end 
    - start).count() * 1e-9 << " sec" << std::endl;
}

void StringProfiler(const std::string& path) {
    auto start = cl::now(); 
    std::fstream file(path);
    std::string s;
    file >> s;
    std::string object;
    for (int i = 1; object[chunk_size - 1] != ']'; i += chunk_size) {
        object = s.substr(i, chunk_size);
        std::string user = object.substr(9, 36);
        std::string question = object.substr(59, 36);
        int score = object[105] - '0';
    }
    file.close();
    auto end = cl::now(); 
    std::cout << "Reading from string takes " << std::chrono::duration_cast<ns>(end 
     - start).count() * 1e-9 << " sec" << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Not enough arguments...\nPath to file should be in arguments!" << std::endl;
        std::cout << "Example: ./jsonreader ../jsondata/data-small.json" << std::endl;
        exit(1);
    }
    std::string path = argv[1];
    DomProfiler(path);
    SaxProfiler(path);
    ChunksProfiler(path);
    StringProfiler(path);
    return 0;
}