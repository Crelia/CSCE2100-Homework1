#ifndef bucket_h
#define bucket_h

#include <string>
using namespace std;

class bucket {
	private:
		bucket *	next; //next node
		int		jugMax; //max volume bucket can hold
		int		jugID; //ID for bucket
		int		currentVol; //current volume of bucket
	public:
		bucket();
		bucket(int, int, int); //constructor
		int		getMax(); //gets max volume from user
		void		setMax(int max); //sets max to bucket object
		bucket *	getNext(); //gets next node
		void		setNext(bucket*); //sets next bucket
		int		getID(); //gets ID of bucket
		void		setID(int id); //sets ID to bucket
		int		getVol(); //gets current volume of node
		void		setVol(int vol); //sets current volume of node
};
 #endif /*bucket_h*/
