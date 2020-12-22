
#include "PQueue.h"

template< class T, int MAX_SIZE >
PQueue<T, MAX_SIZE>::PQueue()
{
    _size = 0;

}
template<class T, int MAX_SIZE>
PQueue<T, MAX_SIZE>::PQueue(T* items, int size)
{
    _size=0;
    for (int i=0;i<size;i++)
    {
        insert(items[i]);
    }
}
template< class T, int MAX_SIZE >
    void PQueue<T, MAX_SIZE>::insert(T item)
    {
        if (MAX_SIZE > _size)
        {
            _array[++_size] = item;
        }
        moveUp();
    }
template< class T, int MAX_SIZE >
    T PQueue<T, MAX_SIZE>::findMin()
    {
        if (_size > 0)
            return _array[1];
        else
            return -1;
    }
template< class T, int MAX_SIZE >
    void PQueue<T, MAX_SIZE>::deleteMin()
    {
        int index = 1;
        _array[index] = _array[_size];
        _array[_size] = _array[index];
        _size--;
        moveDown(index);
    }
template< class T, int MAX_SIZE >
    bool PQueue<T, MAX_SIZE>::isEmpty()
    {
        return _size == 0;
    }
template< class T, int MAX_SIZE >
    int PQueue<T, MAX_SIZE>::size()
    {
        return _size;
    }

template< class T, int MAX_SIZE >
    void PQueue<T, MAX_SIZE>::buildHeap()
    {
        // for (int i=_size/2;i>0;i--)
        // {
        //  MinHeapify(i);
        // }
    }

template< class T, int MAX_SIZE >

    void PQueue<T, MAX_SIZE>::moveDown(int index)
    {
        int s = index;

        while (s < _size/2+1)
        {
            bool minRight = false;
            if (_array[s*2] < _array[s*2 + 1])
                minRight = true;

            if (minRight)
            {
                if (_array[s*2] < _array[s])
                {
                    T temp = _array[s*2];
                    _array[s*2] = _array[s];
                    _array[s] = temp;
                    s = s*2;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if (_array[s*2 + 1] < _array[s])
                {
                    T temp = _array[s*2 + 1];
                    _array[s*2 + 1] = _array[s];
                    _array[s] = temp;
                    s = s*2 + 1;
                }
                else
                {
                    break;
                }
            }
        }
    }
template< class T, int MAX_SIZE >
    void PQueue<T, MAX_SIZE>::moveUp()
    {
        int s = _size;
        while (s > 1)
        {
            if (_array[(int) s/2] > _array[s])
            {
                T temp = _array[(int) s/2];
                _array[(int) s/2] = _array[s];
                _array[s] = temp;
                s = (int)s/2;
            }
            else
            {
                break;
            }
        }
    }