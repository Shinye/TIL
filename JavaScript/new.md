# Object creation / Part2

## new 키워드에 대하여

`new` 키워드는 객체를 생성하는 방법 중, 생성자 함수(Constructor) 를 사용하여 객체를 만들 때 함께 쓰는 키워드이다.<br> `new 생성자함수명()` 의 형식을 통해 자바스크립트에서 동일한 구성을 가진 객체를 여러 개 만들어 낼 수 있다.

**📌 생성자 함수란?**

생성자 함수를 통해 새로 만든 객체에 속할 프로퍼티들을 초기화 하는 역할을 한다.



**📌 new키워드와 생성자를 통해 객체를 만드는 방법**

```javascript
function bar(){
  this.name = "shinye";
  this.age "27";
}

var foo = new bar();

// 이제 foo객체는 다음과 같아진다.
foo = {
  name:"shinye",
  age:"27"
}

foo.name // "shinye"
```



1. **새 객체 생성** : 객체 리터럴로 생성되는 것과 동일. `var foo = {}`
2. **생성자 함수를 호출해 객체에 속한 프로퍼티 초기화** : 
   - 주어진 인자들과 함께 생성자를 호출한다. 이 때 방금 생성된 새 객체를 `this` 키워드의 값으로 설정해 전달한다. 
   - 생성자 함수는 이 this키워드를 통해 새로 생성된 객체(foo)의 프로퍼티 초기화
   - 일반적으로 생성자 함수는 return값을 반환하지 않는다.



### new가 하는 일

- **STEP 1 :** Create a new object (plain object. no properties!)<br>새로운 빈 객체를 만든다.
- **STEP 2 :** Set the prototype of the new object that just has created to be object<br>1 과정으로 만든 빈 객체의 프로토타입을 설정해준다. 이 프로토타입은 생성자 함수(constructor)의 `prototype property` 를 상속받는다.
- **STEP 3 :** Execute constructor with `this` keyword(`this` in constructor). `this` will set to the object that it created in step1<br>[`this`키워드](https://github.com/Shinye/TIL/blob/master/JavaScript/bind_this.md#this)에 step1에서 생성한 빈 객체를 대입해 생성자 함수를 실행한다.



new 키워드가 하는 일에 대해 직접 만들어보자.

```javascript
// 생성자 함수. 생성자를 통해 만들어진 객체는 이 생성자 내에 선언된 프로퍼티들을 프로퍼티로 갖는다.
function Person(saying){ 
  this.says = saying;
}

// 생성자 함수의 프로토타입. 생성자를 통해 만들어진 객체는 이 프로토타입의 프로퍼티들을 '상속'받는다.
Person.prototype.talk = function(){ 
  console.log("I say : ", this.saying);
}

function newExample(constructor){
  let obj = {}; // STEP1 : 빈 객체 만들기
  Object.setPrototypeOf(obj, constructor.prototype); // STEP2 : 생성자 프로퍼티 상속받기
  let args = Array.from(arguments); // == Array.prototype.slice.apply(arguments)
  constructor.apply(obj,args.slice(1)); /*STEP3 : 생성한 객체(obj)를 this에 넣어 생성자 함수 실행. 	이 생성자 함수를 실행시킴으로써 obj.says = saying이라는 객체의 프로퍼티가 추가되는 것이다.*/  
  
  return obj; // 생성한 객체를 return 함.
}
```

