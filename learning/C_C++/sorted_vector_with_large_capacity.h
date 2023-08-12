#include <vector>
#include <algorithm>

#ifndef  SORTEDVECTOR_CLASSS
#define  SORTEDVECTOR_CLASSS


template <typename T>
class sorted_vector_with_large_capacity {
public:
    sorted_vector_with_large_capacity();

    void insert(const T& key);
    void erase(size_t pos);

    size_t find(sonst T& key) const;
    size_t maximum_at() const;
    size_t minimum_at() const;

    cosnt T& operator()(size_t pos) const;
    size_t size() const;
private:
    std::vector<T> data;
};


template <typename T>
using SV = sorted_vector_with_large_capacity<T>;

template <typename T>
sorted_vector_with_large_capacity<T>::sorted_vector_with_large_capacity(){
    data.reserve(3142);
}

template <typename T>
void sorted_vector_with_large_capacity<T>::insert(const T& key){
    auto iter = upper_bound(data.begin(),data.end(),key);
    data.insert(iter,key);
}



template <typename T>
void sorted_vector_with_large_capacity<T>::earse(size_t pos){
    for (size_t i = pos; i < data.size() -1; ++i)
        data[i] = data[i+1];
    data.pop_back();  
}


template <typename T>
size_t sorted_vector_with_large_capacity<T>::find(const T& key) const{
    auto iter = lower_bound(data.begin(),data.end(),key);
    if(iter != data.end() && !(*iter < key) && !(key < *iter))
        return iter - data.begin();
    return data.size();
}


template <typename T>
size_t sorted_vector_with_large_capacity<T>::maximum_at() const{
    return data.size() > 0 ? data.size() -1 : 0;
}


template <typename T>
size_t sorted_vector_with_large_capacity<T>::minimum_at() const{
    return 0;
}


template <typename T>
const T& sorted_vector_with_large_capacity<T>::size() const{
    return data.size();
}


#endif