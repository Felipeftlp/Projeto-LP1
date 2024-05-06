#include <iostream>
#include <map>

int main() {
    std::multimap<int, std::string> myMultimap;

    // Inserindo elementos
    myMultimap.insert(std::make_pair(1, "um"));
    myMultimap.insert(std::make_pair(2, "dois"));
    myMultimap.insert(std::make_pair(1, "primeiro"));
    myMultimap.insert(std::make_pair(3, "três"));
    myMultimap.insert(std::make_pair(2, "segundo"));
    myMultimap.insert(std::make_pair(2, "mais dois"));
    myMultimap.insert(std::make_pair(2, "outro"));

    // Percorrendo e exibindo elementos
    std::cout << "Multimap antes da exclusão:\n";
    for (const auto& pair : myMultimap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }


    auto it = myMultimap.find(2);
    while (it != myMultimap.upper_bound(2)) {
        if (it->first == 2) {
            it = myMultimap.erase(it);
        } else {
            ++it;
        }
    }
    
    // Exibindo o multimap após a exclusão
    std::cout << "\nMultimap após a exclusão:\n";
    for (const auto& pair : myMultimap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
