#include <map>
#include <string>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <iostream>     // std::cout
#include <iterator>     // std::iterator_traits
#include <typeinfo>     // typeid
class penis
{};
int main() {
    // std::map<std::string, int> m;
    // // Insert Element in map
    // m.insert(std::pair<std::string, int>("a", 1));
//
    // m.insert(std::pair<std::string, int>("xb", 2));
    // m.insert(std::pair<std::string, int>("bb", 2));
    // m.insert(std::pair<std::string, int>("b", 2));
    // m.insert(std::pair<std::string, int>("c", 3));
    // m.insert(std::pair<std::string, int>("d", 4));
    // m.insert(std::pair<std::string, int>("e", 5));
//
    // m.insert(std::pair<std::string, int>("g", 5));
    // // Create a map iterator and point to beginning of map
    // std::map<std::string, int>::iterator it = m.begin();
	// std::map<std::string, int>::iterator itlow=m.lower_bound ("f");
	// std::cout<<itlow->first<<std::endl;
	// std::map<int,int> test_insert;
	// std::pair<int,int> temp;
	// for (int i = 0 ;i<10; i++)
	 // {
		// temp = std::make_pair(i,i);
		// std::pair<std::map<int,int>::iterator,bool> ret = test_insert.insert(temp);
		// std::cout << "Was present : " << ret.second << std::endl;
		// // std::cout<<it->first<<std::endl;
	 // }
	// for (int i = 0 ;i<10; i++)
	 // {
		// temp = std::make_pair(i,i);
		// std::pair<std::map<int,int>::iterator,bool> ret = test_insert.insert(temp);
		// std::cout << "again Was present : " << ret.second << std::endl;
		// // std::cout<<it->first<<std::endl;
	 // }
 
typedef std::iterator_traits<penis*> traits;
  if (typeid(traits::iterator_category)==typeid(std::random_access_iterator_tag))
    std::cout << "int* is a random-access iterator";
  return 0;
}
