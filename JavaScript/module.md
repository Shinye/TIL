# Module in Javascript
자바스크립트의 최신 동향을 보면 모듈, 모듈 번들러, webpack 등 알 수 없는(ㅠㅠ) 단어들과 함께하는 경우가 많다.<br> 설명을 봐도 잘 이해가 안가서 ㅎㅎ...그래서 하나하나 찾아보았다...

모던 자바스크립트 개발 환경에서 툴링을 잘 이해하기 위해서는 `모듈` , `모듈 포맷` , `모듈 로더` 와 `모듈 번들러` 사이의 차이를 이해하는 것이 중요하다.

## 모듈
### 모듈이란?
구현한 코드 세부 사항을 캡슐화 하고, 공개 API를 노출해 **다른 코드에서 쉽게 로드하고 사용할 수 있도록** 재사용 가능한 코드 조각을 뜻함.

### 모듈의 조건
- **코드 추상화**<br>
특수한 일정 라이브러리에 기능을 위임하여 복잡한 구현 방식에 대해 굳이 이해하지 않아도 된다.
- **코드 캡슐화**<br>코드의 무분별한 변경을 막기 위해 모듈 내부에 코드를 숨긴다.
- **코드 재사용**<br>같은 코드를 반복해서 작성할 필요가 없어진다.
- **의존성 관리**<br>코드를 다시 작성하지 않고도 쉽게 의존성을 변경한다.


## ES5의 모듈 패턴
ES5를 비롯한 이전 버전에서는 모듈에 대한 고려가 있지 않았다. 시간이 지나면서 개발자들은 자바스크립트의 모듈화 디자인을 시뮬레이션하기 위해 다양한 패턴을 고안해 냈다.

이러한 패턴이 생기게 된 아이디어를 알기 위해 `즉시 실행 함수 표현식` 과 `노출식 모듈` 에 대해 살펴보자.

