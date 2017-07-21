# DOM

## DOM이란?
W3C의 레퍼런스를 보면 다음과 같이 작성되어 있다.

>The DOM is a W3C (World Wide Web Consortium) standard.
><br>The DOM defines a standard for accessing documents:
>
>"The W3C Document Object Model (DOM) is a platform and language-neutral interface that allows programs and scripts to dynamically access and update the content, structure, and style of a document."
>
>The W3C DOM standard is separated into 3 different parts:
>
>Core DOM - standard model for all document types<br>
>XML DOM - standard model for XML documents<br>
>HTML DOM - standard model for HTML documents<br>


DOM이란 Document Object Model의 줄임말로, HTML과 XML문서의 내용, 구조, 스타일을 조작하고 나타낼 수 있게 해주는 `API`이다.<br>
**`브라우저`** 가 HTML파일을 `파싱`하여 **DOM tree** 로 만들어주어, 문서(HTML파일)을 구조화해서 표현해준다.

W3C의 설명에 의하면, <br>
The HTML DOM is a `standard object model` and `programming interface` for HTML. It defines:

- The HTML elements as objects
- The properties of all HTML elements
- The methods to access all HTML elements
- The events for all HTML elements
- In other words: The HTML DOM is a standard for how to get, change, add, or delete HTML elements.

정리하자면 DOM은 표준 객체모델이자 다른 프로그램(스크립트 언어 및 다른 프로그래밍 언어)을 위한 HTML/XML의 인터페이스 이며,<br>

- HTML 도큐먼트 내의 요소들을 객체로 만들어
- 해당 HTML 요소의 속성,
- 해당 HTML 요소의 메서드,
- 해당 HTML 요소에 할당된 이벤트 들을 가지게 한다.
- 다시 말해, HTML DOM은 HTML의 요소들을 가져오고, 변경하고, 추가하고, 삭제할 수 있는 표준 방법을 제공한다.

### 📌 파싱이란?
문장을 그것을 이루고 있는 구성 성분으로 분해하고 그들 사이의 위계 관계를 분석하여 문장의 구조를 결정하는 것.<br>
일련의 문자열을 의미있는 토큰으로 분해하여 이들로 이루어진 parse tree를 생성하는 것이다.<br> **파서**는 파싱을 실행하는 프로그램 모듈!

### 📌 API란?
Application Programming Interface의 약자.<br>일반적으로 `Interface` 란 무언가를 조작하기 위한 디자인으로, 예를 들어 키보드와 스크린은 사람이 컴퓨터를 조작할 수 있도록 해주는 둘 사이의 접점이다. <br>그리고 `Programming Interface` 는 한 프로그램이 다른 프로그램을 이용할 때 쓰는 인터페이스이다. 이를 통해 프로그램간의 커뮤니케이션이 가능해진다. <br><br>API의 예로,<br> 카카오톡 친구에게 게임 친구추가 메세지를 보내고 싶다면 게임이 카카오톡 메세지 전송 기능에 접근 및 사용할 수 있도록 카카오톡 API를 사용 할 것이다.

이처럼 API의 역할을 하는 DOM은, 자바스크립트 및 프로그래밍 언어들이 DOM구조에 접근할 수 있는 방법을 제공해준다.

### 📌 설명에 노드와 객체가 혼용되어 쓰이는데 뭐가 뭐지?🙄
스택오버플로우에 영어로 나와있는 설명이 직관적이고 이해가 잘 되어있어서 덧붙인다.<br>
Node interface is the primary datatype for the entire Document Object Model.<br>A node is the generic name for any type of object in the DOM hierarchy. A node could be one of the built-in DOM elements such as document or document.body, it could be an HTML tag specified in the HTML such as `<input>` or `<p>` or it could be a text node that is created by ㄴthe system to hold a block of text inside another element. So, `**a node is any DOM object.**`

An element is one specific type of node as there are many other types of nodes (text nodes, comment nodes, document nodes, etc...).

The DOM consists of a hierarchy of nodes where each node can have a parent, a list of child nodes and a nextSibling and previousSibling.

한마디로 요약하자면 node는 DOM의 각 객체들의 데이터 타입과 같은 것이다. 객체들을 node로 표현할 수 있는 것이다.

## DOM이 하는 일

- Document(HTML,XML파일)의 요소 집합이, DOM에서는 객체의 구조화 된 계층구조로 만들어져 트리 형태로 제공한다.
- 이렇게 문서를 계층적으로 표현한 DOM은, `<body>` 와 `<p>` 같은 HTML태그나 요소를 나타내는 노드, 텍스트의 문자열을 나타내는 노드를 포함하고 있다. (주석 역시도 노드로 포함된다!)
- DOM 은 구조화된 `nodes`와 `property` 와 `method` 를 갖고 있는 `objects` 로 문서를 표현한다.
- 예를 들어 `document object` 는 document 자체를 의미하며, `table object` 는 HTML table 에 접근하기 위한 HTMLTableElement DOM 인터페이스를 구현한 것이다.
> 이 항목이 잘 이해가 안갔는데, 개발자도구 콘솔창에 쳐서 보니 이제서야 객체가 맞구나 하고 이해가 갔다
> ![https://68.media.tumblr.com/0d840b3c7992edb4eabb6c574c43dd7b/tumblr_ote79uaAMe1v80c66o1_1280.png](https://68.media.tumblr.com/0d840b3c7992edb4eabb6c574c43dd7b/tumblr_ote79uaAMe1v80c66o1_1280.png)
> ![https://68.media.tumblr.com/dcfb118750af1eae2b1f6dfab1b8f672/tumblr_ote79uaAMe1v80c66o2_1280.png](https://68.media.tumblr.com/dcfb118750af1eae2b1f6dfab1b8f672/tumblr_ote79uaAMe1v80c66o2_1280.png)



- DOM은 트리에 대한 접근을 허용하는 `method` 를 규정하고, 해당 메서드는 문서의 구조, 양식, 내용을 변경할 수 있다.
- 또한 `nodes` 는 각기 부여된 **`이벤트 핸들러`를 내포**할 수 있으며, 어떠한 이벤트가 발생하면 그에 해당하는 이벤트 핸들러가 실행된다.


<br>
### 참고 URL
책 자바스크립트 완벽가이드<br>
[Difference between Node object and Element object?](https://stackoverflow.com/questions/9979172/difference-between-node-object-and-element-object)<br>
[파싱,파서](https://zetawiki.com/wiki/%ED%8C%8C%EC%8B%B1,_%ED%8C%8C%EC%84%9C)<br>
[JavaScript HTML DOM](https://www.w3schools.com/js/js_htmldom.asp)<br>[[용어 뜻/설명] API란?](http://blog.naver.com/azure0777/220749852024)<br>[MDN-DOM 소개](https://developer.mozilla.org/ko/docs/Gecko_DOM_Reference/%EC%86%8C%EA%B0%9C)<br>[MDN-문서 객체 모델 (DOM)](https://developer.mozilla.org/ko/docs/Gecko_DOM_Reference)<br>

