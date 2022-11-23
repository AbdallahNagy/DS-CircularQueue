#include <iostream>
#include <stdlib.h>
#include <windows.h>
using namespace std;

class CircularQueue
{
    private:
        int f, r;
        int* arr;
        int Size;
        int isFull;
        int isEmpty;

    public:
        CircularQueue()
        {
            isFull = 0;
            isEmpty = 1;

            f = 0, r = 0;
            Size = 5;
            arr = new int[Size];
        }

        CircularQueue(int _Size)
        {
            isFull = 0;
            isEmpty = 1;

            f = 0, r = 0;
            Size = _Size;
            arr = new int[Size];
        }

        void enqueue(int num)
        {
            if(!isFull)
            {
                arr[r] = num;
                r++;
                isEmpty = 0;

                r = r % Size;

                if(r == f)
                    isFull = 1;

            }else{
                cout << "FULL"<<endl;
            }
        }

        void dequeue()
        {
            if(!isEmpty)
            {
                arr[f] = -99; //rubish
                f++;
                isFull = 0;

                f = f % Size; 

                if(f == r)
                    isEmpty = 1;
                    
            }else{
                cout << "EMPTY" << endl;
            }
        }

        void print()
        {
            for(int i=0; i<Size; i++)
                cout << arr[i] << "  ";

            cout <<endl;
        }

        ~CircularQueue()
        {
            delete[] arr;
        }
};

int main()
{
    CircularQueue q1;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.enqueue(50);

    q1.dequeue();
    q1.dequeue();
    q1.enqueue(60);
    q1.enqueue(70);
    q1.dequeue();

    q1.print();

    return 0;
}
