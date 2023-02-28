#include <iostream>
#include <filesystem>
#include <string>
#include <fstream>
#include <exception>

namespace fs = std::filesystem;

class Solution
{
public:
	Solution(){}
	void open_file(fs::path name)
	{
		try
		{
			if (!fs::exists(name))
				throw 0;
			std::fstream f(name);
			if (!f.is_open())
				throw 1;
			std::cout << "Success" << std::endl;
		}
		catch (int ex)
		{
			std::fstream file("log.txt", std::ios_base::app);
			std::string exception;
			if (ex == 0)
				exception = "There is no file in such directory\n";
			else if(ex==1)
				exception = "File is not opened\n";
			std::cout << exception << std::endl;
			file << exception;
		}
	}
};

int main()
{
	Solution sol;
	fs::path path("file.txt");
	sol.open_file(path);
	return 0;
}