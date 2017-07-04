# Object creation / Part1

객체 생성 시 방법에 있어 정답은 없다. 본인의 상황에 따라 적절한 것을 선택하면 된다.

객체지향 언어에서 중요하게 쓰이는 키워드 중 하나가 바로 `this` 이다. 따라서 this와 this의 활용을 더욱 원활하게 해주는 bind함수에 대해 알아보자.



## bind()와 this키워드

### this

앞서 말한 것 처럼 객체지향 프로그래밍에서 중요하게 사용된다. (반면 함수형 프로그래밍의 경우에는 this나 self와 같은 개념이 없다. 참고로 자바스크립트는 함수형 프로그래밍을 구성할 수 있기도 하다!)

this 키워드가 프로그램 안에서 어느 위치에 있냐에 따라 각기 다른 값으로 판단된다. **메서드 (객체의 속성으로 저장된 함수) 본문 안에서의 this는 메서드를 호출한 객체로 판단된다.**

키워드 this는 우리가 흔히 쓰는 영어에서의 this와 의미가 같다. <br>한 대화 안에서의 "I love this!"는 문맥 상 this가 무엇을 가리키는지 알 수 있다. (프로그래밍의 경우 이 문맥은 this가 속한 메서드를 호출한 객체가 될 것이다) 하지만 문맥을 벗어나면 this가 무엇인지 알 수 없다(undefined)

다음의 예시를 살펴보자.

```javascript
let dog = {
  sound : "woof!",
  talk : function(){
    console.log(this.sound);
  }
}
dog.talk; // "woof!"

let talkFunction = dog.talk;
talkFunction(); // undefined
```

talkFuntion 변수에 객체 dog의 메서드를 할당하여 "woof!" 가 출력되기를 기대하였지만 undefined가 출력된다.<br>사실 talkFunction 변수에 메서드를 할당한 것은 다음과 같은 셈이다.

```javascript
let talkFunction = function(){console.log(this.sound);}
// 여기서 this 키워드는 더 이상 dog객체를 가리키고 있지 않다. (lost its connection to the object)
// 어느 객체에도 속하지 않기 때문에 전역객체를 가리키고 있게 된다.
```

dog객체의 메소드가 제 3의 변수에 할당 된 이상 더 이상 method가 아닌 그냥 일반 function이 된다.

하지만 이를 가능하게 해주는 기능이 있는데, 바로 `bind()` 이다.

<br>

### bind()

bind(묶다)라는 단어 그대로 별개였던 함수와 객체를 서로 묶어 주는 역할을 한다. 위의 예시를 가능하게 하기 위해서 다음과 같이 코드를 수정하면 될 것이다.

```javascript
let talkFunction() = dog.talk.bind(dog);
talkFunction(); // "woof!"
```

조금 더 실용적인 예로 들어보자면 다음과 같다.

```javascript
let button = document.getElementById("myButton");
button.addEventListener('click',dog.talk.bind(dog)); // woof!
```



---

위의 this, bind()에 대해 조금 더 부가적인 설명...

```javascript
function talk(){
  console.log(this);
}
talk();
```

앞서 설명했다시피 talk() 의 결과로 전역 객체에 대한 정보가 출력된다. (this가 호출된 위치에서의 객체)<br>위의 예시의 경우우 talk함수가 특정 객체 안에 속한 메서드가 아니기 때문에 이 코드가 실행된 곳의 객체를 보여준다. 만약 터미널에서 node 명령어를 사용하여 코드를 실행한 경우 node의 객체를, 브라우저 console창에서 실행한 경우 window객체에 대해 보여 줄 것이다.



다음과 같은 예시 역시 확인할 수 있다.

```javascript
let talk = function(){console.log(this.sound);}
let student = function(){console.log(this.name);}

let foo = {
  speak : talk,
  sound : "hello world",
  name : "shinye"
};
foo.speak(); // hello world
talk(); // undefined
// 둘 다 같은 함수를 참조하지만, 어느 객체 안에서 불리느냐에 따라 결과 값이 다르다.

// 만약 foo객체에 학생 이름을 출력하는 메서드(callName)를 추가하고 싶다면
foo.callName = student.bind(foo); // bind 안하면 undefined 뜬다.
```

