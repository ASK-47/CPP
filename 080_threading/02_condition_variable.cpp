//Section 80.8: Using Condition Variables

#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <chrono>

std::mutex mtx;//мьютекс для защиты общего сотояния
std::condition_variable cv;//условная переменная для синхронизации потоков
bool ready=false;//общее состояние, которое будет изменено

void print_hello() {//suspended (waiting thread)	
	std::cout<< "Start print_hello" << '\n';
	std::unique_lock<std::mutex> lock(mtx);//захватываем мьютекс
	cv.wait(lock, []{ return ready;});//sleep...ждем пока ready не станет true
	std::cout<< "Hello" << '\n';
}

void set_ready () {//(сcondition thread)
	std::cout<< "Start set_ready" << '\n';
	std::this_thread::sleep_for(std::chrono::seconds(5));//имитация задержки
	{//lock		
		std::unique_lock<std::mutex> lock(mtx);//захватываем мьютекс		
		ready=true;//=> line 16-17 => print Hello
	}//unlock
	cv.notify_one(); //knock-knock, wake up...and check the "ready!=0" уведомляем один из ожидающих потоков	
}
	

int main() {
	std::thread t1 (print_hello);//содаем supespended-поток для вывода сообщения
	std::thread t2 (set_ready);//содаем condition-поток для смены сотояния
	
	t1.join();//ждем завершение первого потока в main()
	t2.join();//ждем завершение второго потокав в main()	
}