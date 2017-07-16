# Arrow function
ES6부터 새로 추가 된 Arrow function은 기존의 함수 문법을 보다 간결하게 쓸 수 있는 `익명함수` 이다.<br>익명함수이기 때문에 객체 내의 메서드가 아닌 일반적인 함수로 쓰는 것이 권장되며(안되는 건 아님), 생성자로 사용할 수 없다.

## 기본 문법
```javascript
(param1, param2, …, paramN) => { statements }
(param1, param2, …, paramN) => expression
          // 다음과 동일함:  => { return expression; }
 
// 매개변수가 하나뿐인 경우 괄호는 선택사항:
(singleParam) => { statements }
singleParam => { statements }
 
// 매개변수가 없는 함수는 괄호가 필요:
() => { statements }
```

### 화살표 함수의 본문
화살표 함수의 본문은 블록 없이 쓰는 방법과, 익숙한 (),{} 블록을 사용하는 방법도 있다.<br>블록이 없으면 암시적으로 그 값은 return값으로 정해진다. 반면 블록을 사용할 때 return값이 있다면 `return` 을 명시해 주어야 한다.

```javascript
(x,y) => x+y // return x+y
(z,q) => {return z+q}
```

### 리터럴 객체 반환 방법
화살표 함수를 활용하여 리터럴 객체를 반환하기 위해선 반드시 {}를 ()로 감싸주어 `({})` 의 형태로 리턴해주어야 한다.

```javascript
var foo = () => ({ bar1 : "1", bar2 : "2" })
```

### 화살표 함수 앞에 new 키워드를 쓸 수 없음.
앞서 말한 바와 같이 화살표 함수를 통해 생성자 함수를 만드는 것은 권장되지 않는다.

```javascript
var Foo = () => {};
var foo = new Foo(); // TypeError: Foo is not a constructor
```

또한 화살표 함수는 **프로토타입을 가지지 않는** 자바스크립트의 몇 안되는 요소 중 하나이다.

```javascript
var Foo = () => {};
console.log(Foo.prototype); // undefined
```


### 바인딩 되지 않는 this
화살표 함수 등장 이전의 함수들은, 함수를 정의하면 각각의 객체를 위한 `this` 가 존재하였다. [참고링크](https://github.com/Shinye/TIL/blob/master/JavaScript/bind_this.md#this)

```javascript
function Person() {
    // Person() 생성자는 `this`를 자신의 인스턴스로 정의.
    console.log(this); // Person(){}
 
    setTimeout(function growUp() {
        // 비엄격 모드에서, growUp() 함수는 `this`를
        // 전역 객체로 정의하고, 이는 Person() 생성자에
        // 정의된 `this`와 다름.
        console.log(this); // 브라우저 기준 전역 객체인 Window 객체를 나타냄.
    }, 1000);
}
 
var p = new Person();
```

위와 같은 경우를 해결하기 위해 setTimeout 함수 뒤에 `.bind()` 함수를 붙여주거나, 함수의 this를 따로 변수에 할당하여 그 변수를 setTimeout 함수 내에 사용하는 방법이 있다.

반면 화살표 함수는 자신의 this객체를 만들지 않는다. 따라서 위와 같은 수정 과정을 거치지 않아도 된다.

```javascript
function Person() {
    console.log(this); // Person(){}
 
    setTimeout(() => { console.log(this) }, 1000); // Person(){}
}
 
var p = new Person();
```


### 참고URL
[[자바스크립트] ES6(ECMA Script 6) - 화살표 함수(Arrow function)](http://beomy.tistory.com/19)



