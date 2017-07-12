# Object creation / Part3

## Prototype

자바스크립트, C++, JAVA, Ruby, Python은 모두 객체지향 언어라는 공통점이 있지만,<br> 자바스크립트는 `프로토타입 기반`의 객체지향 언어 / C++, JAVA, Ruby, Python은 `클래스 기반`의 객체지향 언어이다. 아래에 후술 될 프로토타입의 특징들을 알게 되면 자바스크립트의 대부분이 객체로 이루어져 있으며, (프로토타입 기반이기 때문에) 거의 모든 객체는 프로토타입을 가지고 있다는 말을 이해할 수 있게 될 것이다. (처음엔 이 말을 이해하지 못했었다…ㅎㅎㅎ) 

참고로 자바스크립트에서는 `문자열(string)`, `숫자(number)` , `true/false` , `null/undefined` 를 제외하면 **전부 객체**다.

자바스크립트는 상속 기능을 가능하게 해주는 클래스가 없다. (ES2015부터 class 키워드를 지원하기 시작했으나, JAVA,C++에 익숙한 사람들의 수요를 반영한 문법적인 요소일 뿐이며 자바스크립트는 여전히 프로토타입 기반의 언어다.) 하지만 자바스크립트는 객체지향 언어이기도 하기 때문에 상속 기능의 구현이 가능한데, 이는 `Prototype` 이라는 개념을 통해 객체지향의 '상속' 기능을 구현할 수 있다.



### 객체 리터럴의 상속

다음의 예시를 보자

```javascript
function talk(){
  console.log(this.sound);
}

let animal = {
  speak : talk
};

let cat = {
  sound : "meow!"
};

Object.setPrototypeOf(cat, animal); // 객체 cat의 프로토타입을 객체 animal로 설정한다.
cat.speak();
/*
cat객체로 감 -> speak 메서드가 없는데? --그러면 이 객체(cat)의 프로토타입에 있나?--> cat의 프로토타입으로 감
-> animal객체 방문 -> speak찾았다! -> "meow" 출력
*/
```

객체 리터럴 방식을 통해 만든 객체를, 객체 리터럴 방식으로 만든 또 다른 객체의 프로토타입으로 설정하고 싶을 때<br>`setPrototypeOf(객체,프로토타입객체)` 를 이용하여 만들 수 있다.

여기서 한 가지 짚고 넘어가야 할 것은, 객체 리터럴 방식이 겉보기엔 생성자 함수와 관련이 없어보여 상속받는 프로토타입이 없다고 느껴질 수 있다.

하지만 객체 리터럴 방식 역시도 **생성자 함수를 통해 만들어지는 것**이다.

