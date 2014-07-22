/******************************************************************************
 *   OpenMP Example - Combined Parallel Loop Reduction - C/C++ Version
 *   This example demonstrates a sum reduction within a combined parallel loop
 *   construct.  Notice that default data element scoping is assumed - there
 *   are no clauses specifying shared or private variables.  OpenMP will
 *   automatically make loop index variables private within team threads, and
 *   global variables shared.
 ******************************************************************************/

#include "Config.h"

#if (COMBINED_PARALLEL_LOOP_REDUCTION > 0)
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int i, n;
	float a[100], b[100], sum;

	/* Some initializations */
	n = 100;
	for (i = 0; i < n; i++)
	a[i] = b[i] = i * 1.0;
	sum = 0.0;

#pragma omp parallel for reduction(+:sum)
	for (i = 0; i < n; i++)
	sum = sum + (a[i] * b[i]);

	printf("   Sum = %f\n", sum);

}
#endif
