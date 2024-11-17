#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	const char	*resultat;

	resultat = NULL;
	while (*s)
	{
		if (*s == (char)c)
			resultat = s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return ((char *)resultat);
}

#include <stdio.h>
#include <string.h>

void test_strrchr(const char *str, int c)
{
	char *res1 = ft_strrchr(str, c);
	char *res2 = strrchr(str, c);

	printf("\nTest avec '%s' et c=%d (0x%x):\n", str, c, c);
	printf("ft_strrchr: %s\n", res1 ? res1 : "NULL");
	printf("strrchr:    %s\n", res2 ? res2 : "NULL");
	
	if (res1 == res2)
		printf("OK: Les résultats sont identiques\n");
	else
		printf("ERREUR: Les résultats diffèrent!\n");
}

int main()
{
    test_strrchr(" sss 0 sss 0 sss", 0);
    return 0;
}