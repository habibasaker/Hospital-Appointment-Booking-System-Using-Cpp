#pragma once
#include <string>

class User {
public:
    User(std::string name, int id);
    std::string getName() const;
    int getId() const;

private:
    std::string name;
    int id;
};
