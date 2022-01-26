#include <iostream>
#include <fstream>
#include <filesystem>
#include <cstdio>
#include <queue>

//Call queues
bool helper(const std::filesystem::path& p, std::filesystem::file_status s)
{
	if (std::filesystem::is_regular_file(s))
		return false;
	else
		return true;
}

void copyfile(std::string input_dir, std::string ifile_path, std::string output_dir)
{
	std::ifstream source(ifile_path, std::ios::binary);
	std::ofstream dest(output_dir + ifile_path.substr(input_dir.length(), ifile_path.length() - 1), std::ios::binary);

	source.seekg(0, std::ios::end);
	int size = source.tellg();
	source.seekg(0);

	std::cout << std::endl << size;

	char* buffer = new char[size];

	source.read(buffer, size);
	dest.write(buffer, size);

	delete[] buffer;

	source.close();
	dest.close();
}
int main(int argc, char** argv)
{
	
	std::queue<std::string> in_directory_queue;
	std::queue<std::string> out_directory_queue;
	std::string input_dir = argv[0];

	in_directory_queue.push(input_dir);
	std::string output_dir = argv[1];
	out_directory_queue.push(output_dir);
	while (!in_directory_queue.empty())
	{
		in_directory_queue.pop();
		out_directory_queue.pop();
		for (auto& it : std::filesystem::directory_iterator(input_dir))
		{
			if (helper(it, symlink_status(it)))
			{
				std::cout << std::endl << "path: " << it.path().string() << "\n";
				std::string temp = output_dir + '/' + it.path().string().substr(input_dir.length(), it.path().string().length() - 1);
				in_directory_queue.push(input_dir + '/' + it.path().string().substr(input_dir.length(), it.path().string().length() - 1));
				out_directory_queue.push(temp);
				std::filesystem::create_directory(std::filesystem::path(temp));
			}
			else
			{
				copyfile(input_dir, it.path().string(), output_dir);
			}
		}
		if (!in_directory_queue.empty())
		{
			output_dir = out_directory_queue.front();
			input_dir = in_directory_queue.front();
			std::cout << std::endl << output_dir << " " << input_dir;
		}

	}
	//Write files

	return 0;
}
