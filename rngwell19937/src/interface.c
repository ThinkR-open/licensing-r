#include "R.h"
#include <R_ext/Random.h>

#define m1   4294949027.0
#define m2   4294934327.0
extern double  s10, s11, s12, s13, s14, s20, s21, s22, s23, s24;
unsigned int MRG32k5a ();

void InitWELLRNG19937a ();
extern unsigned int (*WELLRNG19937a) (void);
void select_case();

#define R19937a   624
static unsigned int random_seed[1+R19937a]; // for interface to R
static int seedlength[1] = {1+R19937a};     // for interface to R
unsigned int *rstate_i = random_seed;  // used in WELLRNG19937a()
unsigned int *STATE = random_seed+1;   // used in WELLRNG19937a()
unsigned int check_state_i;  // detect user modification of .Random.seed

#define bin32m 2.3283064365386962891e-10 // 2^(-32)
#define bin33m 1.1641532182693481445e-10 // 2^(-33)
#define bin53m 1.1102230246251565404e-16 // 2^(-53)
#define bin54m 5.5511151231257827021e-17 // 2^(-54)

double x;

void get_rand_32(void)
{
	x = WELLRNG19937a() * bin32m;
	if (x == 0) {
		x = bin33m;
	}
}

void get_rand_53(void)
{
	x = (double) (WELLRNG19937a() >> 6);
	x = (134217728.0 * x + (double) (WELLRNG19937a() >> 5)) * bin53m;
	if (x == 0) {
		x = bin54m;
	}
}

static void (*get_rand) (void) = get_rand_53;

void set_resolution(int *r)
{
	if (*r) {
		get_rand = get_rand_53;
	} else {
		get_rand = get_rand_32;
	}
}

double *user_unif_rand(void)
{
	if (random_seed[0] != check_state_i) {
		select_case();
	}
	get_rand();
	check_state_i = random_seed[0];
	return(&x);
}

void init_mrg32k5a(int n, unsigned int *seed)
{
	int i,j;
	unsigned int l16, h16;
	s10 = 12345.0;
	s11 = 12345.0;
	s12 = 12345.0;
	s13 = 12345.0;
	s14 = 12345.0;
	s20 = 12345.0;
	s21 = 12345.0;
	s22 = 12345.0;
	s23 = 12345.0;
	s24 = 12345.0;
	for (i=0; i < n; i++) {
		l16 = seed[i] & 0x0000ffff;
		h16 = seed[i] >> 16;
		s14 += (double) h16 + 1.0;
		s24 += (double) h16 + 1.0;
		if (s14 >= m1) { s14 -= m1; }
		if (s24 >= m2) { s24 -= m2; }
		for (j=0; j<5; j++) MRG32k5a();
		s14 += (double) l16 + 1.0;
		s24 += (double) l16 + 1.0;
		if (s14 >= m1) { s14 -= m1; }
		if (s24 >= m2) { s24 -= m2; }
		for (j=0; j<5; j++) MRG32k5a();
	}
	for (i = 0; i < R19937a; i++) {
		STATE[i] = (MRG32k5a() & 0x0000ffff);
		STATE[i] = (STATE[i] << 16) | (MRG32k5a() & 0x0000ffff);
	}
	InitWELLRNG19937a();
}

void init_vector_mrg32k5a(int *n, double *seed, unsigned int *iseed, unsigned int *state)
{
	int i;
	for (i=0; i < *n; i++) {
		iseed[i] = (unsigned int) seed[i];
	}
	init_mrg32k5a(*n, iseed);
	for (i=0; i < 625; i++) {
		state[i] = random_seed[i];
	}
}

void user_unif_init_mrg32k5a(unsigned int seed)
{
	init_mrg32k5a(1, &seed);
}

void user_unif_init_sfmt(unsigned int seed)
{
	int i;
	STATE[0] = seed;
	for (i = 1; i < R19937a; i++) 
		STATE[i] = 1812433253UL * ( STATE[i - 1] ^ ( STATE[i - 1] >> 30 ) ) + i;
	InitWELLRNG19937a();
}

static void (*user_unif_init_selected) (unsigned int seed) = user_unif_init_mrg32k5a;

void set_initialization(int *initialization)
{
	if (*initialization) {
		user_unif_init_selected = user_unif_init_mrg32k5a;
	} else {
		user_unif_init_selected = user_unif_init_sfmt;
	}
}

void user_unif_init(unsigned int seed)
{
	seed = 3602842457U * seed + 105890386U; // undo initial scrambling
	user_unif_init_selected(seed);
	check_state_i = random_seed[0];
}

int *user_unif_nseed(void)
{
	return (seedlength);
}

int *user_unif_seedloc(void)
{
	return ((int *) random_seed);
}

