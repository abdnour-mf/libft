#include "libft.h"
size_t ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}


// #include <stdio.h>
// #include <string.h> // To compare with the real strlen


/* int	main(void)
{
	const char *test_strings[] = {
		"Hello, World!",
		"42",
		"",
		"Lorem ipsum dolor sit amet, consectetur adipiscing elit.",
		"Tab\tNewline\nCharacter",
		"1234567890"
	};
	int num_tests = sizeof(test_strings) / sizeof(test_strings[0]);
	int failed = 0;

	printf("=== RUNNING TESTS FOR ft_strlen ===\n");
	for (int i = 0; i < num_tests; i++)
	{
		const char *s = test_strings[i];
		size_t mine = ft_strlen(s);
		size_t real = strlen(s);

		if (mine != real)
		{
			printf("❌ FAILED for string: \"%s\" | Yours: %zu | Real: %zu\n", s, mine, real);
			failed++;
		}
		else
		{
			printf("✅ PASSED for string: \"%s\" (Length: %zu)\n", s, mine);
		}
	}

	if (failed == 0)
		printf("\n🎉 ALL ft_strlen TESTS PASSED SUCCESSFULLY!\n");
	else
		printf("\n⚠️  %d TEST(S) FAILED.\n", failed);
		
	return (0);
} */