# include <iostream>
# include <chrono>

# define PRINT

# define N 3

# define COUNT 1000

using namespace std;


float scalar_mult(float *vector_1, float *vector_2, int length)
{
	float result = 0;
	auto start = chrono::high_resolution_clock::now();
	int i;
	for (int t = 0; t < COUNT; ++t)
	{
		result = 0;
		for (i = 0; i < N; ++i)
			result += vector_1[i] * vector_2[i];
	}
	auto end = chrono::high_resolution_clock::now();
	cout << "C/C++ scalar mult: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() / static_cast<float>(COUNT) << " nanoseconds" << endl;
	return result;
}

float my_scalar_mult(float *vector_1, float *vector_2, int length)
{
	float result = 0;
	auto start = chrono::high_resolution_clock::now();
	int i;
	for (int t = 0; t < COUNT; ++t)
	{
		result = 0;
		__asm
		{
			push edi;
			push esi;
			mov edi, vector_1;
			mov esi, vector_2;
			movss xmm1, result;
			mov i, 0;
			cmp i, N;
			jge end_for_i;
		for_i:
			movss xmm0, [edi];
			mulss xmm0, [esi];
			addss xmm1, xmm0;
			inc i;
			add edi, 4;
			add esi, 4;
			cmp i, N;
			jl for_i
		end_for_i:
			movss result, xmm1;
			pop esi;
			pop edi;
		}
	}
	auto end = chrono::high_resolution_clock::now();
	cout << "Assembler scalar mult: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() / static_cast<float>(COUNT) << " nanoseconds" << endl;
	return result;
}

void fill_vector(float *vector, int length)
{
	for (int i = 0; i < N; ++i)
	{
		vector[i] = (float)rand() / RAND_MAX * 5;
# ifdef PRINT
		cout << vector[i] << " ";
# endif
	}
# ifdef PRINT
	cout << endl;
# endif
}

int main()
{
	float a[N], b[N];

# ifdef PRINT
	cout << "Vectors:" << endl;
#endif

	fill_vector(a, N);
	fill_vector(b, N);

# ifdef PRINT
	cout << endl;
#endif

	float cpp_result = scalar_mult(a, b, N);
	float asm_result = my_scalar_mult(a, b, N);

# ifdef PRINT
	cout << endl;
	cout << "C/C++ result: " << cpp_result << endl << "Assembler result: " << asm_result << endl;;
# endif


	// float a = 20.5;
	// float b = 21.4;
	// float c = 0;
	// __asm
	// {
	// 	movss xmm0, a;
	// 	addss xmm0, b; 
	// 	movss xmm1, c;
	// 	addss xmm1, xmm0;
	// 	movss c, xmm1;
	// }
	// cout << c;

	return 0;
}