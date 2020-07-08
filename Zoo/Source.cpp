#include<iostream>
#include"Zoo.h"

using namespace std;

int main() {
	Bear bear("bear");
	Worker worker("Tom");
	VideoCamera camera(12);
	Menu menu;
	menu.addAnimal(bear);
	menu.addWorker(worker);
	menu.addCamera(camera);
	menu.printAniaml();
	menu.printWorker();
	menu.printCamera();
	menu.watchAnimals(worker, bear);
	menu.watchCamera(camera, bear);
	menu.feedAnimal(worker, bear);
	
}