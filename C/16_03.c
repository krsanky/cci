#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * Given 2 segments ([start-point, end-point]),
 * where do they intersect if at all?
 */

/*
https://www.youtube.com/watch?v=4bIsntTiKfM
slope = (y2 - y1) / (x2 - x1) 
*/

struct point {
	double 		x;
	double 		y;
};

struct segment {
	struct point 	a;
	struct point 	b;
};

void
print_segment(struct segment * s)
{
	printf("segment: A(%.2lf %.2lf) B(%.2lf %.2lf)\n", s->a.x, s->a.y, s->b.x, s->b.y);
}

struct segment *
scan_new_segment()
{
	struct segment *s = NULL;
	assert((s = malloc(sizeof(struct segment))) != NULL);

	printf("input point one; eg: 23.2 -0.5 :\n");
	scanf("%lf %lf", &(s->a.x), &(s->a.y));

	printf("input point two; eg: 23.2 -0.5 :\n");
	scanf("%lf %lf", &(s->b.x), &(s->b.y));

	print_segment(s);
	return s;
}

int
main(void)
{
	printf("16_03\n");
	struct segment *s;

	s = scan_new_segment();

	free(s);
	return EXIT_SUCCESS;
}
