#include "Serializer.hpp"
#include <iostream>

int main(void)
{
    Data original;
	original.id = 1;
    original.name = "test";
    original.age = 42;
	original.balance = 100.00;
	original.email = "helloworld@lol.pt";
	original.phone = "919123456";

    std::cout << "Original ptr:      " << &original << std::endl;

    uintptr_t raw = Serializer::serialize(&original);
    std::cout << "Serialized:        " << raw << std::endl;

    Data *deserialized = Serializer::deserialize(raw);
    std::cout << "Deserialized ptr:  " << deserialized << std::endl;

    if (deserialized == &original) {
        std::cout << "SUCCESS: pointers match!" << std::endl;
	}
    else {
        std::cout << "FAILURE: pointers differ!" << std::endl;
	}

	std::cout << "Id: " << deserialized->id << std::endl;
    std::cout << "Name:  " << deserialized->name << std::endl;
    std::cout << "Age: " << deserialized->age << std::endl;
    std::cout << "Balance: " << deserialized->balance << std::endl;
    std::cout << "Email: " << deserialized->email << std::endl;
    std::cout << "Phone: " << deserialized->phone << std::endl;


    return 0;
}
