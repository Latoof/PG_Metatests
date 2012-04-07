#ifndef H_PRIME_H
	#define H_PRIME_H

	#define IS_PRIME(n) (Prime<n>::val != 0)

	/**** EXO 2 ****/
	/* Implementer un type generique prime pour tester statiquement la primalite d’un entier. */
	/* Code trouve, a comprendre/readapter */

	template <int N, int P>
	struct modulo_t
	{
	    static const int value = N % P;
	};


	template <int N, int P>
	struct divisible_t
	{
	    static const bool value = (modulo_t<N,P>::value == 0);
	};


	template <int N,int P>
	struct try_divide
	{
	    static const bool value = (divisible_t<N,P>::value || try_divide<N,P-1>::value);
	};

	template <int N>
	struct try_divide<N,1>
	{
	    static const bool value = false;
	};


	template <int N,int P>
	struct is_prime_impl
	{
	    static const bool value = !try_divide<N,P>::value;
	};

	template <int N>
	struct Prime
	{
	    static const bool val = is_prime_impl<N,N/2>::value;
	};

#endif