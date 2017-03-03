# 문자열과 숫자 사이의 변환

### 1. string to int

string에서 int로 형변환을 하고 싶을 때 `atoi()` 함수를 사용한다. <br>(array to int의 약자인가? string에 문자열 배열 값을 복사하니..)

atoi함수의 정확한 형태는 `atoi(char*)` 이다. 함수의 인자가 char* 형이기 때문에 인자를 `c_str()`함수로 변환해주어야 한다. c_str() 함수는 해당 string 문자열의 첫 번째 문자의 주소를 반환한다. 이는 곧 해당 string문자열의 주소를 반환한다는 뜻과 같다. (이 개념에 대한 자세한 사항은 [여기](https://github.com/Shinye/TIL/blob/master/Algorithm/Pointer_CallByValue_CallByRef.md#배열과-포인터의-관계) 참조.)

```c++
string str = "34";
int intValue = atoi(str.c_str()); 
```



### 2. int to string

int를 string으로 바꾸기 위해서는 `to_string(int)` 함수를 사용하면 된다.

```c++
int intValue = 5;
string str = to_string(intValue);
```

숫자를 기존의 문자열에 포함시키고 싶을 때 숫자를 string으로 형변환을 한 후 기존의 문자열에 추가하면 된다.