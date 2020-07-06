#include "../common.hpp"

Cassette::Cassette(const char* _file_name) {
    this->file_name = _file_name;
    FILE* fp = fopen(this->file_name, "rb");
    if(fp == NULL) {
        std::cout << "Cannot read specified nes file\n";
        return;
    }

    if(fread(content, sizeof(content[0]), sizeof(content), fp) < sizeof(content)) {
        std::cout << "Cannot read specified nes file\n";
        return;
    }

    if(fclose(fp) == EOF ) {
        std::cout << "Cannot close fp";
        return;
    }
}

void Cassette::copy_to_ram(RAM* ram) {
    memcpy(&ram->memory[0x8000], this->content, sizeof(0x4000));
}