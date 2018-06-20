#include <iostream>
#include "bucket.h"
#include "buckets.h"
#include "info.h"

using namespace std;

int main() {
	int id, total, vol;

	buckets jugs;

	prtInfo(); //print name, course, etc

	jugs.addBucket();//add OOP bucket

	cout << "\n\nPlease add the second jug now\n";

	jugs.addBucket(); //add second OOP bucket

	jugs.checkOrder(id); //check order of jugs and put largest first

	cout << "Please enter the desired amount of units: ";
	cin >> total; //desired amount of water
	cout << endl << endl;

	jugs.checkBuckets(total); //check if total is valid

	return 0;
}
