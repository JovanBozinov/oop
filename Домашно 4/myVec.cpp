#include <iostream>
#include <cstdint>

struct myVec{
private:
    uint64_t size;
    uint64_t capacity;
    int* arr;
    void calcCap(){
        if (size==0)
            capacity=8;
        else{
            capacity=1;
            while(capacity<=size){
                capacity=capacity<<1;
            }
        }
    }
public:
    myVec(uint64_t sz=0, uint64_t val=0){
        size=sz;
        calcCap();
        arr=new int[capacity];
        for(int i=0; i<sz; i++){
            arr[i]=val;
        }
    }
    int& at(int i){
        return arr[i];
    }
    int& back(){
        return arr[size-1];
    } 
    uint64_t vecSize(){
        return size;
    }
    uint64_t vecCap(){
        return capacity;
    }
    void printVec(){
        for(int i=0; i<size; i++)
            std::cout << arr[i] << " ";
        std::cout << '\n';
    }
    void info(){
        std::cout << "Size: " << size << " Capacity: " << capacity << '\n';
        for(int i=0; i<size; i++)
            std::cout << arr[i] << " "; 
        std::cout << '\n';
    }
    void pop_back(){
        if (size>0)
            size--;
    }
    void push_back(int value){
        size++;
        if (size>capacity){
            capacity=capacity<<1;
        }
        int* newArr=new int[capacity];
        for(int i=0; i<size-1; i++){
            newArr[i]=arr[i];
        }
        newArr[size-1]=value;
        delete[] arr;
        arr=newArr;
    }
    ~myVec(){
        delete[] arr;
    }
};

int main(){
    myVec v(1, 5);
    v.info();
    v.at(0)=10;
    v.info();
    v.push_back(21);
    v.info();
    v.push_back(39);
    v.push_back(200);
    v.push_back(1);
    v.push_back(0);
    v.back()=15;
    v.info();
    v.pop_back();
    v.info();

    return 0;
}