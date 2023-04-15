// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
struct SYM {
  char ch;
  int prior;
};
template<typename T, int size>
class TPQueue {
 private:
  SYM m[5];
  int count;
  int head;
 
 public:
  TPQueue() {
    count = 0;
    head = 0;
    for (int i = 0; i < size; i++) {
      m[i].prior = 0;
    }
  }
  void push(T elm) {
    int pos = 0;
    if (count == size) {
      return;
    }
    if (count == 0 && head == 0) {
      pos = 0;
      m[0] = elm;
      count++;
    } else {
      for (int i = 0; i <= count; i++) {
        pos = head + i;
        if (pos > size - 1)
          pos = pos - size;
        if (m[pos].prior < elm.prior) {
          UpHeaval(pos);
          m[pos] = elm;
          count++;
          break;
        }
      }
    }
    return;
  }
  T pop() {
    if (count == 0) {
      return SYM{'0', 0};
    }
    SYM Buf = m[head];
    m[head].ch = 0;
    m[head].prior = 0;
    head++;
    if (head > size-1)
      head = 0;
    count--;
    if (count == 0)
      head = 0;
    return Buf;
  }
  void UpHeaval(int pos) {
    int end = head + count;
    if (end > size - 1)
      end = end - size;
    int num = head + count - pos;
    if (num >= size)
      num = num - size;
    for (int i = 0; i < num; i++) {
      if (end == 0) {
        m[0] = m[size - 1];
        end = size-1;
      } else {
        m[end] = m[end - 1];
        end--;
      }
    }
    return;
  }
};


#endif  // INCLUDE_TPQUEUE_H_
