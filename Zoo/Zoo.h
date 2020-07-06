#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<ctime>
using namespace std;

__interface MyInterface {
	void iEat();
	void iWalk();
	void iSleep();
};
class Animal {
public:
	Animal(const string name) :name(name) {

	}
	const string& getName() {
		return name;
	}
	void print() {
		cout << name << endl;
	}
private:
	string name;

};
class Bear :public MyInterface,public Animal {
public:
	Bear(const string& name) :Animal(name) {

	}
	void iEat() {
		cout << getName() << "- eats" << endl;
	}
	void iWalk() {
		cout << getName() << "- walks" << endl;
	}
	void iSleep() {
		cout << getName() << "- sleep" << endl;
	}
	void print() {
		Animal::print();
	}
	
};
class Monkey :public MyInterface, public Animal {
public:
	Monkey(const string& name) :Animal(name) {

	}
	void iEat() {
		cout << getName() << "- eats" << endl;
	}
	void iWalk() {
		cout << getName() << "- walks" << endl;
	}
	void iSleep() {
		cout << getName() << "- sleep" << endl;
	}
	void print() {
		Animal::print();
	}
};
__interface iWatch {
	void Watch(Animal an);
};
class VideoCamera :public iWatch{
public:
	VideoCamera(size_t number) :number(number) {

	}
	size_t getNumber() {
		return number;
	}
	void Watch(Animal an) {
		cout << "Camera number->" << number << " takes care of->"<<an.getName() << endl;
	}
	void print() {
		cout << "Camera number->" << number << endl;
	}
private:
	size_t number;
};
class Worker :public iWatch {
public:
	Worker(const string name) :name(name) {

	}
	const string& getname() {
		return name;
	}
	void Watch(Animal an) {
		cout << name << " takes care of->"<<an.getName() << endl;
	}
	void Feed(Animal an) {
		cout << "Worker->" << name << " feed->" << an.getName() << endl;
	}
	void print() {
		cout << "Worker->" << name << endl;
	}
private:
	string name;
};

class Zoo {

	void pushAnimal(Animal an) {
		animal.push_back(an);
	}
	void PushWorker(Worker work) {
		workers.push_back(work);
	}
	void pushCamera(VideoCamera cam) {
		cameras.push_back(cam);
	}
public:
	void menu(Worker worker, VideoCamera camera, Animal animals) {
		int action;
		do {
			cout << "1.Add animal" << endl;
			cout << "2.Add worker" << endl;
			cout << "3.Add camera" << endl;
			cout << "4.Distribution of aniamal" << endl;
			cout << "5.Distribution of zone" << endl;
			cout << "6.Feed animal" << endl;
			cout << "Select action->";
			cin >> action;
			system("cls");
			switch (action)
			{
			case 1:
				pushAnimal(animals);
				for (auto an : animal) {
					an.print();
				}
				break;
			case 2:
				PushWorker(worker);
				for (auto wo : workers) {
					wo.print();
				}
				break;
			case 3:
				pushCamera(camera);
				for (auto cam : cameras) {
					cam.print();
				}
				break;
			case 4:
				worker.Watch(animals);
				break;
			case 5:
				camera.Watch(animals);
				break;
			case 6:
				worker.Feed(animals);
				break;
			}
		} while (action != 7);
	}
private:
	vector<Animal>animal;
	vector<Worker>workers;
	vector<VideoCamera> cameras;
};
