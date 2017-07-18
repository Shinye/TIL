# class
자바스크립트는 기존의 클래스 중심의 객체지향 언어와는 달리 `프로토타입 중심` 의 언어이다.<br> 따라서 class가 애초에 존재하지 않지만 class를 사용하는 여타 객체지향 언어(JAVA, Python, C++...) 에 익숙한 사람들의 수요에 의해 ES6부터 새롭게 적용 된 문법이다.<br>하지만 그럼에도 불구하고 자바스크립트는 `프로토타입 중심` 임에는 변함 없고, class 역시도 프로토타입을 기반으로 만들어진 것이다. (영상의 비유에 의하면 케잌 위의 설탕 모형 스러운 거라고...)

자바스크립트로 설정한 class에 `typeof()` 를 입혀보면 실은 `function` 임을 알 수 있다. JS에는 클래스 정말 없으니 속지 말자 😊
![https://drive.google.com/uc?id=0B3Or0Wv2t1xwSUpZMTh3aDc5c0k](https://drive.google.com/uc?id=0B3Or0Wv2t1xwSUpZMTh3aDc5c0k)

class를 이용한 예제를 보자.

```javascript
class Mammal{
    constructor(sound){
        this._sound = sound;
        console.log("sound : ", this._sound);
    }

    talk(){
        console.log("talk : ", this._sound);
        return this._sound;
    }
}

console.log("type of mammal class : ",typeof(Mammal));

class Dog extends Mammal{
    constructor(){
        super("woof!!");
    }
}

let fluffy = new Dog();
fluffy.talk();
```

- **constructor()** : constructor 메소드는 class 로 생성된 객체를 생성하고 초기화하기 위한 특수한 메소드.  "constructor" 라는 이름을 가진 특수한 메소드는 클래스 안에 한 개만 존재할 수 있다. 만약 클래스에 한 개를 초과하는 constructor 메소드를 포함한다면, SyntaxError 가 발생.
- **extends** : 우리가 흔히 알고있듯 클래스명 뒤에 extends를 붙이면 이 뒤에 상속받고자 하는 클래스 명을 써주면 된다.
- **super()** : Calling the constructor of the inherited class<br>상속 받은 클래스 내의 생성자를 호출하는 것이다.
- 일반적인 객체지향 언어에서 클래스 내에서 쓰이는 `private` 은 자바스크립트에는 **존재하지 않고 제공되는 유사한 기능도 없다.** <br>따라서 private하게 쓰고 싶은 멤버 변수 앞에 `_` 를 붙여주면 private이니 건들지 말라는 뜻의 코딩컨벤션도 존재한다.


상속관계는 다음과 같이 확인할 수 있다.

![https://drive.google.com/uc?id=0B3Or0Wv2t1xwdWtXRTZOWE5GOTg](https://drive.google.com/uc?id=0B3Or0Wv2t1xwdWtXRTZOWE5GOTg)



### 참고 URL
[Class keyword - Object Creation in JavaScript P7 - Fun Fun Function
](https://youtu.be/Tllw4EPhLiQ?list=PL0zVEGEvSaeHBZFy6Q8731rcwk0Gtuxub)<br>
[Classes](https://developer.mozilla.org/ko/docs/Web/JavaScript/Reference/Classes)