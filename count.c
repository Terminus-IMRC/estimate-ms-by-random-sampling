#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gmp.h>
#include "X.h"

mpz_t count_right, count_all;
static mpz_t X2_f;
static char *X2_f_str;
static mpf_t X2_f_mpf;
static int log2_X2_f, log10_X2_f;
static mpf_t estimated_ms_count;
static char *count_right_str, *count_all_str;
static int count_str_size;
static mpf_t count_right_mpf, count_all_mpf;

void count_init()
{
	mpz_init(X2_f);
	mpz_fac_ui(X2_f, X*X);
	X2_f_str=mpz_get_str(NULL, 10, X2_f);

	log2_X2_f=mpz_sizeinbase(X2_f, 2);
	log10_X2_f=mpz_sizeinbase(X2_f, 10);

	mpf_init2(X2_f_mpf, log2_X2_f+16);
	mpf_set_str(X2_f_mpf, X2_f_str, 10);

	mpz_init2(count_right, log2_X2_f);
	mpz_init2(count_all, log2_X2_f);

	count_str_size=0xffff;
	count_right_str=(char*)malloc(count_str_size*sizeof(char));
	if(count_right_str==NULL){
		fprintf(stderr, "%s:%d: error: failed to allocate count_right_str\n", __FILE__, __LINE__);
		exit(EXIT_FAILURE);
	}
	count_all_str=(char*)malloc(count_str_size*sizeof(char));
	if(count_all_str==NULL){
		fprintf(stderr, "%s:%d: error: failed to allocate count_all_str\n", __FILE__, __LINE__);
		exit(EXIT_FAILURE);
	}

	mpf_init2(count_right_mpf, log2_X2_f+16);
	mpf_init2(count_all_mpf, log2_X2_f+16);

	mpf_init2(estimated_ms_count, log2_X2_f+16);

	return;
}

void estimate_ms_count()
{
	count_right_str=mpz_get_str(count_right_str, 10, count_right);
	count_all_str=mpz_get_str(count_all_str, 10, count_all);

	mpf_set_str(count_right_mpf, count_right_str, 10);
	mpf_set_str(count_all_mpf, count_all_str, 10);

	mpf_div(estimated_ms_count, count_right_mpf, count_all_mpf);
	mpf_mul(estimated_ms_count, estimated_ms_count, X2_f_mpf);

	return;
}

char* get_estimated_ms_count_str()
{
	char *s, *s_orig;
	char *s2, *s2_orig;
	mp_exp_t e;
	int slen;

	s=mpf_get_str(NULL, &e, 10, log10_X2_f, estimated_ms_count);
	s_orig=s;
	slen=strlen(s);

	if(e>0){
		_Bool pad_0s;

		if(e>=slen){
			pad_0s=!0;
			/* '\0' plus '0's */
			s2=(char*)malloc((e+1)*sizeof(char));
		}else{
			pad_0s=0;
			/* '\0' plus '.' */
			s2=(char*)malloc((slen+2)*sizeof(char));
		}
		if(s2==NULL){
			fprintf(stderr, "%s:%d: error: failed to allocate s2\n", __FILE__, __LINE__);
			exit(EXIT_FAILURE);
		}
		s2_orig=s2;

		if(pad_0s){
			strncpy(s2, s, slen);
			s2+=slen;
			for(e-=slen; e>0; e--)
				*s2++='0';
		}else{
			for(; e>0; e--)
				*s2++=*s++;
			*s2++='.';
			while((*s2++=*s++))
				;
		}
	}else{
		/* '\0' plus "0." and '0's */
		s2=(char*)malloc((slen+3+(-e))*sizeof(char));
		if(s2==NULL){
			fprintf(stderr, "%s:%d: error: failed to allocate s2\n", __FILE__, __LINE__);
			exit(EXIT_FAILURE);
		}
		s2_orig=s2;

		*s2++='0';
		*s2++='.';
		for(; e<0; e++)
			*s2++='0';
		while((*s2++=*s++))
			;
	}

	free(s_orig);

	return s2_orig;
}

char* get_incremental_count_str(mpz_t count)
{
	char *s;

	s=mpz_get_str(NULL, 10, count);

	return s;
}
