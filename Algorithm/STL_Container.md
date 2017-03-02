# STL Container

*Container 목록 및 특징은 완성될 때 까지 수시로 추가합니다.

STL은 Standard Template Library의 약자로, **알고리즘, 컨테이너, 함수, 이터레이터** 로 이루어져 있다.



## Pair

자료형 pair를 사용하면 두 자료형 V1, V2를 한꺼번에 묶을 수 있다. Pair이라는 이름과 같이 반드시 두 개씩 묶어야 한다.<br>첫 번째 자료는 `first `, 두 번째 자료는 `second` 로 접근할 수 있다. 

`#include <utility>`에 존재하지만 다른 헤더파일들에 이미 존재하고 있기 때문에 따로 include하는 일은 없다.<br>pair을 선언하는 방법은 `생성자` 와 `make_pair` 를 사용하는 방법 두 가지가 있다.

```c++
// Pair를 선언하는 다양한 방법들

pair<int, int> p1;
cout << p1.first << ' ' << p1.second; // 0 0

p1 = make_pair(10,20);
cout << p1.first << ' ' << p1.second; // 10 20

p1 = pair<int, int>(30,40);
cout << p1.first << ' ' << p1.second; // 30 40

pair<int, int>(50,60) p2;
cout << p2.first << ' ' << p2.second; // 50 60

// Pair안에 Pair를 또 선언할 수 있다.
pair<pair<int,int>, pair<int, char>> p3;
make_pair(make_pair(10,20), make_pair(30,'forty'));
cout << p3.first.first << ' ' << p3.first.second; // 10 20
cout << p3.second.first << ' ' << p3.second.second; // 30 forty
```



## Tuple

기존의 Pair가 두 개의 자료형을 묶을 수 있었다면 Tuple은 여러 개를 묶을 수 있다.

접근방식은 .first .second .third …가 아닌, `get` 을 이용해 인덱스에 접근하여야 한다.<br> tuple을 사용하기 위해선 `#include <tuple>`을 정의해야 한다. tuple을 선언하는 방식은 다음과 같다.

```c++
tuple<int, int, int> t1 = make_tuple(1,2,3);
cout << get<0>t1; // 1
cout << get<1>t1; // 2
cout << get<2>t1; // 3

// 주의!!! get<> 의 꺽새 사이에 변수는 넣을 수 없다. 따라서 for문을 돌리는 것이 불가능하다.
```



## ⭐️ Vector

vector는 길이를 변경할 수 있는 배열이다. vector를 사용하려면 코드 상단에 `#include <vector>` 를 선언해주면 된다. 예제를 통하여 알아보자.<br>  

```c++
#include <iostream>
#include <vector>
using namespace std;

int main(){
  // 다양한 선언방식들
  vector<int> v1; // 길이 0
  vector<int> v2(10); // 길이 10
  vector<int> v3(20,3); // 길이 20의 벡터, 벡터 v3의 모든 원소값들이 3으로 초기화되어 있다.
  vector<int> v4 = {1,2,3,4}; // 벡터 v4에 각각 원소 초기화
  vector<pair<int,int>> v5; // 벡터 원소의 자료형에 pair도 쓸 수 있다.
  vector<pair<int,int>> v6 = {{1,2},{3,4}};
  int n=10, m=20;
  vector<vector<int>> v8(n, vector<int>(m)); // 이차원 배열 설정과 동일. int v8[n][m]; 
  
  // 원소 삽입 및 삭제
  vector<int> a = {1,2,3,4,5};
  
  a.push_back(6); // [1,2,3,4,5,6]
  a.push_back(7); // [1,2,3,4,5,6,7]
  
  a.pop_back(); // [1,2,3,4,5,6]
  a.pop_back(); // [1,2,3,4,5]
  a.pop_back(); // [1,2,3,4]
  
  a.clear(); // []
  a.resize(5); // [0,0,0,0,0]
  
  a.clear(); //[]
  a.push_back(1); //[1]
  a.push_back(2); // [1,2]
  
  a.resize(5); // [1,2,0,0,0]
  a.resize(3); // [1,2,0]

  return 0;
}
```



```c++
vector<int> v1 = {1,2,3,4};
cout << "size : " << v1.size(); // 4
cout << "front = " << v1.front(); // 1
cout << "back = " << v1.back(); // 4

for (int i=0; i<v1.size(); i++) {
    cout << v1[i]; // 1 2 3 4
}

for(int &x :v1){
  cout << x; // 1,2,3,4
}

print(v1); // 1,2,3,4

/* insert */
auto it = v1.begin();
v1.insert(it,5); // 5,1,2,3,4 / it의 위치는 1에.

it = v1.begin()+1;
v1.insert(it,4,0); // 5,0,0,0,0,1,2,3,4

it = v1.begin()+2;
vector<int> v2 = {9,8,7,6,5};
v1.insert(it, v2.begin(), v2.end()); // 5 0 9 8 7 6 5 0 0 0 1 2 3 4

/* erase */
vector<int> v3 = {1,2,3,4,5,6,7};

v3.erase(a.begin()+2); // 1 2 4 5 6 7
v3.erase(a.begin()+1, a.begin()+3); // 1 5 6 7 왜냐하면 [begin, end) 이기 때문이다..

```



## MAP

> [https://github.com/Shinye/Algorithm-Study/blob/master/cracking_1_5_v1.cpp](https://github.com/Shinye/Algorithm-Study/blob/master/cracking_1_5_v1.cpp) <br>map을 이용해 푼 알고리즘 문제

자료구조 중 HashMap과 파이썬의 dictionary와 비슷한 개념. key와 value로 이루어져 있다.

```c++
map<int, int> m1;
map<char, int> m2 = {{a,1},{b,2},{c,3}};
map<int, int> m3 = {{4,1}, {2,5}, {5,7}};

cout << "m1 size : " << m1.size(); // 0
cout << "m2 size : " << m2.size(); // 3
cout << m2[a] << m2[b] << m3[c]; // 1 2 3

for (int i=1; i<=5; i++) {
    if (m3[i]) {
      cout << i << ' '; // 5 1 7
    }
}

for(auto p : m3){
  cout << p.first << ' ' << p.second<< '\n'; 
  /*
  2 5
  4 1
  5 7
  key값이 정렬되서 나온다...왜지???? ranged-base for문 다시 공부하기;;
  */
}
```