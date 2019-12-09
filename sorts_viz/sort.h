#pragma once
#include <ncurses.h>
#include <algorithm>
#include <vector>
#include <thread>
#include <chrono>

enum order{
	regular,
	reversed
};

template<class T>
void viz(const std::vector<T> &arr){
	int h, w;
	getmaxyx(stdscr, h, w);
	clear();
	T max = *std::max_element(arr.begin(), arr.end());
	for(size_t i=0; i<arr.size(); i++){
		int printh = (arr.at(i)*1.0/max)*h;
		int printw = i*1.0/arr.size()*w;
		mvaddch(printh, printw, 'O');
	}
	refresh();
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
}