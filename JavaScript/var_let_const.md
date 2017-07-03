# var / let / const

기존의 ES5까지는 변수를 선언할 때 var을 이용하여 선언하였다.(물론 var이 없어도 선언은 가능하다.)<br>하지만 ES6이 도입되며 var이 가지는 한계를 보완하는 `let`과 `const` 가 새로 추가되었다.

### 1. var

**`함수 기반`** 의 scope를 가지고 있다.<br> [hoisting](https://github.com/Shinye/TIL/blob/master/JavaScript/aboutFunction.md#호이스팅hoisting) 이 가능하며, 한 scope 안에서 같은 이름의 변수를 중복 **선언** (예 : var foo = 123;) 하는 것이 가능하다. 중복 선언 할 시 가장 최근 선언 및 할당 된 값으로 값이 덮어씌워진다.

다음의 예제들을 살펴보자.

```javascript
for(var i=0; i<10; i++){
  console.log(i); // 0~9
}
console.log(i); // 10
// 기존의 다른 언어의 경우 블록기반이기 때문에 i가 선언되지 않았다는 에러가 나겠지만, 
// 자바스크립트의 경우 다음의 경우는 i가 전역변수로 선언된 셈이므로 에러가 나지 않는다.
```

```javascript
function count(){
  for(var i=0; i<10; i++){
    console.log(i); // 0~9
  }
}
count();
console.log(i); // undefined
// 변수 i가 count함수 안에 선언되었기 때문에 함수 밖에서 i를 호출하면 선언되지 않았다는 오류가 난다.
```



### 2. let

**`블록`** 기반의 scope를 가지고 있다.<br>var과는 달리, hoisting이 불가능하며 한 scope 안에서 같은 이름의 변수를 중복 선언(!=재할당) 하지 못한다.

```javascript
function bar(){
  let foo = 1234;
  let foo = 567; // syntax error!
}
```

```javascript
for(let i=0; i<10; i++){
  console.log(i); // 0~9
}
console.log(i); // undefined
```



### 3. const

기존의 다른 프로그래밍 언어의 상수 개념이다.<br>값 재할당이 불가능하며 const를 이용해 변수를 선언할 시 초기 값을 설정하지 않으면 에러가 난다. 값 재할당이 불가능하다는 점을 제외하고는 `let` 과 동일한 특성을 가지고 있다.

```javascript
let i = 2;
i = 3;
console.log(i); // 3

const j = 2;
j = 3; // syntax error!
```

<br>

ES6를 사용하여 코딩을 할 때는 특별한 경우가 아니면 `const`를 사용하는 것이 권장된다 ( for minimize mutable state! )

**원시형 데이터 타입(string, number, boolean, null, undefined..)** : 값을 변경하지 않는 경우 `const` 사용<br>**참조형 데이터 타입(array, object, function)** : 되도록 `const` 사용이 권장됨. const로 선언하더라도 **멤버 값**들은 수정이 가능함. (당연하지만) 대신 원시 데이터 타입의 변수를 동일한 이름으로의 중복 선언이 되지 않음.

