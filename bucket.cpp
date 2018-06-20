#include <iostream>
#include "bucket.h"

using namespace std;

bucket::bucket() {
	jugMax = 0;
	jugID = 0;
	currentVol = 0;
	next = NULL;
} //set all values to 0/NULL

bucket::bucket(int max, int id, int vol) {jugMax = max; jugID = id; currentVol = vol;} //constructor

int bucket::getMax() {return jugMax;} //gives max units of node

void bucket::setMax(int max) {jugMax = max;} //sets max units

bucket* bucket::getNext() {return next;} //gets next node

void bucket::setNext(bucket* nb) {next = nb;} //assign next node

int bucket::getID() {return jugID;} //return the ID of node

void bucket::setID(int id) {jugID = id;} //set ID of node

int bucket::getVol() {return currentVol;} //return the current volume of node

void bucket::setVol(int vol) {currentVol = vol;} //set volume of node
