#include "Serializer.hpp"
#include <iostream>

int main(void)
{
	// =============================================
	// 1. Criar uma ficha de cliente
	// =============================================
	Data client;
	client.id = 1042;
	client.name = "Diogo Ferreira";
	client.email = "diogo.ferreira@email.com";
	client.phone = "+351 912 345 678";
	client.age = 25;
	client.balance = 1547.83;

	std::cout << "============================================" << std::endl;
	std::cout << "  FICHA DE CLIENTE (ORIGINAL)" << std::endl;
	std::cout << "============================================" << std::endl;
	std::cout << "Address:  " << &client << std::endl;
	std::cout << "ID:       " << client.id << std::endl;
	std::cout << "Name:     " << client.name << std::endl;
	std::cout << "Email:    " << client.email << std::endl;
	std::cout << "Phone:    " << client.phone << std::endl;
	std::cout << "Age:      " << client.age << std::endl;
	std::cout << "Balance:  " << client.balance << std::endl;
	std::cout << std::endl;

	// =============================================
	// 2. Serialize: ponteiro → inteiro
	// =============================================
	uintptr_t raw = Serializer::serialize(&client);

	std::cout << "============================================" << std::endl;
	std::cout << "  AFTER SERIALIZE" << std::endl;
	std::cout << "============================================" << std::endl;
	std::cout << "Raw (uintptr_t): " << raw << std::endl;
	std::cout << std::endl;

	// =============================================
	// 3. Deserialize: inteiro → ponteiro
	// =============================================
	Data *result = Serializer::deserialize(raw);

	std::cout << "============================================" << std::endl;
	std::cout << "  FICHA DE CLIENTE (DESERIALIZED)" << std::endl;
	std::cout << "============================================" << std::endl;
	std::cout << "Address:  " << result << std::endl;
	std::cout << "ID:       " << result->id << std::endl;
	std::cout << "Name:     " << result->name << std::endl;
	std::cout << "Email:    " << result->email << std::endl;
	std::cout << "Phone:    " << result->phone << std::endl;
	std::cout << "Age:      " << result->age << std::endl;
	std::cout << "Balance:  " << result->balance << std::endl;
	std::cout << std::endl;

	// =============================================
	// 4. Testes automáticos
	// =============================================
	std::cout << "============================================" << std::endl;
	std::cout << "  TESTS" << std::endl;
	std::cout << "============================================" << std::endl;

	int pass = 0;
	int fail = 0;

	// Ponteiro igual ao original?
	if (result == &client)
	{ std::cout << "\033[32m[OK]\033[0m Pointer matches original" << std::endl; pass++; }
	else
	{ std::cout << "\033[31m[KO]\033[0m Pointer does NOT match" << std::endl; fail++; }

	// Todos os campos intactos?
	if (result->id == 1042)
	{ std::cout << "\033[32m[OK]\033[0m ID is correct (1042)" << std::endl; pass++; }
	else
	{ std::cout << "\033[31m[KO]\033[0m ID is wrong" << std::endl; fail++; }

	if (result->name == "Diogo Ferreira")
	{ std::cout << "\033[32m[OK]\033[0m Name is correct" << std::endl; pass++; }
	else
	{ std::cout << "\033[31m[KO]\033[0m Name is wrong" << std::endl; fail++; }

	if (result->email == "diogo.ferreira@email.com")
	{ std::cout << "\033[32m[OK]\033[0m Email is correct" << std::endl; pass++; }
	else
	{ std::cout << "\033[31m[KO]\033[0m Email is wrong" << std::endl; fail++; }

	if (result->phone == "+351 912 345 678")
	{ std::cout << "\033[32m[OK]\033[0m Phone is correct" << std::endl; pass++; }
	else
	{ std::cout << "\033[31m[KO]\033[0m Phone is wrong" << std::endl; fail++; }

	if (result->age == 25)
	{ std::cout << "\033[32m[OK]\033[0m Age is correct (25)" << std::endl; pass++; }
	else
	{ std::cout << "\033[31m[KO]\033[0m Age is wrong" << std::endl; fail++; }

	if (result->balance == 1547.83)
	{ std::cout << "\033[32m[OK]\033[0m Balance is correct (1547.83)" << std::endl; pass++; }
	else
	{ std::cout << "\033[31m[KO]\033[0m Balance is wrong" << std::endl; fail++; }

	// Modificar via ponteiro desserializado altera o original?
	result->balance = 2000.00;
	if (client.balance == 2000.00)
	{ std::cout << "\033[32m[OK]\033[0m Modifying via deserialized ptr changes original" << std::endl; pass++; }
	else
	{ std::cout << "\033[31m[KO]\033[0m Modification did NOT affect original" << std::endl; fail++; }

	std::cout << std::endl;
	int total = pass + fail;
	std::cout << "RESULTS: " << pass << "/" << total << " passed";
	if (fail == 0)
		std::cout << " \033[32m ALL OK!\033[0m" << std::endl;
	else
		std::cout << " \033[31m " << fail << " FAILED\033[0m" << std::endl;

	return (fail > 0 ? 1 : 0);
}
