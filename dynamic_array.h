//
// Created by guan on 2025/8/21.
//

#ifndef C_PRIME_DYNAMIC_ARRAY_H
#define C_PRIME_DYNAMIC_ARRAY_H
#include <stdexcept>
#include <print>

// 定义类模板DynamicArray，模板参数为template <typename T, int InitCapacity = 4>（T为元素类型，InitCapacity为初始容量，默认值 4）。
// 核心成员变量（private）：
//     T* data：指向动态分配的连续内存（存储元素）。
//     int size_：当前元素数量（初始 0）。
//     int capacity_：当前容量（初始为InitCapacity）。
// 核心成员函数（public）：
//     构造函数：初始化data、size_、capacity_。
//     析构函数：释放data指向的内存，避免泄漏。
//     push_back(const T& val)：在数组末尾添加元素（容量不足时自动扩容 2 倍）。
//     T& get(int index)：返回指定索引的元素（越界抛std::out_of_range）。
//     int size() const：返回当前元素数量。
//     int capacity() const：返回当前容量。
//     void display() const：打印数组元素（格式：[1, 2, 3]，空数组打印[]）。
// 禁用拷贝构造和赋值运算符（避免浅拷贝问题）。


template <typename T,int InitCapacity = 4>
class DynamicArray {
    T* data;
    int size_;
    int capacity_;
    //构造析构
    //single
    public:
    DynamicArray();
    DynamicArray(const DynamicArray& arr)=delete;
    DynamicArray& operator=(const DynamicArray& arr)=delete;
    DynamicArray(DynamicArray&& other) noexcept;
    ~DynamicArray();
    void push_back(T value);
    T& get(int index) const;
    int size() const;
    int capacity() const;
    void display() const;
    //友元 数组拼接
    template <typename T2,int InitCapacity1,int InitCapacity2>
    friend DynamicArray<T2> concat(DynamicArray<T2,InitCapacity1>& a1,DynamicArray<T2,InitCapacity2>& a2);
    //友元 find
    template <typename T2,int InitCapacity1>
    friend int find(const DynamicArray<T2,InitCapacity1>& arr,T2 value);
};


template <typename T, int InitCapacity>
DynamicArray<T, InitCapacity>::DynamicArray() :
size_(0),capacity_(InitCapacity){
    data = new T[InitCapacity];
}

template <typename T, int InitCapacity>
 DynamicArray<T, InitCapacity>::DynamicArray(DynamicArray&& other) noexcept:
data(other.data),size_(other.size()),capacity_(other.capacity()){
    other.data = nullptr;
    other.size_ = 0;
    other.capacity_ = 0;
 }

template <typename T, int InitCapacity>
DynamicArray<T, InitCapacity>::~DynamicArray() {
    delete [] data;
}

/**
 * @brief
 * @param value
 */
template <typename T, int InitCapacity>
void DynamicArray<T, InitCapacity>::push_back(T value) {
    if (size_>=capacity_) {
        int new_capacity=2*capacity_;
        T* new_data=new T[new_capacity];
        for (int i=0;i<size_;i++) {
            new_data[i]=data[i];
        }
        delete [] data;
        data=new_data;
        capacity_=new_capacity;
    }
    data[size_++]=value;
}

template <typename T, int InitCapacity>
T& DynamicArray<T, InitCapacity>::get(int index) const{
    if (index<size_) {
        return data[index];
    }
    throw std::out_of_range("out of range");
}

template <typename T, int InitCapacity>
int DynamicArray<T, InitCapacity>::size() const {
    return size_;
}

template <typename T, int InitCapacity>
int DynamicArray<T, InitCapacity>::capacity() const {
    return capacity_;
}

template <typename T, int InitCapacity>
void DynamicArray<T, InitCapacity>::display() const {
    std::print("[");
    if (size_!=0) {
        for (int i=0;i<size_-1;i++) {
            std::print("{},", data[i]);
        }
        std::print("{}", data[size_-1]);
    }
    std::print("]");
    std::println();
}

template <typename T2,int InitCapacity1,int InitCapacity2>
DynamicArray<T2> concat(DynamicArray<T2,InitCapacity1>& a1,DynamicArray<T2,InitCapacity2>& a2){
    auto new_arr=DynamicArray<T2>();
    for (auto i=0;i<a1.size();i++) {
        new_arr.push_back(a1.get(i));
    }
    for (auto i=0;i<a2.size();i++) {
        new_arr.push_back(a2.get(i));
    }
    return new_arr;
}

template <typename T2,int InitCapacity1>
int find(const DynamicArray<T2,InitCapacity1>& arr,T2 value) {
    for (auto i=0;i<arr.size();i++) {
        if (arr.get(i)==value) {
            return i;
        }
    }
    return -1;
}




#endif //C_PRIME_DYNAMIC_ARRAY_H
