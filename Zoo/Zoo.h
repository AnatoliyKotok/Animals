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
public:

	void pushAnimal(Animal an) {
		animal.push_back(an);
	}
	void PushWorker(Worker work) {
		workers.push_back(work);
	}
	void pushCamera(VideoCamera cam) {
		cameras.push_back(cam);
	}
	void printAniaml() {
		for (auto an : animal) {
			an.print();
		}
	}
	void printWorker() {
		for (auto work : workers) {
			work.print();
		}
	}
	void printCamera() {
		for (auto cam : cameras) {
			cam.print();
		}
	}
private:
	vector<Animal>animal;
	vector<Worker>workers;
	vector<VideoCamera> cameras;
};
class Menu:public Zoo {
public:
	Menu() = default;
	void addAnimal(Animal animal) {
		Zoo::pushAnimal(animal);
	}
	void addWorker(Worker worker) {
		Zoo::PushWorker(worker);
	}
	void addCamera(VideoCamera camera) {
		Zoo::pushCamera(camera);
	}
	void watchAnimals(Worker worker, Animal animal) {
		worker.Watch(animal);
	}
	void watchCamera(VideoCamera camera, Animal animal) {
		camera.Watch(animal);
	}
	void feedAnimal(Worker worker, Animal animal) {
		worker.Feed(animal);
	}
	void printAniaml() {
		Zoo::printAniaml();
	}
	void printWorker() {
		Zoo::printWorker();
	}
	void printCamera() {
		Zoo::printCamera();
	}
};