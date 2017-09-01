# 정렬

선형 배열의 index를 일정 기준에 따라 정렬하는 방법을 말한다. 일반적으로 가장 작은 값에서 가장 큰 값 순으로 정렬시킨다.



## 선택정렬

> 비교 기준 인덱스 보다 작은 값을 '선택' 한다.

최대, 최소, 평균 실행시간 모두 **Θ(n^2)** 이다.

선택정렬의 로직은 다음과 같다.

- 우선 배열의 첫 index를 값 비교의 기준점으로 삼고, 그 뒤의 index들을 순서대로 돌며 비교 기준점인 첫 index 보다 작은 값을 발견할 시 그 값을 첫 index 값과 swap 한다.
- 이렇게 하면 첫번째 index에 배열에서 가장 작은 값을 갖게 되므로 더 이상 첫 번째 index를 손댈 필요는 없다. 따라서 그 다음 index인 두 번째 index를 비교 기준점으로 삼고, 그 뒤의 index들을 순서대로 돌며 비교기준점인 두 번째 index보다 작은 값을 발견할 시 그 값을 첫 index 값과 swap한다.
- 이러한 일련의 과정들을 반복한다. 비교 기준점은 마지막 index-1까지만 가지면 될 것이다.

그림으로 표현하자면 다음과 같다.

![https://68.media.tumblr.com/85c59c6093edebdf4215630a0eaf5485/tumblr_oor2n1tGVH1w8w3y8o1_540.jpg](https://68.media.tumblr.com/85c59c6093edebdf4215630a0eaf5485/tumblr_oor2n1tGVH1w8w3y8o1_540.jpg)



코드는 다음과 같다.

```c++
#include <iostream>
using namespace std;

int main(){
    int arr[10] = {10,-1,3,2,6,4,9,30,7,14};
    int temp;
    
    for(int i=0; i<9; i++){
        for (int j=i; j<10; j++){
            if(arr[i]>arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    for(int k=0; k<10; k++){
        cout << arr[k] << ", ";
    }
}
```





## 삽입정렬

최대, 최소, 평균 실행시간 모두 **Θ(n^2)** 이다.

숫자가 적힌 카드를 갖고 있고 이 카드들이 순서대로 정렬되어 있다고 가정하자. 만약 새로운 숫자가 적힌 카드를 받았을 때 정렬된  기존의 카드 안에 집어넣기 위해서는 어떻게 해야할까? 앞서 정렬된 카드들의 숫자를 새 카드의 숫자와 하나하나 비교하면서 올바른 자리를 찾아갈 것이다. 

삽입정렬도 이와 비슷한 개념이다. 로직은 다음과 같다.

- 1번 인덱스부터 시작해 배열에 따라 루프하며 알맞는 자리를 찾아간다.
- 0~n-1번째 배열 인덱스가 정렬되어있다고 가정하고, n번째와 n+1번째 숫자를 비교한다.
- 만약 n번째 숫자가 n+1번째 숫자보다 크면 둘의 위치를 바꾼다.
- n번째 숫자가 n+1번째 숫자가 커지는 때가 오면 비교를 종료하고 다음 숫자를 비교한다. 



그림으로 나타내면 다음과 같다.

![https://68.media.tumblr.com/bf564cc583677fd84449a2c655161d33/tumblr_oor7j8NxSh1w8w3y8o1_1280.jpg](https://68.media.tumblr.com/bf564cc583677fd84449a2c655161d33/tumblr_oor7j8NxSh1w8w3y8o1_1280.jpg)



코드는 다음과 같다.

```c++
#include <iostream>
using namespace std;

int main(){
    int arr[10] = {10,-1,3,2,6,4,9,30,7,14};
    int temp;
    for(int i=1; i<10; i++){
        for(int j=i-1; j>=0; j--){
            if(arr[j]>arr[j+1]){
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            } else break;
        }
    }
    
    for(int i=0; i<10; i++){
        cout << arr[i] << ", ";
    }
}
```



## 병합정렬



