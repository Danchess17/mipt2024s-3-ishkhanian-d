#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <chrono>

#define chunk_size 108

using json = nlohmann::json;

using cl = std::chrono::high_resolution_clock;
using ns = std::chrono::nanoseconds;

class sax_event_consumer : public json::json_sax_t {
  public:
    std::vector<std::string> events;

    bool null() override {
        events.push_back("\tnull()");
        return true;
    }

    bool boolean(bool val) override {
        events.push_back("\tboolean(val=" + std::string(val ? "true" : "false") + ")");
        return true;
    }

    bool number_integer(number_integer_t val) override {
        events.push_back("\tnumber_integer(val=" + std::to_string(val) + ")");
        return true;
    }

    bool number_unsigned(number_unsigned_t val) override {
        events.push_back("\tnumber_unsigned(val=" + std::to_string(val) + ")");
        return true;
    }

    bool number_float(number_float_t val, const string_t& s) override {
        events.push_back("\tnumber_float(val=" + std::to_string(val) + ", s=" + s + ")");
        return true;
    }

    bool string(string_t& val) override {
        events.push_back("\tstring(val=" + val + ")");
        return true;
    }

    bool start_object(std::size_t elements) override {
        events.push_back("{\n\telements=" + std::to_string(elements));
        return true;
    }

    bool end_object() override {
        events.push_back("}\n");
        return true;
    }

    bool start_array(std::size_t elements) override {
        events.push_back("[\nelements=" + std::to_string(elements));
        return true;
    }

    bool end_array() override {
        events.push_back("]\n");
        return true;
    }

    bool key(string_t& val) override {
        events.push_back("\tkey(val=" + val + ")");
        return true;
    }

    bool parse_error(std::size_t position, 
                     const std::string& last_token, const json::exception& ex) override {
        events.push_back("\tparse_error(position=" 
        + std::to_string(position) + ", last_token=" + last_token + ",\n            ex=" + std::string(ex.what()) + ")");
        return false;
    }
};


void DomProfiler(const std::string& path) {
    auto start = cl::now(); 
    std::fstream file(path);
    json j = json::parse(file);
    file.close();
    auto end = cl::now(); 
    std::cout << "DOM-Parser from library takes " << std::chrono::duration_cast<ns>(end 
     - start).count() * 1e-9 << " sec" << std::endl;    
    //std::cout << j.dump(1);
}

void SaxProfiler(const std::string& path) {
    auto start = cl::now(); 
    std::fstream file(path);
    sax_event_consumer sec;
    bool result = json::sax_parse(file, &sec);
    file.close();
    auto end = cl::now(); 
    std::cout << "SAX-Parser from library takes " << std::chrono::duration_cast<ns>(end 
     - start).count() * 1e-9 << " sec" << std::endl; 
    // for (auto& event : sec.events) {
    //     std::cout << event << std::endl; 
    // }
    // std::cout << "\nresult: " << std::boolalpha << result << std::endl; 
}

void ChunksProfiler(const std::string& path) {
    auto start = cl::now(); 
    std::fstream file(path);
    file.seekg(1);
    char* buffer = new char[chunk_size];
    while (buffer[chunk_size - 1] != ']') {
        file.read(buffer, chunk_size);
        //std::cout << buffer << std::endl;
    }
    delete [] buffer;
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
    int i = 1;
    while (s.substr(i, chunk_size)[chunk_size - 1] != ']') {
        i += chunk_size;
    }
    file.close();
    auto end = cl::now(); 
    std::cout << "Reading from string takes " << std::chrono::duration_cast<ns>(end 
     - start).count() * 1e-9 << " sec" << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Not enough arguments...\nPath to file should be in arguments!" << std::endl;
        std::cout << "Example: ./jsonreader ../../jsondata/data-small.json" << std::endl;
        exit(1);
    }

    std::string path = argv[1];
    DomProfiler(path);
    SaxProfiler(path);
    ChunksProfiler(path);
    StringProfiler(path);
    return 0;
}