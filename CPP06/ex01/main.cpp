#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>
#include <iomanip>

void printDataInfo(const Data* ptr, const std::string& name)
{
    if (ptr) {
        std::cout << "[" << name << " Info]" << std::endl;
        std::cout << "  Address: 0x" << std::hex << reinterpret_cast<uintptr_t>(ptr) << std::dec << std::endl;
        std::cout << "  ID: " << ptr->id << ", Content: " << ptr->content << std::endl;
    } else {
        std::cout << "[" << name << " Info] NULL" << std::endl;
    }
}

int main()
{
    Data original_data(42, "Module 06 Serialization Test", 10.5f);
    Data* original_ptr = &original_data;

    std::cout << "--- BASLANGIC ---" << std::endl;
    printDataInfo(original_ptr, "Original Pointer");

    std::cout << "\n--- SERILESTIRME ---" << std::endl;
    uintptr_t raw_address = Serializer::serialize(original_ptr);

    std::cout << "Raw Address (uintptr_t): 0x" << std::hex << raw_address << std::dec << std::endl;

    std::cout << "\n--- DESERILESTIRME ---" << std::endl;
    Data* deserialized_ptr = Serializer::deserialize(raw_address);
    printDataInfo(deserialized_ptr, "Deserialized Pointer");

    std::cout << "\n--- KONTROL ---" << std::endl;
    if (original_ptr == deserialized_ptr) {
        std::cout << "SUCCESS: Orijinal adres ve Deserileştirilen adres ESIT!" << std::endl;
        std::cout << "reinterpret_cast, bellek adresini hatasiz tasimistir." << std::endl;
    } else {
        std::cerr << "FAILURE: Adresler esit degil. Veri butunlugu bozuldu." << std::endl;
    }

    return 0;
}