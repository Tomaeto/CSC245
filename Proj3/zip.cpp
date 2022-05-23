#include "huffman.h"
#include <iostream>
#include <fstream>
#include <cstring>
//Program for compressing a file using Huffman encoding
//Takes arguments from command line, if arg is --help, displays help menu,
//if arg is --t filename, displays Huffman table for input file,
//if arg is filename, compresses file into filename.zip, otherwise
//prints error message and exits

//Output file has format:
//	numChars
//	ASCIIval HuffmanCode
//	encodedString
	
//By Adrian Faircloth
//CSC245
//11-10-21

//Function declarations
void InsertChars(int Letters[], HuffmanTree& tree, int& numChars);

int main(int argc, char *argv[])
{
	HuffmanTree tree;
	int Letters[256];
	int numChars = 0;
	string filename;
	//If the first argument is --t, stores second arg as filename
	//Otherwise stores first arg as filename
	if (!strcmp(argv[1], "--t"))
		filename = argv[2];
	else
		filename = argv[1];
	ifstream file(filename);
	//If first arg is --help, displays help menu
	if (!strcmp(argv[1], "--help") )
	{
		cout << "Compress a text file with Huffman encoding." << endl << endl;
		cout << "--t\t\tDisplay Huffman encoding table" << endl;
		cout << "--help\t\tDisplay help menu" << endl;
	}
	//If filename is invalid, prints error message and exits	
	else if (!file.is_open())
	{
		cout << "Bad Filename entered on command line" << endl;
	}
	//Otherwise, either compresses file into a .zip or prints Huffman table
	else
	{
		//Getting frequency of each char in file as well as
		//	number of unique characters
		char ch;
		for (char c = char(0); c <= char(126); c++)
		{
			Letters[c] = 0;
		}
	
		string filestring = "";
		while (file.get(ch))
		{
			Letters[ch]++;
			filestring += ch;
		}
		//Inserting each char into the tree w/ weights and building tree
		InsertChars(Letters, tree, numChars);
		tree.build();
		//If first arg is --t, prints Huffman table and exits
		if (!strcmp(argv[1], "--t"))
		{
			cout <<	"\t#ENCODING TABLE FOR ZIP FILE#" << endl;
			cout << "Index\tChar\tWeight\tParent\tChildType" << endl;
			tree.PrintTable();
		}
		//Otherwise, compresses file into .zip
		else
		{
			//Creating output file and deleting input file
			ofstream outfile;
			remove(argv[1]);
       			filename = filename + ".zip";
       			string codedStr = "";
       			outfile.open(filename);
			//Putting number of unique chars as header of output file
       			outfile << numChars;
       			outfile << "\n";
       			for (char c = char(0); c <= char(126); c++)
       			{
				//For each char present in file, puts is ASCII
				//	value and Huffman code into output file
       	       		 	if (Letters[c] > 0)
       	        		{
       	                		outfile << (int)(c);
       	                		outfile << " ";
       	                		outfile << tree.GetCode(c);
       	                		outfile << "\n";
       		       	 	}
       			}
			//For each character from input file, puts Huffman
			//	code into last line of output file
			for (int i = 0; i < filestring.length(); i++)
			{
				codedStr += tree.GetCode(filestring[i]);
			}
			outfile << codedStr;
			//Closing completed output file and printing exit message
			outfile.close();
			cout << "File successfully compressed" << endl;
		}
	}
	
	
}




void InsertChars(int Letters[], HuffmanTree& tree, int& numChars)
{
	//Inserts each char w/ weight > 0 into Huffman tree and
	//	increments num of unique chars
	for (char c = char(0); c <= char(126); c++)
	{
		if (Letters[c] > 0)
		{
			tree.insert(c, Letters[c]);
			numChars++;
		}
	}
}
