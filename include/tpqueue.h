// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

template<typename T, int size>
class TPQueue {
  // реализация шаблона очереди с приоритетом на кольцевом буфере
  
  private:
    SYM m[size]; //массив элементов типа структуры
    int count; // количество элементов в очереди
    int head; // текущий номер первого элемента
  public:
	// конструктор без параметров
  TPQueue() {
    count = 0;
    head = 0;
    for (int i = 0; i < size; i++) {
      m[i].prior = 0;
    }
  }
	// функция, добавляющая в очередь новый элемент
  void push(T elm) {
    int pos = 0;
    if (count == size) {
      cout << "Очередь полна: count = " << Count() << endl;
      return;
    }
    if (count == 0 && head == 0) {
      pos = 0;
      m[0] = elm;
      count++;
    }	else {
        for (int i = 0; i <= count; i++) {
          pos = head + i;
          if (pos > size - 1)
            pos = pos - size;//поправка на цикличность
          if (m[pos].prior < elm.prior) {  //Поиск позиции pos в массиве m с приоритетом меньше prt
            UpHeaval(pos);//Сдвиг
            m[pos] = elm;
            count++;
            break;//выход из цикла
          }
        }
    }
    return;
  }
	// функция, вытягивающая из очереди первый элемент
  T pop() {
    if (count == 0) {
      cout << "Очередь пуста: count = " << Count() << endl;
      return SYM{'0',0};
    }
    SYM Buf = m[head];
    m[head].ch = 0;
    m[head].prior = 0;
    head++;
    if (head > size-1)
      head = 0;
    count--;//Уменьшить количество элементов в очереди на 1
    if (count == 0)
      head = 0;
		return Buf;
  }
  // функция, выводящая очередь
  void Vyvod() {
    int pos = 0;
    cout << "Позиция::Символ::Приоритет" << endl;
    cout << "-----------------" << endl;
    for (int i = 0; i < count; i++)	{
      pos = head + i;
      if (pos > size - 1)
        pos = pos - size;//поправка на цикличность
      cout << pos << "::" << m[pos].ch << "::" << m[pos].prior << endl;
    }
    cout << "---------------" << endl;
    cout << "Количество элементов в очереди : " << Count() << endl << endl;
    return;
  }
  // Возвращает количество элементов в очереди
  int Count()	{
    return count;
  }
};
struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
