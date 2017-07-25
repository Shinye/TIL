# 함수형 프로그래밍(@JavaScript)

> 잠시 당신이 나무꾼이라고 가정해보자. 당신은 숲에서 가장 좋은 도끼를 가지고 있고, 그래서 가장 일 잘하는 나무꾼이다. 그런데 어느 날 누가 나타나서 나무를 자르는 새로운 패러다임인 전기톱을 알리고 다닌다. 이 사람이 무척 설득력이 있어서 당신은 사용하는 방법도 모르면서 전기톱을 사게 된다. 당신은 여태껏 했던 방식대로 시동을 걸지도 않고 전기톱으로 나무를 마구 두들겨댄다. 곧 당신은 이 새로운 전기톱은 일시적인 유행일 뿐이라고 단정하고 다시 도끼를 쓰기 시작한다. 그때 누군가 나타나서 전기톱의 시동 거는 법을 가르쳐 준다. — “함수형 사고” 에서

함수형 프로그래밍의 장점을 비유적으로 표현한 것이다. 

## 함수형 프로그래밍의 특징

함수형 프로그래밍을 하기 위해서는, 함수가 고차함수의 특징을 가지고 있어야 한다.

### 고차함수(Higher-Order function)

함수를 `파라미터로 전달` 받거나, `함수를 리턴` 하는 `함수` 를 뜻한다. 이러한 고차함수의 조건은 [1급객체](https://github.com/Shinye/TIL/blob/master/JavaScript/aboutFunction.md) 역시 갖고 있다.

### 함수형 프로그래밍의 주요 특성

- 변경 가능한 상태를 불변상태(Immutab)로 만들어 SideEffect를 없애자
- 함수형 언어에서 모든 것은 객체이다.
- ⭐️ 코드를 간결하게 하고 가독성을 높여 구현할 로직에 집중 시키자.
- 동시성 작업을 보다 쉽게 안전하게 구현 하자.


## Map

`Array.prototye.map` 은 배열 내의 모든 요소 각각에 대하여 제공된 함수(callback)를 호출하고, 그 결과를 모아서, 새로운 배열을 반환한다. 배열의 요소들에 **특정한 처리를 할때** 주로 사용한다

React에서 list를 그려줄 때 map을 많이 사용한다.

예시) animals 객체 배열에서 name 프로퍼티의 값만을 추출하고 싶을 때

```javascript
let animalsArr = [
  { name: 'Fluffykins', species: 'rabbit' },
  { name: 'Caro',       species: 'dog' },
  { name: 'Hamilton',   species: 'dog' },
  { name: 'Harold',     species: 'fish' },
  { name: 'Ursula',     species: 'cat' },
  { name: 'Jimmy',      species: 'fish' }
]

// 기존의 for문을 써 출력
let names = []
for (var i = 0; i < animalsArr.length; i++) {
  names.push(animalsArr[i].name)
}

// map함수를 써 출력
let names = animalsArr.map(function(animal) { return animal.name })

// ES6의 arrow function 적용
let names = animalsARr.map((animal) => animal.name)

```

<br>

## Filter

> Should return true or false value.<br>
> To determine whether or not the item should be included in the array or not.
> When it's done, it will return the new filtered aray.

Array.prototype.filter는 파라미터로 넘겨진 함수의 테스트를 통과하는(true인 경우) 모든 요소가 있는 새로운 배열을 반환한다.

```javascript
// 과목 이름, 점수 데이터
let subjects =
    [{
        name: 'math',
        score: 100,
    }, {
        name: 'english',
        score: 85
    }, {
        name: 'korean',
        score: 95
    }];

// 90점 이상인지 체크
function is90Over(subject) {
    return subject.score > 90;
}

// for문으로 작성한 경우.
let result = [];
for (let i = 0; i < subjects.length; i++) {
    let subject = subjects[i];
    if(is90Over(subject)){
        result.push(subjects[i]);
    }
}
console.log(result); // [ { name: 'math', score: 100 }, { name: 'korean', score: 95 } ]

// filter함수를 쓴 경우
let funcResult = subjects.filter(is90Over);
console.log(funcResult); // [ { name: 'math', score: 100 }, { name: 'korean', score: 95 } ]
```
<br>

## Reduce

Array.prototype.reduce는 인자로 주어진 함수를 사용하여 **배열의 원소들을 하나의 값으로 결합**한다.<br>
map, filter 함수와 구조가 다소 달라 구조를 확인해볼 필요가 있다.

```javascript
let array = [1,2,3,4,5];
let foo = array.reduce(function(sum, value){return sum+value}, 0);
```

reduce 함수의 <br>
- **첫 번째 인자** : 배열 원소 개수의 감소 작업을 하는 함수. 배열의 원소를 하나하나 방문하면서 크기를 점차 줄여가다가 마지막 남은 값을 반환한다.<br>
- **두 번째 인자** : 감소함수의 첫 번째 인자에 전달될 초기 값

reduce 함수 내부의 감소 함수의<br>
- **첫 번째 인자** : 최종적으로 할당 할 변수에 전달 될 값. 배열의 원소를 감소함수를 거쳐 하나씩 돌며 값의 변동이 있을 시 반영한다.<br>
- **두 번째 인자** : 배열의 각 원소를 가리킴

예시) subjectsArr에서 과목들의 모든 글자수의 합을 얻고 싶다.

```javascript
// 과목을 저장
let subjects = ['math', 'english', 'korean'];

// 이전 숫자에 단어 숫자를 카운트해서 저장
function addLength(total, word) {
    return total + word.length;
}

// 기존의 for loop을 이용한 방법
let loopTotal = 0;
for (let i = 0; i < subjects.length; i++) {
    let subject = subjects[i];
    loopTotal = addLength(loopTotal, subject);
}
console.log(loopTotal); // 17

// Reduce함수를 쓴 방법

let funcTotal = subjects.reduce(addLength, 0);
console.log(funcTotal);  // 17
```



### 참고 URL
[Functional Programming in Javascript](http://dev-momo.tistory.com/entry/Functional-Programming-in-Javascript)

[Higher-order functions - Part 1 of Functional Programming in JavaScript] (https://youtu.be/BMUiFMZr7vk?list=PL0zVEGEvSaeEd9hlmCXrk5yUyqUag-n84)<br>
[함수형 프로그래밍이란?](https://medium.com/@lazysoul/%ED%95%A8%EC%88%98%ED%98%95-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D%EC%9D%B4%EB%9E%80-d881230f2a5e)