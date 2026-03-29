#include "Functions.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>

// Captura o output de identify para uma string
static std::string capturePtr(Base *p)
{
	std::ostringstream oss;
	std::streambuf *old = std::cout.rdbuf(oss.rdbuf());
	identify(p);
	std::cout.rdbuf(old);
	return oss.str();
}

static std::string captureRef(Base &p)
{
	std::ostringstream oss;
	std::streambuf *old = std::cout.rdbuf(oss.rdbuf());
	identify(p);
	std::cout.rdbuf(old);
	return oss.str();
}

int main(void)
{
	std::srand(std::time(NULL));

	int pass = 0;
	int fail = 0;

	// =============================================
	// 1. Testes com tipos conhecidos (sabemos o que criámos)
	// =============================================
	std::cout << "============================================" << std::endl;
	std::cout << "  KNOWN TYPE TESTS" << std::endl;
	std::cout << "============================================" << std::endl;

	Base *a = new A();
	Base *b = new B();
	Base *c = new C();

	// Teste identify(Base *p) com tipos conhecidos
	std::string rA = capturePtr(a);
	std::string rB = capturePtr(b);
	std::string rC = capturePtr(c);

	if (rA == "A")
	{ std::cout << "\033[32m[OK]\033[0m identify(A*) = " << rA << std::endl; pass++; }
	else
	{ std::cout << "\033[31m[KO]\033[0m identify(A*) = " << rA << " (expected A)" << std::endl; fail++; }

	if (rB == "B")
	{ std::cout << "\033[32m[OK]\033[0m identify(B*) = " << rB << std::endl; pass++; }
	else
	{ std::cout << "\033[31m[KO]\033[0m identify(B*) = " << rB << " (expected B)" << std::endl; fail++; }

	if (rC == "C")
	{ std::cout << "\033[32m[OK]\033[0m identify(C*) = " << rC << std::endl; pass++; }
	else
	{ std::cout << "\033[31m[KO]\033[0m identify(C*) = " << rC << " (expected C)" << std::endl; fail++; }

	// Teste identify(Base &p) com tipos conhecidos
	std::string rrA = captureRef(*a);
	std::string rrB = captureRef(*b);
	std::string rrC = captureRef(*c);

	if (rrA == "A")
	{ std::cout << "\033[32m[OK]\033[0m identify(A&) = " << rrA << std::endl; pass++; }
	else
	{ std::cout << "\033[31m[KO]\033[0m identify(A&) = " << rrA << " (expected A)" << std::endl; fail++; }

	if (rrB == "B")
	{ std::cout << "\033[32m[OK]\033[0m identify(B&) = " << rrB << std::endl; pass++; }
	else
	{ std::cout << "\033[31m[KO]\033[0m identify(B&) = " << rrB << " (expected B)" << std::endl; fail++; }

	if (rrC == "C")
	{ std::cout << "\033[32m[OK]\033[0m identify(C&) = " << rrC << std::endl; pass++; }
	else
	{ std::cout << "\033[31m[KO]\033[0m identify(C&) = " << rrC << " (expected C)" << std::endl; fail++; }

	delete a;
	delete b;
	delete c;

	// =============================================
	// 2. Testes com generate() — tipo aleatório
	//    Verificamos que ptr e ref dão o mesmo resultado
	// =============================================
	std::cout << std::endl;
	std::cout << "============================================" << std::endl;
	std::cout << "  RANDOM GENERATE TESTS (20 rounds)" << std::endl;
	std::cout << "============================================" << std::endl;

	for (int i = 0; i < 20; i++)
	{
		Base *obj = generate();
		std::string byPtr = capturePtr(obj);
		std::string byRef = captureRef(*obj);

		bool valid = (byPtr == "A" || byPtr == "B" || byPtr == "C");
		bool match = (byPtr == byRef);

		if (valid && match)
		{
			std::cout << "\033[32m[OK]\033[0m Round " << (i + 1)
					  << ": ptr=" << byPtr << "  ref=" << byRef << std::endl;
			pass++;
		}
		else
		{
			std::cout << "\033[31m[KO]\033[0m Round " << (i + 1)
					  << ": ptr=" << byPtr << "  ref=" << byRef << std::endl;
			fail++;
		}
		delete obj;
	}

	// =============================================
	// 3. Relatório final
	// =============================================
	std::cout << std::endl;
	int total = pass + fail;
	std::cout << "============================================" << std::endl;
	std::cout << "  RESULTS: " << pass << "/" << total << " passed";
	if (fail == 0)
		std::cout << " \033[32m ALL OK!\033[0m" << std::endl;
	else
		std::cout << " \033[31m " << fail << " FAILED\033[0m" << std::endl;
	std::cout << "============================================" << std::endl;

	return (fail > 0 ? 1 : 0);
}
