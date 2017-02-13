# 구조체 / 클래스 / 생성자

구조체와 클래스는 분명한 차이점이 있지만 공통점 역시 많습니다. 클래스에서 멤버함수를 제외하면 구조체가 되고, 구조체에서 함수를 추가하여 확장한 것이 클래스가 됩니다. C언어에서 부터 비롯된 구조체와, 구조체의 부족한 점을 보완하여 만들어진 C++ 클래스에 대해 기록하여봅니다.

C++ 폴더를 따로 만들어 넣어야 하나 고민했지만…알고리즘 폴더에 넣은 이유는 구조체 혹은 클래스가 기본 알고리즘(링크드리스트, 이진트리 등)을 C/C++로 구현할 때 필수적으로 쓰이는 것이기 때문입니다…처음엔 이걸 이해하지 못해서 코드를 읽지 못해 고생을 많이 했던 기억이 납니다. 😥 (제 기준) 알고리즘을 구현을 할 때 클래스를 중심으로 씀에도 구조체를 꼼꼼히 작성하는 이유는 클래스가 구조체를 기반으로 발전한 개념이기 때문입니다. 따라서 구조체에 대한 이해가 탄탄하면 클래스에 대한 이해가 쉬워집니다.





## 구조체

구조체란 쉽게 말해 변수들이 모여 있는 집합체다. 다시 말해, 논리적 공통점이 있는 서로 다른 타입의 다른 변수 (Variety of data types that have a logical connection) 들을 필요에 의해 한 곳에 모아놓아 사용할 수 있도록 하는 **사용자 정의 데이터형**이다. 배열과 같은 문법으로 사용자 정의 데이터형을 만들면 동일한 데이터형만을 그룹지을수 있기 때문에 단순한 형태만 정의가능하다는 단점이 있는데, 이것을 보완하기 위해 만들어진게 구조체라는 문법이다.

멤버변수로 쓰일 수 있는 변수의 종류는 다양하며 개수에 제한이 없다(성능이 허락할 때 까지). 일반 변수부터 시작해 배열, 포인터, 심지어 다른 구조체까지 포함할 수 있다. 하지만 구조체는 어디까지나 멤버를 포함시키는 것 뿐, **static const register같은 지정자들을 붙이거나, 초기화 해줄 수 없다!**

구조체는 C언어의 모든 데이터 타입 중 가장 덩치가 큰 타입이다. 이렇게 덩치가 커서 어떻게 활용을 할 수가 있을까?

예를 들어, 야구선수 명단 관리 프로그램을 만든다고 가정하였을 때 필요한 정보는 다음과 같을 것이다.<br>선수이름, 소속 팀, 나이, 포지션, 타율, 평균자책점 등등…  이렇게 비슷한 정보들을 한꺼번에 묶어서 관리할 수 있다면 프로그래밍을 설계하기도 쉽고 가독성도 좋아질 것이다. 

위의 예시를 구조체로 선언해보자면 다음과 같다.

```c++
#include <iostream>
using namespace std;

typedef struct BaseballPlayer{ 
  string name;
  string team;
  int age;
  string position;
  double AVG;
  double ERA;
};

int main(){
  // BaseballPlayer이라는 이름의 데이터형을 가진 변수 선언.
  BaseballPlayer pitcher; 
  BaseballPlayer *outfielder;  
  BaseballPlayer arr[100];
}
```

구조체를 선언할 때의 기본 형식은 다음과 같다. 이렇게 선언된 구조체명이 새로 만들어진 데이터형의 이름이 된다. 즉 int char같은 역할을 한다는 뜻이다. 

```c++
// case1
typedef struct 구조체명{ // typedef : 사용자정의 구조체를 만들어라!
  데이터형 변수명;
  데이터형 변수명; 
  ...
}; // 괄호때문에 얼핏보면 함수같이 생겼지만 함수가 아닌 엄연한 선언문이니 세미콜론(;)을 붙이는 것을 잊지 말자!

// case2
typedef struct {
  데이터형 변수명;
  데이터형 변수명;
  ...
} 구조체명;

```

구조체를 선언할 때 `typedef`를 붙이는 것은 선택사항인데, 붙이는 것이 적극 권장된다.

```c++
int main(){
	// 1. typedef 키워드를 붙이지 않을 시 구조체 변수를 선언해줄 때 앞에 꼭 'struct'를 붙여줘야 한다.
  	struct BaseballPlayer pitcher;
  	struct BaseballPlayer outfielder;
  	
  	// 2. typedef 키워드를 붙여 사용자 정의 구조체를 만들면 struct를 붙이지 않아도 된다.
  	// 또한, typedef키워드를 사용해야만 구조체배열을 선언할 수 있다.
   	BaseballPlayer pitcher;
  	BaseballPlayer *outfielder;  
  	BaseballPlayer arr[100];
}
```





