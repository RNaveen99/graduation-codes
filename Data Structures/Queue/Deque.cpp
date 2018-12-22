#include "Queue.cpp"
template <typename T>
class Deque : private Queue<T> {
	public:
		using Queue<T> :: enqueue;
		using Queue<T> :: dequeue;
		using Queue<T> :: display;
		
		Deque(int s = 0) : Queue<T>(s) {
			
		}
		void addToFront(T ele) {
			if (this -> isFull()) {
				throw "Deque Overflow";
			}
			if (this -> front == -1) {
				this -> front = this -> rear = 0;
			}
			else if (this -> front == 0) {
				this -> front = this -> size - 1;
			}
			else {
				this -> front-- ;
			}
			this -> arr[this -> front] = ele;
		}
		
		T removeFromRear() {
			if (this -> isEmpty()) {
				throw "Deque underflow";
			}
			T temp = this -> arr[this -> rear];
			if (this -> front == this -> rear) {
				this -> front = this -> rear = -1;
			}
			else if (this -> rear == 0){
				this -> rear = this -> rear - 1;
			}
			else {
				this -> rear--;
			}
			return temp;
		}
};
