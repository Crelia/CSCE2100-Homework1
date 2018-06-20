#include "buckets.h"
#include <iostream>

using namespace std;

int buckets::getCount() {return cnt;} //return count of nodes

bucket* buckets::getTail() {return tail;} //return tail node

bucket* buckets::getHead() {return head;} //return head node

void buckets::incCount() {cnt++;} //increase count

void buckets::decCount() {cnt--;} //decrease count

void buckets::setTail(bucket* tb) {tail = tb;} //set tail

void buckets::setHead(bucket* hb) {head = hb;} //set head

void buckets::addBucket() {
	int max, id;

	bucket *temp = new bucket(); //create newnode

	cout << "\nHow many units can the jug hold: " << endl;
	cin >> max; //obtain max

	if (cnt == 0) {
		id = 1;
	}
	else {
		id = 2;
	} //set id

	temp->setID(id); //set id
	temp->setMax(max); //set max

	if(cnt == 0) { head = tail = temp; }
	else {
		tail->setNext(temp);
		tail = temp;
	} //set nodes
	cnt++; //increase count
	return;
}

void buckets::checkOrder(int) {
	int id; //id
	bucket *temp, *temp2; //create pointers to bucket

	temp = head;
	temp2 = tail;

	if(temp->getMax() > temp2->getMax()) {
		id = 1;
		temp->setID(id);
		id = 2;
		temp2->setID(id);
	} //if head node  is bigger than tail  switch

	cout << "\n\n\n\nID: " << temp->getID() << endl;
	cout << "Max units: " << temp->getMax() << endl << endl;

	cout << "\nID: " << temp2->getID() << endl;
	cout << "Max units: " << temp2->getMax() << endl << endl << endl << endl << endl;
	//reprint info
}

void buckets::checkBuckets(int total) {
	int vol;
	int id = 1;

	bucket *temp, *temp2; //create pointers to bucket
	temp = head;
	temp2 = tail;

	if (temp->getMax() + temp2->getMax() != total) {
		for (int i = 2; i <= temp->getMax(); i++) { //runs from 2-max volume
			for (int j = 2; j <= temp2->getMax(); j++) { //runs from 2-max volume
				if (temp->getMax() % i == 0 && temp2->getMax() % i == 0) {//if both numbers are not prime
					if (total % 2 != 0) {//if the total is not even
						if (temp->getMax() + temp2->getMax() == total || temp->getMax() == total || temp2->getMax() == total) {
							break;
						}
						else {
							cout << "The amount cannot be obtained\n";
							temp->setMax(0);
							temp2->setMax(0);//set both maxes to 0 to skil the while loop
						}
					}
				}
			}
		}


		cout << "\n\n\n\n\n"; //formatting




		while ((temp->getVol() + temp2->getVol()) != total) {

			if(temp->getMax() + temp2->getMax() < total) { //if the sum of maxes are less than the total
				cout << "The amount cannot be obtained\n";
				break;
			}

			if (temp->getVol() == 0) { //if volume of head is 0
				fillBucket(1); //fill the first bucket

				cout << "Fill bucket 1: \n";
				cout << temp->getVol() << endl << temp2->getVol() << endl << endl; //formatting

				if (temp->getVol() == total || temp2->getVol() == total || temp->getVol() + temp2->getVol() == total) {//if total is reached
                                	if (temp->getVol() == total) {
						if (temp2->getVol() != 0) {
							emptyBucket(2, 0); //empty second bucket
							cout << "Empty bucket 2: \n";
							cout << temp->getVol() << endl << temp2->getVol() << endl << endl; //formatting
						}
					}

					if (temp2->getVol() == total) {
						if (temp2->getVol() != 0) {
							emptyBucket(1, 0);
							cout << "Empty bucket 1: \n";
							cout << temp->getVol() << endl << temp2->getVol() << endl << endl; //formatting
						}
					}

					cout << "\n\nSUCCESS. AMOUNT OBTAINED\n\n"; //completeion message
                                	break; //break from loop
				}
			}

			emptyBucket(1, 2); //empty 1st bucket to 2nd

			cout << "Empty bucket 1 into bucket 2: \n";
			cout << temp->getVol() << endl << temp2->getVol() << endl << endl; //formatting

                        if (temp->getVol() == total || temp2->getVol() == total || temp->getVol() + temp2->getVol() == total) {//if total is reached
				if (temp->getVol() == total) {
                                	if (temp2->getVol() != 0) {
                                        	emptyBucket(2, 0); //empty second bucket
                                                cout << "Empty bucket 2: \n";
                                                cout << temp->getVol() << endl << temp2->getVol() << endl << endl; //formatting
					}
				}

                                if (temp2->getVol() == total) {
                                        if (temp2->getVol() != 0) {
                                               	emptyBucket(1, 0);
                                                cout << "Empty bucket 1: \n";
                                                        cout << temp->getVol() << endl << temp2->getVol() << endl << endl; //formatting
                                      	}
                            	}

				cout << "\n\nSUCCESS. AMOUNT OBTAINED\n\n"; //completion message
                                break; //break from loop
			}

			if (temp2->getVol() == temp2->getMax()) {//if if tail is filled
				emptyBucket(2, 0); //empty buucket

				cout << "Empty bucket 2: \n";
				cout << temp->getVol() << endl << temp2->getVol() << endl << endl; //formatting
			}

			if (temp->getVol() == total || temp2->getVol() == total || temp->getVol() + temp2->getVol() == total) {//if total is reached
				if (temp->getVol() == total) {
					if (temp2->getVol() != 0) {
						emptyBucket(2, 0); //empty second bucket
						cout << "Empty bucket 2: \n";
						cout << temp->getVol() << endl << temp2->getVol() << endl << endl; //formatting
					}
				}
				if (temp2->getVol() == total) {
					if (temp2->getVol() != 0) {
						emptyBucket(1, 0);
						cout << "Empty bucket 1: \n";
						cout << temp->getVol() << endl << temp2->getVol() << endl << endl; //formatting
					}
				}


				cout << "\n\nSUCCESS. AMOUNT OBTAINED\n\n"; //completion message
				break; //break from loop
			}
		}
	}

	else { //if the two jugs sum = total
		cout << "\nWorks. Fill both buckets completely.\n";
		fillBucket(1);
		fillBucket(2);
	}

	cout << temp->getVol() << endl << temp2->getVol() << endl << endl << endl << endl; //formatting

}


