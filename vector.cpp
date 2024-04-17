// include header files
#include <iostream>
#include <cstring>

// use namespace std for this code base
using namespace std;

// vector implementation
template<typename T>
class vector{

    // data members

    size_t vecSize;       // size of array(elements in array)
    size_t vecCapacity;  // actual memory blocks in array
    T* arr;             // base address pointer

    public:

    // default constructor when user don't pass any size
    vector(){

        vecSize = 0;
        vecCapacity = 0;
        arr = new T[vecCapacity];
    }


    // parameterized constructor , take capacity of array and fill it with desired value
    vector(size_t capacity, T filler = 0){

        vecSize = capacity;
        vecCapacity = capacity;
        
        arr = new T[vecCapacity];

        // fill the value of array with filler value
        for (int idx = 0 ; idx < vecSize ; idx++){

            arr[idx] = filler;
        }
    }


    /* -----------------Methods of array ------------------------------*/

    // get value at randomIdx
    T at(int idx){
        
        try{
            
            // index out of bound 
            if (!(idx >= 0  && idx < vecSize)){

                throw runtime_error("Exception :: Array index out of bound");
            }

            return arr[idx];

        }catch(const std::exception& e){

            std::cerr << e.what() << '\n';

            exit(1);
        }
    }

    // size of array
    size_t size(){

        return vecSize;
    }

    // capacity of array
    size_t capacity(){

        return vecCapacity;
    }

    // traversal of array
    void print(){
        
        for (int idx = 0 ; idx < vecSize ; idx++){
            
            cout << arr[idx] << " ";
        }

        cout << endl;

    }

    // insert at end (push_back)
    bool push_back(T val){

        try{

            if (vecSize == vecCapacity){
                
                // doubled capacity of array
                vecCapacity = vecSize == 0 ? 1 : vecCapacity * 2;

                // create a new array in heap
                T* newArr = new T[vecCapacity];

                // copy the previous array in new array
                for (int idx = 0 ; idx < vecSize; idx++){

                    newArr[idx] = arr[idx];
                }

                // delete the previous arr in heap
                delete [] arr;

                // change the reference of previous arr
                arr = newArr;
            }

            // push value
            arr[vecSize] = val;

            // increment the size of array
            vecSize++;

            return true;

        }catch(...){

           cerr << "Something went wrong while insert element at end of array" << endl;

           return false;
        }
    }

    // remove at end (pop_back())
    T pop_back(){

        try{

            if (vecSize == 0){

                throw runtime_error("Exception :: vector is already empty");
            }

           // store the value of last element
            T val = arr[vecSize-1];

            // delete last element
            vecSize--;

            //  return value
            return val;
            
        }catch(exception& e){

            cerr << e.what() << endl;

            exit(1);
        }
    }

    // accumulate (sum of all elements of array) (only for integers)
    T accumulate(int startIdx, int endIdx , T startVal = 0){  

        try{

             // index out of bound 
            if (!(min(startIdx, endIdx) >= 0  && max(startIdx, endIdx) < vecSize)){

                throw runtime_error("Exception :: Array index out of bound while adding elements of array");
            }

            // sum in reverse order
            if (startIdx > endIdx){

                swap(startIdx, endIdx);
            }

            // acummulate 
            T sum = startVal;

            for (int idx = startIdx ; idx <= endIdx ; idx++){

                sum += arr[idx];
            }

            return sum;

        } catch(exception &e){

            cerr << e.what() << endl;

            exit(1); // terminate the program with status code 1;
        }
    }


    // minimumValue
    T min_element(int startIdx, int endIdx){

        try{

             // index out of bound 
            if (!(min(startIdx, endIdx) >= 0  && max(startIdx, endIdx) < vecSize)){

                throw runtime_error("Exception :: Array index out of bound while finding element");
            }

            // find min element
            int mini = arr[0];

            for (int idx = startIdx ; idx <= endIdx; idx++){

                mini = min(mini, arr[idx]);
            }

            return mini;

        }catch(const std::exception& e){

            std::cerr << e.what() << '\n';
        }
        
    }

    // maximimumValue
    T max_element(int startIdx, int endIdx){

        try{

             // index out of bound 
            if (!(min(startIdx, endIdx) >= 0  && max(startIdx, endIdx) < vecSize)){

                throw runtime_error("Exception :: Array index out of bound while finding element");
            }

            // find min element
            T maxi = arr[0];

            for (int idx = startIdx ; idx <= endIdx; idx++){
                
                maxi = max(maxi, arr[idx]);
            }

            return maxi;

        }catch(const std::exception& e){

            std::cerr << e.what() << '\n';
        } 
    }

    // reverse array
    void reverse(int startIdx, int endIdx){

        try{

             // index out of bound 
            if (!(min(startIdx, endIdx) >= 0  && max(startIdx, endIdx) < vecSize)){

                throw runtime_error("Exception :: Array index out of bound while reverse array");
            }

            // reverse
            while (startIdx <= endIdx){

                swap(arr[startIdx], arr[endIdx]);

                startIdx++; 
                endIdx--;
            }

        }catch(const std::exception& e){

            std::cerr << e.what() << '\n';
        }
    }

    // insertion at random index : time complexity - O(N)
    void insert(int index, T val){

        try{

            // index out of bound 
            if (!(index >= 0  && index < vecSize)){

                throw runtime_error("Exception :: Array index out of bound");
            }

            // insert element at end of array 
            push_back(val);

            // shift all the elements from end to index by 1 to right
            for (int idx = vecSize-2 ; idx >= index; idx--){

                arr[idx+1] = arr[idx];
            }

            // insert the value at that random index
            arr[index] = val;

        }catch(const std::exception& e){

            std::cerr << e.what() << '\n';
        }
    }

    // deletion at random index : time complexity : O(N)
    void erase(int index){

        try{

            // index out of bound 
            if (!(index >= 0  && index < vecSize)){

                throw runtime_error("Exception :: Array index out of bound");
            }

            // shift all the elements from index to end by 1 to left
            for (int idx = index; idx < vecSize-1 ; idx++){

                arr[idx] = arr[idx+1];
            }

            // decrease the vecSize by 1
            vecSize--;
            
        }catch(const std::exception& e){

            std::cerr << e.what() << '\n';
        }
    }

    /*------------------------------ operator overlaoding --------------------------*/

    // == operator overload
    bool operator == (vector& v){

        if (this->vecSize != v.size()){

            return false;
        }

        for (int idx = 0 ; idx < vecSize ; idx++){

            if (this->arr[idx] != v.arr[idx]){

                return false;
            }
        }

        return true;
    }

    //  (=) assignment opertor overload 
    vector& operator = (vector& v){

        this->vecSize = v.size();
        this->vecCapacity = v.capacity();

        this->arr = new int[vecSize];

        for (int idx = 0 ; idx < v.size() ; idx++){

            this->arr[idx] = v.arr[idx];
        }

        return *this;
    }

    // Overload [] operator for random index access
    T& operator [] (int index){

        try {

            // index out of bound
            if (!(index >= 0 && index < vecSize)) {

                throw runtime_error("Exception :: Array index out of bound");
            }

            // return the reference of the memory 
            return arr[index];

        }catch (const std::exception& e) {

            std::cerr << e.what() << '\n';

            exit(1);
        }
    }
};


int main(){
   
    // Main- Menu
}