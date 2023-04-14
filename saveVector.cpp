#include <fstream>

template<typename T>
void saveVectorToFile(const std::string& filename, const std::vector<T>& vec) {
    std::ofstream outfile(filename, std::ios::binary);
    if (!outfile.is_open()) {
        std::cerr << "Error: could not open file " << filename << " for writing\n";
        exit(1);
    }
    size_t size = vec.size();
    outfile.write(reinterpret_cast<const char*>(&size), sizeof(size));
    outfile.write(reinterpret_cast<const char*>(&vec[0]), size * sizeof(T));
    outfile.close();
}


template<typename T>
vector<T> readVectorFromFile(const std::string& filename) {
    std::ifstream infile(filename, std::ios::binary);
    if (!infile.is_open()) {
        std::cerr << "Error: could not open file " << filename << " for reading\n";
        exit(1);
    }

    size_t size;
    infile.read(reinterpret_cast<char*>(&size), sizeof(size));

    std::vector<T> vec(size);
    infile.read(reinterpret_cast<char*>(&vec[0]), size * sizeof(T));

    infile.close();
    return vec;
}

saveVector(costs,"costs.txt");
