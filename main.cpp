#include <iostream>
#include <fstream>
using namespace std;
int comp=0,shifts=0;
void insertionsort1(int a[],int n) {
    int j, x;
    for (int i = 1; i < n; ++i) { //80 90 60| 30 50 70 40
        x = a[i]; //90
        for ( j = i; j >0 ; j--) {//yes
            comp++;
            if(x<a[j-1]) {
                a[j] = a[j - 1]; // 80 60 90 // 60 80 90
                shifts++;
            }else
                break;
        }
        a[j] = x;

    }
    cout<<endl;
    cout << "number of comparisons: " << comp << endl;
    cout << "number of shifts: " << shifts << endl;
}
void printarr(int a[],int n){
    cout<<"the sorted array is: ";
    for (int i = 0; i <n ; ++i) {

        cout<<a[i]<<" ";
    }

}
int comp2=0,shifts2=0;
int binarysearch(int a[],int l,int h,int elem){
    if (h<=l){
        comp2++;
        if(elem>a[l]) // 7 8 // 8>7// index= l+1=0+1=1
            return l+1;
        else
            return l; // 7 2 // 2<7// index=l=0
    }
    int m=(l+h)/2;
    comp2++;
    if(a[m]==elem){  // 2 3 4| 3 // 3==3// index=m+1=1+1=2

        return m+1;
    }
    if(a[m]>elem){ // 2 3 4| 1// 3>1 // h=m-1=1-1=0
        return binarysearch(a,l,m-1,elem);
    }
    else{// 2 3 4| 5// 3<5 // l=m+1=1+1=2
        return binarysearch(a,m+1,h,elem);

    }
}
void insertionsort(int a[],int n) {
    int x, j,index;
    for (int i = 1; i < n; ++i) {
        j=i-1;
        x = a[i];
        index= binarysearch(a, 0, j, x);
        while (j >=index ) { //yes
            shifts2++;
            a[j + 1] = a[j]; // 80 60 90 // 60 80 90
            j--;
        }

        a[j + 1] = x;
   }
    cout<<endl;
    cout<<"number of comparisons: "<<comp2<<endl;
    cout <<"number of shifts:  "<< shifts2 << endl;
}
template <class T>
void selectionSort(T data[], int n){
    cout<<"Selection Sort: "<<endl;
    int comparisons=0;
    int moves=0;

    for(int i=0,j,least;i<n-1;i++){
        for(j=i+1,least=i;j<n;j++){
            comparisons++;
            if(data[j]<data[least]){
                least=j;
            }
        }

        swap(data[least],data[i]);
        moves+=3; //increment 3 moves for one single swap
    }

    cout<<"Comparisons: "<<comparisons<<endl;
    cout<<"Moves: " <<moves<<endl;
}
template <typename T>
void shellSort(T a[], int n) {
    cout<<"Shell Sort: "<<endl;
    int comparisons=0;
    int moves=0;

    for (int gap=n/2; gap>0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            T tmp = a[i];
            int j = i;
            comparisons++;

            for (; j >= gap && tmp < a[j - gap]; j -= gap){
                a[j] = a[j - gap];
                moves++;
                comparisons++;
            }
            a[j] = tmp;

        }
    }

    cout << "Comparisons: "<<comparisons<<endl;
    cout << "Moves: "<<moves<<endl;
}


void mergeFN(int A[],int left,int middle,int right,int &comps,int &moves){

    int n1=middle-left +1;
    int n2=right-middle;

    int L[n1];
    int R[n2];

    for (int i=0;i<n1;i++){
        L[i] =A[left+i];
        moves++;
    }
    for (int j=0;j<n2;j++){
        R[j]=A[middle+ 1+j];
        moves++;
    }

    int k=left;
    int i=0;
    int j=0;


    while (i<n1 &&j<n2){
        comps++;
        if (L[i]<=R[j]){
            A[k++]=L[i++];
            moves++;
        }
        else{
            A[k++]=R[j++];
            moves++;
        }
    }

    while (i<n1){
        A[k++]=L[i++];
        moves++;
    }
    while (j<n2){
        A[k++]=R[j++];
        moves++;
    }
}

void mergeSort(int A[],int left,int right,int &comps,int &moves){
    if (left<right){
        int middle=left+(right-left)/2;
        mergeSort(A,left,middle,comps,moves);
        mergeSort(A,middle+1,right,comps,moves);
        mergeFN(A,left,middle,right,comps,moves);
    }
}

int main() {
    cout<<"welcome to our programm:) "<<endl;
    cout<<"TASK1 : "<<endl;
    int n;
    cout<<"enter the size of the array : "<<endl;
int s;
cin>>s;
int arr[2][s];
cout<<"enter array elements: ";
    for (int i = 0; i < s; ++i) {
        cin>>arr[0][i];
        arr[1][i]=arr[0][i];

    }
    cout<<"case 1: ";
    insertionsort1(arr[0],s);
    printarr(arr[0],s);
    cout<<endl<<"case 2: ";
    insertionsort(arr[1],s);
    printarr(arr[1],s);
    cout<<endl;
    cout<<"TASK2 : "<<endl;
    ifstream ArraysFile("arrays.txt");

    int SizeOfArray;
    ArraysFile>>SizeOfArray;

    while (!ArraysFile.eof()){
        int* OriginalArray=new int[SizeOfArray];
        int* SelectionArray=new int[SizeOfArray];
        int* ShellArray=new int[SizeOfArray];
        int* MergeArray =new int[SizeOfArray];

        for (int i= 0; i<SizeOfArray;i++) {
            ArraysFile>>OriginalArray[i];
            SelectionArray[i]=OriginalArray[i];
            ShellArray[i]=OriginalArray[i];
            MergeArray[i]=OriginalArray[i];
        }

        cout<<"Original Array: "<<endl;
        for(int i= 0;i<SizeOfArray;i++) {
            cout<<OriginalArray[i]<<" ";
        }
        cout<<endl;

        int comps_counter=0;
        int moves_counter=0;

        selectionSort(SelectionArray,SizeOfArray);
        cout<<"Sorted Array: ";
        for (int i=0;i<SizeOfArray; i++) {
            cout<<SelectionArray[i]<<" ";
        }
        cout <<endl;

        shellSort(ShellArray,SizeOfArray);
        cout<<"Sorted Array: ";
        for (int i = 0; i<SizeOfArray; i++){
            cout<<ShellArray[i] <<" ";
        }
        cout<<endl;

        comps_counter=0; //resetting the comps and moves counters before moving to mext array
        moves_counter=0;

        cout <<"Merge Sort: "<<endl;
        mergeSort(MergeArray, 0,SizeOfArray - 1,comps_counter,moves_counter);
        cout<<"Comparisons: "<<comps_counter<<endl;
        cout<<"Moves: " <<moves_counter<<endl;
        cout<<"Sorted Array: ";
        for (int i=0; i <SizeOfArray;i++){
            cout<<MergeArray[i]<<" ";
        }
        cout<<endl;

        delete[] OriginalArray;
        delete[] SelectionArray;
        delete[] ShellArray;
        delete[] MergeArray;

        ArraysFile>>SizeOfArray; //next array size reading
    }

    return 0;
}