# DOM과 자바스크립트

DOM이란? (추가바람…ㅎㅎ...)



### NODE의 클래스 계층

![https://68.media.tumblr.com/5409e7d06eb7bc0066a56ec190d4224b/tumblr_os9ddhqzHy1v80c66o1_1280.jpg](https://68.media.tumblr.com/5409e7d06eb7bc0066a56ec190d4224b/tumblr_os9ddhqzHy1v80c66o1_1280.jpg)



### 'Element' 객체 선택하기

```javascript
// 1. Id - '하나'의 Element 객체가 선택됨
var foo1 = document.getElementById("idName");

// 2. class - '복수'의 Element 객체가 선택됨
var foo2 = document.getElementsByClassName("className");

// 3. name - '복수'Element 객체가 선택됨
var foo3 = document.getElementsByName("name");

// 4. tagName - '복수'의 Element 객체가 선택됨
var foo4 = document.getElementsByTagName("tagName");
```

2~4번 케이스의 경우와 같이 getElements~ method를 통해 복수의 Element 객체가 선택 될 때는 객체들이 `nodeList(Elements의 배열)` 의 형태로 return된다. nodeList의 item들은 일반적인 배열처럼 `index` 를 통해 접근이 가능한다. 2번의 예시에서 4개의 객체가 선택되었다면 `foo2[3]` 의 형태와 같이 아이템을 선택할 수 있다.

📌 return된 nodeList의 **아이템 개수**가 궁금하면 자바스크립트에서 배열의 길이를 알아보는 API와 동일하게 `.length()` 함수를 사용하면 된다.



### 객체의 속성(Attribute) 찾기

```javascript
var foo = element.attributes;
foo[n];
```



### Elements의 내용 가져오기 / 수정하기

```javascript
/*
<div id = "idName"> hello world </div>
*/

var foo = document.getElementById("idName");
foo.textContent = "I'm hungry..."; // #idName 안의 텍스트가 hello world에서 I'm hungry로 바뀐다.
```



📌 **innerText와 textContent 사이의 차이점**

![https://drive.google.com/uc?id=0B3Or0Wv2t1xwOExuS3VpYTZDN1k](https://drive.google.com/uc?id=0B3Or0Wv2t1xwOExuS3VpYTZDN1k)

**`textContent` 프로퍼티의 경우**

- 지정한 요소의 모든 자손 노드 중에서 Text 노드만을 뽑아서 보기 좋게 하나로 연결해준다. 
- 지정한 요소 안에 `<script>` 나 `<style>` 요소가 있다면 이 요소들 안의 텍스트 노드 역시 반환할 수 있다.



**`innerText` 프로퍼티의 경우**

- **무의미한 공백을 제외**하고 열 간격을 조정해서 출력해준다. 

- 따라서 `<table>`, `<tbody>`, `<tr>` 과 같은 중요한 테이블 요소에 대해서 읽기 전용 속성이 된다.

  ![https://drive.google.com/uc?id=0B3Or0Wv2t1xwU3RGZXNCeGhWb0k](https://drive.google.com/uc?id=0B3Or0Wv2t1xwU3RGZXNCeGhWb0k)

- textContent속성과는 달리 지정한 요소 안에 `<script>` 나 `<style>` 요소가 있어도 이 요소들 안의 텍스트 노드를 반환하지 않는다.




### '노드'의 생성 / 삽입 / 삭제

**1. 생성**

```javascript
var foo = document.createElement("div"); // 삽입을 원하는 태그 이름을 작성한다
foo.id = "fooId"; // 생성한 요소에 id명을 추가하고 싶을 때
foo.className = "fooClassName"; // 생성한 요소에 class명을 추가하고 싶을 때
```



**2. 삽입**

- 방법1 : appendChild(삽입노드이름)

  ```javascript
  var div1 = document.getElementById("box1");
  div1.appendChild(foo); 
  // 삽입하고자 하는 노드를 매개변수로 넣는다(따옴표X)
  // 삽입될 위치의 요소에서 가장 마지막에 추가된다.
  ```

- 방법2 : insertBefore(삽입노드이름, 삽입기준노드)

  ```javascript
  var newItem = document.createElement("li");       // Create a <li> node
  var textnode = document.createTextNode("Water");  // Create a text node
  newItem.appendChild(textnode);                    // Append the text to <li>

  var list = document.getElementById("myList"); // Get the <ul> element to insert a new node
  list.insertBefore(newItem, list.childNodes[0]); // Insert <li> before the first child of <ul>
  ```



**3. 삭제와 교체**

1. 삭제 : removeChild(삭제노드이름)

   `removechild()` 메서드는 문서 계층 구조에서 하나의 노드를 삭제한다.<br>주의할 점은, 이 메서드는 삭제하려는 노드가 아니라 **이 노드를 자식으로 가진 부모 노드** 에서 실행된다는 점이다. 메서드 전달인자로 삭제할 자식 노드를 넘기고 부모 노드의 메서드로 호출한다.

   임의의 노드 n을 삭제하기 위해선 다음처럼 작성한다.

   ```javascript
   n.parentNode.removeChild(n);
   ```



2. 교체 : replaceChild(새노드이름, 교체될노드이름)

   `replaceChild()` 메서드 역시 이 노드를 자식으로 가진 부모 모드에서 실행된다. 자식 노드 하나를 삭제하고 새 노드로 교체되는 방식으로 이루어진다.<br>메서드의 첫 번째 인자로는 새 노드 이름 / 두 번째 인자로는 교체될 노드의 이름이 넘겨진다.

   텍스트 문자열로 임의의 노드 n을 교체하기 위해서는 다음과 같이 작성한다.

   ```javascript
   n.parentNode.replaceChild(document.createTextNode("hello world"), n);
   ```





### 자바스크립트를 통한 CSS 값 선택 및 조작

Element에 지정된 css style 값을 추가 수정 삭제하고 싶을 때는 style 속성을 활용하면 된다. 문법은 다음과 같다.

```javascript
var foo = document.getElementById("box1");
foo.style.fontSize = "24pt";
foo.style.fontWeight = "bold";
foo.style.color = "blue";
```

하지만 이 style 속성 값은 정확히는 `CSSStyleDeclaration` 객체라는 점을 유의해야 한다.

따라서 style 속성 명에 미세한 차이가 있는데, 그 차이 중 대표적으로는 CSS 스타일 프로퍼티의 이름에 하이픈(-)이 포함되어 있지 않다는 것이다. 자바스크립트에서는 하이픈이 뺄셈 기호로 인식되기 때문이다. <br>예를 들어 `foo.style.font-size = "24pt"` 와 같은 코드는 문법 오류가 난다.

만약 값을 설정할 때 변수를 따로 지정하여 유동적으로 값을 조정하고 싶다면 다음과 같이 설정하면 된다.

```javascript
var topMarginVal = windows.prompt("상단 마진 값 입력","예)20");
foo.style.marginTop = topMarginVal+"px"; // 숫자+"" => 문자열
```



