# include <iostream>
# include <chrono>
# include <complex>
# include <iomanip>

using namespace std;

# define COUNT 1000


void add_float()
{
	
	//asm("#float");
	auto tm = chrono::high_resolution_clock::now() - chrono::high_resolution_clock::now();
	float a = rand();
	float b = rand();

	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < COUNT; ++i)
		a += b;
	auto end = chrono::high_resolution_clock::now();
	
	cout << "float add time: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() / static_cast<double>(COUNT) << " nanoseconds" << endl << endl;
}

void add_double()
{
	double a = rand();
	double b = rand();
	//asm("#double");
	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < COUNT; ++i)
		a += b;
	auto end = chrono::high_resolution_clock::now();
	cout << "double add time: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() / static_cast<double>(COUNT) << " nanoseconds" << endl << endl;
}
# ifndef MNO
void add_long_double()
{
	long double a = rand();
	long double b = rand();
	//asm("#long double");
	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < COUNT; ++i)
		a += b;
	auto end = chrono::high_resolution_clock::now();
	cout << "long double add time: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() / static_cast<double>(COUNT) << " nanoseconds" << endl << endl;
}
# endif

void mult_float()
{
	float a = 1.5246;
	float b = 2.75;
	//asm("#float");
	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < COUNT; ++i)
		a *= b;
	auto end = chrono::high_resolution_clock::now();
	cout << "float mult time: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() / static_cast<double>(COUNT) << " nanoseconds" << endl << endl;
}

void mult_double()
{
	double a = 1.5246;
	double b = 2.75;
	//asm("#double");
	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < COUNT; ++i)
		a *= b;
	auto end = chrono::high_resolution_clock::now();
	cout << "double mult time: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() / static_cast<double>(COUNT) << " nanoseconds" << endl << endl;
}
# ifndef MNO
void mult_long_double()
{
	long double a = 1.5246;
	long double b = 2.75;
	//asm("#long double");
	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < COUNT; ++i)
		a *= b;
	auto end = chrono::high_resolution_clock::now();
	cout << "long double mult time: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() / static_cast<double>(COUNT) << " nanoseconds" << endl << endl;
}
# endif

// мои функции
# ifndef MNO
void my_add_float()
{
	float a = 1.5246f;
	float b = 2.75f;
	//asm("#float");
	auto start = chrono::high_resolution_clock::now();

	for (int i = 0; i < COUNT; ++i)
	{
		__asm
		{
			fld b
			fld a
			fadd st, st(1)
			fstp a
		};
	}
	auto end = chrono::high_resolution_clock::now();
	cout << "my float add time: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() / static_cast<double>(COUNT) << " nanoseconds" << endl << endl;
}

void my_add_double()
{
	double a = 1.5246;
	double b = 2.75;
	//asm("#double");
	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < COUNT; ++i)
	{
		__asm
		{
			fld b
			fld a
			fadd st, st(1)
			fstp a
		};
	}
	auto end = chrono::high_resolution_clock::now();
	cout << "my double add time: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() / static_cast<double>(COUNT) << " nanoseconds" << endl << endl;
}
# ifndef MNO
void my_add_long_double()
{
	long double a = 1.5246;
	long double b = 2.75;
	//asm("#long double");
	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < COUNT; ++i)
	{
		__asm
		{
			fld b
			fld a
			fadd st, st(1)
			fstp a
		};
	}
	auto end = chrono::high_resolution_clock::now();
	cout << "my long double add time: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() / static_cast<double>(COUNT) << " nanoseconds" << endl << endl;
}
# endif
void my_mult_float()
{
	float a = 1.5246;
	float b = 2.75;
	//asm("#float");
	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < COUNT; ++i)
	{
		__asm
		{
			fld b
			fld a
			fmul st, st(1)
			fstp a
		};
	}
	auto end = chrono::high_resolution_clock::now();
	cout << "my float mult time: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() / static_cast<double>(COUNT) << " nanoseconds" << endl << endl;
}

void my_mult_double()
{
	double a = 1.5246;
	double b = 2.75;
	//asm("#double");
	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < COUNT; ++i)
	{
		__asm
		{
			fld b
			fld a
			fmul st, st(1)
			fstp a
		};
	}
	auto end = chrono::high_resolution_clock::now();
	cout << "my double mult time: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() / static_cast<double>(COUNT) << " nanoseconds" << endl << endl;
}
# endif

# ifndef MNO
void my_mult_long_double()
{
	long double a = 1.5246;
	long double b = 2.75;
	//asm("#long double");
	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < COUNT; ++i)
	{
		__asm
		{
			fld b
			fld a
			fmul st, st(1)
			fstp a
		};
	}
	auto end = chrono::high_resolution_clock::now();
	cout << "my long double mult time: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() / static_cast<double>(COUNT) << " nanoseconds" << endl << endl;
}
# endif

# define PI 3.14

# define MORE_PI 3.141593

int main()
{
	srand(time(0));

	add_float();
	# ifndef MNO
	my_add_float();
	# endif
	cout << endl << endl;
	
	add_double();
	# ifndef MNO
	my_add_double();
	# endif
	cout << endl << endl;
	
	# ifndef MNO
	add_long_double();
	# ifndef MNO
	my_add_long_double();
	# endif
	cout << endl << endl;
	# endif
	
	mult_float();
	# ifndef MNO
	my_mult_float();
	# endif
	cout << endl << endl;
	
	mult_double();
	# ifndef MNO
	my_mult_double();
	# endif
	cout << endl << endl;
	
	# ifndef MNO
	mult_long_double();
	my_mult_long_double();
	# endif

	cout << endl << endl << "SIN:" << endl;


	cout << "PI: " << PI << "\tsin(PI): " << sin(PI);
	double fi1 = PI;
	__asm {
		fld fi1
		fsin
		fstp fi1
	}
	cout << " / " << fi1 << endl;

	cout << "PI: " << MORE_PI << "\tsin(PI): " << sin(MORE_PI);

	double fi2 = MORE_PI;
	__asm {
		fld fi2
		fsin
		fstp fi2
	}
	cout << " / " << fi2 << endl;

	# ifndef MNO
	long double pi = 0;
	__asm {
		fldpi
		fstp pi
	}
	cout << fixed << setprecision(15) << "PI: " << pi << "\tsin(PI): " << sin(pi);

	double fi3 = pi;
	__asm {
		fld fi3
		fsin
		fstp fi3
	}
	cout << " / " << fi3 << endl;

	# endif
	return 0;
}

// ключ -mno-80387 отключает команды работы с сопроцессором FPU
// работа с double и float предпочтительнее на SSE (там быстрее), однако long double работает только на FPU (возможно из-за объёма занимаемой памяти)