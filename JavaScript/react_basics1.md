# React Basics1

### 목차

- [React란?]()
- [라이브러리 vs 프레임워크]()
- [Virtual DOM]()
- [React의 장단점]()
- [React의 구조 - Elements]()
- [React의 구조 - Component]()
- [JSX]()



## React란?

> A JAVASCRIPT LIBRARY FOR BUILDING USER INTERFACES

리액트 공식 홈페이지에 들어가보면, 리액트란 UI를 만들기 위한 `자바스크립트 라이브러리` 라고 작성되어 있다.<br>리액트는 페이스북에서 개발한 유저인터페이스 라이브러리로서 개발자로 하여금 재사용 가능한 UI를 생성 할 수 있게 해준다. 

이 라이브러리는 `Virtual DOM` 이라는 개념을 사용하여 상태의 변함에 따라 선택적으로 유저인터페이스를 렌더링한다.
따라서, 최소한의 DOM 처리로 컴포넌트들을 업데이트 할 수 있게 해준다.



### 라이브러리 vs 프레임워크

이 때, 라이브러리와 함께 자주 언급되는 프레임워크의 차이를 먼저 알아보자.

- **라이브러리 : 필요한 것만 가져다 쓰면 됨**

  간략 설명: 프로그램 제작 시 필요한 기능<br>
  비교 설명: 자동차 바퀴, 자동차 헤드라이트, 자동차 에어백

  - 재사용이 필요한 기능으로 `반복적인 코드 작성을 없애기 위해` `언제든지 필요한 곳에서 호출` 하여 사용할 수 있도록 Class나 Function으로 만들어진 것.
  - `사용 여부는 코드 작성자 선택 사항` 이며 새로운 라이브러리 제작 시에도 엄격한 규칙이 존재하지 않는다. 제작 의도에 맞게 작성하면 된다.
  - **예시 : **jQuery, React, 객체지향 프로그래밍(OOP)은 기본적으로 각 기능마다 함수화하는 것으로 클래스 라이브러리라고 할수도 있다

- **프레임워크 : [제어의 역전] 필요한 기본적인 기능들이 이미 모두 만들어져있음. 틀이 있으면 이 안에 필요한 걸 채워넣는 것. **

  간략 설명: 프로그램 기본 구조(뼈대)
  비교 설명: 자동차 프레임

  - 원하는 기능 구현에만 집중하여 빠르게 개발 할 수 있도록 기본적으로 필요한 기능을 갖추고 있는 것이다. (라이브러리가 포함되어 있음)
  - 필요한기능 : 코드의 품질, 필수적인 코드, 알고리즘, 암호화, 데이터베이스 연동 같은 기능들을 어느정도 구성이 되어있다.
  - 프레임워크만으로는 실행되지 않으며, 필요한 기능을 추가 해야 되고, 
  - 프레임워크에 의존하여 개발해야 되며 프레임워크가 정의한 규칙을 준수해야한다.
  - **예시** : Django, AngularJS, Spring, Laravel 


