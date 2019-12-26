//Copyright 2019 <Sralk>

#include <iostream>
#include <random>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>

#define MB 1024 * 1024

static unsigned int seed;

int Levels(int x, int n){
    int size = 0;
        size = ceil(pow(2, (x + n)) * MB / 4);
    return size;
}

 std::vector<int> CreatingBuffer(int size){
    srand(time(nullptr));

    std::vector<int>buffer(size);

            for (int i = 0; i < size; i++) {
                buffer[i] = rand_r(&seed);
            }
    return buffer;
}

void Heating(std::vector <int>* buffer) {
    for (u_int64_t i = 0; i < buffer->size(); i++) {
        buffer[i] = buffer[i];
    }
}

__uint64_t Direct(std::vector <int>* buffer){
    int num = 1000;

    auto start = std::chrono::system_clock::now();
    for (int j = 0; j < num; j++){
        for (u_int64_t i = 1; i < buffer->size(); i++) {
            if (buffer->at(i) < 0)
                buffer[i] = buffer[i];
        }
    }
    auto end = std::chrono::system_clock::now();

    uint64_t time_cycle = ceil((end-start).count()/num);
    return time_cycle;
}

__uint64_t Reverse(std::vector <int>* buffer){ //авто испраление
    int num = 1000;

    auto start = std::chrono::system_clock::now();
    for (int j = 0; j < num; j++){
        for (u_int64_t i = buffer->size() - 1 ; i > 0; i--){
            if (buffer->at(i) < 0)
                buffer[i] = buffer[i];
        }
    }
    auto end = std::chrono::system_clock::now();


    return ceil((end-start).count()/num);
}

__uint64_t Randomize(std::vector <int>* buffer){
    int num = 1000;

    std::vector<int> rand_buffer(buffer->size());
    for (u_int64_t i = 0; i < rand_buffer.size(); i++){
        rand_buffer[i] = i;
    }
    std::shuffle(rand_buffer.begin(), rand_buffer.end(), std::mt19937(std::random_device()()));
    auto start = std::chrono::system_clock::now();
    for (int j = 0; j < num; j++){
        for (u_int64_t i = 0; i < buffer->size(); i++){
            if (buffer->at(rand_buffer[i]) < 0)
                buffer[rand_buffer[i]] = buffer[rand_buffer[i]];
        }
    }
    auto end = std::chrono::system_clock::now();
    return ceil((end-start).count() / num);
}

int main() {
int x, n;
std::cout << "Введите корень кеша: ";
std::cin >> x;
std::cout << "Введите количество уровней кеша: ";
std::cin >> n;

std::vector<int>buffer = CreatingBuffer(Levels(x, 0)/2);

    Heating(&buffer);

    std::cout << Direct(&buffer) << " ";

    Heating(&buffer);

    std::cout << Reverse(&buffer) << " ";

    Heating(&buffer);

    std::cout << Randomize(&buffer) << std::endl;

for (int i = 1; i <= n; i++){
    buffer.clear();
    buffer = CreatingBuffer(Levels(x, i));

    Heating(&buffer);

    std::cout << Direct(&buffer) << " ";

    Heating(&buffer);

    std::cout << Reverse(&buffer) << " ";

    Heating(&buffer);

    std::cout << Randomize(&buffer) << std::endl;
}
    buffer.clear();
    buffer = CreatingBuffer(Levels(x, n + 1)*1.5);

    Heating(&buffer);

    std::cout << Direct(&buffer) << " ";

    Heating(&buffer);

    std::cout << Reverse(&buffer) << " ";

    Heating(&buffer);

    std::cout << Randomize(&buffer) << std::endl;

    return 0;
}
