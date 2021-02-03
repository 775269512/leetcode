#include <hash_map>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

using stringmap = unordered_map<string, string>;

stringmap merge(stringmap a, stringmap b) {
	stringmap temp {a};
	temp.insert(b.begin(), b.end());
	return temp;
}

int main() {
	//������
	stringmap first;
	stringmap second {{"apple", "red"},{"lemon","yellow"}};
	stringmap third {{"orange","orange"}, {"strawberry", "red"}};
	stringmap fourth (second);
	stringmap fifth (merge(third, fourth));
	stringmap sixth (fifth.begin(), fifth.end());

	cout << "sixth contains : ";
	for(auto& x:sixth) cout << "  " << x.first << ":" << x.second;
	cout << endl;

	//����
	second.swap(third);
	//empty
	cout << "first " << (first.empty()?"is empty":"is not empty") << endl;

	//size
	first.size();

	//������
	unordered_map<string, string> mymap;
	mymap = {{"Australia", "canberra"}, {"U.S.", "Washington"}, {"France", "Paris"}};
	cout << "mymap contains : ";
	for(auto it = mymap.begin(); it!=mymap.end(); ++it)
		cout << "  " << it->first << " : " << it->second;
	cout << endl;

	//����
	mymap.insert ({"Australssia", "Australssia"});

	//����
	mymap.find ("Australssia");

	//�޸�
	mymap.at("Australssia") = "Australssia";
	mymap["Australssia"] = "Australssia";


	//ɾ��
	mymap.erase(mymap.begin());  //ͨ��λ��
	mymap.erase("Australssia");    //ͨ��key

	//���
	mymap.clear();

	return 0;
}
