#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <stdint.h>

struct Data {
    int			id;
	std::string	name;
	std::string	email;
	std::string	phone;
	int			age;
	double		balance;
};

class Serializer {
    private:
        Serializer();
        Serializer(const Serializer &other);
        Serializer &operator=(const Serializer &other);
        ~Serializer();
    
    public:
        static uintptr_t serialize(Data *ptr);
        static Data *deserialize(uintptr_t value);
};

#endif