#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

//https://t.me/codeof_art/274
// Выберите самый точный вариант вычисления суммы (предполагаем, что числа только положительные)
// Вариант 1
	double sum1(std::vector<float> &v) {
		return std::accumulate(v.begin(), v.end(), 0.0);
	}
// Вариант 2
	double sum2(std::vector<float> &v) {
		std::sort(v.begin(), v.end());//std::less<float>()
		return std::accumulate(v.begin(), v.end(), 0.0);
	}
// Вариант 3
	double sum3(std::vector<float> &v) {
		std::sort(v.begin(), v.end(), std::greater<float>());
		return std::accumulate(v.begin(), v.end(), 0.0);
	}
int main() {	

	std::vector<float> v={1.0, 2.0,3.0};
	sum2(v);
	for(auto e:v){
		std::cout << e << ' ';
	}
	sum3(v);
	for(auto e:v){
		std::cout << e << ' ';
	}

}