# 유효범위와 클로져



## 유효범위 (Scope) : var 기준

> 다음의 글은 자바스크립트의 변수를 나타낼 때 쓰는 `var` 을 기준으로 한 유효범위의 설명입니다.<br> var은 함수 기준의 유효범위이지만 ES6의 `let` , `const` 는 `블록 {}` 를 기준으로 유효범위를 가집니다. 따라서 ES6가 상용화 된 이후부터는 let, const의 사용이 권장되고 var은 서서히 죽은 문법이라는 의견이 주를 이루고 있습니다.<br> let과 const에 대한 설명은 [여기](https://github.com/Shinye/TIL/blob/master/JavaScript/var_let_const.md)에서!

변수의 유효범위란 다른 프로그래밍 언어에서도 알 수 있듯, 프로그램에서 어떤 변수가 정의되어 있는 영역을 말한다.<br> 영어의 뜻을 가져와서 설명해보면, 현재 자신의 위치에서 볼 수 있는 변수들을 결정하는 방법인 것이다. 자신의 scope 안에 있다면 접근이 가능하여 변수를 읽거나 쓸 수 있는 것이고, scope 밖에라면 해당하는 변수는 접근이 불가능한 것이다.

다시 말해, "정의된 변수를 사용 가능한 소스 코드의 집합" 이다.

`전역변수`는 코드 전체에 걸쳐 모든 곳에서 유효한 것이고, `지역변수`는 어떤 **함수** 안에서 선언된 변수로(let,const의 경우 블록 안에 선언된 지역 변수가 되겠다.) 변수가 선언된 함수 전체에 걸쳐 유효하고, 그 안에 중첩된 함수 내에서도 유효하다. (함수의 매개변수로 받아오는 변수도 지역변수이다 물론!)

자바, C++과 같은 프로그래밍 언어에서는 '블록단위' 에 따라 지역변수의 유효범위가 결정되었다. 해당 블록`{}` 안에 선언된 지역변수는 블럭을 벗어난 곳에서는 보이지 않는다. <br>하지만 자바스크립트는 블록 단위 개념의 유효범위가 없고, 대신 `함수 단위`의 유효범위가 존재한다. 따라서 함수 안에 정의된 지역변수는 해당 변수가 정의된 함수 안에서 보이는 것 뿐만 아니라, 그 함수 안에 중첩 된 함수 안에서도 유효하다.

함수 유효범위는 어떤 함수 안에서 선언된 모든 변수는 그 함수 전체에 걸쳐 유효하다는 의미이다. <br>흥미롭게도, 이는 변수가 미처 선언되기 전에도 유효하다는 뜻이기도 하다. (이를 [호이스팅](https://github.com/Shinye/TIL/blob/master/JavaScript/aboutFunction.md#호이스팅hoisting)이라고 한다.) 자바스크립트 코드는 함수 안에 있는 모든 변수를 함수 맨 꼭대기로 '끌어올린' 것처럼 동작한다. 하지만 할당문 (= "something") 까지 끌어올리진 않는다.

```javascript
var scope = "global";
function f(){
  console.log(scope); // "global" 아닌 undefined 출력. 아래에 지역변수로 선언 및 할당된 scope가 할당문
  // 을 제외하고 호이스팅 되었기 때문에 선언은 되었지만 할당값은 없는 undefined가 출력
  scope = "local"; // 이제 scope변수가 초기화되고 제대로 된 값이 있다.
  console.log(scope); // local출력
}
```



 다음 코드에서 변수 i, j, k는 다른 위치에서 선언되지만, 모두 같은 유효범위를 갖는다. 다시 말해, 세 변수는 모두 함수의 몸체 안에 정의되어 있다.

```javascript
function test(o){
  var i = 0; // i는 함수 전체에 걸쳐 정의된다.
  
  if (typeof o == "object"){
    var j = 0; // j는 if문 블록 뿐만 아니라, 함수 전체에 걸쳐 정의된다.
  
    for(var k=0; k<10; k++){ // k는 반복문 외에도 함수 전체에 걸쳐 정의된다.
      console.log(k); // 0~9 출력
    }
    
    console.log(k); // k는 여전히 정의되어 있다. 10 출력
  }
  console.log("j : "+j); // j는 정의되어 있고, if문을 거치지 않았다면 초기화 되지 않아 undefined일 것.
}
```



다음의 추가적인 예시로, 자바스크립트는 지역변수의 유효범위가 블록 기준이 아닌 `함수` 기준임을 다시 한 번 알 수 있다.

![https://68.media.tumblr.com/1311bfd36e06920278e3e7e145720396/tumblr_op682wHWlk1w8w3y8o2_1280.png](https://68.media.tumblr.com/1311bfd36e06920278e3e7e145720396/tumblr_op682wHWlk1w8w3y8o2_1280.png)

![https://68.media.tumblr.com/7cbf499ec3942843cedc7aa9d5a24841/tumblr_op682wHWlk1w8w3y8o3_1280.png](https://68.media.tumblr.com/7cbf499ec3942843cedc7aa9d5a24841/tumblr_op682wHWlk1w8w3y8o3_1280.png)

첫 번째, 두 번째 스크린샷에서 변수 i는 if문 안에서 선언 되어 있다. C++, JAVA와 같은 경우라면 console.log(j) 부분에 Reference Error가 나야 할 것이다.

하지만 자바스크립트이기에!! <br>첫 번째 스크린샷의 경우(if문을 통과하지 못함) j는 정의는 되었지만 초기화(값 할당)는 되지 않았다는 뜻의 undefined가 뜬다.<br>두 번째 스크린샷의 경우(if문을 통과함) j의 값이 할당된 그대로 콘솔에 1이 출력된다.

![https://68.media.tumblr.com/d58eba930f60f5f202189495cadb49da/tumblr_op682wHWlk1w8w3y8o1_1280.png](https://68.media.tumblr.com/d58eba930f60f5f202189495cadb49da/tumblr_op682wHWlk1w8w3y8o1_1280.png)

반면 함수 안에 정의된 변수 j는 `함수단위 유효범위`에 의해 함수 외부에서 j를 부를 시 j가 defined되지 않았다는 Reference Error가 뜬다. (물론 클로져의 기능을 추가 활용한다면 외부에서 함수 내부에 선언된 지역변수를 부를 수 있다. 추후에 다시 클로져에 대해 설명하겠다.)



전역변수와 어떤 함수 내부의 지역변수가 같은 이름을 갖는 경우, 함수 내부의 지역변수를 우선시 한다. 지역 변수 혹은 함수 매개변수를 전역변수와 같은 이름으로 선언하면, 전역변수는 감춰진다.

```javascript
var scope = "global";
function checkScope(){
  var scope = "local";
  return scope;
}
checkScope(); // "local"
```



이와 같은 특성에 따라, 다음과 같은 특수한 경우도 볼 수 있다.

![https://68.media.tumblr.com/d71103800486ea8a552acbe9578ebd99/tumblr_op64ss7CS41w8w3y8o1_1280.png](https://68.media.tumblr.com/d71103800486ea8a552acbe9578ebd99/tumblr_op64ss7CS41w8w3y8o1_1280.png)

전역변수로 scope2가 선언 및 값이 할당되어 있지만, 함수 foo() 안에도 역시 scope2가 선언 및 값 할당 되어 있다. 따라서 전역변수, 지역변수 중복 선언된 변수인 scope2는 둘 중 기존에 선언한 전역변수가 감춰진다. 자바스크립트의 [호이스팅](https://github.com/Shinye/TIL/blob/master/JavaScript/aboutFunction.md#호이스팅hoisting) 성질에 따라, 지역변수 scope2는, `console.log(scope2)` 가 작성된 줄에서는 아직 값 할당이 안된 상태이므로 결과값으로 undefined가 뜬다.

이와 같은 이유로 기존의 블록유효범위를 가진 언어들(C++, JAVA)에서 지역변수를 선언할 때, 일반적으로 그 지역변수를 사용하는 코드와 최대한 가까운 곳에서 선언을 권장한다. 반면 자바스크립트의 지역변수는 함수의 최상단에 변수를 선언 하는 것이 권장된다는 의견도 있다.



### var에 대하여

자바스크립트에서 변수를 선언할 때 꼭 `var`을 써야하는 것은 아니다. var을 쓰지 않고도  변수 선언을 할 수 있다. 다만 권장하지 않을 뿐이다…!

var 키워드는 **해당 변수의 Scope(유효범위)를 설정하는 역할**을 한다고 볼 수 있다. 함수 내에서 변수를 선언할 때, `var` 를 변수 앞에 덧붙이지 않으면 함수의 지역변수가 아닌 전역변수같은 역할을 하는 것이 되어버린다. (정확하게는 전역객체에 등록되는 전역변수가 되는 셈이라고 하는데…)

이러한 선언의 단점은 크게 두 가지가 있다.

- 함수 안에 작성한 변수는 지역변수로써의 역할을 의도한 것일텐데, 실상은 전역변수가 되어버리므로 필요한 경우 외에도 항시 메모리를 차지하고 있다.
- var 없는 변수가 할당되는 것은 런타임 과정에서 일어나는 일이므로, 함수 안에 var없는 변수가 선언되었다면 해당 변수는 함수 호출이 되기 전 (함수 객체 생성 전) global scope에 등록되지 않는다.

```javascript
var x = 1;
function foo(){
  y = 2;
  return x+y;
}

//Case 1
console.log(x+y); // Reference Error - y is not defined

//Case 2
console.log(foo()); // 3
console.log(x+y); // 3
```

<br>

## 스코프 체인 (Scope Chain)

자바스크립트에서 **함수를 생성할 때** 일반적인 코드 구조나 블럭 외에, 유효범위를 탐색하기 위한 속성도 만들어진다. 이를 `스코프(유효범위) 체인` 이라고 부른다. 

이 스코프 체인은 일종의 (대표적 자료구조 중 하나인) 스택 같은 컬렉션 형태를 가지고 있으며, `Variable Object(변수 객체)` 를 요소로 가지고 있다.<br>📌 `Variable Object`란? 어떤 코드가 실행될 때, 찾을 변수(variable, function, function parameter 등등)를 키와 값으로 가진 객체를 말한다.

정리하자면, `스코프 체인` 은 다음과 같이 정의할 수 있다.

- 함수가 생성될 때 같이 생성되는 변수 객체(Variable object)의 컬렉션.
- 요소로 변수 객체를 가진다.
- 변수를 찾을 때 이 컬렉션을 스택처럼 사용하게 된다.

함수가 생성될 때 만들어지는 이 스코프 체인은, 함수 객체의 프로퍼티(속성)인 `[[scope]]` 를 통해 참조되어진다. <br> 이때 이 Variable Object들에 대한 연결들을 Scope Chain 으로 관리하고 [[scope]]를 통해 Scope Chain을 참조하여 함수객체가 가지는 유효범위를 설정하게 되는 것이다.

지금까지 설명한 것을 그려보자면 다음과 같다.<br>
![https://68.media.tumblr.com/7323cd2bddb62d4bd3af5784a1c671bb/tumblr_oudc5eeK7H1v80c66o1_1280.png](https://68.media.tumblr.com/7323cd2bddb62d4bd3af5784a1c671bb/tumblr_oudc5eeK7H1v80c66o1_1280.png)

변수의 검색은 이 scope chain에 의해서만 탐색된다.<br>스코프 체인의 하위([0])에서 부터 상위로 거슬러 올라가며 등록된 변수가 있는지 확인해가는 과정을 갖는다. 가장 먼저 탐색되는 변수를 선택할 것이고, 끝까지 스코프 체인을 탐색해도 찾는 변수가 없을 시엔 `undefined` 를 띄운다.<br>예를 들어, 전역변수 x와 지역변수 x가 동일한 이름으로 사용이 가능한 이유는 이처럼 각각 x에 접근하기 위해 참조하는 Variable Object가 다르기 때문인 것이다.

그렇다면 실제로 코드에서 스코프체인과 변수 객체가 정확히 어떻게 동작하는지 확인해보자.

> 하단의 설명과 예시들은 [여기](http://blog.javarouka.me/2012/01/closure.html)에서 참고 및 재구성 하였습니다.

```javascript
var v = "global_context";
function showVar(i) {
    return i+v;
}
```

이 코드의 스코프 체인은 다음과 같은 구조를 가지고 있다.

![https://drive.google.com/uc?id=0B3Or0Wv2t1xwNGljczk2ZVFTRWc](https://drive.google.com/uc?id=0B3Or0Wv2t1xwNGljczk2ZVFTRWc)

자바스크립트에서 함수를 **실행**하면, 자바스크립트 엔진은 먼저 `실행 문맥(Execution context)`을 생성한다. <br>실행문맥과 함수는 1:1 관계가 아니고, 함수가 실행될 때 마다 실행문맥이 하나씩 생성되는 것이다.

실행 문맥은 스택에 차례대로 쌓이게 되고, 실행이 되고 난 후에는 파괴되는 것이 일반적이다.

실행문맥은 함수를 실행시키기 위해 어떤 사전작업을 수행하는데, 그 중 하나는 해당 함수가 가진 `스코프 체인` 을 자신(실행문맥)의 스코프 체인으로 복사하는 일이다. 실행 문맥 또한 스코프 체인을 통해 유효범위를 검사하기 때문이다.

그 뒤 실행문맥은 `활성 객체(Activation Object)` 라는 변수 객체를 하나 만들어서, 자신(실행문맥)의 스코프 체인의 맨 앞([0])에 삽입한다.<br>이 활성 객체는 **함수 단위의 유효범위(다시 말해 함수 내부의)에서 정의 된** 지역 변수들, 함수명, 인자, this 등의 특수한 변수까지 포함한 변수객체이다.

정리하자면,<br>
**실행 문맥 (Execution Conext)**

- 코드가 실행될 때마다 생성되는, 실행 환경을 정의하고 실제 실행하는 내부 객체.
- 실행 후 파괴되어 없어진다.

**활성 객체 (Activation Object)**

- 함수가 실행될 때 실행 문맥에 의해 생성되며, 해당 함수 자체에 대한 변수 객체가 된다.
- 때때로 호출 객체 (Call Object) 라고도 불린다.
- 지역변수, this, arguments등이 포함되어 있고 실행문맥의 스코프 체인 맨 앞에 온다.

실행 문맥은 코드를 실행하면서 변수나 프로퍼티를 만날 경우 실행중인 영역이 가진, 스코프 체인을 순서대로 넘기면서 해당 변수와 프로퍼티를 찾아 값을 참조하면서 코드를 실행시킨다.

위의 예시 코드 하단에 `showVar("This is ");` 를 추가하여 showVar() 함수를 실행한다면, showVar함수 실행문맥의 스코프체인은 다음과 같은 구조를 갖게 될 것이다.

![https://drive.google.com/uc?id=0B3Or0Wv2t1xwclJCODJlYVZqSTQ](https://drive.google.com/uc?id=0B3Or0Wv2t1xwclJCODJlYVZqSTQ)

index 0의 변수 객체 부터 차례대로 원하는 변수의 값을 찾을 수 있을 것이다.

### 클로저와 스코프체인
여기서부터 작성하시오옹ㅇ오오오오오오오ㅗ오



![https://68.media.tumblr.com/929b25aed28e2e6d7bbf33668be91b38/tumblr_oud0jaef0O1v80c66o1_1280.jpg](https://68.media.tumblr.com/929b25aed28e2e6d7bbf33668be91b38/tumblr_oud0jaef0O1v80c66o1_1280.jpg)
[자바스크립트 완벽가이드](http://www.insightbook.co.kr/book/programming-insight/%EC%9E%90%EB%B0%94%EC%8A%A4%ED%81%AC%EB%A6%BD%ED%8A%B8-%EC%99%84%EB%B2%BD-%EA%B0%80%EC%9D%B4%EB%93%9C) 책에 나오는 유효범위 체인의 예시에 대한 구절이다. 위의 설명이 줄글로 다시 작성되어 있다.

위의 예시를 코드와 다이어그램으로 잘 표현한 [포스팅](http://meetup.toast.com/posts/86)이 있어 첨부한다.
![http://image.toast.com/aaaadh/alpha/2016/techblog/scopchain.png](http://image.toast.com/aaaadh/alpha/2016/techblog/scopchain.png)

## 클로져

### 📌 [람다](https://github.com/Shinye/TIL/blob/master/JavaScript/lambda.md) 개념과 함께 보기!🙂

> Function body has access to variables that are defined outside the function.

MDN에서는 클로져를 다음과 같이 표현하고 있다.<br>
> A closure is the combination of a function and the lexical environment within which that function was declared.<br>
>클로저는 독립적인 (자유) 변수 (지역적으로 사용되지만, 둘러싼 범위 안에서 정의된 변수)를 참조하는 함수들이다. 다른 말로 하면, 이 함수들은 그들이 생성된 환경을 '기억'한다.

대다수의 현대 프로그래밍 언어와 마찬가지로 자바스크립트 또한 어휘적 유효범위(lexical scoping)을 사용한다.<br>어휘적 유효범위를 사용한다는 말은 곧, <br> 함수를 호출하는 시점에서의 변수 유효범위가 아닌, 함수가 **정의**된 시점의 변수 유효범위를 사용해 함수가 실행 된다는 뜻이다.<br>이러한 어휘적 유효범위를 구현하기 위해, 자바스크립트 `함수 객체`는 내부 상태에 `함수 자체의 코드` 뿐만 아니라 해당 함수가 정의될 당시의 `현재 유효범위 체인에 대한 참조` 도 포함하고 있다. <br>예를 들어, 한 외부 함수 내에 정의 된 내부함수는, 해당 내부함수가 정의될 당시 존재하던  외부함수 내에 정의된 지역변수와 전역변수에 접근이 가능할 수 있는 것이다.

따라서 함수 객체와, 함수의 변수가 해석되는 유효범위 (함수가 선언된 당시의 문법적 환경) 를 아울러 `클로져` 라고 부른다.

다음의 예시를 보자.

```javascript
function makeFunc() {
  var name = "Mozilla"; // name은 init에 의해 생성된 지역변수다
  function displayName() { // displayName()은 내부 함수이며, '클로져'를 형성한다
    alert(name); // 부모 함수에서 선언된 변수를 사용한다
  }
  return displayName; 
}

var myFunc = makeFunc();
myFunc(); // Mozilla
```
 
한 눈에 봐서는 이 코드가 여전히 작동하는 것이 직관적으로 보이지 않을 수 있다. 몇몇 언어에서는, 함수 안의 지역 변수들은 그 함수가 수행되는 기간 동안에만 존재한다. makeFunc() 실행이 끝나면 name 변수에 더 이상 접근할 수 없게 될 것으로 예상하는 것이 합리적이다. 

하지만 자바스크립트의 함수는 `클로져` 를 형성하기에 이를 가능하게 한다.

클로저는 함수와 함수가 선언된 문법적 환경의 조합이다.<br> 이 환경은 클로저가 생성된 시점의 범위 내에 있는 모든 지역 변수로 구성된다. 위의 경우, myFunc은 makeFunc이 실행될 때 생성된 displayName 함수의 인스턴스에 대한 참조다. displayName의 인스턴스는 그 변수, name 이 있는 문법적 환경에 대한 참조를 유지한다.그러므로 myFunc가 호출될 때 그 변수, name은 사용할 수 있는 상태로 남게 되고 "Mozilla" 가 alert 에 전달된다.
<br> <br>

## 클로져의 응용

> Closures are useful because they let you associate some data (in the lexical environment) with a function that operates on that data. This has obvious parallels to object oriented programming, where objects allow us to associate some data (the object's properties) with one or more methods.

### 1. 반복문 클로져



### 2. 페이지의 글자 크기를 조정하는 몇 개의 버튼을 추가하기

> Situations where you might want to do this are particularly common on the web. Much of the code we write in front-end JavaScript is event-based — we define some behavior, then attach it to an event that is triggered by the user (such as a click or a keypress). Our code is generally attached as a callback: a single function which is executed in response to the event.



일반적으로 클로져를 고려하지 않고 이에 대한 코딩을 한다면 다음과 같이 할 것이다.

```javascript
document.getElementById("size_12").onclick = function(){
    document.getElementById("textSpace").style.fontSize = "12px";
};

document.getElementById("size_15").onclick = function(){
    document.getElementById("textSpace").style.fontSize = "15px";
};

document.getElementById("size_18").onclick = function(){
    document.getElementById("textSpace").style.fontSize = "18px";
}
```

```html
<a href="#" id="size_12">12px</a>
<a href="#" id="size_15">15px</a>
<a href="#" id="size_18">18px</a>

<div id="textSpace">
  양념치킨 먹고싶다...
</div>
```

올바르게 의도한 대로 동작이 가능하긴 하지만, 자바스크립트 코드가 간결하지 못하다는 점을 알 수 있다.<br> 이러한 이슈를 `클로저` 를 통해 해결이 가능하다.

```javascript
function makeSizeFunc(size){
	return function(){
   		document.getElementById("textSpace").style.fontSize = size + "px";
    }
}

let size12 = makeSizeFunc(12);
let size15 = makeSizeFunc(15);
let size18 = makeSizeFunc(18);

document.getElementById("size_12").onclick = size12;
document.getElementById("size_15").onclick = size15;
document.getElementById("size_18").onclick = size18;
```


### 3. 클로저를 이용해서 프라이빗 메소드 (private 메소드) 흉내내기

일반적인 객체지향 프로그래밍에서 말하는 `private` 은, 해당 메소드/프로퍼티가 속해있는 클래스 내의 요소만이 접근할 수 있게 만들어 핵심적인 프로퍼티나 메소드가 오염되는 것을 막는 역할을 한다.

하지만 자바스크립트에서는 private을 공식적으로 제공해주지 않는다. 따라서 함수 안에 내부 함수를 구현할 수 있으며,  return값으로 함수를 쓸 수 있는 [자바스크립트 함수의 특징](https://github.com/Shinye/TIL/blob/master/JavaScript/aboutFunction.md) 을 기반으로 클로져를 통해 프라이빗 메소드를 구현할 수 있다.

프라이빗 메소드는 코드에 제한적인 접근만을 허용한다는 점 뿐만 아니라, 전역 네임 스페이스를 관리하는 강력한 방법을 제공하여 불필요한 메소드가 공용 인터페이스(전역변수)를 혼란스럽게 만들지 않도록 한다.

아래는 프라이빗 함수와 프라이빗 변수에 접근하는 퍼블릭 함수를 정의할 수 있는 클로저를 사용하는 방법을 보여주는 코드가 있다. 이렇게 클로저를 사용하는 것을 `모듈 패턴` 이라 한다.

```javascript
var counter = (function() {
  var privateCounter = 0;
  function changeBy(val) {
    privateCounter += val;
  }
  
  return {
    increment: function() {
      changeBy(1);
    },
    decrement: function() {
      changeBy(-1);
    },
    value: function() {
      return privateCounter;
    }
  };   
})();

console.log(counter.value()); // logs 0
counter.increment();
counter.increment();
console.log(counter.value()); // logs 2
counter.decrement();
console.log(counter.value()); // logs 1
```

이 예제에서는 counter.increment, counter.decrement, counter.value 세 함수에 의해 공유되는 하나의 문법적 환경이 만들어져 있음을 알 수 있다.

공유되는 문법적 환경은 정의되자마자 실행되는 익명 함수 안에서 만들어진다. 이 문법적 환경은 두 개의 프라이빗 아이템을 포함한다. 하나는 privateCounter라는 변수이고 나머지 하나는 changeBy라는 함수이다. 둘 다 외부에서 직접적으로 익명 함수 접근할 수 없다. 대신에 익명 래퍼(감싸고 있는 익명함수를 뜻하는듯 함) ㄴ에서 반환된 세 개의 퍼블릭 함수를 통해서만 접근되어야만 한다.

위의 세 가지 퍼블릭 함수는 같은 환경을 공유하는 클로저이다. 자바스크립트 문법적 스코핑(유효범위, lexical scoping) 덕분에 세 함수 모두 privateCounter 변수와 changeBy 함수에 접근할 수 있다.

카운터를 생성하는 익명 함수를 정의하고 그 함수를 즉시 호출하고 결과를 counter 변수에 할당하는 것을 알아차렸을 것이다. 이 함수를 별도의 변수 makeCounter 저장하고 이 변수를 이용해 여러 개의 카운터를 만들수도 있다.

```javascript
var makeCounter = function() {
  var privateCounter = 0;
  function changeBy(val) {
    privateCounter += val;
  }
  return {
    increment: function() {
      changeBy(1);
    },
    decrement: function() {
      changeBy(-1);
    },
    value: function() {
      return privateCounter;
    }
  }  
};

var Counter1 = makeCounter();
var Counter2 = makeCounter();
alert(Counter1.value()); /* 0 */
Counter1.increment();
Counter1.increment();
alert(Counter1.value()); /* 2 */
Counter1.decrement();
alert(Counter1.value()); /* 1 */
alert(Counter2.value()); /* 0 */
```

<br>

### 📌 네임스페이스

네임스페이스(namespace)는 구분이 가능하도록 정해놓은 범위나 영역을 뜻한다. 즉, 말 그대로 이름 공간을 선언하여 다른 공간과 구분하도록 한다.

네임스페이스가 무엇인가를 정의하기에 앞서서 파일을 생각해보자.<br> 파일은 데이터를 보관하고 있는 일종의 컨테이너다. 그리고 이 컨테이너는 파일명으로 식별이 된다. 파일의 수가 많아지면서 파일을 관리하는 것이 점점 어려워진다. 그래서 고안된 것이 바로 디렉토리다. 디렉토리를 이용하면 같은 이름의 파일이 하나의 컴퓨터에 존재할 수 있다. 파일명의 충돌을 회피 할 수 있게 된 것이다. <br>네임스페이스란 간단하게 디렉토리와 같은 것이라고 생각하자. 하나의 에플리케이션에는 다양한 모듈을 사용하게 된다. 그런데 모듈이 서로 다른 개발자에 의해서 만들어지기 때문에 같은 이름을 쓰는 경우가 생길 수 있다. 이런 경우 먼저 로드된 모듈은 나중에 로드된 모듈에 의해서 덮어쓰기 되기 때문에 이에 대한 대책이 필요하다. 네임스페이스가 필요해지게 되는 것이다. 

자바스크립트에는 네임스페이스에 대해 특별히 지원하는 바가 없지만 자바스크립트 객체나 모듈을 그러한 목적으로 사용할 수 있다. 

네임스페이스 내에서 작성된 변수나 함수를 사용하고 싶다면  네임스페이스명.변수명(혹은 함수명) 의 형식으로 작성하면 이름의 중복으로 인한 덮어쓰기 걱정 없이 관리가 가능하다.

결국 네임스페이싱(namespacing)은 객체나 변수가 겹치지 않는 안전한 소스코드를 만드는 개념이다. 하지만 JavaScript는 아직까지 네임스페이싱을 위한 기능을 지원하지 않기 때문에 다음의 특성을 통해 네임스페이스와 비슷한 효과를 얻을 수 있다.

- JavaScript의 모든 객체는 프로퍼티를 가진다.
- 그 프로퍼티는 다시 다른 객체를 담을 수 있다.<br>

이러한 네임스페이싱 코딩 기법들을 `네임스페이스 패턴(namespace pattern)` 이라고 한다.

다음은 네임스페이스 패턴의 예시이다.

```javascript
// 하나의 전역 객체
var MYAPP = {};

MYAPP.Parent = function() { console.log('Parent'); };  
MYAPP.Child = function() { console.log('Child'); };

MYAPP.variable = 1;

// 객체 컨테이너
MYAPP.modules = {};

// 객체들을 컨테이너 안에 추가합니다.
MYAPP.modules.module1 = {};  
MYAPP.modules.module1.data = {a: 1, b: 2};  
MYAPP.modules.module2 = {};

MYAPP.Parent();                               // Parent 출력  
console.log(MYAPP.modules.module1.data.a);    // 1 출력  
MYAPP.Child();                                // Child 출력  
```

이 패턴은 코드 내에서 뿐 아니라 같은 페이지에 존재하는 JS 라이브러리나 서드 파티 코드(third-party code)와의 이름 충돌도 방지해 주며 체계적이라는 장점이 있다. 따라서 모듈이 네임스페이스의 역할을 해준다는 개념이 성립한다. 하지만 다음과 같은 단점도 존재한다.

- 모든 변수와 함수에, 상위 객체 명을 모두 붙여야 하기 때문에 소스코드량이 늘어납니다. 결국 그에 따라 다운로드해야 하는 파일의 크기도 늘어나게 된다.

- 전역 인스턴스가 단 하나뿐이기 때문에 코드의 어느 한 부분이 수정되어도 전역 인스턴스를 수정하게 됩니다. 계속해서 나머지 기능들도 갱신된 상태를 물려받게 된다.

- 매번 객체에 접근하는데다, 이름이 중첩되고 길어지므로 검색이 느려지게 된다.




### 참고 URL
[JavaScript: 네임스페이스 패턴(Namespace Pattern) 바로 알기](http://www.nextree.co.kr/p7650/)<br>[모듈과 네임스페이스](http://codingnuri.com/javascript-tutorial/javascript-modules-and-namespaces.html)<br>[MDN-클로져](https://developer.mozilla.org/ko/docs/Web/JavaScript/Guide/Closures)<br>[JavaScript Closures and the Module Pattern](https://www.joezimjs.com/javascript/javascript-closures-and-the-module-pattern/)<br>[Practical Uses for Closures](https://medium.com/written-in-code/practical-uses-for-closures-c65640ae7304)<br>[클로저(Closure) 사용에는 주의가 필요합니다](http://blog.javarouka.me/2012/01/closure.html)<br>[javascript 기초 - Scope, Scope Chain & arguments](http://insanehong.kr/post/javascript-scope/)


