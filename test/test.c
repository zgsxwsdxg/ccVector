#include <stdio.h>

#include <ccVector/ccVector.h>

#define PI 3.141592f

int main(int argc, char **argv) {
	ccvVec2 vec0, vec1, vec2;
	ccvMat2x2 mat0, mat1, mat2;

	float r = PI / 4;

	vec0[0] = 1;
	vec0[1] = 0;

	ccvVec2Normalize(vec0);
	
	printf("(%f, %f)\n", vec0[0], vec0[1]);

	mat1[0][0] = cosf(r);
	mat1[1][0] = -sinf(r);
	mat1[0][1] = sinf(r);
	mat1[1][1] = cosf(r);

	// mat2 will scale rotation matrix mat0

	ccvMat2x2Identity(mat2);
	ccvMat2x2MultiplyScalar(mat2, 3.f);

	ccvMat2x2MultiplyMatrix(mat0, mat1, mat2);

	// print scaled rotation matrix mat2

	printf("\n");
	for(int col = 0; col < 2; col++) {
		for(int row = 0; row < 2; row++) {
			printf("%f\t", mat0[row][col]);
		}
		printf("\n");
	}
	printf("\n");

	// apply rotation matrix mat0 to vec0

	ccvMat2x2MultiplyVector(vec1, mat0, vec0);

	printf("(%f, %f)\n", vec1[0], vec1[1]);

	vec2[0] = -1;
	vec2[1] = -0.1f;
	ccvVec2Normalize(vec2);

	ccvVec2Reflect(vec0, vec2, vec1);

	printf("(%f, %f)\n", vec0[0], vec0[1]);

	getchar();

	return 0;
}