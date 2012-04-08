#ifndef H_PRIME_H
	#define H_PRIME_H

	#define IS_PRIME(n) (Prime<n>::val != 0)

	/**** EXO 2 ****/
	/* Implementer un type generique prime pour tester statiquement la primalite d’un entier. */
	/* Code trouve, a comprendre/readapter */

	/*** Si pas divisible, est recursif sur N-1 et s'arretera a N == 1 si toujours faux ***/
	template <int N,int P>
	struct try_divide {
	    static const bool value = ( N % P == 0 || try_divide<N,P-1>::value);
	};

	/* Pour stopper la boucle/recursivite a 1 */
	template <int N>
	struct try_divide<N,1> {
	    static const bool value = false;
	};
	/*** ----- ***/

	/* On lance des tests de division a partir de la moitie du nombre */
	template <int N>
	struct Prime {
	    static const bool val = !try_divide<N,N/2>::value;
	};

#endif