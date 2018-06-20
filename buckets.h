#ifndef buckets_h
#define buckets_h

#include "bucket.h"

using namespace std;

class buckets {
	private:
		int cnt; //count
		bucket* tail; //node tail
		bucket* head; //node head
	public:
		buckets() {cnt = 0;} //constructor, set to 0
		int getCount(); //return count
		bucket* getTail(); //return tail
		bucket* getHead(); //return head
		void incCount(); //increase count
		void decCount(); //decrease count
		void setTail(bucket*); //set tail
		void setHead(bucket*); //set head
		void addBucket(); //ad a bucket
		void checkOrder(int); //check bucket order
		void checkBuckets(int); //check if amount is valid
		void fillBucket(int); //fill a bucket
		void emptyBucket(int, int);//empty a bucket to another, or to the ground
		void cleanUp(); //clean up nodes/memory
};
#endif /* buckets_h */