### 1. 즉시 실행 함수 표현식<br>
[자세한 설명은 이쪽에서](https://github.com/Shinye/TIL/blob/master/JavaScript/aboutFunction.md#함수-표현-function-expression)

```javascript
(function(){
  // ...
})()
```

즉시 실행 함수 표현식은 선언된 동시에 실행되는 함수이다.함수를 반환하고, 즉시 이 함수를 호출할 수 있다.


```javascript
// 이렇게 함수 선언문을 ()를 통해 실행하려고 하면 오류가 난다.
function(){
	console.log("hello world");
}() // syntax error!

// 대신 함수 선언문 전체를 괄호로 묶어주면 함수 표현식이 된다.
(function(){
	console.log("hello world");
}) // returns -> function (){console.log("hello world");}

// ()를 통해  실행하면 콘솔에 hello world를 출력한 수 undefined를 리턴한다(return값 없으므로)
(function(){
	console.log("hello world");
})() // "hello world"
```

즉시 실행 함수 표현식(IIFE, Immediately Invoked Function Expressions)을 모듈과 결합하여 활용한다면 다음과 같은 특징을 가질 수 있다.

- IIFE를 즉시 실행시킴으로써, 내부의 코드 복잡도를 캡슐화하여 IIFE 코드가 무엇을 하는지 이해하지 않아도 된다.
- IIFE 안에 변수를 정의하여 전역 스코프를 오염시키지 않는다. (IIFE 내부의 var문은 IIFE의 클로저 안에 남아있는다)


### 2. 노출식 모듈 패턴

`노출식 모듈 패턴` 은 즉시 실행 함수 표현식과 유사하지만, **변수에 반환 값을 할당** 한다는 점에서 차이점이 있다.
다음은 `싱글톤 디자인 패턴` 을 구현한 것이다.

```javascript
// Expose module as global variable
var singleton = function(){

  // Inner logic
  function sayHello(){
    console.log('Hello');
  }

  // Expose API
  return {
    sayHello: sayHello
  }
}()
```

function 키워드가 시작하는 줄에 괄호가 없는 상태로 끝에 ()가 붙었음에도, 앞의 변수에 할당하는 형식을 가지니 오류가 나지 않는다.<br>이제 모듈 API에 변수를 통해 다음과 같이 접근할 수 있다.

```javascript
// Access module functionality
singleton.sayHello();  
// => Hello
```

> **Singleton이란?**<br>
> 대표적인 디자인패턴 기법 중 하나이다.<br><br> 
> 프로그램을 실행할 때 보통은 많은 인스턴스가 생성된다.<br> 예를 들어 문자열을 표시하는 java.lang.String 클래스의 인스턴스는 문자열 1개에 대해서 1개가 생성되기 때문에 문자열이 1000개 등장하는 프로그램이라면, 1000개의 인스턴스가 만들어진다.
>
>그러나 클래스의 인스턴스가 단 하나만 필요한 경우도 있다.<br>그것은 시스템 안에서 1개밖에 존재하지 않는 것을 프로그램으로 표현하고 싶을 때이다.
>
>즉, 지정한 클래스의 인스턴스가 절대로 1개 밖에 존재하는 않는 것을 보증하고 싶을 때 사용한다.<br>  Singleton이란 요소를 1개 밖에 가지고 있지 않은 집합을 의미한다.


싱글톤과 같은 단일 인스턴스가 아닌, 여러 개의 인스턴스를 만들고 싶을 때 다음과 같이 구현할 수 있다.

```javascript
// Expose module as global variable
var Module = function(){

  // Inner logic
  function sayHello(){
    console.log('Hello');
  }

  // Expose API
  return {
    sayHello: sayHello
  }
}
```

함수를 바로 실행하지 않는 대신, Module 생성자 함수를 사용해서 모듈을 인스턴스화 한다.

```javascript
var module = new Module();

// 공개 API로 접근하려면 다음과 같다.
module.sayHello();  
// => Hello
```

이처럼 자바스크립트가 진화하면서 모듈을 정의하기 위해 다양한 문법이 개발되었으며, 이 문법들은 각각 고유의 장단점을 가진다.

우리는 이것을 `모듈 포맷` 이라고 부른다.


## 모듈 포맷
`모듈 포맷` 은 모듈을 정의하기 위해 사용할 수 있는 문법이다.<br>앞서 말했다시피 ES5 까지는 모듈을 정의하는 공식적인 문법이 없었다. 따라서 모듈을 정의할 수 있도록 도와주는 다양한 포맷들이 출시되었고, 최근 ES6 부터는 모듈 포맷을 제공한다.

다음은 많이 알려지고 채택된 포맷들이다.

- CommonJS
- 비동기 모듈 정의(AMD, Asynchronous Module Definition)
- 만능 모듈 정의(UMD, Universal Module Definition)
- System.register
- ES6 모듈 포맷

각 문법을 간략하게 살펴보도록 하자.

### CommontJS 

CommonJS([http://www.commonjs.org/](http://www.commonjs.org/)) 는 JavaScript를 브라우저에서뿐만 아니라, 서버사이드 애플리케이션이나 데스크톱 애플리케이션에서도 사용하려고 조직한 자발적 워킹 그룹이다. <br><br>CommonJS의 'Common'은 JavaScript를 브라우저에서만 사용하는 언어가 아닌 일반적인 범용 언어로 사용할 수 있도록 하겠다는 의지를 나타내고 있는 것이라고 이해할 수 있다.
이 그룹은 JavaScript를 범용적으로 사용하기 위해 필요한 '명세(Specification)'를 만드는 일을 한다. 이 그룹에서 현재까지 정의한 명세로는 Module 명세 1.0, 1.1, 1.1.1 등이 있다. Node.js 모듈도 Module 명세 1.0을 따르고 있다.

CommonJS 포맷은 require와 module.exports를 사용해서 의존성과 모듈을 정의한다.

```javascript
var dep1 = require('./dep1');  
var dep2 = require('./dep2');

module.exports = function(){  
  // ...
}
```
CommonJS를 만든 목적이 서버사이드에서 JavaScript를 사용하는 것이었기 때문에 서버사이드 용으로 사용할 때에 장점이 많다. CommonJS가 만들어지기 전 서버사이드에 JavaScript를 사용하는데에는 다음과 같은 이슈들이 있었다.

- 서로 호환되는 표준 라이브러리가 없다.
- 데이터베이스에 연결할 수 있는 표준 인터페이스가 없다.
- 다른 모듈을 삽입하는 표준적인 방법이 없다.
- 코드를 패키징해서 배포하고 설치하는 방법이 필요하다.
- 의존성 문제까지 해결하는 공통 패키지 모듈 저장소가 필요하다.

앞에서 언급한 문제점들은 결국 모듈화로 귀결된다. 그리고 CommonJS의 주요 명세는 바로 이 모듈을 어떻게 정의하고, 어떻게 사용할 것인가에 대한 것이다.

모듈화는 아래와 같이 세 부분으로 이루어진다.

- 스코프(Scope): 모든 모듈은 자신만의 독립적인 실행 영역이 있어야 한다.
- 정의(Definition): 모듈 정의는 exports 객체를 이용한다.
- 사용(Usage): 모듈 사용은 require 함수를 이용한다.

먼저 모듈은 자신만의 독립적인 실행 영역이 있어야 한다.<br> 따라서 전역변수와 지역변수를 분리하는 것이 매우 중요하다. 서버사이드 JavaScript의 경우에는 **파일마다 독립적인 `파일 스코프`**가 있기 때문에 파일 하나에 모듈 하나를 작성하면 간단히 해결된다.


### 비동기 모듈 정의(AMD)

'Asynchronous Module Definition'이라는 말에서 알 수 있듯이, AMD에서는 비동기 모듈(필요한 모듈을 네트워크를 통해 내려받을 수 있도록 하는 것)에 대한 표준안을 다루고 있다.

AMD 그룹은 비동기 상황에서도 JavaScript 모듈을 쓰기 위해 CommonJS에서 함께 논의하다 합의점을 이루지 못하고 독립한 그룹이다.<br>
본래 CommonJS가 JavaScript를 브라우저 밖으로 꺼내기 위한 노력의 일환으로 탄생했기 때문에,<br> 브라우저 내에서의 실행에 중점을 두었던 AMD와는 합의를 이끌어 내지 못하고 결국 둘이 분리되었다. CommonJS 공식 위키에도 AMD가 독립했다는 사실을 알리고 있다.

AMD 포맷은 브라우저에서 사용되고 define 함수를 사용해서 모듈을 정의한다.

```javascript
//Calling define with a dependency array and a factory function
define(['dep1', 'dep2'], function (dep1, dep2) {

  //Define the module value by returning a value.
  return function () {};
});
```

AMD가 목표로 하는 것은 필요한 모듈을 네트워크를 이용해 내려받아야 하는 `브라우저 환경` 에서도 모듈을 사용할 수 있도록 표준을 만드는 일이다.<br> 따라서 현재 JavaScript 모듈화에 대한 논의는 크게 CommonJS 진영과 AMD 진영으로 나뉘게 되었다.

둘 중에 무엇이 더 좋다고 이야기할 수는 없다. 왜냐하면 AMD도 브라우저에서 동작하는 JavaScript만을 대상으로 모듈을 정의하지는 않았기 때문이다.

두 진영(commonJS/AMD) 에서 정의하는 모듈 명세의 차이는 `모듈 로드` 에 있다.
필요한 파일이 모두 로컬 디스크에 있어 바로 불러 쓸 수 있는 상황, 즉 서버사이드에서는 CommonJS 명세가 AMD 방식보다 간결하다. 반면 필요한 파일을 네트워크를 통해 내려받아야 하는 브라우저와 같은 환경에서는 AMD가 CommonJS보다 더 유연한 방법을 제공한다.

### 만능 모듈 정의(UMD)

UMD 포맷은 브라우저와 Node.js에서 둘 다 사용될 수 있다.

```javascript
(function (root, factory) {
  if (typeof define === 'function' && define.amd) {
    // AMD. Register as an anonymous module.
    define(['b'], factory);
  } else if (typeof module === 'object' && module.exports) {
    // Node. Does not work with strict CommonJS, but
    // only CommonJS-like environments that support module.exports,
    // like Node.
    module.exports = factory(require('b'));
  } else {
    // Browser globals (root is window)
    root.returnExports = factory(root.b);
  }
}(this, function (b) {
  //use b in some fashion.

  // Just return a value to define the module export.
  // This example returns an object, but the module
  // can return a function as the exported value.
  return {};
}));
```

### System.register

System.register 포맷은 ES5에서 ES6 모듈 문법을 지원하기 위해 디자인되었다.

```javascript
import { p as q } from './dep';

var s = 'local';

export function func() {  
  return q;
}

export class C {  
}
```

### ES6 모듈 포맷

ES6에서 자바스크립트는 내장된 모듈 포맷도 지원한다.<br>
모듈의 공개 API로 내보내기 위해 export 토큰을 사용한다.

```javascript
// lib.js

// Export the function
export function sayHello(){  
  console.log('Hello');
}

// Do not export the function
function somePrivateFunction(){  
  // ...
}
```

그리고 import 토큰은 모듈이 **내보내는 부분**을 가져온다.

```javascript
import { sayHello } from './lib';

sayHello();  
// => Hello
```

우리는 as를 사용하여 가져오는 모듈에 별명을 줄 수도 있다.

```javascript
import { sayHello as say } from './lib';

say();  
// => Hello
```

또는 전체 모듈을 한 번에 로드할 수도 있다.

```javascript
import * as lib from './lib';

lib.sayHello();  
// => Hello
```

이 형식은 default export도 지원한다. (역자주: default export를 사용하면 모듈을 가져올 때 괄호({})를 사용하지 않아도 되며, 단일 값을 내보낼 때 사용한다)

```javascript
// lib.js

// Export default function
export default function sayHello(){  
  console.log('Hello');
}

// Export non-default function
export function sayGoodbye(){  
  console.log('Goodbye');
}
```

모듈은 다음과 같이 가져온다.

```javascript
import sayHello, { sayGoodbye } from './lib';

sayHello();  
// => Hello

sayGoodbye();  
// => Goodbye
```

함수뿐만 아니라 어떤 것이든 내보낼 수 있다.

```javascript
// lib.js

// Export default function
export default function sayHello(){  
  console.log('Hello');
}

// Export non-default function
export function sayGoodbye(){  
  console.log('Goodbye');
}

// Export simple value
export const apiUrl = '...';

// Export object
export const settings = {  
  debug: true
}
```

불행하게도 내장된 모듈 포맷은 아직 모든 브라우저에서 지원되지 않는다.

그래서 우리는 이미 ES6 모듈 포맷을 사용할 수 있지만, 브라우저에서 코드를 실행하기 전에 `Babel` 과 같은 변환기를 사용해 ES5 모듈 포맷(AMD 또는 CommonJS)으로 코드 변환이 필요하다.

<br>

## 모듈 로더
모듈 로더는 주요 모듈 포맷으로 작성된 모듈을 해석하고 로드한다.

모듈 로더는 **`런타임`** 에 실행된다.

- 브라우저에서 모듈 로더를 로드한다.
- 모듈 로더에게 어떤 메인 애플리케이션 파일을 로드할 것인지 알려준다.
- 모듈 로더는 메인 애플리케이션 파일을 다운로드하고 해석한다.
- 필요한 경우 모듈 로더가 파일을 다운로드한다.
- 브라우저 개발자 콘솔에서 네트워크 탭을 열면, 모듈 로더에 의해 많은 파일들이 로드된 것을 볼 수 있다.

인기 있는 모듈 로더에는 다음과 같은 것들이 있다.

- RequireJS : AMD 포맷 모듈을 위한 로더
- SystemJS : AMD, CommonJS, UMD 또는 System.register 포맷 모듈을 위한 로더

<br>
## 모듈 번들러
📌 번들러(Bundler) : bundle - 꾸러미, 묶음, 보따리. bundler - 짐을 꾸리는 사람<br><br>
모듈 번들러는 모듈 로더를 **대체**한다.<br>
모듈 로더와 반대로 모듈 번들러는 **`빌드 타임`** 에 실행된다.

- 빌드 타임에 번들 파일을 생성하기 위해 모듈 번들러를 실행한다. (예: bundle.js)
- 브라우저에서 번들 파일을 로드한다.
- 브라우저 개발자 콘솔에서 네트워크 탭을 열면, 모듈 로더에 의해 1개 파일만 로드된 것을 볼 수 있다. 
- 브라우저에서 모듈 로더를 필요로 하지 않는다. 모든 코드는 번들 안에 포함되어 있다.

인기 있는 모듈 번들에는 다음과 같은 것들이 있다.

- Browserify : CommonJS 모듈을 위한 번들러
- ♨️ Webpack : AMD, CommonJS, ES6 모듈을 위한 번들러


### 빌드타임 vs 런타임
- **빌드타임** : 소프트웨어 빌드(software build)는 소스 코드 파일을 컴퓨터에서 실행할 수 있는 독립 소프트웨어 가공물로 변환하는 과정을 말하거나 그에 대한 결과물을 일컫는다.<br> 소프트웨어 빌드 과정에 있어 가장 중요한 단계들 가운데 하나는 소스 코드 파일이 실행 코드로 변환되는 컴파일 과정이다.
- **런타임** : 컴퓨터 프로그램이 실행되고 있는 동안의 동작을 말한다.




