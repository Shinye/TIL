
# Object creation / Part4
## Object.create()
> "Static method on the object prototype"

객체 리터럴 방식, 생성자와 new키워드를 사용하는 방식 외에 객체를 생성하는 세 번째 방법으로는 `Object.create()` 함수를 쓰는 방법이 있다. 문법은 다음과 같다.

```javascript
Object.create(proto, [propertiesObject]);
```
`Object.create()` 의 첫 번째 인자는 **필수 인자**로, 새로 만들 객체의 `프로토타입` 이다.<br>두 번째 인자는 새로 만들 객체의 속성(property)과 각 속성들의 특성들을 나열한 것이다.


```javascript
let bar = {
	prop1 : "hello",
	prop2 : "world"
}

let foo1 = Object.create(bar); // 객체 bar을 상속받음
let foo2 = Object.create({x:1, y:2}); // 리터럴 객체를 상속받음.
```
Object.create()의 첫 번째 인자를 `null` 로 설정해도 오류는 없다. 하지만 아무것도 상속 받지 못하게 되기 때문에 toString()과 같이 Object객체가 제공하는 기본적인 메소드 조차 사용하지 못한다.<br>따라서 기본적인 최상위 객체만을 상속받고 싶다면 첫 번째 인자에 `Object.prototype` 을 넣어주면 된다.

```javascript
var foo = Object.create(Object.prototype);
```

두 번째 인자를 사용한 예시는 다음과 같다.
![https://drive.google.com/uc?id=0B3Or0Wv2t1xwLW8waS1RUEtlbWc](https://drive.google.com/uc?id=0B3Or0Wv2t1xwLW8waS1RUEtlbWc)


### Q. 왜 Object.create()가 필요한건지?
자바스크립트에서 객체를 새로 생성할 때 프로토타입이 반드시 수반된다는 것을, `new 키워드` 를 사용하는 것 보다 좀 더 직관적으로 표현할 수 있기 때문이다.

### Q. 비슷한 역할을 하는 setPrototypeOf() 도 있다.
`setPrototypeOf()` 는 프로토타입의 개념을 설명하고 이해하는 데에는 좋지만, JS engine 성능에는 치명적으로 나쁘다고 한다.  따라서 사용을 지양해야 하고, 프로토타입을 간편하게 직접 설정할 수 있는 Object.create()를 쓰는 것이 훨씬 낫다.
<br>

📌 TIP : 다음과 같이 작성을 하면 생성자 함수의 역할을 할 수 있다.

```javascript
const cat = {
  init: function(sound){
    this.sound = sound;
    this.name = "kitty"
    console.log("this : ", this);
    return this
  },
  makeSound: function(){
    console.log(this.sound);
  }
}

const mark = Object.create(cat).init("meow!");
mark.makeSound();

```

### 참고URL
[MDN : Object.create()](https://developer.mozilla.org/ko/docs/Web/JavaScript/Reference/Global_Objects/Object/create)<br>[Object.create - Object Creation in JavaScript P6 - FunFunFunction #57](https://youtu.be/CDFN1VatiJA?list=PL0zVEGEvSaeHBZFy6Q8731rcwk0Gtuxub)<br> 책 자바스크립트 완벽가이드
