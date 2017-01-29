/*Copyright (c) 2017 The Paradox Game Converters Project

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.*/



#ifndef NAMES_MAPPER_H
#define NAMES_MAPPER_H



#include <map>
#include <string>
#include <vector>
using namespace std;



class namesMapper
{
	public:
		static vector<string> getFirstNames(string culture)
		{
			return getInstance()->GetFirstNames(culture);
		}
		static vector<string> getSurnames(string culture)
		{
			return getInstance()->GetSurnames(culture);
		}
	private:
		static namesMapper* instance;
		static namesMapper* getInstance()
		{
			if (instance == nullptr)
			{
				instance = new namesMapper();
			}
			return instance;
		}
		namesMapper();

		void processNamesFile(string filename);

		vector<string> GetFirstNames(string culture) const;
		vector<string> GetSurnames(string culture) const;


		map<string, vector<string>> firstNamesMap;
		map<string, vector<string>> surnamesMap;
};





#endif // NAMES_MAPPER_H