```javascript
let foo = {};
let foo = new Object();
// 두 문장이 같은 뜻이다.
```

 객체 리터럴로 생성된 모든 객체는 프로토타입 객체가 같으며, 이 프로토타입 객체는 Object.prototype이다.<br>[new키워드](https://github.com/Shinye/TIL/blob/master/JavaScript/new.md) 를 통해 생성자를 호출하면, 생성자 함수의 프로토타입이 생성된 객체의 프로토타입이 된다. 따라서 위의 객체 리터럴 방식과 같이 `new Object()` 로 생성된 객체는 `Object.prototype` 을 상속받는다. 

마찬가지로,  `new Array()` 를 통해 배열 객체를 생성하게 되면 이 객체는 `Array.prototype` 를 프로토타입으로 갖는다. 물론 `프로토타입 체인` 개념에 의해 Array객체의 프로토타입이자 최상위 객체인 `Object.prototype` 를 상속받기도 하다. 

그렇다면 자꾸 언급되는 `.prototype` 은 어떤 개념인가?



## Prototype Link / Prototype Object

일반적으로 prototype link와 prototype object를 통틀어 prototype이라고 부른다.

### prototype Object

모든 객체의 조상은 생성자 함수이다. 대표적인 `네이티브 객체`인 Array, Function, Date도 모두 생성자 함수로 정의되어 있다. 그래서 생성자 함수와 prototype이 중요한 것이다.

생성자 함수가 정의되면 다음과 같은 두 과정이 발생한다.

- `new 키워드` 를 통해 객체를 만들 수 있다.
- 해당 생성자 함수의 `prototype object` 생성 및 연결. 생성되는 디폴트 프로토타입 객체는 빈 객체이다.



그림으로 그려보자면 다음과 같다.

![https://68.media.tumblr.com/bd41da97f15f61bb3c6a211ff9827533/tumblr_osyxrq4YVE1v80c66o1_1280.png](https://68.media.tumblr.com/bd41da97f15f61bb3c6a211ff9827533/tumblr_osyxrq4YVE1v80c66o1_1280.png)



그림을 통해 알 수 있듯, `prototype 속성` 은 **생성자 함수만이 가질 수 있는 속성**이다. prototype 속성을 통해, 생성자 함수를 정의했을 때 함께 생성 된 `prototype object` 에 접근할 수 있다.

prototype object에 상속 받게 할 프로퍼티를 추가하고 이 것을 새로 만든 객체에 상속받게 하고 싶다면<br> `생성자함수명.prototype.프로퍼티명` 에 값을 할당하면 된다.

다음과 같은 코드를 짜면 될 것이다.

```javascript
function Person(name, age){
  this.name = name;
  this.age = age;
}

Person.prototype.eyes = "2개";
Person.prototype.talk = function(){console.log("hello world!");}

let shinye = new Person("shinye song", "27");
shinye.name; // shinye song
shinye.age; // 27
shinye.talk(); // hello world!
shinye.eyes; // 2개
```

위의 코드를 그림으로 표현하면 다음과 같다.

![https://68.media.tumblr.com/54a1cba70b1f45fb69d277614214d056/tumblr_osz3e3TLxo1v80c66o1_1280.png](https://68.media.tumblr.com/54a1cba70b1f45fb69d277614214d056/tumblr_osz3e3TLxo1v80c66o1_1280.png)



### prototype link

`prototype 속성` 은 생성자 함수만 갖고 있던 것과는 달리, `__proto__` 속성은 모든 객체가 다 가지고 있다. `__proto__` 는 객체가 생성될 때 조상이였던 함수의 `prototype object` 를 가리킨다. 

생성자 함수를 통해 만들어진 객체에, 상속받은 프로퍼티를 호출하고자 한다면 원하는 프로퍼티가 나올 때 까지 prototype 객체로 거슬러 올라갈 것이다. 최상위 객체인 `Object`의 prototype object에도 없을 시 undefined를 리턴한다.

 이를 가능하게 해주는 것이 `__proto__` 속성이며,  이 속성을 통해 상위 프로토타입과 연결 된 형태를 `prototype chain` 이라고 한다. 이러한 프로토타입 체인 개념 때문에 (최상위 객체인 Object를 제외하고) 모든 객체가 프로토타입을 가지고 있으며, Object의 자식이라는 말이 설명되는 것이다.



### 프로토타입 프로퍼티는 어떻게 가져올까?

생성자 함수의 내의 프로퍼티들은 객체가 생성될 시 해당 객체의 프로퍼티로 포함된다. 따라서 객체가 이미 생성된 후 생성자 함수에 프로퍼티를 추가해도 이미 만들어진 객체를 이를 반영하지 못한다.

하지만 프로토타입의 프로퍼티는 값을 복사해서 가져오는 것이 아닌, 프로토타입 객체의 프로퍼티가 호출이 될 때 마다 **프로토타입 객체의 위치에 가 참조를 하는 과정**을 갖기 때문에 프로토타입 객체에 프로퍼티가 중간중간 추가되어도 이미 만들어진 객체라도 참조가 가능하다.

![https://drive.google.com/uc?id=0B3Or0Wv2t1xweDdLOXNMN1d0NzA](https://drive.google.com/uc?id=0B3Or0Wv2t1xweDdLOXNMN1d0NzA)







### 참고 URL

[[Javascript ] 프로토타입 이해하기](https://medium.com/@bluesh55/javascript-prototype-%EC%9D%B4%ED%95%B4%ED%95%98%EA%B8%B0-f8e67c286b67)

[Javascript 기초 - Object prototype 이해하기](http://insanehong.kr/post/javascript-prototype/)

[상속과 프로토타입](https://developer.mozilla.org/ko/docs/Web/JavaScript/Guide/Inheritance_and_the_prototype_chain)

[_ _ proto _ _ vs prototype](https://www.youtube.com/watch?v=DqGwxR_0d1M&list=PL0zVEGEvSaeHBZFy6Q8731rcwk0Gtuxub&index=5)

