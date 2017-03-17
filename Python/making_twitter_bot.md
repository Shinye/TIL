# 트위터봇을 만들며 배운 점



## 1) if _ _ name _ _ == "_ _ main _ _":

(_ 사이에 띄어쓰기를 안쓰면 자꾸 마크다운 문법으로 변환을 시켜줘서 부득이하게 띄어쓰기를 하였습니다..<br>`if __name__ == "__main__"` 입니다!!!)

이 문장을 이해하기 앞서 파이썬의 `namespace` 와 `name`, 그리고 `module` 이라는 개념을 알아야 한다.

### name

name은 일반적으로 다른 언어에서의 `변수` 의 역할을 한다고 볼 수 있다. 하지만 파이썬 특유의 유연한 성격 때문에 기존의 다른 언어들의 변수들과는 달리 파이썬의 name은 담을 수 있는 요소들이 훨씬 많다.

```python
a = 12
b = 'B'
c = [1,2,3,4]
dict = {'a':'hello','b':'world'} # dict['a'] == 'hello' / dict['b'] == 'world'

# 일반적인 값들 뿐만 아니라 함수 역시 name 안에 담을 수 있다.
def foo():
    print "hello world"
   
newF = foo
newF() # foo()를 실행시킨 결과와 동일하게 "hello world" 출력됨

# name의 재사용 역시 가능하다.
var = 12
var = "hello"
var = [1,2,3,4]
```

`name`개념은 파이썬의 객체 시스템과 함께한다. 파이썬의 모든 요소들은 객체이다. 숫자, 문자열, 배열, 함수, 클래스 등 모든 것이 객체이고 그 객체에 접근하기 위해서 필요한 것이 name이다. 이러한 각 객체들에 name을 할당하면 각 name들을 해당 객체들에 접근할 수 있다.



### namespace와 module

namespace라는 이름에서 알 수 있듯, 네임스페이스는 말 그대로 많은 name들을 담고 있는 공간이라는 뜻이다. <br> namespace를 이해하기 위해선 module에 대한 이해가 필요한데,  `module` **은 파이썬 코드를 담고 있는 파일이다.** 해당 파일에는 파이썬 클래스, 함수 또는 단순하게 names 의 리스트가 들어있을 수 있다.

각 모듈은 자신만의 고유한 namespace를 갖고 있다. (모듈의 namespace의 이름은 보통 해당 모듈의 파일 이름을 가진다.)  그래서 동일한 모듈내에서 동일한 이름을 가지는 클래스나 함수를 정의할 수 없다. <br>하지만 각 모듈들은 완벽하게 독립적이기 때문에 (namespace의 이름이 다르기 때문에) 동일한 이름을 가지는 클래스나 함수를 정의할 수 있다. 

> 예를 들어, 한 학교의 3학년 2반에도 3학년 5반에도 김광현이라는 학생이 있다고 가정해보자. 2반 교실 안에서 수업을 진행하고 있을 때 선생님이 광현이가 발표해봐, 라고 말한다면 당연히 2반의 김광현이 발표를 할 것이고 5반의 경우도 5반의 김광현이 발표를 할 것이다.<br> 하지만 방송실에서 누군가 김광현학생 교무실로 오세요 하고 부른다면, 부르는 대상이 2반의 김광현일지 5반의 김광현일지 알 수 없다. 이름 앞에 몇 반의 김광현인지 정확히 언급을 해야 할 것이다. <br>이 때 언급되는 반 이름이 바로 namespace의 역할을 해주는 것이고, 한 namespace에는 한 명의 김광현만 있는 것이다. 
>
> (김광현선수 재활 잘하고 돌아오셔서 20승 하세요…화이팅🙂ㅋㅋㅋ)

module을 import하는 방법에는 여러가지가 있다. 방법에 따라 namespace가 달라질 수 있다.

1. **import (module_name)**

   모듈을 import 하는 가장 간단한 방법이고, 일반적으로 추천되는 방법이다. 이렇게 import 를 하게 되면 module 의 name 을 prefix 로 사용함으로써 모듈의 namespace 에 접근할 수 있다.

   아래 예제에서 sys 는 모듈 이름이고, path 는 sys 모듈의 namespace 에 담겨있는 name 이다. 따라서 path 에 접근을 하기 위해서는 모듈 이름인 sys 를 prefix 로 붙여서 sys 모듈의 namespace 에 접근한 후에 사용해야 한다.

   ```python
   import random
   print random.randint(0,100)
   ```

