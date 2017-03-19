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

`문자열객체.split('기준')` <br>문자열 객체에서 원하는 기준에 따라 문자열을 자를 수 있다. 다음의 예시를 통해 확인해보자.

```python
string1 = "hello world"
string1.split(' ') # ['hello','world']
string1.split(' ')[0] # 'hello'
string1.split(' ')[1] # 'world'

string2 = "this/is/string"
string2.split('/') # ['this','is','string']
string2.split('/')[0] # 'this'
string2.split('/')[1] # 'is'
string2.split('/')[2] # 'string'
```



## 4) 파싱, 파서

### 파싱

- 문장을 그것을 이루고 있는 구성 성분으로 분해하고, 그들 사이의 위계 관계를 분석하여 문장의 구조를 결정하는 것
- 일련의 문자열을 의미있는 토큰(token)으로 분해하고, 이들로 이루어진 파스 트리(parse tree)를 만드는 과정

### 파서

- 파싱을 수행하는 프로그램 모듈

- 인터프리터 나 [컴파일러](https://github.com/Shinye/TIL/blob/master/Algorithm/allocation.md) 의 구성요소 중 하나

  __인터프리터? __

  해석기. 프로그래밍 언어의 소스코드를 바로 실행하는 컴퓨터 프로그램 혹은 환경. 한 줄 한 줄 읽어가며 바로바로 처리됨.

## 5) pip requirements & freeze

보통 파이썬 가상환경을 통해 필요한 패키지들을 관리하고, 패키지는 파이썬 패키지 관리자인 pip를 통하여 설치한다.<br>보통 `pip install 패키지명` 명령어를 통해 하나하나 설치하는 경우가 일반적이다. 하지만 한꺼번에 설치할 패키지가 많을 경우  requirements.txt를 만들어 패키지 리스트를 이 파일에서 관리하고 이 파일을 통해 pip 설치 수행하는 것이 더 좋은 방법이다.

```python
pip install -r requirements.txt
```

하지만 경우에 따라 requirements.txt를 미리 만들지 않고, 개발서버의 가상환경에 여러 패키지를 이미 설치했을 수도 있다. 이런 경우는 아래와 같은 pip freeze 명령을 사용하여 requirements.txt 파일을 만들 수 있다.

(웹서버 heroku에 동일한 가상환경을 주어주기 위해 프로젝트 루트 디렉토리에 requirements.txt파일을 만들고, pip freeze명령어를 통해 requirements.txt에 현재 내 가상환경에 설치 된 패키지 목록을 입력시켰다.)

```python
pip freeze > requirements.txt 
# pip freeze의 결과물이 터미널에 출력되는게 아닌 requirements.txt에 출력되는 명령어.
# 출력결과
appdirs==1.4.3
APScheduler==3.3.1
BeautifulSoup==3.2.1
beautifulsoup4==4.5.3
bs4==0.0.1
funcsigs==1.0.2
futures==3.0.5
oauthlib==2.0.1
packaging==16.8
pyparsing==2.2.0
pytz==2016.10
requests==2.13.0
requests-oauthlib==0.8.0
six==1.10.0
tweepy==3.5.0
tzlocal==1.3
```



## 6) 함수에서 한 개 이상의 값을 return 하기

```python
# 1. Dictionary 사용
def foo(x):
    y0 = x+1
    y1 = x+2
    y2 = x+3
    return {'y0':y0, 'y1':y1, 'y2':y2}

# 2. list 사용
def foo(x):
    result = [x + 1]
  	result.append(x * 3)
  	result.append(y0 ** y3)
  	return result
```

## 7) 파이썬 인코딩 관련

작성하시오….ㅇ<-<



## 8) 기타 외부 modules

### Requests

Python에는 `requests` 라는 유명한 http request 라이브러리가 있다. 

0. 설치하기

    ```python
    pip install requests
    ```

1. 기본적인 사용 방법

   ```python
   import requests
   URL = "http://www.naver.com"
   req = requests.get(URL) #HTTP GET Request
   html = req.text #HTML 소스 가져오기
   ```

   ![https://68.media.tumblr.com/e29cf4d4d6cddbf6e4d7d5cea41f8c4b/tumblr_on0693monj1w8w3y8o1_1280.png](https://68.media.tumblr.com/e29cf4d4d6cddbf6e4d7d5cea41f8c4b/tumblr_on0693monj1w8w3y8o1_1280.png)

   다음과 같이 잘 됨을 확인할 수 있다.

   더 많은 기능들이 있지만 이번 프로젝트에는 다음과 같은 개념만 활용하였다.


### BeautifulSoup

Requests는 좋은 라이브러리이지만, html을 ‘의미있는’, 즉 Python이 이해하는 객체 구조로 만들어주지는 못한다. 위에서 req.text는 python의 문자열(str)객체를 반환할 뿐이기 때문에 정보를 추출하기가 어렵다.

따라서 [BeautifulSoup](https://www.crummy.com/software/BeautifulSoup/bs4/doc/)을 이용하게 된다. 이 BeautifulSoup은 추출해낸 html 코드를 Python이 이해할 수 있는 객체 구조로 `Parsing`하는 역할을 맡고 있고, 이 라이브러리를 통해 제대로 '의미있는' 정보들을 추출해낼 수 있다.

아래 코드에서는 BeautifulSoup 라이브러리를 사용해 문서를 파싱하고 그 결과를 출력하는 과정을 확인할 수 있다.<brsprettify 함수는 BeautifulSoup 에서 파싱 처리한 파서 트리를 유니코드 형태로 리턴하는 함수이다.

```python
# BeautifulSoup으로 html소스를 python객체로 변환하기.
# 첫 인자는 html소스코드, 두 번째 인자는 어떤 parser를 이용할지 명시.
# 여기선 Python 내장 파서인 html.parser를 이용했다.
# 이제 soup 객체에서 원하는 정보를 찾아낼 수 있다.
soup = BeautifulSoup(html, 'html.parser') #soup 객체 내에서 데이터를 탐색할 수 있다.

print(soup.prettify())
# <html>
#  <head>
#   <title>
#    The Dormouse's story
#   </title>
#  </head>
#  <body>
#   <p class="title">
#    <b>
#     The Dormouse's story
#    </b>
#   </p>
#   <p class="story">
#    Once upon a time there were three little sisters; and their names were
#    <a class="sister" href="http://example.com/elsie" id="link1">
#     Elsie
#    </a>
#    ,
#    <a class="sister" href="http://example.com/lacie" id="link2">
#     Lacie
#    </a>
#    and
#    <a class="sister" href="http://example.com/tillie" id="link2">
#     Tillie
#    </a>
#    ; and they lived at the bottom of a well.
#   </p>
#   <p class="story">
#    ...
#   </p>
#  </body>
# </html>
```

html 문서를 구성하는 요소나 속성 값들을 간단하게 탐색하거나 검색할 수 있다. 예제 코드에서의 find_all('a') 함수는 a 태그를 모두 찾아내 리스트를 반환하고 있으니 여기다 for ~ in 구문을 이용해 원하는 조건의 요소를 찾을 수도 있겠다.<br>get_text() 메소드를 이용해 텍스트만 뽑아 낼수도 있다.

```python
# soup 객체의 데이터 탐색 
print(soup.title) 
# <title>The Dormouse's story</title> 

print(soup.title.name) 
# u'title' 

print(soup.title.string) 
# u'The Dormouse's story' 

print(soup.title.parent.name) 
# u'head' 

print(soup.p) 
# <p class="title"><b>The Dormouse's story</b></p> 

print(soup.p['class']) 
# u'title' 

print(soup.a) 
# <a class="sister" href="http://example.com/elsie" id="link1">Elsie</a> 

print(soup.find_all('a')) # find_all은 함수!!
# [<a class="sister" href="http://example.com/elsie" id="link1">Elsie</a>, 
# <a class="sister" href="http://example.com/lacie" id="link2">Lacie</a>, 
# <a class="sister" href="http://example.com/tillie" id="link3">Tillie</a>]

print(soup.find(id="link3")) 
# <a class="sister" href="http://example.com/tillie" id="link3">Tillie</a>

################################################################################## 
for link in soup.find_all('a'): 
    print(link.get('href')) 
# http://example.com/elsie 
# http://example.com/lacie 
# http://example.com/tillie ################################################################################## 

print(soup.get_text()) 
```

저는 코드를 짤 때 다음과 같이 짰습니다.

![https://68.media.tumblr.com/f198992f8005d83366b0bc5dbdd0bdee/tumblr_on2c29joBH1w8w3y8o1_1280.png](https://68.media.tumblr.com/f198992f8005d83366b0bc5dbdd0bdee/tumblr_on2c29joBH1w8w3y8o1_1280.png)



### APScheduler

[Advanced Python Scheduler](http://apscheduler.readthedocs.io/en/3.0/userguide.html)의 약자. 파이썬 코드가 주기적으로 동작 할 수 있게 도와주는 파이썬 라이브러리. 프로그램 작업을 하다보면 호스트 시스템에서 동작하는 시간 관련 스케줄러 작업이 필요할 경우가 있다.

__APScheduler 수행방식(3가지)__

- Cron 방식 - Cron 표현식으로 Python code 를 수행
- Date 방식 - 특정 날짜에 Python code 를 수행
- Interval 방식 - 일정 주기로 Python code 를 수행



__Job Store__

APScheduler는 Job(Python Code)을 저장해두고 주기적으로 실행한다. 이 때 4가지 저장방식을 지원한다.

- Memory(기본)
- SQLAlchemy - RDBMS 에서 동작
- MongoDB
- Redis



__Scheduler 종류__

- [Blocking Scheduler](http://apscheduler.readthedocs.io/en/3.0/modules/schedulers/blocking.html#apscheduler.schedulers.blocking.BlockingScheduler) 단일 Job 수행 시
- [Background Scheduler](http://apscheduler.readthedocs.io/en/3.0/modules/schedulers/background.html#apscheduler.schedulers.background.BackgroundScheduler) 다중 Job 수행 시. background 에서 Job 들이 수행되며, 여러 Job 들을 등록하여 동시에 수행할 수 있다.



크롤링 튜토리얼을 따라하면서 Blocking Scheduler를 사용한 예시입니다. 10초에 한 번씩 scraping 함수를 실행시켰습니다.

![https://68.media.tumblr.com/5f0e3fb3b80cc80fdad4f77d1074fd52/tumblr_on2dopyvM91w8w3y8o1_1280.png](https://68.media.tumblr.com/5f0e3fb3b80cc80fdad4f77d1074fd52/tumblr_on2dopyvM91w8w3y8o1_1280.png)



### Tweepy