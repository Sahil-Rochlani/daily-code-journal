#include<bits/stdc++.h>
using namespace std;

class Heap{
  public:
    int *arr;
    int size;
    int index;
    
    Heap(int cap) : arr(new int[cap]), size(cap), index(0) {}
    
    void insert(int val){
      //overflow
      if(index == size - 1)return;
      //insert logic
      index++;
      arr[index] = val;
      //placing at correct position
      int child = index;
      while(child > 1 && arr[child] > arr[child / 2]){
        swap(arr[child], arr[child / 2]);
        child /= 2;
      }
    }
    
    void printHeap(){
      for(int i = 1;i<=index;i++){
        cout << arr[i] << " ";
      }
      cout << endl;
    }
    
    bool isEmpty(){
      return index == 0;
    }
    
    int top(){
      return index == 0 ? -1 : arr[1];
    }
    
    // int size
    // void heapify(int *arr, int index, int curr){
    //   if(curr > index)return;
    //   int left = 2 * curr;
    //   int right = 2 * curr + 1;
    //   //find the largest inde
    //   int largest = curr;
    //   //cjck with leftindex
    //   if(left <= index && arr[left] > arr[largest])largest = left;
    //   if(right <= index && arr[right] > arr[largest])largest = right;
      
    //   //what if largest == curr, do nothing, curr
      
    //   //else 
      
    //   if(largest != curr){
    //     swap(arr[curr], arr[largest]);
    //     curr = largest;
    //     heapify(arr, index, curr);
    //   }
      
    // }
    
    // void deleteFromHeap(){
    //   swap(arr[1], arr[index]);
    //   index--;
      
    //   heapify(arr, index, 1);
      
    // }
};

void heapify(int *arr, int index, int curr){
      if(curr > index)return;
      int left = 2 * curr;
      int right = 2 * curr + 1;
      //find the largest inde
      int largest = curr;
      //cjck with leftindex
      if(left <= index && arr[left] > arr[largest])largest = left;
      if(right <= index && arr[right] > arr[largest])largest = right;
      
      //what if largest == curr, do nothing, curr
      
      //else 
      
      if(largest != curr){
        swap(arr[curr], arr[largest]);
        curr = largest;
        heapify(arr, index, curr);
      }
      
    }
    
void heapSort(int * arr, int size, int curr){
  while(curr > 1){
    swap(arr[1], arr[curr]);
    curr--;
    heapify(arr, curr, 1);
  }
}

void buildHeap(int *arr, int n){
  for(int i = n / 2; i>= 1;i--){
    heapify(arr, n, i);
  }
}



int main() 
{
  // Heap pq(3000);
  // pq.insert(5);
  // pq.insert(7);
  // pq.insert(8);
  // pq.insert(2);
  // pq.insert(4);
  // pq.printHeap();
  // pq.deleteFromHeap();
  // pq.printHeap();
  
  int arr[] = {-1,10, 20, 30, 40, 50};
  int size= 5;
  
  buildHeap(arr, size);
  
  for(int i = 1;i <= size;i++){
    cout << arr[i] << " ";
  }
  cout << endl;
  
  heapSort(arr, size, size);
  
  for(int i = 1;i <= size;i++){
    cout << arr[i] << " ";
  }
  cout << endl;
  
  
    
}