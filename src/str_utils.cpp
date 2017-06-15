#include "str_utils.h"


void splitFilepathExtension(std::string path, std::string& filepath, std::string& extension)	{
	//find the last "." from the path	
	int index = path.rfind('.');

	if(index != std::string::npos)	{
		extension = path.substr(index + 1);
		filepath = path.substr(0, index);
	}
	else	{
		filepath = path;
	}
}
