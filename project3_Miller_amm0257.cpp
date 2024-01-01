/* FILE NAME: project3_Miller_amm0257.cpp 
* AUTHOR: Abby Miller
* Referenced hint page
*/ 
 
#include <fstream> 
#include <iostream>
#include <algorithm> 
#include <vector> 
using namespace std; 
 
/* Confirm file is legal and exists */ 
bool check_file(string); 
 
 
 
/* Open a file and read any information */ 
vector<int> read_file(string); 
 
 
 
 /* Push data to a new file*/
void write_file(string, vector<int>); 
 
 
 
 
 /* Combine two vectors*/
vector<int> merge(vector<int>, vector<int>); 
 
 
 
 
/* 
* Display the values of a given vector. 
* 
* Param: file Name of file to display. (string) 
* Param: v Vector containing values to display. (vector<int>) 
*/ 
void to_string(string file, vector<int> v); 
 
 
 
/* 
* Merge the numbers in two specified files and write all the numbers 
* to a specified third file sorted in ascending order. 
* 
* Return: 1 Program completed successfully. (int) 
*/ 
int main() { 
 /* declare your variables */ 
    ifstream inStream; 
    int data; 
    vector<int> numbers1;
    vector<int> numbers2;
    vector<int> numbers3;
    string file1;
    string file2;
    string file3;

    cout << "*** Welcome to Abby's sorting program ***\n";
 /* Get name of file one. */ 
 do { 
    cout << "Enter the first input file name: ";
    cin >> file1;
  /* user friendly interfaces */ 
 } while (cin.fail() || !check_file(file1)); 
 
 /* Get and display numbers from file one. */ 
 numbers1 = read_file(file1); 
 to_string(file1, numbers1);
 
 /* Get name of file two. */ 
 do { 
    cout << "\nEnter the second input file name: ";
    cin >> file2;
  /* user friendly interfaces */ 
 } while (cin.fail() || !check_file(file2)); 
 
 /* Get and display numbers from file two. */ 
  numbers2 = read_file(file2); 
  to_string(file2, numbers2);
 
 /* Combine vectors and display the sorted result. */ 
 numbers3 = merge(numbers1, numbers2); 
 cout << "\nThe sorted list of " << numbers3.size() << " numbers is: ";
 for(int i = 0; i < numbers3.size(); i++) {
   cout << numbers3.at(i) << ' ';
 }
 
 /* Get name of output file. */ 
 do { 
    cout << "\nEnter the output file name: ";
    cin >> file3;
  /* user friendly interfaces */ 
 } while (cin.fail()); 
 
 /* Write combined vector to output file. */ 
 write_file(file3, numbers3);
 
  
 cout << "*** Please check the new file - " << file3 << " ***\n";
 cout << "*** Goodbye. ***";
 
 //return null; 
} 
 
 
 
bool check_file(string file) { 
 /* Input file stream. (ifstream) */ 
 ifstream stream; 
 
 /* Check whether file exists. */ 
 stream.open(file.c_str()); 
 if (stream.fail()) { 
   cout << "Input file opening failed." << endl; 
   exit(1); 
 } 
 stream.close(); 
 
 return true; 
} 
 
vector<int> read_file(string filename) { 
 /* Input file stream. (ifstream) */ 
 ifstream stream; 
 
 /* Vector containing numbers from file. (vector<int>) */ 
 vector<int> v; 
 
 /* Integer read from file. (int) */ 
 int i; 
 
 /* Add each number in the file to a vector. */ 
 stream.open((char*)filename.c_str());

 while (stream.good()) { 
    stream >> i;
    v.push_back(i);
 } 

 return v; 
} 
 
void write_file(string file, vector<int> v) { 
 /* Output file stream. (ofstream) */ 
  ofstream output(file);

  // Write to the file
  for(int i=0; i < v.size(); i++) {
   output << v.at(i) << ' ';
  }
  // Close the file
  output.close();
 
} 
 
vector<int> merge(vector<int> v1, vector<int> v2) { 
    vector<int> v3(v1);
    /* Put both vectors in one */
    v3.insert(v3.end(), v2.begin(), v2.end());
    /* Sort that vector */
    std::sort (v3.begin(), v3.end());
    return v3;
} 
 
void to_string(string file, vector<int> v) { 
 /* Vector interator number. (unsigned short) */ 
 unsigned short i; 

 cout << "The list of " << v.size() <<" numbers in file " << file << " is:\n"; 
 
 /* Display the numbers contained in a vector. */ 
  for(int i=0; i < v.size(); i++) {
   cout << v.at(i) << '\n';
  }
} 