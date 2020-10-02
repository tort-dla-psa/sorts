#pragma once
#include <algorithm>
#include <vector>
#include <numeric>
#include <iterator>
#include <list>
#include <chrono>
#include <tuple>

template<class T>
std::vector<T> gen_vec(size_t n){
	std::vector<T> arr(n);
	std::iota(arr.begin(), arr.end(), 0);
	std::random_shuffle(arr.begin(), arr.end());
	return arr;
}

template<class T>
std::list<T> gen_lst(size_t n){
	auto vec = gen_vec<T>(n);
	return std::list<T>(vec.begin(), vec.end());
}

template<class T>
void sort(std::list<T> &c){ c.sort(); }
template<class Cont>
void sort(Cont &c){ std::sort(c.begin(), c.end()); }

template<class Time, class Cont, class Sort>
auto test_case(Cont &c0, Sort user_sort){
    Cont c1 = c0;

    auto t0 = std::chrono::steady_clock::now();
    user_sort(c0.begin(), c0.end());
    auto t1 = std::chrono::steady_clock::now();

    auto t2 = std::chrono::steady_clock::now();
    sort(c1);
    auto t3 = std::chrono::steady_clock::now();

    bool eq = std::equal(c0.begin(), c0.end(), c1.begin(), c1.end());
    if(!eq){
        std::copy(c0.begin(), c0.end(), std::ostream_iterator<typename Cont::value_type>(std::cout, " "));
        std::cout << "\n";
        std::copy(c1.begin(), c1.end(), std::ostream_iterator<typename Cont::value_type>(std::cout, " "));
        std::cout << "\n";
        std::cout.flush();
        abort();
    }
    auto time_sort = std::chrono::duration_cast<Time>(t1-t0).count();
    auto time_stl = std::chrono::duration_cast<Time>(t3-t2).count();
    return std::make_tuple(time_sort, time_stl);
}

template<class Time, class T, class Func>
void test_sorts(std::vector<int> elements, Func lbd){
    for(auto &els:elements){
        auto vec = gen_vec<T>(els);
        auto times_vec = test_case<Time>(vec, lbd);
        std::cout << "vec sort, els:" << els
            << " sort time:" << std::get<0>(times_vec)
            << " stl time:" << std::get<1>(times_vec)
            << "\n";

        auto lst = gen_lst<T>(els);
        auto times_lst =test_case<Time>(vec, lbd);
        std::cout << "lst sort, els:" << els
            << " sort time:" << std::get<0>(times_lst)
            << " stl time:" << std::get<1>(times_lst)
            << "\n";
    }
}