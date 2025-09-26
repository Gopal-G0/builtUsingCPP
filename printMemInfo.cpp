#include<iostream>
#include<fstream>
#include<string>

int main() {

    std::ifstream file("/proc/meminfo");

    if(!file) {

        std:: cerr << "Failed to open /proc/meminfo";
        return 1;
    }

    std::string key;
    long value;
    std::string unit;

    std::cout << "\n" << "<------------------- RAM Memory Stats ------------------->" << "\n\n";

    double totalMemInGB;
    double FreeMemInGB;
    double CachedMemInGB;
    double AvailableMemInGB;
    double usedMemInGB;


    while(file >> key >> value >> unit) {

        unit = " GB";

        if(key == "MemTotal:") totalMemInGB = value / (1024.0 * 1024.0);

        else if(key == "MemFree:") FreeMemInGB = value / (1024.0 * 1024.0);

        else if(key == "Cached:") CachedMemInGB = value / (1024.0 * 1024.0);

        else if(key == "MemAvailable:") AvailableMemInGB = value / (1024.0 * 1024.0);

        usedMemInGB = totalMemInGB - AvailableMemInGB;

    }

    double usedMemPercent = (usedMemInGB / totalMemInGB) * 100;
    double AvailableMemPercent = (AvailableMemInGB / totalMemInGB) * 100;
    double FreeMemPercent = (FreeMemInGB / totalMemInGB) * 100;
    double CachedMemPercent = (CachedMemInGB / totalMemInGB) * 100;

    std::cout << "Total Memory: " << totalMemInGB << unit << "\n\n";

    std::cout << "Used Memory: " << usedMemInGB << unit << "\n";
    std::cout << usedMemPercent << "%" << " Of Total Memory" << "\n\n";

    std::cout << "Available Memory: " << AvailableMemInGB << unit << "\n";
    std::cout << AvailableMemPercent << "%" << " Of Total Memory" << "\n\n";

    std::cout << "Free Memory: " << FreeMemInGB << unit << "\n";
    std::cout << FreeMemPercent << "%" << " Of Total Memory" << "\n\n";
    
    std::cout << "Cached Memory: " << CachedMemInGB << unit << "\n";
    std::cout << CachedMemPercent << "%" << " Of Total Memory" << "\n\n";

    std::cout <<"\n";

    return 0;
}