void buckets::fillBucket(int id) {
	bucket *temp, *temp2; //pointer to bucket

	temp = head;
	temp2 = tail;

	if (temp->getID() == id) { //if head node == id
		temp->setVol(temp->getMax());
	}

	else  { //if tail node == id
		temp2->setVol(temp2->getMax());
	}
}

void buckets::emptyBucket(int id, int id2) {
	bucket *temp, *temp2;

	temp = head;
	temp2 = tail;

	if (temp->getID() == id && id2 == 2) { //if pouring from 1 to 2
		if ((temp->getVol() + temp2->getVol()) <= temp2->getMax()) { //if sum of volume is less than 2's max volume
			temp2->setVol(temp->getVol() + temp2->getVol()); //set 2's volume to the sum of 1 and 2's current volume
			temp->setVol(0); //set head volume to 0
		}
		else { //if sum of volume is greater than 2's max volume
			temp->setVol(temp->getVol() - (temp2->getMax() - temp2->getVol())); //set the head volume to the remainder after puring to two
			temp2->setVol(temp2->getMax()); //set 2 to max volume
		}
	}

	if (temp2->getID() == id && id2 == 1) { //if puring from 2 to 1
		if((temp2->getVol() + temp->getVol()) <= temp->getMax()) { //if sum of volume is less than or equal to 1's max volume
			temp->setVol(temp2->getVol() + temp->getVol()); //set 1's volume to the sume of 1 and 2's current volume
			temp2->setVol(0); //set tail volume to 0
		}
		else { //if sum of volume is greater than 1's max volume
			temp2->setVol((temp->getVol() - temp2->getVol())); //set the tail volume to the remainder after pouring two 1
			temp->setVol(temp->getMax()); //set 1 to max volume
		}
	}

	if (temp->getID() == id && id2 == 0) { //if puring from 1 to nothing
		temp->setVol(0); //set volume to 0
	}

	if (temp2->getID() == id && id2 == 0) { //if pouring from 1 to nothing
		temp2->setVol(0); //set volume to 0
	}
}
