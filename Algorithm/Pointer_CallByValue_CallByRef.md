# Pointer

### 포인터 : 변수의 **주소**를 저장하는 특수한 변수

다음의 예제를 보자.

```c++
#include <iostream>
using namespace std;

int main(){
  int a = 20;
  int *ptr_a; 
  ptr_a = &a;
  
  cout << "변수 a의 값 : " << a; // 20
  cout << "변수 a의 주소값 : " << &a; // 0x7fff5fbff77c
  cout << "포인터 ptr_a의 값 : " << ptr_a; // 0x7fff5fbff77c
  cout << "포인터 ptr_a가 가리키는 변수의 값 : " << *ptr_a; //20
}
```

위의 예제 코드 중 5~7번째 줄을 보자.

![https://68.media.tumblr.com/ed5c7228060afff562530f1fc5719ba1/tumblr_okubmnd0vK1v80c66o2_540.png](https://68.media.tumblr.com/ed5c7228060afff562530f1fc5719ba1/tumblr_okubmnd0vK1v80c66o2_540.png)<br>

자료형* <-가 포인터변수를 나타낼 수 있는 하나의 자료형처럼 여긴다. int* ptr_a; int *ptr_a 모두 동일한 뜻이다.<br>

![https://68.media.tumblr.com/141a36f632d7f2c7666d5190b11fd564/tumblr_okud5o480d1v80c66o1_540.png](https://68.media.tumblr.com/141a36f632d7f2c7666d5190b11fd564/tumblr_okud5o480d1v80c66o1_540.png)

위의 개념과 같이, 포인터 변수(ptr_a)는 다른 변수(a)의 위치를 가리키는 것이 역할이다. 위치를 가리키는 방법으로 그 다른 변수(a)의 주소 값을 저장한다.

공부하다 보면 문득, 포인터변수를 선언하는 과정에서 포인터변수의 자료형을 꼭 내가 가리킬 변수와 동일한 자료형을 써야하는지 의문이 들 때가 있었다. 확인해본 결과 동일한 자료형을 쓰지 않으면 오류가 발생하는 것을 알 수 있다.

![](https://68.media.tumblr.com/2fadd1c8976cf3cbfdd6a329b29f4f47/tumblr_okucnsRik71v80c66o1_540.png)<br>

![](https://68.media.tumblr.com/991ea3b2ab915d8036b5becdfe7672c6/tumblr_okucnsRik71v80c66o2_1280.png) <br> ptr_test의 자료형을 int로 바꿔보았을 때, 자료형이 서로 맞지 않는다는 오류가 발생함을 확인할 수 있다.

![](https://68.media.tumblr.com/ace08db0cd7d7ba594b841ba063bc2ff/tumblr_okucnsRik71v80c66o3_540.png)<br>



*의 역할은 포인터변수를 처음 선언할 때도 쓰이고, 선언 후에도 쓰일 수 있는데 이 경우에는 조금 다른 용도로 쓰인다.

이미 선언된 포인터 변수 ptr_a 앞에 * 를 붙여 `*ptr_a` 을 선언하면 ptr_a가 가리키고 있는 변수의 값을 가져온다.(==ptr_a에 저장된 주소값과 매치되는 변수의 값.) <br> 즉, `*ptr_a` 는 곧 `변수 a` 와 동일한 의미를 가진다.( *ptr_a == a // true )<br> 따라서 위의 예시 코드대로라면 *ptr_a를 출력하면 0x7fff5fbff77c 대신 20을 출력할 것이다. 

더 나아가 응용해보자면 `&*ptr_a == ptr_a` 임을 알 수 있다. 

```
&*ptr_a == &a == ptr_a
```





# Call By Value vs Call By Reference

- Call by value : 함수의 인자로 사용될 때 변수의 **값을 그대로 복사** 하여 사용하고, 함수가 닫히면 그 값을 사라진다. 함수 안에서 선언된 지역변수는 그 함수 내부가 사용범위이기에 자신이 선언된 함수가 종료되면 자신도 종료된다.
- Call by reference : 함수의 인자로 사용될 때 포인터를 사용해 주소를 가진 참조변수를 이용한다.



이해를 돕기 위해 swap코드를 각 경우에 맞게 사용해보자.

### Call By Value의 경우

```c++
void swap(int x, int y){
  int tmp;
  tmp = x;
  x = y;
  y = tmp;
}

int main(){
  int a = 10;
  int b = 20;
  swap(a,b); // swap의 두 인자는 변수 a와 b의 값을 복사한 값을 가진다.
  
  cout << a << b; // a == 10, b == 20 => SWAP이 이뤄지지 않음.
}
```

![](https://68.media.tumblr.com/47f251a82a4e333339d4b94fb0201364/tumblr_okwgz7QjLx1v80c66o1_400.png)





### Call By Reference의 경우

```c++
void swap(int *x; int *y){
  int tmp;
  tmp = *x; // *x == a
  *x = *y; // *y == b
  *y = tmp;
}

int main(){
  int a = 10;
  int b = 20;
  swap(&a, &b);
  
  cout << a << b; // a==20, b==10 정상적으로 두 변수의 값이 swap되었다.
}
```

![https://68.media.tumblr.com/0bfea78321fc26e8b3fcf99e07a22b3c/tumblr_okwgz7QjLx1v80c66o2_400.png](https://68.media.tumblr.com/0bfea78321fc26e8b3fcf99e07a22b3c/tumblr_okwgz7QjLx1v80c66o2_400.png)

swap함수의 매개변수 int *x와 int *y에 각각 &a와 &b를 대입해 (int *x = &a / int *y = &b 와 같은 셈) swap 함수 안에서 *x와 *y를 쓰면 메인함수 안의 변수 a와 b의 값을 직접 수정할 수 있는 것이 된다.

