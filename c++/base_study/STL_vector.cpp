#include<iostream>
#include<vector>
#include<algorithm>	//sort

using namespace std;

struct stu {
	int a;
	int b;
};

int main() {
	vector<stu> test(5); //�������stu
	vector<vector<int>> attack(4, vector<int>(4, 0));	//�����ά����


	//vector<int> vec;				//�޲�������
	//cout << vec[0];				//��Ԫ�أ��������
	vector<int> vec1(5);			//5��int����Ԫ�أ���ʼֵΪ0
	for (int i = 0; i < 5; i++) {
		cout << vec1[i] << endl;
	}

	vector<int> vec2(5, 12);		//5��int����Ԫ�أ���ʼֵ��Ϊ12
	for (int i = 0; i < 5; i++) {
		cout << vec2[i] << endl;
	}

	vector<char> vec3(5, 'a');		//5��char����Ԫ�أ���ʼֵ��Ϊ'a'
	for (int i = 0; i < 5; i++) {
		cout << vec3[i] << endl;
	}

	vector<int> vec4(vec2);			//��vec2��ʼ��vec4
	for (int i = 0; i < 5; i++) {
		cout << vec4[i] << endl;
	}
	//������
	vector<int>::iterator ite = vec1.begin();//ָ��ͷ�ĵ�����
	vector<int>::iterator ite1 = vec1.end(); //ָ��β�ĵ�����
	vector<int>vec5(ite, ite1);				 //��vec5�õ�����֮���ֵ��ʼ��
	for (int i = 0; i < 5; i++) {
		cout << vec5[i] << endl;
	}

	//size  reserve empty
	vector<int> vec(5);
	cout << vec.size() << endl;
	vec.reserve(10);
	cout << vec.size() << endl;
	cout << vec.empty() <<  endl;



	//���
	for (int i = 0; i < 5; i++) {
		cout << vec[i] << endl;
	}
	//ʹ��for_each()�����Ҫ���ͷ�ļ�#include< algorithm >
//	vector<int> vec;
//	for (int i = 0; i < 10; i++) {
//		vec.push_back(i);		//β����� push_back
//	}
//	for_each(vec.begin(), vec.end(), fun);

	//β����� push_back
	vec.push_back(0);
	//β��ɾ��
	vec.pop_back();
	//ɾ������
	vec.clear();				//ɾ������Ԫ��


	//�м���ӣ�insert��
	vec.insert(vec.begin() + 2, 12);		//��ָ����������λ�ü���һ������

	//����
	vec.swap(vec1); //��vec��vec1���н���


	//����
	int a[10] = { 9, 0, 1, 2, 3, 7, 4, 5, 100, 10 };
	sort(a, a +10);

	return 0;
}
