#include<iostream>
#include"Zoo.h"

using namespace std;

int main() {
	Bear bear("bear");
	Worker worker("Tom");
	VideoCamera camera(12);
	Zoo zoo;
	zoo.menu(worker, camera, bear);
	
}