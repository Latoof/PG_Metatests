#ifndef H_FIBO_H
	#define H_FIBO_H


/**** EXO 1 ****/

	/** Question 1 : Implementer un metaprogramme "naif" (calculs redondants)

		fib0 = 0
		fib1 = 1
		fibn = fibn−1 + fibn−2 , n ≥ 2

	*/

	template <int n>
	struct Fibo { enum { val = Fibo<n-1>::val + Fibo<n-2>::val }; };

	template <> struct Fibo<0> { enum { val = 0 }; };
	template <> struct Fibo<1> { enum { val = 1 }; };




	/** Question 2 : Implementer un metaprogramme efficace simulant le code optimise suivant :

		int fib(int n) {
			int x = 0;
			int y = 1;
			while (n>0) { x = x + y; y = x - y; --n; }
			return x;
		}

	*/

	/* Equivalent au debut du "while" avec les parametres par defaut */
	template <int n, int x = 0, int y = 1>
	struct FiboN { enum { val = FiboN<n-1,x+y,x>::val }; };
//	struct FiboN { enum { val = FiboN<n-1,x+y,x-y>::val }; };

	/* Sera appele a la sortie de la boucle */
	template <int x, int y> 
	struct FiboN<0, x, y > { enum { val = x }; };

#endif