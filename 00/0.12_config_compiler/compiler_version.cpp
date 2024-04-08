#include <iostream>

const int numStandards = 7;
const long stdCode[numStandards] = {
	199711L, 201103L, 201402L, 201703L, 202002L, 202302L, 202612L
};
const char* stdName[numStandards] = {
	"Pre-C++11", "C++11", "C++14", "C++17", "C++20", "C++23", "C++26"
};

long getCPPStandard()
{
	#if defined (_MSVC_LANG)
		return _MSVC_LANG;
	#elif defined (_MSC_VER)
		return 1;
	#else	
		return __cplusplus;
	#endif
}

int main()
{
	long standard = getCPPStandard();

	if (standard == 1)
	{
		std::cout << "Error: unable to determine your language standard" << std::endl;
		return 0;
	}

	std::cout << "Your compiler is using language standard: ";
	for (int i = 0; i < numStandards; i++)
	{
		if (standard <= stdCode[i])
		{
			std::cout << stdName[i];

			if (standard < stdCode[i])
			{
				// If the reported version is between two standard codes, this must be a preview / experimental support
				std::cout << " (preview)";
			}
			break;
		}
	}
	std::cout << std::endl;

	return 0;
}