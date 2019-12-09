#define SORT_VERBOSE
#include <iostream>
#include <algorithm>
#include <numeric>
#include <ncurses.h>
#include "sorts_viz/bubble.h"
#include "sorts_viz/cocktail.h"
#include "sorts_viz/odd-even.h"
#include "sorts_viz/comb.h"
#include "sorts_viz/gnome.h"
#include "sorts_viz/quick.h"
#include "sorts_viz/selection.h"

template<class T>
inline std::vector<T> gen_vec(size_t n){
	std::vector<int> arr(n);
	std::iota(arr.begin(), arr.end(), 0);
	std::random_shuffle(arr.begin(), arr.end());
	return arr;
}

template<class T>
void print(const std::vector<T> &vec){
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
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
	//std::cout<<name<<":\n";
	//print(arr);
#ifdef SORT_VERBOSE
	f(arr, swaps, compares);
	//print(arr);
	//std::cout<<"swaps:"<<swaps<<"\ncompares:"<<compares<<"\n\n";
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
	//std::cout<<name<<":\n";
	//print(arr);
#ifdef SORT_VERBOSE
	f(arr, param, swaps, compares);
	//print(arr);
	//std::cout<<"swaps:"<<swaps<<"\ncompares:"<<compares<<"\n\n";
#else
	f(arr, param);
	print(arr);
#endif
}

int main(){
	initscr();
	do_sort<int>("bubble", bubble);
	do_sort<int>("cocktail", cocktail);
	do_sort<int>("odd-even", odd_even);
	do_sort<int>("comb", comb, 1.3);
	do_sort<int>("gnome", gnome);
	do_sort<int>("quick", quick);
	do_sort<int>("selection", selection);
	endwin();
}