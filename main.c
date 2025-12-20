#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

// --- MACROS FOR COLOR and STYLING ---
#define GRN   "\x1B[32m"
#define RED   "\x1B[31m"
#define YEL   "\x1B[33m"
#define RESET "\x1B[0m"
#define BOLD  "\x1B[1m"

// --- TEST CASE COUNTERS ---
static int g_test_count = 0;
static int g_success_count = 0;

// A simple function to print a header for each test section
void	print_header(char *title)
{
	printf("\n" BOLD YEL "--- %s ---" RESET "\n", title);
}

// The core of the tester: runs a test case and compares the results
void	run_test(int ft_ret, int std_ret)
{
	g_test_count++;
	printf("YOURS : ret = %d\n", ft_ret);
	printf("LIBC  : ret = %d\n", std_ret);
	if (ft_ret == std_ret)
	{
		printf(GRN "[✅ OK]\n" RESET);
		g_success_count++;
	}
	else
	{
		printf(RED "[❌ KO]\n" RESET);
	}
}

int	main(void)
{
	char	*null_str;
	void	*null_ptr;
	int		ft_ret;
	int		std_ret;

	null_str = NULL;
	null_ptr = NULL;
	print_header("Character Specifier (%c)");
	ft_ret = ft_printf("Char: [%c]\n", 'A');
	std_ret = printf("Char: [%c]\n", 'A');
	run_test(ft_ret, std_ret);

	print_header("String Specifier (%s)");
	ft_ret = ft_printf("String: [%s]\n", "Hello, World!");
	std_ret = printf("String: [%s]\n", "Hello, World!");
	run_test(ft_ret, std_ret);
	ft_ret = ft_printf("NULL String: [%s]\n", null_str);
	std_ret = printf("NULL String: [%s]\n", null_str);
	run_test(ft_ret, std_ret);

	print_header("Pointer Specifier (%p)");
	ft_ret = ft_printf("Pointer: [%p]\n", &g_test_count);
	std_ret = printf("Pointer: [%p]\n", &g_test_count);
	run_test(ft_ret, std_ret);
	ft_ret = ft_printf("NULL Pointer: [%p]\n", null_ptr);
	std_ret = printf("NULL Pointer: [%p]\n", null_ptr);
	run_test(ft_ret, std_ret);

	print_header("Decimal/Integer Specifiers (%d, %i)");
	ft_ret = ft_printf("Decimal: [%d]\n", );
	std_ret = printf("Decimal: [%d]\n", "49");
	run_test(ft_ret, std_ret);
	ft_ret = ft_printf("Integer: [%i]\n", -456);
	std_ret = printf("Integer: [%i]\n", -456);
	run_test(ft_ret, std_ret);

	print_header("Unsigned Specifier (%u)");
	ft_ret = ft_printf("Unsigned: [%u]\n", 12345);
	std_ret = printf("Unsigned: [%u]\n", 12345);
	run_test(ft_ret, std_ret);

	print_header("Hexadecimal Specifiers (%x, %X)");
	ft_ret = ft_printf("Hex Lower: [%x]\n", 255);
	std_ret = printf("Hex Lower: [%x]\n", 255);
	run_test(ft_ret, std_ret);
	ft_ret = ft_printf("Hex Upper: [%X]\n", 42);
	std_ret = printf("Hex Upper: [%X]\n", 42);
	run_test(ft_ret, std_ret);

	print_header("Percent Specifier (%%)");
	ft_ret = ft_printf("Percent: [%%]\n");
	std_ret = printf("Percent: [%%]\n");
	run_test(ft_ret, std_ret);

	// --- FINAL SCORE ---
	printf("\n\n" BOLD "--- FINAL RESULTS ---" RESET "\n");
	if (g_success_count == g_test_count)
		printf(GRN "All %d tests passed! Congratulations!\n" RESET, g_test_count);
	else
		printf(RED "%d / %d tests passed.\n" RESET, g_success_count, g_test_count);
	return (0);
}