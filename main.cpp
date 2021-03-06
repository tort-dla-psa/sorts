#include <iostream>
#include <algorithm>
#include <numeric>
#include "sorts/bubble.h"
#include "sorts/cocktail.h"
#include "sorts/odd-even.h"
#include "sorts/comb.h"
#include "sorts/gnome.h"
#include "sorts/quick.h"
#include "sorts/selection.h"

#ifndef SORT_VIZ
	#include <ncurses.h>
#endif

template<class T>
inline std::vector<T> gen_vec(size_t n){
	std::vector<int> arr(n);
	std::iota(arr.begin(), arr.end(), 0);
	std::random_shuffle(arr.begin(), arr.end());
	return arr;
}

template<class T>
void print(const std::vector<T> &vec){
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<T>(std::cout, " "));
	std::cout<<"\n";
}

template<class T>
#ifdef SORT_VERBOSE
void do_sort(const std::string &name, void(*f)(std::vector<T>&, int&, int&)){
	int swaps, compares;
	swaps = compares = 0;
#else
void do_sort(const std::string &name, void(*f)(std::vector<T>&)){
#endif

	auto arr = gen_vec<T>(50);
	std::cout<<name<<":\n";
	print(arr);
#if defined(SORT_VERBOSE) && !defined(SORT_VIZ)
	f(arr, swaps, compares);
	print(arr);
	std::cout<<"swaps:"<<swaps<<"\ncompares:"<<compares<<"\n\n";
#else
	f(arr);
	print(arr);
#endif
}

template<class T>
#ifdef SORT_VERBOSE
void do_sort(const std::string &name, void(*f)(std::vector<T>&, double, int&, int&), double param){
	int swaps, compares;
	swaps = compares = 0;
#else
void do_sort(const std::string &name, void(*f)(std::vector<T>&, double), double param){
#endif
	auto arr = gen_vec<T>(50);
	std::cout<<name<<":\n";
	print(arr);
#if defined(SORT_VERBOSE) && !defined(SORT_VIZ)
	f(arr, param, swaps, compares);
	print(arr);
	std::cout<<"swaps:"<<swaps<<"\ncompares:"<<compares<<"\n\n";
#else
	f(arr, param);
	print(arr);
#endif
}

int main(){
#ifdef SORT_VIZ
	initscr();
#endif
	do_sort<int>("bubble", bubble);
	do_sort<int>("cocktail", cocktail);
	do_sort<int>("odd-even", odd_even);
	do_sort<int>("comb", comb, 1.3);
	do_sort<int>("gnome", gnome);
	do_sort<int>("quick_hoare", quick_hoare);
	do_sort<int>("quick_lomuto", quick_lomuto);
	do_sort<int>("selection", selection);
#ifdef SORT_VIZ
	endwin();
#endif
}