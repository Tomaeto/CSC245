#include <fstream>
#include <iostream>
#include <map>
using namespace std;
//Program for decoding zip file encryped w/ Huffman encoding
//Takes command line input for zip file name, creates uncompressed
//	file if input is valid
//By Adrian Faircloth
//CSC 245
//11-9-21

int main(int argc, char* argv[])
{
	//Declaring necessary variables
	//Using map to store Huffman codes and corresponding
	//	ASCII codes
	map<string, int> codes;
	int numChars;
	//Getting filename from command line
	string filename = argv[1];
	string newname;
	string line;
	string templine;
	string code;
	ifstream stream(filename);
	
	//If filename does not contain ".zip", prints error message and exits
	if (!stream.is_open())
	{
		cout << "Bad Filename entered on command line" << endl;
	}
	//If filename is valid, creates uncompressed file from zip file
	else
	{
		//Creating output file from zip file name and opening file
		newname = filename.substr(0, filename.find(".zip"));
		ofstream newfile;
		newfile.open(newname);
		//Opening zip file for reading, getting number of unique characters
		//	from header of file and skipping to next line
	
		stream >> numChars;
		stream.ignore();

		for (int i = 0; i < numChars; i++)
		{
			//Getting line from zip file, getting Huffman code for character
			//	and storing the corresponding ASCII value
			getline(stream,line);
			code = line.substr(line.find(' ')+1, line.length());
			codes[code] = stoi(line.substr(0, line.find(' ')));
		}
		//Getting line of encoded text after storing all unique character codes
		getline(stream, line);
		for (int i = 0; i < line.length(); i++)
		{
			//Appends each character to a string, if this string matches a
			//	Huffman code in the map, adds the corresponding character
			//	to the output file and clears the string
			//At end of loop, entire line will be read and decoded into original text
			templine += line[i];
			if (codes.find(templine) != codes.end())
			{
				newfile << (char)(codes[templine]);
				templine.clear();
			}
		}
		//Closing output file and printing successful decompression message
		newfile.close();
		cout << "File successfully inflated back to original" << endl;
		return 0;
	}
}
