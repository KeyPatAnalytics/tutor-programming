
#include<iostream> 
#include<cstdlib> 
#include<thread> 
using namespace std;


void summ(int number, int arr[], int idx) {

    std::thread::id id = std::this_thread::get_id();
    cout << "Thread with id " << id << " started. " << "\n";
    int sum = 0;
    for (int i = 0; i < number; i++) {
        sum += i;
    }
    arr[idx] = sum;
}

int main() {
    const int length = 20;
    thread::id id;
    thread thread_array[length];
    int res_arr[length] = { 0 };
    for (int i = 0; i < length; i++) {
        thread_array[i] = thread(summ, rand(), res_arr, i);
    }
    for (int i = 0; i < length; i++) {
        if (thread_array[i].joinable()) {
            id = thread_array[i].get_id();
            thread_array[i].join();
            cout << "Thread with id " << id << " finished. With result " << res_arr[i] << "\n";
        }
    }
    return 0;
}


/*

Упражнения.

1. Обратите внимание на ошибки (непоследовательность) при выводе сообщения о старте потока. 
Чем это вызвано? Почему этого не происходит при выводе результата работы потока? Как можно решить эту проблему? 
(Подсказка: каким ресурсом хотят воспользоваться потоки и как организовать эксклюзивный доступ к нему.)

Ответ: Потому что имеется функция rand(), в создании потока, которая определяет значение массива.
При выводе потоки завершаются строго по id, друг за другом. Неободимо, динамическим массивом организовать доступ.

2. Доработайте программу таким образом, что расчёты в потоках останавливаются после того как хотябы один из них
завершился. После этого цикл прерывается, а запись в arr не производится. 
Проверьте правильность работы разработанной программы замером времени работы потоков (или временем их завершения).


#include<iostream> 
#include<cstdlib> 
#include<thread> 
using namespace std;

void summ(int number, int arr[], int idx, bool* flag) {

    std::thread::id id = std::this_thread::get_id();
    cout << "Thread with id " << id << " started. " << "\n";
    int sum = 0;
    for (int i = 0; i < number && *flag; i++) {
        sum += i;
    }
    if (*flag) arr[idx] = sum;
}

int main() {
    bool flag = true;
    const int length = 20;
    thread::id id;
    thread thread_array[length];
    int res_arr[length] = { 0 };
    for (int i = 0; i < length; i++) {
        thread_array[i] = thread(summ, rand(), res_arr, i, &flag);
    }
    for (int i = 0; i < length; i++) {
        if (thread_array[i].joinable()) {
            id = thread_array[i].get_id();
            thread_array[i].join();
            cout << "Thread with id " << id << " finished. With result " << res_arr[i] << "\n";
            flag = false;
			
        }
    }
    return 0;
}



3.1. Напишите программу производяющую паралельное суммирование двух матриц. Результат записывается в матрице продукт и выводится на экран.

#include <iostream>
#include <cstdlib>
#include <omp.h>

using namespace std;

void randomiseMatrix(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rand() % 11;
        }
    }
    return;
}

int main(int argc, char** argv) {
    srand(time(NULL));
    int n1 = 1000;
    int m1 = 500;
    int n2 = 500;
    int m2 = 1200;

    //Матрица n1 x m1
    int** matrix1;
    //Матрица n2 x m2
    int** matrix2;

    matrix1 = (int**)malloc(sizeof(int*) * n1);
    for (int i = 0; i < n1; i++) {
        matrix1[i] = (int*)malloc(sizeof(int) * m1);
    }
    matrix2 = (int**)malloc(sizeof(int*) * n2);
    for (int i = 0; i < n2; i++) {
        matrix2[i] = (int*)malloc(sizeof(int) * m2);
    }
     
    int** result = (int**)malloc(sizeof(int*) * n1);;
    for (int i = 0; i < n1; i++) {
        result[i] = (int*)malloc(sizeof(int) * m2);
    }
    //Устанавливаем число потоков
    int threadsNum = 2;
    omp_set_num_threads(threadsNum);
    int i, j, k;
#pragma omp parallel for shared(matrix1, matrix2, result) private(i, j, k)
    for (i = 0; i < n1; i++) {
        for (j = 0; j < m2; j++) {
            result[i][j] = 0;
            for (k = 0; k < m1; k++) {
                result[i][j] += (matrix1[i][k] + matrix2[k][j]);
            }
        }
    }
    return 0;
}



3.2. Напишите программу производяющую паралельное умножение двух матриц. Результат записывается в матрице продукт и выводится на экран.

#include <iostream>
#include <cstdlib>
#include <omp.h>

using namespace std;

void randomiseMatrix(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rand() % 11;
        }
    }
    return;
}

int main(int argc, char** argv) {
    srand(time(NULL));
    int n1 = 1000;
    int m1 = 500;
    int n2 = 500;
    int m2 = 1200;

    //Матрица n1 x m1
    int** matrix1;
    //Матрица n2 x m2
    int** matrix2;

    matrix1 = (int**)malloc(sizeof(int*) * n1);
    for (int i = 0; i < n1; i++) {
        matrix1[i] = (int*)malloc(sizeof(int) * m1);
    }
    matrix2 = (int**)malloc(sizeof(int*) * n2);
    for (int i = 0; i < n2; i++) {
        matrix2[i] = (int*)malloc(sizeof(int) * m2);
    }

    //Генерируем случайные матрицы для умножения
    randomiseMatrix(matrix1, n1, m1);
    randomiseMatrix(matrix2, n2, m2);

    int** result = (int**)malloc(sizeof(int*) * n1);;
    for (int i = 0; i < n1; i++) {
        result[i] = (int*)malloc(sizeof(int) * m2);
    }

    //Устанавливаем число потоков
    int threadsNum = 2;
    omp_set_num_threads(threadsNum);
    int i, j, k;
#pragma omp parallel for shared(matrix1, matrix2, result) private(i, j, k)
    for (i = 0; i < n1; i++) {
        for (j = 0; j < m2; j++) {
            result[i][j] = 0;
            for (k = 0; k < m1; k++) {
                result[i][j] += (matrix1[i][k] * matrix2[k][j]);
            }
        }
    }

    return 0;
}

*/