- **프레임워크와 라이브러리의 차이점**

  라이브러리와 프레임워크의 차이는 **제어 흐름에 대한 주도성이 누구에게/어디에 있는가**에 있다.<br>즉, 어플리케이션의 **Flow(흐름)를 누가 쥐고 있느냐**에 달려 있다.

  프레임워크는 전체적인 흐름을 스스로가 쥐고 있으며 사용자는 그 안에서 필요한 코드를 짜 넣으며 반면에,<br>라이브러리는 사용자가 전체적인 흐름을 만들며 라이브러리를 가져다 쓰는 것이라고 할 수 있다.

  다시 말해, 라이브러리는 라이브러리를 가져다가 사용하고 호출하는 측에 전적으로 주도성이 있으며 프레임워크는 그 틀안에 이미 제어 흐름에 대한 주도성이 내재(내포)되어 있다.

  프레임워크는 가져다가 사용한다기보다는 거기에 들어가서 사용한다는 느낌/관점으로 접근할 수 있다.

  ```
  - 제어의 역전?
  제어의 역전이란 어떠한 일을 하도록 만들어진 프레임워크에 제어의 권한을 넘김으로써 클라이언트 코드가 신경 써야 할 것을 줄이는 전략입니다.
  이것을 제어가 역전 되었다 라고 합니다. 
  일반적으로 라이브러리는 프로그래머가 작성하는 클라이언트 코드가 라이브러리의 메소드를 호출해서 사용하는 것을 의미 합니다. 
  프레임워크를 규정하는 특성은 프레임워크의 메소드가 사용자의 코드를 호출 한다는데 있습니다. 
    
  여기까지는 이해가 쉽지만, 의문이 생깁니다. 
  대체 어떻게 프레임워크가 나의 메소드를 호출하는가에 대한 의문입니다. 
  어떻게 하면 프레임워크가 나의 코드를 호출 할 수 있을까? 프레임워크는 내가 작성한 코드를 모르잖아!. 
    
  제어를 역전시키는 (프레임워크가 나의 코드를 호출 할 수 있게 하는) 가장 쉽게 생각할 수 있는 접근 방법은 프레임워크의 event, delegate 에 나의 메소드를 등록 시키는 것입니다. 
  전달되는 인자와 반환 형식만 일치 한다면, 프레임워크 코드는 내가 작성한 객체와 타입을 고려하지 않습니다. 
  등록된 메소드만 감지하여 실행 invoke 하는 것입니다. 
  다른 방법은 프레임워크에 정의 되어 있는 인터페이스 interface, 추상타입 abstract 을 나의 코드에서 구현, 상속 한후 프레임워크에 넘겨주는 것입니다. 
    
  프레임워크는 인터페이스와 추상을 알고 있으므로 내가 하고자 하는 일련의 작업을 처리할 수 있습니다. 
  이는 객체를 프레임워크에 주입하는 것이고, 이를 의존을 주입 dependency injection 한다고 합니다.
  ```

  보다 자세한 설명은 [여기](http://webclub.tistory.com/458) 나 [여기](http://blog.gaerae.com/2016/11/what-is-library-and-framework-and-architecture-and-platform.html) 를 참고하면 된다.

  <br>



### Virtual DOM

> Unlike browser DOM elements, React elements are plain objects, and are cheap to create. <br>React DOM takes care of updating the DOM to match the React elements.

React.js는 자바스크립트 내에 DOM Tree와 같은 구조체를 VIRTUAL DOM으로 갖고 있다. 

Virtual DOM은 실제 DOM의 구조와 비슷한, React 객체의 트리다. 개발자는 직접 DOM을 제어하지 않고 Virtual DOM을 제어하고, React에서 적절하게 Virtual DOM을 DOM에 반영하는 작업을 한다

다시 말해, DOM을 제어하는 방식이 아니라 중간에 가상의 DOM인 Virtual DOM을 두어 개발의 편의성(DOM을 직접 제어하지 않음)과 성능(배치 처리로 DOM 변경)을 개선한 것이다.

`setState(forceUpdate)` 함수가 호출되면 그 컴포넌트와 하위 컴포넌트가 다시 랜더링되는 대상이 된다. 이 말을 듣게 되면 매번 광범위하게 DOM이 갱신된다고 느껴지지만 React.js에서는 VIRTUAL DOM이라고 하는 형태로 메모리상에 DOM의 상태를 유지하고 있고 전/후 상태를 비교하여 달라진 부분만 실제 DOM에 반영한다. 참고로 CSS도 마찬가지로 객체 형식으로 지정해 변경된 Style만 갱신한다.

즉, UI를 다시 그릴 때는 그 구조체의 전후 상태를 비교하여 변경이 필요한 최소한의 요소만 실제 DOM에 반영한는 말이다. 따라서 무작위로 다시 그려도 변경에 필요한 최소한의 DOM만 갱신되기 때문에 빠르게 처리할 수 있다.

보다 자세한 내용은 [React and the Virtual DOM](https://www.youtube.com/watch?v=BYbgopx44vo) 영상이나 NAVER D2에 올라온 [React 적용 가이드 - React 작동 방법](http://d2.naver.com/helloworld/9297403) 의 Virtual DOM 항목을 정독하자.



### ReactJS의 장점

- 앞서 설명한 Virtual DOM을 통하여 실제 달라지는 부분만 렌더링에 반영되어 성능 유지에 도움을 준다.

- 좋은 가비지컬렉팅 능력 (왜지? 이유 찾아보기...)

- 간단한 UI수정 및 재사용에 능하다.

- UI를 위한 라이브러리이기 때문에 Express 등 다른 third-party 프레임워크/라이브러리를 사용 가능하다.

- 단방향 Data Flow를 지향해서 단순하고 이해하기 쉬운 애플리케이션을 만들 수 있다. 데이터를 관리하는 모델 컴포넌트가 있고, 그 데이터를 UI컴포넌트에 전달해 이 데이터를 기반으로 UI를 그려주는 단순한 흐름이다.

  > 과거엔 데이터가 변경되면 전체를 새로 그리는 간편하고 단순한 방법으로 애플리케이션을 구현했습니다. 현대에 들어 애플리케이션을 개발하는 방법이 많이 복잡해졌다고 생각합니다. Angular.js의 양방향 데이터 바인딩은 코드를 줄여주고 사용하기 편하지만, 규모가 커질수록 데이터의 흐름을 추적하기 힘듭니다. 
  >
  > React.js는 근원(根源)으로 돌아가는 개발 방법입니다. 그리고 그 과정에서 발생하는 비효율적인 부분, 예를 들어 DOM 전체를 갱신해야하는 문제를 VIRTUAL DOM과 비교(diff)로 해결했습니다. [출처](https://blog.coderifleman.com/2015/06/23/learning-react-1/)



### ReactJS의 단점

- IE8이하는 지원이 되지 않는다.

- UI만을 위한 라이브러리이다. (단점이 될 수도! 다른 기능은 다른 라이브러리, 프레임워크를 써야한다.)

  <br>



## React의 구조

### Elements

> Elements are the smallest building blocks of React apps. An element describes what you want to see on the screen:

Element는 리액트 앱을 만들 때 필요한 최소한의 블럭이다. 브라우저 요소인 DOM과 달리 React Element는 보다 적은 비용으로 생성할 수 있으며, React DOM은 React Element와 일치하도록 DOM을 업데이트 한다.

**Elements를 DOM으로 렌더링하기**

```html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8" />
  <title>Document</title>
</head>
<body>
  <div id="root"></div>
</body>
</html>
```

다음과 같은 코드가 있을 때, React의 관점에서는 저 `root` 노드를 중심으로 코드가 돌아갈 것이다. 이 것을 리액트에서는 `Root DOM node` 라고 부른다. 이 태그(root) 내부의 모든 element는 React DOM에 의해 관리된다.

```jsx
const element = (
    <h1>Hi!</h1>
);
ReactDOM.render(element, document.getElementById('root'));
```

getElementById를 통해 root노드를 select해서 이 루트노드 안에 element를 `render` 할 수 있다.

> With our knowledge so far, the only way to update the UI is to create a new element, and pass it to `ReactDOM.render()`.

<br>

**Immutable Element**

리액트에서는 Element가 렌더 된 이후에는 해당 element의 자식이나 attribute를 변경할 수 없다. UI를 변경하고 싶다면 새로운 element를 전달하여 업데이트 해야한다. 

만약 '새로이 전달되는 element가 굉장히 길고 복잡하면 어떡하지?' 라는 생각이 들어 굉장히 비효율적이라는 생각이 들지만, React DOM은 기존에 이미 렌더링되어 있는 DOM과 새로이 전달받은 Element를 비교하여 업데이트가 필요한 부분만 업데이트해준다.

[여기](https://reactjs.org/docs/rendering-elements.html#react-only-updates-whats-necessary)를 보면, 매 초마다 시간이 바뀌는데 업데이트 되는 특정 element만 업데이트 되고 있음을 알 수 있다.

<br>

### Component

> Components let you split the UI into independent, reusable pieces, and think about each piece in isolation.

위에서 설명한 element의 형식으로만 UI를 구성한다면, 길고 복잡한 마크업의 경우 복잡하고 구조가 한눈에 들어오기 아주 어려울 것이다. 따라서 리액트에서는 `Component` 형식을 제공해 리액트가 제공하는 장점인 독립적이고 재사용 할 수 있는 UI를 가능하게 해준다.

위의 영문 설명과 같이, React.js는 `Component` 를 통해 UI를 구성하여 독립적이고 재사용 가능하게 만들어준다. Component 안에 앞서 설명한 `Element` 를 넣어 구성하면 된다.

### Component의 정의

Component는 ES6의 `class`문법을 사용하여 정의할 수 있고 `React.createClass` 문법을 통하여 정의할 수 있고, `stateless한 Component`에 대하여 `functional Component` 방식으로 정의할 수 있다.

만약 소스 안에 state나 refs가 있으면, `React.createClass` 보다는 `class extends React.Component` 를 사용하자. (이에 대한 자세한 설명은 후술하겠다.)

<br>

> Conceptually, components are like JavaScript functions. They accept arbitrary inputs (called “props”) and return React elements describing what should appear on the screen.

ES6이 본격화 되기 전에는 component를 선언하기 위해 `props` 을 인수로 갖는 function을 사용하였다. 

```jsx
// ES5 : 데이터를 담고 있는 props를 전달받고, React elements를 리턴하니 올바른 컴포넌트의 형태가 맞다.
function Welcome(props) {
  return <h1>Hello, {props.name}</h1>;
}

// ES6
class Welcome extends React.Component {
  render() {
    return <h1>Hello, {this.props.name}</h1>;
  }
}
```



하지만 ES6이 본격화 되었기 때문에, React.js의 `Component` 는 `Class` 로 정의하고 구성한다. 그리고 이 컴포넌트는 기본적으로 `React Component` 를 상속받는다. 기본적인 구조는 다음과 같고, 결과 화면도 다음과 같이 출력된다.

```jsx
class Codelab extends React.Component{ // 클래스명의 시작은 대문자로 써주는게 코딩컨벤션
    render(){
        let style={
            backgroundColor:'aqua',
        };

        return(
            <div>
                <h1 style={style}>Hello {this.props.name}</h1>
                <div>{this.props.children}</div>
            </div>
        );
    }
}

class App extends React.Component{
    render(){
        return(
            <Codelab name="shinye">이 사이에 있는게 this.props.Children 으로 감.</Codelab>
        );
    }
}

ReactDOM.render(<APP />, document.getElementById('root'));
export default App;
```

![https://68.media.tumblr.com/350bcb8c9b1ddda6dd873612df7e123e/tumblr_ox14kc1A6w1v80c66o1_1280.png](https://68.media.tumblr.com/350bcb8c9b1ddda6dd873612df7e123e/tumblr_ox14kc1A6w1v80c66o1_1280.png)

> Previously, we only encountered React elements that represent DOM tags.<br>However, elements can also represent user-defined components:

위의 예시를 보면 render함수 내부의 태그에 component의 이름이 들어가 있는걸 확인할 수 있다.

이전의 element 예시 까지만 해도 기존의 우리가 알고 있는 DOM태그만을 요소로 넣었다.<br>하지만 React의 elements는 사용자가 정의한 component 역시도 elements로 가질 수 있다. 다시 위의 예시를 언급하며 정확한 예를 들어보자. (더 직관적으로 원리를 보기 위해 클래스버전이 아닌 함수 버전으로 작성하겠다.)

```jsx
function Welcome(props) {
  return <h1>Hello, {props.name}</h1>;
}

const element = <Welcome name="Shinye" />;
ReactDOM.render(
  element,
  document.getElementById('root')
);
```

> When React sees an element representing a user-defined component, it passes JSX attributes to this component as a single object. We call this object “props”.

리액트는 render시에 사용자가 정의한 컴포넌트를 element로 전달한 것을 확인하게 된다면, 이 element 내의 JSX attribute들을(위의 예시에선 `name="shinye"` 부분) 하나의 객체로 만든다. 그리고 우리는 이것을 `props` 라고 부른다. (props에 대한 설명은 뒤에서 다시...)



또한 모든 리액트의 컴포넌트에는 `render` 메소드가 존재한다. <br>이 render메소드는 해당 컴포넌트가 어떻게 생길지 정의해준다. 다시 말해, 컴포넌트를 통해 어떤 view를 보여줄 것인지 `JSX` 형태로 작성하여 return 해주면 된다. (JSX에 대한 자세한 설명은 후술할 것이다.) <br>또한, `render()` 는 하나의 컴포넌트만을 반환해야한다. 복수의 컴포넌트를 반환할 수 없다.

```jsx
// NO : 두 개의 컴포넌트
render() {
   return (
     <div>title</div>
     <div>contents</div>
   );
}

// OK
render() {
  return (
    <div>
      <div>title</div>
      <div>contents</div>
    </div>
  );
}
```





**Class와 생성자 메소드**

클래스에 대한 설명은 [여기](https://github.com/Shinye/TIL/blob/master/JavaScript/class.md)서 확인할 수 있다. 

(그래도 강의에서 들은 내용을 다시 정리해보자면) 

- 생성자 메소드는,class 로 생성된 객체를 생성하고 초기화할 때 실행되는 것이다. 
- JS의 클래스 안에는 메소드만 만들 수 있다.
- 클래스 안에 변수를 사용하고 싶을 때는 생성자 메소드 안에서 initialize 하면 된다.
- 함수선언과 클래스 선언의 차이점이라면, 함수와는 달리 클래스는 호이스팅이 일어나지 않는다는 점 정도이다.
- `extends` 키워드를 통해 상속이 가능하고, `super` 키워드를 통해 상속 받은 parent 클래스의 생성자 함수를 호출 가능.



### JSX

> This funny tag syntax is neither a string nor HTML.
>
> It is called JSX, and it is a syntax extension to JavaScript. We recommend using it with React to describe what the UI should look like. JSX may remind you of a template language, but it comes with the full power of JavaScript.
>
> JSX produces React "elements". We will explore rendering them to the DOM

- JSX는 자바스크립트와 HTML 사이의 모습을 가진 문법이다.

- 이러한 XML-Like syntax를 nativeJS로 변환해서 사용된다. 

  - 사실 JSX로 작성된 element 또는 Component는 `React.createElement()`로 컴파일된다. React에서 일종의 sugar syntax를 제공하는 셈이다. <br>사실 JSX 없어도 React를 사용하는데 무리는 없지만 React 공식문서도 [Airbnb의 React코딩컨벤션](https://github.com/apple77y/javascript/tree/master/react) 도 JSX의 적극 활용을 권장한다.

    ```jsx
    // JSX로 쓰여진 코드
    class Hello extends React.Component {
      render() {
        return <div>Hello {this.props.toWhat}</div>;
      }
    }

    ReactDOM.render(
      <Hello toWhat="World" />,
      document.getElementById('root')
    );
    ```

    ```javascript
    // JSX 없이 쓰여진 코드
    class Hello extends React.Component {
      render() {
        return React.createElement('div', null, `Hello ${this.props.toWhat}`);
      }
    }

    ReactDOM.render(
      React.createElement(Hello, {toWhat: 'World'}, null),
      document.getElementById('root')
    );
    ```

    ​

- 위에서 컴포넌트 클래스의 `render()` 함수는 반드시 하나의 컴포넌트만을 반환해야한다고 했다. 아래의 예시와 같이 JSX는 반드시 감싸져 있는 코드여야 한다. 

  ```html
  <div>
  	<h1>hello!</h1>
  </div>
  ```

  - 반드시 루트 노드(Root Node)로 **하나의 노드를 지정**해야 한다는 것이다. ReactDOM은 오직 하나의 루트 노드만 렌더링하기 때문에 다음의 경우는 렌더링하지 못합니다.

    ```html
    <h1>hi!</h1>
    <div>hello!</div>
    ```

    ​

- JSX 안에서(render()함수의 return 내부) 자바스크립트 문법을 쓰고 싶다면 `{}` (bracket) 안에 넣어주면 된다.

- JSX로 HTML 태그의 속성 값을 지정하고자 할 때는 `""`(double quote)를 사용하지 않는다. <br>사용하게 되면 JSX는 속성을 표현식이 아닌 문자열 리터럴로 인식하게 된다.<br> 다음의 `img`태그의 경우처럼 태그가 비어있으면 `/>`로 바로 닫아줘야 한다. 자식 컴포넌트가 없거나 한 줄로 element 작성이 끝나는 경우에는 닫힘 태그로 self-close를 해준다.

  ```jsx
  let url = "api/get/someting";
  const element = (
          <img src={url} />
  );
  ```

- JSX에서 주석처리를 할 때는 `{ /* .... */ }` 다음과 같이 container element 안에 주석이 작성되어야 한다.

  ​

  ​

### 참고URL

[inflearn - React & Express 를 이용한 웹 어플리케이션 개발하기](https://www.inflearn.com/course/react-강좌-velopert/)

[[React] 2. Elements and Component](https://jaeyeophan.github.io/2017/05/19/React-2-Elements-and-Component/)<br>[Components and Props](https://reactjs.org/docs/components-and-props.html)<br>[Rendering Elements](https://reactjs.org/docs/rendering-elements.html)<br>[Introducing JSX](https://reactjs.org/docs/introducing-jsx.html)<br>[coderifleman - React.js를 이해하다(4)](https://blog.coderifleman.com/2015/06/29/learning-react-4/)<br>[coderifleman - React.js를 이해하다(1)](https://blog.coderifleman.com/2015/06/29/learning-react-1/)<br>[NAVER D2 - React 적용 가이드 - React 작동 방법](http://d2.naver.com/helloworld/9297403)<br>[프레임워크와 라이브러리의 차이점](http://webclub.tistory.com/458)<br>[프레임워크와 라이브러리의 차이](http://web-front-end.tistory.com/63)<br>[React Without JSX](https://reactjs.org/docs/react-without-jsx.html)