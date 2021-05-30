#include <iostream>
#include <folly/Synchronized.h>
int main()
{
	constexpr auto newl = '\n';
	std::cout << "Hello, world!" << newl;

	auto vault = folly::Synchronized<long>{ 7 };
	{
		auto lck = vault.contextualLock();
		*lck *= 19;
	}
	{
		auto lck = vault.contextualLock();
		std::cout << "The value is: [" << *lck << "]." << newl;
	}
	
	return 0;
}