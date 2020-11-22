#include "Blob.h"
#include "BlobPtr.h"
#include <string>
#include <iostream>


int main() {
	using namespace std;

	Blob<string> strBlob({"hello", "world"});

/**
 * 迭代器测试
 */
	/*
	auto b = strBlob.begin();
	auto e = strBlob.end();
	while (b != strBlob.end()) {
		cout << *b << '\t';
		++b;
	}
	*/
/**
 * 元素的访问，添加，删除测试
 */

   cout << "size : " << strBlob.size() << endl;
   cout << "is empty ? : " << strBlob.empty() << endl;
   strBlob.push_back("Java");
   strBlob.push_back("Cpp");
   strBlob.push_back("Python");

   cout << "size : " << strBlob.size() << endl;
   cout << strBlob[3] << endl;
   cout << strBlob[4] << endl;

   auto &e = strBlob.back();
   cout << "last element is : " << e << endl;
   
   strBlob.pop_back();
   cout << "size : " << strBlob.size() << endl;

	return 0;
}
