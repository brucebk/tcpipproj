#include <iostream>
#include <thread>
#include <memory>

struct func
{
	int& i;

	func(int& i_):i(i_){}
	void operator()()
	{
		for (unsigned j=0; j<10000; j++)
		{
			std::cout << "Do something here" << std::endl;
		}
	}
};

class thread_guard
{
	std::thread& t;
public:
	explicit thread_guard(std::thread& t_):
		t(t_)
	{}
	~thread_guard()
	{
		if (t.joinable())
		{
			t.join();
		}
	}
	thread_guard(thread_guard const&) = delete;
	thread_guard& operator=(thread_guard const&) = delete;
};

const unsigned array_size = 3;
int g_ia[array_size];

int main()
{
	const int bufsize = 0;
	//bufsize = 12;
	//const int init_val;
	const unsigned array_size = 3;
	// no initialization.
	int ia[array_size];

	std::cout << "g_ia[0] : " << g_ia[0] << std::endl;
	std::cout << "ia[0] :   " << ia[0] << std::endl;


	// 2. array init
	const unsigned str_array_size = 5;
	std::string str_arr[str_array_size] = {"hi", "Lo"};

	// 3. overflow is very easy str_arr[5]
	std::cout << "str_array[4] : " << str_arr[4] << std::endl;

	// 4. shared_ptr
	int *a = new int(2);
	std::shared_ptr<int> sp1(a);
	std::unique_ptr<int> sup = std::make_unique<int>(20);

	return 0;
	return 0;
}


