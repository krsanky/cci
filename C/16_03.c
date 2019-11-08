#include <stdio.h>
#include <stdlib.h>

/*
 * Given 2 segments ([start-point, end-point]),
 * where do they intersect if at all?
 */

int
main(void)
{
	double	s1p1, s1p2;
	double	s2p1, s2p2;

	printf("16_03...\n");

	/*
	scanf("%d", &nconv);
	scanf("%lf %c", &val, &unit);
	*/
	printf("input segment one ( eg: 23.2 -0.5 ):\n");
	scanf("%lf %lf", &s1p1, &s1p2);
	printf("segment one [ %lf, %lf ]\n", s1p1, s1p2);
	printf("input segment two ( eg: 23.2 -0.5 ):\n");
	scanf("%lf %lf", &s2p1, &s2p2);
	printf("segment two [ %lf, %lf ]\n", s2p1, s2p2);

	return EXIT_SUCCESS;
}
