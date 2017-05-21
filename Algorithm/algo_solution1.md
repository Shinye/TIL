### 문제상황

[https://github.com/Shinye/Algorithm-Study/blob/master/test_vowel.cpp](https://github.com/Shinye/Algorithm-Study/blob/master/test_vowel.cpp)

띄어쓰기로 구분된 문자열을 입력받아, 띄어쓰기 기준의 단어들을 하나씩 배열 안에 넣고 싶을 때<br>ex) "abc def ghi jkl" 을 입력받은 후, abc/def/ghi/jkl 을 배열에 넣음



## I/O 관련

### getline

> Get line from string into string<br>Extracts characters from istream, and stores them into string until the delim(구분문자) is found (or the newline '\n')

```c++
istream& getline (istream& is, string& str, char delim);
istream& getline (istream& is, string& str);
```

- 입력 과정에서 띄어쓰기 포함된 한 줄 다 입력받고 싶을 때 쓸 수 있다.
- 주로 쓰는 `scanf("%s",s)` 나 `cin >> s` 은 띄어쓰기가 포함된 입력을 받을 수 없다. (띄어쓰기 전까지 잘림..)
- 따라서 C++의 경우 `getline(cin,s)` 를 쓰면 한 줄을 모두 입력받을 수 있다.



그렇다면 입력 받은 후 문자열 토큰들을 배열(혹은 벡터) 형태로 반환받고 싶을 땐 어떻게 해야할까?

### istringstream

> 문자열을 stream으로 바꾸어 주는 역할을 한다.

```c++
istringstream foo(string str); // 문자열 str을 stream화 시켜 변수 foo에 넣어준다.
```

이를 사용하기 위해서는 `#include <sstream>` 이 필요하다. (string stream의 약자)<br>문자열이 stream으로 바뀌기 때문에 `getline` 을 활용하기에 좋다. 

참고로 `cin`과 `cout` 은 객체이다. 입력용 스트림이 객체 cin의 클래스이며, 출력용 스트림이 객체 cout의 클래스이다.<br> 따라서 `getline` 을 쓸 때, 첫 번째 인자에 일반적으로 쓰이는 cin 뿐만 아니라 `istringstream`을 통해 stream형태로 바꿔준 foo 역시 쓸 수 있다.

문자열 토큰들을 벡터 형태에 추가하는 코드는 다음과 같이 짤 수 있다.

```c++
vector<string> tokenVector;
string str = "abc def ghi jkl mno";
istringstream foo(str);
string token;

while(getline(foo, token, ' ')){ // eof까지 while문을 돌린다.
  tokenVector.push_back(token);
}
```

참고로 while(getline(…)) 를 쓸 때 delim의 유무의 차이를 궁금해서 확인해봤다…ㅎㅎ

* delim이 없을 때

  ![https://68.media.tumblr.com/bf4de5713745a247c2be11e35f5ecf1b/tumblr_oq8sl3Cntt1w8w3y8o1_540.png](https://68.media.tumblr.com/bf4de5713745a247c2be11e35f5ecf1b/tumblr_oq8sl3Cntt1w8w3y8o1_540.png)

  ​


* delim이 있을 때

  ![https://68.media.tumblr.com/6eb6e981d2cda29b530804752a52dec9/tumblr_oq8sl3Cntt1w8w3y8o2_540.png](https://68.media.tumblr.com/6eb6e981d2cda29b530804752a52dec9/tumblr_oq8sl3Cntt1w8w3y8o2_540.png)

  > delim이란? **구분문자**. 일반 텍스트 및 데이터 스트림에서 별도의 독립적 영역 사이의 경계를 지정하는 데에 쓰임.



### stream

그렇다면 스트림이 정확하게 뭘까? 스트림에 대하여…~~~



## 그 외

### find 함수 - string에 있는 특정 문자 탐색

`#include <string>` 필요!<br>string 클래스 메소드 `find` 는, string에 있는 특정 문자(열)을 탐색할 때 쓸 수 있다.

```c++
string str1 = "hello world!";
str1.find("world!"); // "world!"" 문자열이 발견된 첫 위치를 반환한다.

if(str1.find("world!") != string::npos){
  // "world!"라는 문자열을 찾았을 때의 동작.
}
```

find 메소드를 실행 후, 탐색에 실패한 경우는 `string::npos` 를 리턴한다. 



### 벡터를 리턴하는 함수도 만들 수 있다..!!

```c++
vector<string> foo(){
  vector<string> bar;
  ...
  return bar; // vector을 리턴
}
```





### 참고 URL

[C++ string 정리](http://makerj.tistory.com/127#string간의-문자열-복사)<br>[string::find](http://www.cplusplus.com/reference/string/string/find/)<br>[Stream에 대해](http://m.blog.naver.com/kks227/220221664888)