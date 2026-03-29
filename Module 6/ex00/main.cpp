#include "ScalarConverter.hpp"
#include <sstream>

static int g_pass = 0;
static int g_fail = 0;

// Captura o output de convert() para uma string
static std::string capture(const std::string &literal)
{
	std::ostringstream oss;
	std::streambuf *old = std::cout.rdbuf(oss.rdbuf());
	ScalarConverter::convert(literal);
	std::cout.rdbuf(old);
	return oss.str();
}

static void test(const std::string &literal, const std::string &expected)
{
	std::string result = capture(literal);
	bool ok = (result == expected);
	if (ok)
		g_pass++;
	else
		g_fail++;

	std::cout << (ok ? "\033[32m[OK] " : "\033[31m[KO] ") << "\033[0m"
			  << "Input: \"" << literal << "\"" << std::endl;
	std::cout << result;
	if (!ok)
	{
		std::cout << "\033[31m  EXPECTED:\033[0m" << std::endl;
		std::cout << expected;
	}
	std::cout << std::endl;
}

static void section(const std::string &title)
{
	std::cout << "============================================" << std::endl;
	std::cout << "  " << title << std::endl;
	std::cout << "============================================" << std::endl;
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		ScalarConverter::convert(argv[1]);
		return 0;
	}

	// =============================================
	section("SUBJECT EXAMPLES");
	// =============================================
	test("0",
		"char: Non displayable\n"
		"int: 0\n"
		"float: 0.0f\n"
		"double: 0.0\n");

	test("nan",
		"char: impossible\n"
		"int: impossible\n"
		"float: nanf\n"
		"double: nan\n");

	test("42.0f",
		"char: '*'\n"
		"int: 42\n"
		"float: 42.0f\n"
		"double: 42.0\n");

	// =============================================
	section("CHAR LITERALS");
	// =============================================
	test("a",
		"char: 'a'\n"
		"int: 97\n"
		"float: 97.0f\n"
		"double: 97.0\n");

	test("z",
		"char: 'z'\n"
		"int: 122\n"
		"float: 122.0f\n"
		"double: 122.0\n");

	test("Z",
		"char: 'Z'\n"
		"int: 90\n"
		"float: 90.0f\n"
		"double: 90.0\n");

	test("*",
		"char: '*'\n"
		"int: 42\n"
		"float: 42.0f\n"
		"double: 42.0\n");

	test("~",
		"char: '~'\n"
		"int: 126\n"
		"float: 126.0f\n"
		"double: 126.0\n");

	test(" ",
		"char: ' '\n"
		"int: 32\n"
		"float: 32.0f\n"
		"double: 32.0\n");

	test("!",
		"char: '!'\n"
		"int: 33\n"
		"float: 33.0f\n"
		"double: 33.0\n");

	// =============================================
	section("INT LITERALS");
	// =============================================
	test("0",
		"char: Non displayable\n"
		"int: 0\n"
		"float: 0.0f\n"
		"double: 0.0\n");

	test("42",
		"char: '*'\n"
		"int: 42\n"
		"float: 42.0f\n"
		"double: 42.0\n");

	test("-42",
		"char: impossible\n"
		"int: -42\n"
		"float: -42.0f\n"
		"double: -42.0\n");

	test("97",
		"char: 'a'\n"
		"int: 97\n"
		"float: 97.0f\n"
		"double: 97.0\n");

	test("127",
		"char: Non displayable\n"
		"int: 127\n"
		"float: 127.0f\n"
		"double: 127.0\n");

	test("128",
		"char: impossible\n"
		"int: 128\n"
		"float: 128.0f\n"
		"double: 128.0\n");

	test("-1",
		"char: impossible\n"
		"int: -1\n"
		"float: -1.0f\n"
		"double: -1.0\n");

	test("2147483647",
		"char: impossible\n"
		"int: 2147483647\n"
		"float: 2147483648.0f\n"
		"double: 2147483647.0\n");

	test("-2147483648",
		"char: impossible\n"
		"int: -2147483648\n"
		"float: -2147483648.0f\n"
		"double: -2147483648.0\n");

	test("2147483648",
		"char: impossible\n"
		"int: impossible\n"
		"float: 2147483648.0f\n"
		"double: 2147483648.0\n");

	test("-2147483649",
		"char: impossible\n"
		"int: impossible\n"
		"float: -2147483648.0f\n"
		"double: -2147483649.0\n");

	// =============================================
	section("FLOAT LITERALS");
	// =============================================
	test("0.0f",
		"char: Non displayable\n"
		"int: 0\n"
		"float: 0.0f\n"
		"double: 0.0\n");

	test("-4.2f",
		"char: impossible\n"
		"int: -4\n"
		"float: -4.2f\n"
		"double: -4.2\n");

	test("4.2f",
		"char: Non displayable\n"
		"int: 4\n"
		"float: 4.2f\n"
		"double: 4.2\n");

	test("42.0f",
		"char: '*'\n"
		"int: 42\n"
		"float: 42.0f\n"
		"double: 42.0\n");

	test("-0.0f",
		"char: Non displayable\n"
		"int: 0\n"
		"float: -0.0f\n"
		"double: -0.0\n");

	test("0.5f",
		"char: Non displayable\n"
		"int: 0\n"
		"float: 0.5f\n"
		"double: 0.5\n");

	// =============================================
	section("DOUBLE LITERALS");
	// =============================================
	test("0.0",
		"char: Non displayable\n"
		"int: 0\n"
		"float: 0.0f\n"
		"double: 0.0\n");

	test("-4.2",
		"char: impossible\n"
		"int: -4\n"
		"float: -4.2f\n"
		"double: -4.2\n");

	test("4.2",
		"char: Non displayable\n"
		"int: 4\n"
		"float: 4.2f\n"
		"double: 4.2\n");

	test("42.0",
		"char: '*'\n"
		"int: 42\n"
		"float: 42.0f\n"
		"double: 42.0\n");

	test("-0.0",
		"char: Non displayable\n"
		"int: 0\n"
		"float: -0.0f\n"
		"double: -0.0\n");

	// =============================================
	section("PSEUDO LITERALS");
	// =============================================
	test("-inff",
		"char: impossible\n"
		"int: impossible\n"
		"float: -inff\n"
		"double: -inf\n");

	test("+inff",
		"char: impossible\n"
		"int: impossible\n"
		"float: +inff\n"
		"double: +inf\n");

	test("nanf",
		"char: impossible\n"
		"int: impossible\n"
		"float: nanf\n"
		"double: nan\n");

	test("-inf",
		"char: impossible\n"
		"int: impossible\n"
		"float: -inff\n"
		"double: -inf\n");

	test("+inf",
		"char: impossible\n"
		"int: impossible\n"
		"float: +inff\n"
		"double: +inf\n");

	test("nan",
		"char: impossible\n"
		"int: impossible\n"
		"float: nanf\n"
		"double: nan\n");

	test("inf",
		"char: impossible\n"
		"int: impossible\n"
		"float: +inff\n"
		"double: +inf\n");

	test("inff",
		"char: impossible\n"
		"int: impossible\n"
		"float: +inff\n"
		"double: +inf\n");

	// =============================================
	section("EDGE CASES / INVALID");
	// =============================================
	test("",
		"char: impossible\n"
		"int: impossible\n"
		"float: impossible\n"
		"double: impossible\n");

	test("hello",
		"char: impossible\n"
		"int: impossible\n"
		"float: impossible\n"
		"double: impossible\n");

	test("42abc",
		"char: impossible\n"
		"int: impossible\n"
		"float: impossible\n"
		"double: impossible\n");

	test("abc42",
		"char: impossible\n"
		"int: impossible\n"
		"float: impossible\n"
		"double: impossible\n");

	test("42.42.42",
		"char: impossible\n"
		"int: impossible\n"
		"float: impossible\n"
		"double: impossible\n");

	test("++42",
		"char: impossible\n"
		"int: impossible\n"
		"float: impossible\n"
		"double: impossible\n");

	test("--42",
		"char: impossible\n"
		"int: impossible\n"
		"float: impossible\n"
		"double: impossible\n");

	test("42ff",
		"char: impossible\n"
		"int: impossible\n"
		"float: impossible\n"
		"double: impossible\n");

	test("f",
		"char: 'f'\n"
		"int: 102\n"
		"float: 102.0f\n"
		"double: 102.0\n");

	test(".",
		"char: '.'\n"
		"int: 46\n"
		"float: 46.0f\n"
		"double: 46.0\n");

	test("+",
		"char: '+'\n"
		"int: 43\n"
		"float: 43.0f\n"
		"double: 43.0\n");

	test("-",
		"char: '-'\n"
		"int: 45\n"
		"float: 45.0f\n"
		"double: 45.0\n");

	// =============================================
	section("NON-DISPLAYABLE BOUNDARIES");
	// =============================================
	test("0",
		"char: Non displayable\n"
		"int: 0\n"
		"float: 0.0f\n"
		"double: 0.0\n");

	test("31",
		"char: Non displayable\n"
		"int: 31\n"
		"float: 31.0f\n"
		"double: 31.0\n");

	test("32",
		"char: ' '\n"
		"int: 32\n"
		"float: 32.0f\n"
		"double: 32.0\n");

	test("126",
		"char: '~'\n"
		"int: 126\n"
		"float: 126.0f\n"
		"double: 126.0\n");

	test("127",
		"char: Non displayable\n"
		"int: 127\n"
		"float: 127.0f\n"
		"double: 127.0\n");

	// =============================================
	// FINAL REPORT
	// =============================================
	int total = g_pass + g_fail;
	std::cout << "============================================" << std::endl;
	std::cout << "  RESULTS: " << g_pass << "/" << total << " passed";
	if (g_fail == 0)
		std::cout << " \033[32m ALL OK! \033[0m" << std::endl;
	else
		std::cout << " \033[31m " << g_fail << " FAILED \033[0m" << std::endl;
	std::cout << "============================================" << std::endl;

	return (g_fail > 0 ? 1 : 0);
}
