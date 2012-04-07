#ifndef H_FACTO_H
	#define H_FACTO_H


	template <int n>
	struct Fact { enum { val=n * Fact<n-1>::val }; };

	template <> struct Fact<0> { enum { val = 1 }; };


#endif