### 멤버 연산자 ( . )

배열을 참조할 땐 `[]연산자`를 , 포인터를 참조할 땐 `*` 연산자를, 그렇다면 **구조체의 멤버**를 참조할 땐 어떤 연산자를 써야할까?<br>바로 `. 연산자`를 쓰면 된다. 위의 예시를 기반으로 작성해 보자면 다음과 같다.

```c++
pitcher.ERA; //구조체변수 이름.멤버이름 
```

활용 예시는 다음과 같다.

![](https://68.media.tumblr.com/c3bd3606cb598d058478c38ceee7ca21/tumblr_ol5ebj9vn31v80c66o1_1280.png)

BaseballPlayer의 구조체의 내용을 가지는(BaseballPlayer 데이터형의) 구조체 변수 pitcher을 선언한 후 이 구조체 변수의 멤버들을 .연산자를 통해 값을 하나씩 대입한 후 출력한 예시이다.

그렇다면 멤버연산자를 통해 어떻게 멤버가 읽혀지는걸까? 다음의 그림을 보면 멤버들은 순서대로 메모리가 나란히 할당된다.





![](https://68.media.tumblr.com/2a5f86643f22efb88f2bd92e32f7f65c/tumblr_ol5eaasH8a1v80c66o1_540.png)



구조체의 이름은 곧 상수 포인터이다. **구조체의 이름에는 첫 번째 멤버의 시작 주소 값이 담겨있다는 뜻이다.** 배열의 이름이 첫 번째 원소의 주소값을 갖고 있다는 것과 유사한 개념이다. [포인터 TIL 참고](https://github.com/Shinye/TIL/blob/master/Algorithm/Pointer_CallByValue_CallByRef.md)

따라서 `구조체변수의_이름.멤버이름` 이라는 연산을 해주면 다음과 같이 포인터 덧셈을 해준 후, 간접 참조연산을 해준다.

```c++
구조체변수의_이름.멤버이름 = *(첫 번째 멤버 주소 값 + 시작점에서 부터 명시한 멤버 주소 만큼의 바이트);
//arr[n] = *(첫번째 원소 주소값+n) 과 유사한 개념
```

실제로 확인해보면 다음과 같다.

![](https://68.media.tumblr.com/9e891be085cd7bbdf500ed5e39a52098/tumblr_ol5fn2omDQ1v80c66o1_1280.png)

구조체변수명인 pitcher의 주소값과 구조체의 첫번째 멤버인 pitcher.name의 주소 값이 같음을 확인할 수 있다.

32씩 더해진 이유는 name, team, position 전부 string 이라 32바이트 짜리들이니까 :)





### 포인터 멤버 연산자 ( -> )

구조체 포인터를 선언할 경우 포인터 멤버 연산자를 사용해야 한다. 위의 예시에 기반한 작성 방법은 다음과 같다.

```c++
outfielder -> name; // 구조체_포인터_이름 -> 멤버_이름
```

포인터 멤버 연산자 ->가 없던 옛날에는 `(*outfielder).name` 과 같은 형식으로 참조를 했다. 하지만 하나하나 포인터를 명시해주어야 하는 것이 불편함을 감안하여 태어나게 된 것이 `->` 연산자이다. 보통 화살표(arrow) 연산자라고 불린다.

따라서 `구조체포인터이름->멤버이름 == (*구조체포인터이름).멤버이름` 이라는 공식이 성립한다.



활용 예시는 다음과 같다 (위의 기존 예시에서 작성한 구조체 구성과 조금 다릅니다 예전에 캡처해둔거라..;;)

![](https://68.media.tumblr.com/5cc035161d5cf1cf4f8caa28f50d136b/tumblr_ol5g4cbCCU1v80c66o1_1280.png)







## 클래스

> 아..드디어 클래스다…이제야 클래스…헥헥…..;ㅅ;…길었다..

C에서 구조체는 타입이 서로 다른 변수들의 집합이라고 했다. 즉 구조체는 변수만을 멤버로 가질 수 있었다.

하지만! 클래스는 변수 뿐만 아니라 **함수**까지도 멤버로 가질 수 있다. 따라서 구조체가 함수를 통해 스스로 동작까지도 할 수 있다. 클래스는 결국 구조체의 확장판이며, 기존의 구조체에서 보지 못했던 클래스만의 새로운 문법들은 새로 만들어진 멤버 함수를 위한 문법들이 많다. 물론 기존의 구조체 문법 역시 그대로 사용 가능하다. ( .연산자, ->연산자 등.. )

앞서 살펴본 구조체와 같이, 클래스 역시 **사용자 정의 데이터 형**의 역할을 한다. C++의 기본 자료형(int, char, double..)처럼 편하게 쓸 수 있는 새로운 데이터타입을 프로그래머가 직접 만들 수 있도록 하고자 하는 것이다.

클래스의 예시를 작성해 보겠다.

```c++
#include <iostream>
using namespace std;

class BasketballPlayer{ 
  string name, team, position;
  double scoring, assist, rebound;
  
  int goal();
  void blockShot();
  void steal();
};

int main(){
  //...
}
```

구조체와 마찬가지로 클래스는 어디까지나 자료형(type)일 뿐, 그 자체가 정보를 저장하는 변수가 아니다. 따라서 클래스 안에서는 멤버변수들을 초기화를 할 수 없다. <br>단순히 어떤 타입의 멤버들이 클래스 안에 포함되어 있는지 컴파일러에게 알려주는 정도의 역할을 하며, 타입을 가지고 선언한 모든 것들에 대한 메모리 할당을 해준다.



### 범위 연산자

기존의 멤버변수를 참조할 때는 `. 연산자` 를 사용하면 되었다. 그렇다면 멤버함수를 참조하기 위해서는 어떤 연산자를 써야할까?

바로 `:: 연산자(범위 연산자)` 를 사용하면 된다. 이 연산자를 통해 어디 클래스의 멤버인지 지정한다. 다음과 같이 표현할 수 있다.

```c++
#include <iostream>
using namespace std;

class BasketballPlayer{ 
  string name, team, position;
  double scoring, assist, rebound;
  
  int goal(int score);
  void blockShot();
  void steal();
};

int BasketballPlayer :: goal(int score){ // 반환형 소속클래스 :: 멤버함수(매개변수)
    scoring += score;
    return scoring;
}

void BasketballPlayer :: blockShot(){
    cout << "block" << endl;
}

void BasketballPlayer :: steal(){
    cout << "steal" << endl;
}
```



### 접근 제어 지시자

클래스 안의 경우, 접근 지시자가 없는 경우엔 그 클래스 안의 멤버들을 외부에서는 건들지 못하도록 막아놓고 있다. (그러나 구조체는 접근 제어 지시자가 없으므로 접근할 수 있다. 이 점이 차이점 중 하나.) 따라서 우리는 원하는대로 엑세스 지정을 할 수 있도록 설정할 수 있다.

![](https://68.media.tumblr.com/226bfd99b88b3abfe64afebcf19e2434/tumblr_olb6r9aroK1v80c66o1_1280.png)

<br>

### 객체

**"클래스가 메모리상에서 구현된 실체"**

앞서 설명하였듯이 클래스는 어디까지나 타입일 뿐이지 그 자체가 정보를 저장하는 변수가 아니다. 우리가 정보를 저장하기 위해 변수를 선언할 때 `자료형 변수명;` 의 형태를 사용하듯, 객체를 생성하는 것 역시 `클래스명 객체명;` 의 형태를 사용하여 객체를 선언한다.

```c++
#include <iostream>
using namespace std;

class BasketballPlayer{ 
c  double scoring, assist, rebound;
  
  int goal(int score);
  void blockShot();
  void steal();
};

//...

int main(){
  BasketPlayer player1, player2, player3; 
  // 클래스명 객체명; 
  // 클래스 BasketPlayer의 인스턴스(객체) player1, player2, player3 생성!
  
}
```

위의 예시와 같이 메인함수 안에 `BasketPlayer player1;` 을 선언함으로써 실제로 메모리에 할당된 것을 가리켜 인스턴스(instance) 라고 한다. 그리고 인스턴스를 다르게 말해 `객체` 라고 부른다.

<br>



## 생성자

객체를 생성한 후에는 반드시 객체를 초기화 해주어야 한다.(쓰레기값을 갖지 않기 위해) <br>초기화에는 멤버 변수의 값을 초기화 하는 것 뿐만 아니라 객체의 동작에 필요한 메모리 공간이나 파일과 같은 여러가지 자원들을 할당받는 것도 포함된다. C++에서는 이를 담당하는 `생성자` 라는 특수한 함수가 존재한다. 생성자를 사용하면 객체 생성과 동시에 초기화 역시 가능하다. <br>생성자는 값을 반환하지 않으며, 매개 변수를 받을 수도 있고, 클래스명과 동일한 이름을 가진다!<br>만약 프로그래머가 생성자를 정의하지 않았을 시엔 디폴트 소멸자가 자동으로 삽입되어 호출된다.

정리하자면, 생성자는 **객체를 초기화한다는 한 가지 일과 이름이 클래스명과 동일하게 고정되어있다** 는 것이다.

자세한 내용은 다음의 생성자 예시를 보자.

```c++
class BasketballPlayer{
private:
  string name, team, position;
  ...
public:
  BasketballPlayer(){ // 매개변수 없으면 디폴트 생성자. 생성자는 반드시! 퍼블릭으로 선언되어야 한다.
    name = "Michael Jordan";
    team = "Chicago Bulls";
    position = "Small Forward";
    ...
  }
  
  // 하나의 클래스 안에 여러 생성자 중복 정의가 가능하다. 
  // 각기 다른 매개변수를 가지고 있음으로써(매개변수가 각기 다르거나 아예 없거나) 구분할 수 있다. 
  BasketballPlayer(string n, string t, string p){ 
    name = n;
    team = t;
    position = p;
  }  
};

// :: 연산자를 사용한다면 클래스 밖에서도 생성자를 선언할 수 있다.
BasketballPlayer::BasketballPlayer(string n){
  name = n;
}

int main(){
  BasketballPlayer player1; // 디폴트 생성자 호출 (생성자를 호출할 땐 컴파일러가 직접 호출한다.)
  BasketballPlayer player2("Magic Johnson", "LA Lakers", "Point Guard"); //두번째생성자 호출
  BasketballPlayer player3("Stephen Curry");
  
  return 0;
}
```



### this 포인터

**"this는 멤버 함수 혹은 생성자를 실행하는 현재 객체"**

한 가지 주의할 점이 있는데, 생성자의 매개변수 이름은 멤버변수 이름과 동일하지 않도록 신경써야 한다는 점이다. 멤버변수와 매개변수의 이름이 동일하게 되면 변수의 우선순위 법칙 때문에 자기자신에다 자신의 값을 대입하는 꼴이 된다. 

만약 두 변수(생성자의 매개변수, 멤버변수) 이름을 굳이 동일하게 사용하고 싶다면 이 때 쓸 수 있는 것이 `this포인터` 이다. 현재 객체의 멤버 변수임을 나타내고자 하는 변수 앞에 `this->`를 붙여 현재 객체의 멤버 변수임을 알린다. **멤버 함수**에 관해서도 동일하게 사용할 수 있다.

```c++
BasketballPlayer::BasketballPlayer(string name){
  this->name = name;
}
```



## 소멸자

객체에 따라서는 객체가 소멸되는 시점에서 마무리 작업을 해주어야 하는 경우가 있다. <br>예를 들어, 생성자에게 [동적메모리](https://github.com/Shinye/TIL/blob/master/Algorithm/allocation.md) 를 할당했다면 객체가 소멸될 때 이 동적메모리 공간을 다시 시스템에 반납하여야 한다.(소멸자 안에 동적메모리 공간을 반납하는 코드를 작성해주어야 겠지유..?ㅎㅎ) 만약 반납하지 않고 객체가 소멸되어 버리면 메모리 누수가 일어나게 된다. 소멸자는 객체 소멸 시에 자동적으로 호출되는 함수다.

자세한 사항은 다음의 예시를 통해 확인해보자.

```c++
class BasketballPlayer{
private:
  char *name;
  string team, position;
  ...
public:
  BasketballPlayer(char *n, string t, string p){
	name = new char[strlen(n)+1]; // 동적할당함. strlen()함수 : 문자열 길이를 바이트 단위로 반환함.
    strcpy(name,n);
    team = t;
    position = p;    
  }
  
  ~BasketballPlayer(){ // 소멸자 역시 외부에서도 선언될 수 있도록 public안에 넣어주자.
    delete [] name; // 동적할당에 사용된 메모리 반납.
  }

int main(){
  BasketballPlayer player1("Magic Johnson", "LA Lakers", "Point Guard");
  return 0;
}
```











### 참고URL

**구조체**<br>

[https://www.youtube.com/watch?v=6RLxPdZ59y0&index=1&list=PL5F6fN0oclNc54H7H8b9u6fiuQyO3-Chw](https://www.youtube.com/watch?v=6RLxPdZ59y0&index=1&list=PL5F6fN0oclNc54H7H8b9u6fiuQyO3-Chw)<br>[http://blog.naver.com/skout123/50132227516](http://blog.naver.com/skout123/50132227516)<br>[http://www.tipssoft.com/bulletin/board.php?bo_table=FAQ&wr_id=968](http://www.tipssoft.com/bulletin/board.php?bo_table=FAQ&wr_id=968)<br>책 C++에스프레소 

**클래스** <br>

[http://blog.naver.com/skout123/50135070635](http://blog.naver.com/skout123/50135070635)<br>[http://blog.naver.com/skout123/50142077311](http://blog.naver.com/skout123/50142077311)<br>책 C++에스프레소 

**생성자**<br>[http://blog.naver.com/skout123/50142139894](http://blog.naver.com/skout123/50142139894)<br>책 C++에스프레소 