2. **from (module_name) import (name, )**

   모듈의 namespace 에서 import 에서 지정된 name 들을 직접 가져오도록 한다. 이렇게 하게 되면 import 이후에 지정한 name 들은 module 의 name을 prefix 로 지정하지 않고도 접근이 가능하다. 하지만, 이 경우에 module 에서 import 된 이름과 main script 에서 지정된 이름이 동일한 경우, 나중에 정의되는 이름으로 대체되어서 이전 것에 접근이 불가능하게 된다. <br>단지 몇개의 name 만 필요하다고 명확하게 알고 있는 경우에 사용하는 것이 유용하다.

   ```python
   from random import randint
   print randint(0,100)
   ```

3. __from (module_name) import * __

   2 와 동일하지만, module 에 있는 모든 name 을 직접 현재 namespace 로 가져오게 된다. 이렇게 되면 namespace 가 섞이게 되어서 일반적으로 사용을 권장하지 않는다. 차라리 첫번째 타입(1번)의 import 를 사용하는 것이 좋다.



### _ _ main _ _  namespace

앞서 import된 namespace가 처리되는 과정을 알아보았다. 그렇다면 import를 통해서가 아닌, 파이썬 인터프리터가 최초로 파일을 읽어서 실행하는 경우를 보자.

파이썬 인터프리터는 소스파일을 읽고, 그 안의 모든 코드를 실행하게 되는데, 코드를 실행하기 전에 특정한 변수값을 정의한다. 그중 하나가 `__name__` 이라는 변수(name)를 `__main__` 으로 세팅을 한다.<br>즉 `python script.py` 와 같이 직접 쉘에서 실행하는 경우에는, 파이썬 인터프리터가 해당 script.py 를 'script' 라는 이름의 모듈과 namespace 가 아닌 `__main__` 이라는 이름의 모듈 그리고 namespace 로 간주하여 다루게 된다.<br>( Whenever you run a simple Python script, the interpreter treats it as module called __main__, which gets its own namespace. )

따라서 처음에 궁금했던 아래 문장은 **'만일 이 파일이 인터프리터에 의해서 실행되는 경우라면'** 이라는 의미를 갖는다.

```python
if __name__ == "__main__":
```

즉 본인이 구현한 코드가 다른 파이썬 코드에 의해서 모듈로 import 될 경우도 있을 수 있고, 파이썬 인터프리터에 의해서 직접 실행될 경우도 있을 수 있는데, 위 코드는 인터프리터에 의해서 직접 실행될 경우에만 실행하도록 하고 싶은 코드 블럭이 있는 경우에 사용한다.<br>

### 참고 URL

[ [Python] if __name__ == "__main__": 의미](http://pinocc.tistory.com/175)<br>[A guide to Python Namespaces](https://bytebaker.com/2008/07/30/python-namespaces/)

<br><br>

## 2) if문, 비교연산자, 반복문 

### if문

기존의 다른 언어(C++, JAVA, JS …) 들과 동일하지만 그 작성 방법에 있어 조금 차이점이 있어 기록해둔다.

```python
if a > b :
    print "case 1"

elif a == b : #기존의 다른 언어들에서 else if라고 썼던 것과는 달리 elif라고 써준다.
    print "case 2"

else:
    print "case c"
```



### 비교연산자 (and, or, not)

비교연산자 역시 기존의 다른 언어들과 동일한 표기법을 사용한다. 하지만 예외의 케이스가 있다.

| 기존의 연산자 형식 | 파이썬 연산자 형식 |          설명          |
| :--------: | :--------: | :------------------: |
|  x \|\| y  |   x or y   | x와 y 둘중에 하나만 참이면 참이다 |
|   x && y   |  x and y   |   x와 y 모두 참이어야 참이다   |
|            |   not x    |     x가 거짓이면 참이다      |



### 반복문(for문)

파이썬에서의 for문의 기본적인 구조는 다음과 같다.

```python
for 변수 in 리스트(또는 문자열, 튜플 ...):
    수행할 문장1
    수행할 문장2
    
# 전형적인 for문
test_list = ['one', 'two', 'three'] 
for i in test_list:
    print(i)
    
a = [(1,2), (3,4), (5,6)]
for (first, last) in a:
    print(first + last)
```



일반적으로 다른 언어들에서 쓰던 for문 구조는 python에서는 다음과 같이 작성할 수 있다.

```javascript
// 기존의 다른 언어 (JavaScript)
for(var i=0; i<10; i++){
  console.log('hello')
}
```

```python
# Python
for i in range(0,10): #range(a,b) : a부터 b미만의 숫자를 포함하는 range객체
    print 'hello'
```













## 3) 문자열 자르기



## 4) 파싱, 파서



## 5) freeze



## 6) 함수에서 한 개 이상의 값을 return 하기



## 7) 기타 외부 modules

### Requests

### BeautifulSoup

### APScheduler

### Tweepy